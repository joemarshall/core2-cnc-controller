//<File !Start!>
// FILE: [cnc_GSLC.h]
// Created by GUIslice Builder version: [0.17.b19]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include"config.h" // our onfig file for guislice
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XListbox.h"
#include "elem/XProgress.h"
#include "elem/XSlider.h"
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
#include <M5Core2.h>
#include "FreeSans14pt7b.h"
/*
//<Fonts !Start!>
#include <M5Stack.h>
#include "Fonts/GFXFF/FreeMonoBold9pt7b.h"
#include "FreeSans14pt7b.h"
#include "Fonts/GFXFF/FreeSans9pt7b.h"
#include "Fonts/GFXFF/FreeSansBold24pt7b.h"
#include "Fonts/GFXFF/FreeSansBold9pt7b.h"
//<Fonts !End!>
*/
// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_BASE,E_PG_MENU,E_PG_JOG,E_PG_FILES,E_PG_RUNFILE
      ,E_PG_JOG_ACTIONS};
enum {E_ELEM_BACK,E_ELEM_BACK2,E_ELEM_BTN13,E_ELEM_BTN14,E_ELEM_BTN17
      ,E_ELEM_BTNFILE,E_ELEM_BTNJOG,E_ELEM_DISTANCE,E_ELEM_FILELIST
      ,E_ELEM_LISTBOX2,E_ELEM_MENU,E_ELEM_PROGRESS1,E_ELEM_SENDFILE
      ,E_ELEM_SPINDLE,E_ELEM_TEXT2,E_ELEM_TEXT3,E_ELEM_TEXTDRO
      ,E_ELEM_XDOWN,E_ELEM_XUP,E_ELEM_YDOWN,E_ELEM_YUP,E_ELEM_ZDOWN
      ,E_ELEM_ZUP,E_LISTSCROLL1,E_LISTSCROLL2};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN5X8,E_FREEMONOBOLD9,E_FREESANS14,E_FREESANS9
      ,E_FREESANSBOLD24,E_FREESANSBOLD9,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                6

#define MAX_ELEM_PG_BASE 1 // # Elems total on page
#define MAX_ELEM_PG_BASE_RAM MAX_ELEM_PG_BASE // # Elems in RAM

#define MAX_ELEM_PG_MENU 2 // # Elems total on page
#define MAX_ELEM_PG_MENU_RAM MAX_ELEM_PG_MENU // # Elems in RAM

#define MAX_ELEM_PG_JOG 10 // # Elems total on page
#define MAX_ELEM_PG_JOG_RAM MAX_ELEM_PG_JOG // # Elems in RAM

#define MAX_ELEM_PG_FILES 5 // # Elems total on page
#define MAX_ELEM_PG_FILES_RAM MAX_ELEM_PG_FILES // # Elems in RAM

#define MAX_ELEM_PG_RUNFILE 5 // # Elems total on page
#define MAX_ELEM_PG_RUNFILE_RAM MAX_ELEM_PG_RUNFILE // # Elems in RAM

