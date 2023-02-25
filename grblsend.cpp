#include "grblsend.h"

const int GRBL_BUF_SIZE = 127;

GRBLSend::GRBLSend(Stream* serial) {
  m_serial = serial;

  m_recv_pos = 0;
  m_commands_in_buf = 0;
  m_bytes_in_buf = 0;
  for (int c = 0; c < 9; c++) {
    m_statuses[c][0] = 0;
  }
}

void GRBLSend::fill_status_buffer(char* buffer, int maxlen) {
  snprintf(buffer,maxlen,"%4s:%5s,%5s,%5s",m_statuses[0],m_statuses[2],m_statuses[3],m_statuses[4]);
}


bool GRBLSend::send_realtime_cmd(char cmd) {
  m_serial->write(cmd);
}
bool GRBLSend::queue_command(const char* cmd) {
  int cmd_len = strlen(cmd) + 2;
  if (cmd_len + m_bytes_in_buf <= GRBL_BUF_SIZE) {
    m_command_lengths[m_commands_in_buf] = cmd_len;
    m_bytes_in_buf += cmd_len;
    m_commands_in_buf += 1;

    m_serial->println(cmd);
    return true;
  } else {
    // buffer full - don't send
    return false;
  }
}

bool GRBLSend::update(bool* status_updated) {
  *status_updated = false;
  if (recv_internal()) {
    bool error = false;
    bool needs_pop = false;

    // got a line in m_recv_buffer
    if (strstr(m_recv_buffer, "ok") != NULL) {
      needs_pop = true;
      // command is okay, pop it off the buffer list
    } else if (strstr(m_recv_buffer, "error") != NULL) {
      needs_pop = true;
      // don't send any more after error, stop now and feed hold
      m_serial->write("!");
      return false;
    } else {
      needs_pop = false;
      // pop off any "<status,pos:x,y,z> info responses"

      int status_num = -1;
      int status_count = 0;
      int pos = 0;
      while (true) {
        if (m_recv_buffer[pos] == "<" && status_num == -1) {
          // in status thingy
          status_num = 0;
        } else if (status_num >= 0) {
          // end of status string - drop out
          if (m_recv_buffer[pos] == '>') {
            m_statuses[status_num][status_count] = 0;
            *status_updated = true;
            break;
          }
          // in status reader, look for end of status
          if (m_recv_buffer[pos] == ',' || m_recv_buffer[pos] == ':'))
          {
              // zero terminate this status
              // move to next
              m_statuses[status_num][status_count] = 0;
              status_num += 1;
              status_count = 0;
            }
          else {
            m_statuses[status_num][status_count] = m_recv_buffer[pos];
            status_count += 1;
          }
        }
        pos += 1;
      }
    }

    if (needs_pop) {
      m_commands_in_buf -= 1;
      m_bytes_in_buf -= m_command_lengths[0];
      for (int c = 0; c < m_commands_in_buf; c++) {
        m_command_lengths[c] = m_command_lengths[c + 1];
      }
    }
  }

  if (m_file) {
    bool sent = true;
    // send as many lines as we can
    while (sent) {
      sent = false;
      // fill empty send buffer from file
      if (m_send_buffer[0] == 0) {
        int line_len = m_file.readBytesUntil("\n", m_send_buffer, 256);
        if (line_len > 0 && line_len < 256) {
          m_send_buffer[line_len] = 0;
        }
      }
      if (m_send_buffer[0] != 0) {
        if (queue_command(m_send_buffer)) {
          m_send_buffer[0] = 0;
          sent = true;
        }
      }
    }
    return true;
  }

  bool GRBLSend::recv_internal() {
    int available = m_serial->available();
    if (available > 0) {
      int read_amount = min(2048 - m_recv_pos, available);
      int bytes_read = m_serial->readBytesUntil("\n", buffer, read_amount);
      m_recv_pos += bytes_read;
      // if it hasn't read a terminator then just move the m_recv_pos
      if (bytes_read != read_amount) {
        // shorter buffer than the read_amount = terminator found
        // zero terminate it and return the buffer
        m_recv_buffer[m_recv_pos] = 0;
        m_recv_pos = 0;
        return true;
      }
    }
  }

  int GRBLSend::commands_in_queue() {
    return m_commands_in_buf;
  }
