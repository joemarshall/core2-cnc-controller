#include<sd.h>

class GRBLSend
{
  public:
  GRBLSend(Stream* serial);
  bool send_realtime_cmd(char cmd);
  bool queue_command(const char* cmd);
  int commands_in_queue();

  void queue_file(File f);

  bool update(bool*status_updated); // returns true if okay to continue
  void fill_status_buffer(char*buffer,int maxlen);
private:
  bool recv_internal();
  // number of commands currently unacknowledged
  int m_commands_in_buf;
  int m_bytes_in_buf;
  // length of each command sent
  int m_command_lengths[256];

  File m_file;
  char m_send_buffer[256]; // buffer for line to send
  char m_recv_buffer[2048]; // buffer for receiving line into
  char m_statuses[9][8];
  int m_recv_pos;
  Stream* m_serial;

};