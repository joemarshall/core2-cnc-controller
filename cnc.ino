//<App !Start!>
// FILE: [cnc.ino]
// Created by GUIslice Builder version: [0.17.b19]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "cnc_GSLC.h"
#include"grblsend.h"

GRBLSend m_gSender(&Serial2);

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemDRO        = NULL;
gslc_tsElemRef* m_pElemFileList   = NULL;
gslc_tsElemRef* m_pElemListbox2   = NULL;
gslc_tsElemRef* m_pElemOutTxt3    = NULL;
gslc_tsElemRef* m_pElemProgress1  = NULL;
gslc_tsElemRef* m_pListSlider1    = NULL;
gslc_tsElemRef* m_pListSlider2    = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    Serial.print("TOUCH");
    Serial.println(pElem->nId);
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_BTNJOG:
        gslc_SetPageCur(pGui,E_PG_JOG);
        break;
      case E_ELEM_BTNFILE:
        fill_file_list();
        gslc_SetPageCur(pGui,E_PG_FILES);
        break;
      case E_ELEM_XUP:
        break;
      case E_ELEM_XDOWN:
        break;
      case E_ELEM_YUP:
        break;
      case E_ELEM_YDOWN:
        break;
      case E_ELEM_ZUP:
        break;
      case E_ELEM_ZDOWN:
        break;
      case E_ELEM_SPINDLE:
        break;
      case E_ELEM_MENU:
        gslc_PopupShow(&m_gui, E_PG_JOG_ACTIONS, true);
        break;
      case E_ELEM_DISTANCE:
        break;
      case E_ELEM_BACK:
        gslc_SetPageCur(&m_gui, E_PG_MENU);
        break;
      case E_ELEM_BACK2:
        gslc_SetPageCur(&m_gui, E_PG_MENU);
        break;
      case E_ELEM_SENDFILE:
// get file here

        break;
      case E_ELEM_BTN13:
        break;
      case E_ELEM_BTN14:
        break;
      case E_ELEM_BTN17:
        gslc_PopupHide(&m_gui);
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui, pElemRef);
  char            acTxt[MAX_STR + 1];
  
  if (pElemRef == NULL) {
    return false;
  }

  // From the element's ID we can determine which listbox was active.
  switch (pElem->nId) {
//<Listbox Enums !Start!>

    case E_ELEM_LISTBOX2:
      if (nSelId != XLISTBOX_SEL_NONE) {
        gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      }
      break;
    case E_ELEM_FILELIST:
      if (nSelId != XLISTBOX_SEL_NONE) {
        gslc_ElemXListboxGetItem(&m_gui, pElemRef, nSelId, acTxt, MAX_STR);
      }
      break;
//<Listbox Enums !End!>
    default:
      break;
  }
  return true;
}
//<Draw Callback !Start!>
//<Draw Callback !End!>

// Callback function for when a slider's position has been updated
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);
  int16_t         nVal;

  // From the element's ID we can determine which slider was updated.
  switch (pElem->nId) {
//<Slider Enums !Start!>
    case E_LISTSCROLL1:
      // Fetch the slider position
      nVal = gslc_ElemXSliderGetPos(pGui,m_pListSlider1);
      break;

    case E_LISTSCROLL2:
      // Fetch the slider position
      nVal = gslc_ElemXSliderGetPos(pGui,m_pListSlider2);
      break;
//<Slider Enums !End!>
    default:
      break;
  }

  return true;
}
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(115200);
  Serial2.begin(115200,SERIAL_8N1,21,22);
  // Wait for USB Serial 
  delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used
  
  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();

}

// -----------------------------------
// Main event loop
// -----------------------------------
long last_update_time=0;

void loop()
{
  long curtime=millis();
  if(curtime>last_update_time+500)
  {
    last_update_time=curtime;
    // query machine position
    m_gSender.send_realtime_cmd("?");
  }
  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);

  bool status_updated=false;
  m_gSender.update(&status_updated);
  if(status_updated)
  {
    char status[32];
    m_gSender.fill_status_buffer(status,32);
    gslc_ElemSetTxtStr(&m_gui,m_pElemDRO,status);
  }
  
  if(M5.BtnC.wasPressed())
  {
    switch(gslc_GetPageCur(&m_gui))
    {
      case E_PG_JOG:
      case E_PG_FILES:
        // return to menu
        gslc_SetPageCur(&m_gui,E_PG_MENU);
        break;
    }
  }
}  

void fill_file_list()
{
  Serial.println("Files:");    
  gslc_ElemXListboxReset(&m_gui,m_pElemFileList);
  File root=SD.open("/");
  while(true)
  {
    File entry=root.openNextFile();
    if(!entry)
    {
      break;
    }
    String name=String(entry.name());
    if(name.length()>31)
    {
      name=name.substring(0,31);
    }
    gslc_ElemXListboxAddItem(&m_gui,m_pElemFileList,entry.name());

    Serial.println(name);    
  }
}