#define MAX_ELEM_PG_JOG_ACTIONS 4 // # Elems total on page
#define MAX_ELEM_PG_JOG_ACTIONS_RAM MAX_ELEM_PG_JOG_ACTIONS // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui m_gui;
gslc_tsDriver m_drv;
gslc_tsFont m_asFont[MAX_FONT];
gslc_tsPage m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asBasePage1Elem[MAX_ELEM_PG_BASE_RAM];
gslc_tsElemRef                  m_asBasePage1ElemRef[MAX_ELEM_PG_BASE];
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MENU_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MENU];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG_JOG_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG_JOG];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG_FILES_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG_FILES];
gslc_tsElem                     m_asPage4Elem[MAX_ELEM_PG_RUNFILE_RAM];
gslc_tsElemRef                  m_asPage4ElemRef[MAX_ELEM_PG_RUNFILE];
gslc_tsElem                     m_asPopup1Elem[MAX_ELEM_PG_JOG_ACTIONS_RAM];
gslc_tsElemRef                  m_asPopup1ElemRef[MAX_ELEM_PG_JOG_ACTIONS];
gslc_tsXListbox                 m_sListbox1;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf1[16384 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll1;
gslc_tsXProgress                m_sXBarGauge1;
gslc_tsXListbox                 m_sListbox2;
// - Note that XLISTBOX_BUF_OH_R is extra required per item
char                            m_acListboxBuf2[32 + XLISTBOX_BUF_OH_R];
gslc_tsXSlider                  m_sListScroll2;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemDRO;
extern gslc_tsElemRef* m_pElemFileList;
extern gslc_tsElemRef* m_pElemListbox2;
extern gslc_tsElemRef* m_pElemOutTxt3;
extern gslc_tsElemRef* m_pElemProgress1;
extern gslc_tsElemRef* m_pListSlider1;
extern gslc_tsElemRef* m_pListSlider2;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui, void* pvElemRef, gslc_teTouch eTouch, int16_t nX, int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui, void* pvElemRef, gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void* pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui, void* pvElemRef, int16_t nPos);
bool CbSpinner(void* pvGui, void* pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui, void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen() {
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui, &m_drv, m_asPage, MAX_PAGE, m_asFont, MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
  //<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREEMONOBOLD9,GSLC_FONTREF_PTR,&FreeMonoBold9pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANS14,GSLC_FONTREF_PTR,&FreeSans14pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANS9,GSLC_FONTREF_PTR,&FreeSans9pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD24,GSLC_FONTREF_PTR,&FreeSansBold24pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_FREESANSBOLD9,GSLC_FONTREF_PTR,&FreeSansBold9pt7b,1)) { return; }
  //<Load_Fonts !End!>

  //<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_BASE,m_asBasePage1Elem,MAX_ELEM_PG_BASE_RAM,m_asBasePage1ElemRef,MAX_ELEM_PG_BASE);
  gslc_PageAdd(&m_gui,E_PG_MENU,m_asPage1Elem,MAX_ELEM_PG_MENU_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MENU);
  gslc_PageAdd(&m_gui,E_PG_JOG,m_asPage2Elem,MAX_ELEM_PG_JOG_RAM,m_asPage2ElemRef,MAX_ELEM_PG_JOG);
  gslc_PageAdd(&m_gui,E_PG_FILES,m_asPage3Elem,MAX_ELEM_PG_FILES_RAM,m_asPage3ElemRef,MAX_ELEM_PG_FILES);
  gslc_PageAdd(&m_gui,E_PG_RUNFILE,m_asPage4Elem,MAX_ELEM_PG_RUNFILE_RAM,m_asPage4ElemRef,MAX_ELEM_PG_RUNFILE);
  gslc_PageAdd(&m_gui,E_PG_JOG_ACTIONS,m_asPopup1Elem,MAX_ELEM_PG_JOG_ACTIONS_RAM,m_asPopup1ElemRef,MAX_ELEM_PG_JOG_ACTIONS);

  // Now mark E_PG_BASE as a "base" page which means that it's elements
  // are always visible. This is useful for common page elements.
  gslc_SetPageBase(&m_gui, E_PG_BASE);


  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MENU);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_BLACK);

  // -----------------------------------
  // PAGE: E_PG_BASE
  
  
  // Create E_ELEM_TEXTDRO runtime modifiable text
  static char m_sDisplayText1[31] = "IDLE: 000.00, 000.00, 000.000";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXTDRO,E_PG_BASE,(gslc_tsRect){0,10,320,11},
    (char*)m_sDisplayText1,31,E_FREEMONOBOLD9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElemDRO = pElemRef;

  // -----------------------------------
  // PAGE: E_PG_MENU
  
  
  // create E_ELEM_BTNJOG button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTNJOG,E_PG_MENU,
    (gslc_tsRect){50,40,220,60},(char*)"Jog",0,E_FREESANSBOLD24,&CbBtnCommon);
  
  // create E_ELEM_BTNFILE button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTNFILE,E_PG_MENU,
    (gslc_tsRect){50,120,220,60},(char*)"File",0,E_FREESANSBOLD24,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG_JOG
  
  
  // create E_ELEM_XUP button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_XUP,E_PG_JOG,
    (gslc_tsRect){240,90,60,60},(char*)"X+",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_XDOWN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_XDOWN,E_PG_JOG,
    (gslc_tsRect){120,90,60,60},(char*)"X-",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_YUP button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_YUP,E_PG_JOG,
    (gslc_tsRect){180,30,60,60},(char*)"Y+",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_YDOWN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_YDOWN,E_PG_JOG,
    (gslc_tsRect){180,150,60,60},(char*)"Y-",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_ZUP button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_ZUP,E_PG_JOG,
    (gslc_tsRect){10,40,50,50},(char*)"Z+",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_ZDOWN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_ZDOWN,E_PG_JOG,
    (gslc_tsRect){10,150,50,50},(char*)"Z-",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_SPINDLE button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_SPINDLE,E_PG_JOG,
    (gslc_tsRect){180,90,60,60},(char*)"SPIN: 0",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_MENU button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_MENU,E_PG_JOG,
    (gslc_tsRect){0,220,100,20},(char*)"...",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_DISTANCE button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_DISTANCE,E_PG_JOG,
    (gslc_tsRect){110,220,100,20},(char*)"Distance: 0.01mm",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_BACK button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BACK,E_PG_JOG,
    (gslc_tsRect){220,220,100,20},(char*)"Back",0,E_BUILTIN5X8,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG_FILES
  
   
  // Create wrapping box for listbox E_ELEM_FILELIST and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,E_PG_FILES,(gslc_tsRect){0,30,300,180});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ELEM_FILELIST,E_PG_FILES,&m_sListbox1,
    (gslc_tsRect){0+2,30+4,300-4-20,180-7},E_FREESANS9,
    (uint8_t*)&m_acListboxBuf1,sizeof(m_acListboxBuf1),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 64, 1); // 64 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 12);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_BLACK);
  m_pElemFileList = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_LISTSCROLL1,E_PG_FILES,&m_sListScroll1,
          (gslc_tsRect){0+300-2-20,30+4,20,180-8},0,64,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLUE);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pListSlider1 = pElemRef;
  
  // create E_ELEM_BACK2 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BACK2,E_PG_FILES,
    (gslc_tsRect){220,220,100,20},(char*)"Back",0,E_BUILTIN5X8,&CbBtnCommon);
  
  // create E_ELEM_SENDFILE button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_SENDFILE,E_PG_FILES,
    (gslc_tsRect){0,220,100,20},(char*)"Send",0,E_BUILTIN5X8,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG_RUNFILE
  

  // Create progress bar E_ELEM_PROGRESS1 
  pElemRef = gslc_ElemXProgressCreate(&m_gui,E_ELEM_PROGRESS1,E_PG_RUNFILE,&m_sXBarGauge1,
    (gslc_tsRect){10,70,300,12},0,100,0,GSLC_COL_GREEN,false);
  m_pElemProgress1 = pElemRef;
  
  // Create E_ELEM_TEXT2 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT2,E_PG_RUNFILE,(gslc_tsRect){20,40,31,13},
    (char*)"File:",0,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  
  // Create E_ELEM_TEXT3 runtime modifiable text
  static char m_sDisplayText3[41] = "";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT3,E_PG_RUNFILE,(gslc_tsRect){60,40,260,13},
    (char*)m_sDisplayText3,41,E_FREESANS9);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  m_pElemOutTxt3 = pElemRef;
  
  // create E_ELEM_BTN13 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN13,E_PG_RUNFILE,
    (gslc_tsRect){10,130,80,40},(char*)"Pause",0,E_FREESANSBOLD9,&CbBtnCommon);
  
  // create E_ELEM_BTN14 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN14,E_PG_RUNFILE,
    (gslc_tsRect){230,130,80,40},(char*)"Cancel",0,E_FREESANSBOLD9,&CbBtnCommon);

  // -----------------------------------
  // PAGE: E_PG_JOG_ACTIONS
  
   
  // Create wrapping box for listbox E_ELEM_LISTBOX2 and scrollbar
  pElemRef = gslc_ElemCreateBox(&m_gui,GSLC_ID_AUTO,E_PG_JOG_ACTIONS,(gslc_tsRect){0,40,200,180});
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLACK);
  
  // Create listbox
  pElemRef = gslc_ElemXListboxCreate(&m_gui,E_ELEM_LISTBOX2,E_PG_JOG_ACTIONS,&m_sListbox2,
    (gslc_tsRect){0+2,40+4,200-4-20,180-7},E_FREESANS14,
    (uint8_t*)&m_acListboxBuf2,sizeof(m_acListboxBuf2),0);
  gslc_ElemXListboxSetSize(&m_gui, pElemRef, 5, 1); // 5 rows, 1 columns
  gslc_ElemXListboxItemsSetSize(&m_gui, pElemRef, -1, 18);
  gslc_ElemSetTxtMarginXY(&m_gui, pElemRef, 5, 5);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLACK);
  gslc_ElemXListboxSetSelFunc(&m_gui, pElemRef, &CbListbox);
  gslc_ElemXListboxItemsSetGap(&m_gui, pElemRef, 5,GSLC_COL_BLACK);
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "Zero XY");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "Zero XYZ");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "Zero Z");
  gslc_ElemXListboxAddItem(&m_gui, pElemRef, "Z Probe");
  gslc_ElemSetFrameEn(&m_gui,pElemRef,true);
  m_pElemListbox2 = pElemRef;

  // Create vertical scrollbar for listbox
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_LISTSCROLL2,E_PG_JOG_ACTIONS,&m_sListScroll2,
          (gslc_tsRect){0+200-2-20,40+4,20,180-8},0,9,0,5,true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLUE,GSLC_COL_BLACK,GSLC_COL_BLUE);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  m_pListSlider2 = pElemRef;
  
  // create E_ELEM_BTN17 button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN17,E_PG_JOG_ACTIONS,
    (gslc_tsRect){0,220,100,20},(char*)"...",0,E_BUILTIN5X8,&CbBtnCommon);
  //<InitGUI !End!>

  //<Startup !Start!>
  //<Startup !End!>
}

#endif  // end _GUISLICE_GEN_H
