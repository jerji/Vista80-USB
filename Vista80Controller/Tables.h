#include <avr/pgmspace.h>
#define byte uchar
enum keycodes {
	KEY_NULL = 0,
	KEY_errorRollOver,
	KEY_POSTfail,
	KEY_errorUndefined,
	KEY_A, // 4
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,        // 0x10
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_1,
	KEY_2,
	KEY_3,        // 0x20
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_0,        // 0x27
	KEY_enter,
	KEY_esc,
	KEY_bckspc,   // backspace
	KEY_tab,
	KEY_spc,      // space
	KEY_minus,    // - (and _)
	KEY_equal,    // = (and +)
	KEY_lbr,      // [
	KEY_rbr,      // ]  -- 0x30
	KEY_bckslsh,  // \ (and |)
	KEY_hash,     // Non-US # and ~
	KEY_smcol,    // ; (and :)
	KEY_ping,     // ' and "
	KEY_grave,    // Grave accent and tilde
	KEY_comma,    // , (and <)
	KEY_dot,      // . (and >)
	KEY_slash,    // / (and ?)
	KEY_cpslck,   // capslock
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,       // 0x40
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_PrtScr,
	KEY_scrlck,
	KEY_break,
	KEY_ins,
	KEY_home,
	KEY_pgup,
	KEY_del,
	KEY_end,
	KEY_pgdn,
	KEY_rarr,
	KEY_larr,     // 0x50
	KEY_darr,
	KEY_uarr,
	KEY_numlock,
	KEY_KPslash,
	KEY_KPast,
	KEY_KPminus,
	KEY_KPplus,
	KEY_KPenter,
	KEY_KP1,
	KEY_KP2,
	KEY_KP3,
	KEY_KP4,
	KEY_KP5,
	KEY_KP6,
	KEY_KP7,
	KEY_KP8,      // 0x60
	KEY_KP9,
	KEY_KP0,
	KEY_KPcomma,
	KEY_Euro2,
	KEY_COMPOSE,  // Keyboard Application
	KEY_POWER, // Keyboard Power
	KEY_KPEQUAL, // Keypad =
	KEY_F13, // Keyboard F13
	KEY_F14, // Keyboard F14
	KEY_F15, // Keyboard F15
	KEY_F16, // Keyboard F16
	KEY_F17, // Keyboard F17
	KEY_F18, // Keyboard F18
	KEY_F19, // Keyboard F19
	KEY_F20, // Keyboard F20
	KEY_F21, // Keyboard F21 0x70
	KEY_F22, // Keyboard F22
	KEY_F23, // Keyboard F23
	KEY_F24, // Keyboard F24
	KEY_OPEN, // Keyboard Execute
	KEY_HELP, // Keyboard Help
	KEY_PROPS, // Keyboard Menu
	KEY_FRONT, // Keyboard Select
	KEY_STOP, // Keyboard Stop
	KEY_AGAIN, // Keyboard Again
	KEY_UNDO, // Keyboard Undo
	KEY_CUT, // Keyboard Cut
	KEY_COPY, // Keyboard Copy
	KEY_PASTE, // Keyboard Paste
	KEY_FIND, // Keyboard Find
	KEY_MUTE, // Keyboard Mute
	KEY_VOLUMEUP, // Keyboard Volume Up   0x80
	KEY_VOLUMEDOWN, // Keyboard Volume Down
	KEY_LCAPS, // 0x82  Keyboard Locking Caps Lock
	KEY_LNUM, // 0x83  Keyboard Locking Num Lock
	KEY_LSCROLL, // 0x84  Keyboard Locking Scroll Lock
	KEY_KPCOMMA, // Keypad Comma
	KEY_KPEQUAL2, // 0x86  Keypad Equal Sign
	KEY_RO, // Keyboard International1
	KEY_KATAKANAHIRAGANA, // Keyboard International2
	KEY_YEN, // Keyboard International3
	KEY_HENKAN, // Keyboard International4
	KEY_MUHENKAN, // Keyboard International5
	KEY_KPJPCOMMA, // Keyboard International6
	KEY_INTL7, // 0x8d  Keyboard International7
	KEY_INTL8, // 0x8e  Keyboard International8
	KEY_INTL9, // 0x8f  Keyboard International9
	KEY_HANGEUL, // Keyboard LANG1         0x90
	KEY_HANJA, // Keyboard LANG2
	KEY_KATAKANA, // Keyboard LANG3
	KEY_HIRAGANA, // Keyboard LANG4
	KEY_ZENKAKUHANKAKU, // Keyboard LANG5
	KEY_LANG6, // 0x95  Keyboard LANG6
	KEY_LANG7, // 0x96  Keyboard LANG7
	KEY_LANG8, // 0x97  Keyboard LANG8
	KEY_LANG9, // 0x98  Keyboard LANG9
	KEY_ALTERASE, // 0x99  Keyboard Alternate Erase
	KEY_SYSREQ, // 0x9a  Keyboard SysReq/Attention
	KEY_CANCEL, // 0x9b  Keyboard Cancel
	KEY_CLEAR, // 0x9c  Keyboard Clear
	KEY_PRIOR, // 0x9d  Keyboard Prior
	KEY_RETURN, // 0x9e  Keyboard Return
	KEY_SEP, // 0x9f  Keyboard Separator
	KEY_OUT, // 0xa0  Keyboard Out         0xa0
	KEY_OPER, // 0xa1  Keyboard Oper
	KEY_CLEARAGAIN, // 0xa2  Keyboard Clear/Again
	KEY_CRSEL, // 0xa3  Keyboard CrSel/Props
	KEY_EXSEL, // 0xa4  Keyboard ExSel
	KEY_RESERVEDA5,
	KEY_RESERVEDA6,
	KEY_RESERVEDA7,
	KEY_RESERVEDA8,
	KEY_RESERVEDA9,
	KEY_RESERVEDAa,
	KEY_RESERVEDAb,
	KEY_RESERVEDAc,
	KEY_RESERVEDAd,
	KEY_RESERVEDAe,
	KEY_RESERVEDAf,
	KEY_00, // 0xb0  Keypad 00        0xb0
	KEY_000, // 0xb1  Keypad 000
	KEY_THOUSEP, // 0xb2  Thousands Separator
	KEY_DECSEP, // 0xb3  Decimal Separator
	KEY_CURUNIT, // 0xb4  Currency Unit
	KEY_CURSUBUNIT, // 0xb5  Currency Sub-unit
	KEY_KPLEFTPAREN, // Keypad (
	KEY_KPRIGHTPAREN, // Keypad )
	KEY_KPLBR, // 0xb8  Keypad {
	KEY_KPRBR, // 0xb9  Keypad }
	KEY_KPTAB, // 0xba  Keypad Tab
	KEY_KPBKSPC, // 0xbb  Keypad Backspace
	KEY_KPA, // 0xbc  Keypad A
	KEY_KPB, // 0xbd  Keypad B
	KEY_KPC, // 0xbe  Keypad C
	KEY_KPD, // 0xbf  Keypad D
	KEY_KPE, // 0xc0  Keypad E         0xc0
	KEY_KPF, // 0xc1  Keypad F
	KEY_KPXOR, // 0xc2  Keypad XOR
	KEY_KPCARET, // 0xc3  Keypad ^
	KEY_KPPERCENT, // 0xc4  Keypad %
	KEY_KPSMALLERT, // 0xc5  Keypad <
	KEY_KPBIGGERT, // 0xc6  Keypad >
	KEY_KPAND, // 0xc7  Keypad &
	KEY_KPANDAND, // 0xc8  Keypad &&
	KEY_KPOR, // 0xc9  Keypad |
	KEY_KPOROR, // 0xca  Keypad ||
	KEY_KPCOLON, // 0xcb  Keypad :
	KEY_KPHASH, // 0xcc  Keypad #
	KEY_KPSPC, // 0xcd  Keypad Space
	KEY_KPAT, // 0xce  Keypad @
	KEY_KPBANG, // 0xcf  Keypad !
	KEY_KPMEMP, // 0xd0  Keypad Memory Store     //d0
	KEY_KPMEMR, // 0xd1  Keypad Memory Recall
	KEY_KPMEMC, // 0xd2  Keypad Memory Clear
	KEY_KPMEMA, // 0xd3  Keypad Memory Add
	KEY_KPMEMS, // 0xd4  Keypad Memory Subtract
	KEY_KPMEMM, // 0xd5  Keypad Memory Multiply
	KEY_KPMEMD, // 0xd6  Keypad Memory Divide
	KEY_KPPLUSMINUS, // 0xd7  Keypad +/-
	KEY_KPCLEAR, // 0xd8  Keypad Clear
	KEY_KPCLEARENTRY, // 0xd9  Keypad Clear Entry
	KEY_KPBIN, // 0xda  Keypad Binary
	KEY_KPOCT, // 0xdb  Keypad Octal
	KEY_KPDEC, // 0xdc  Keypad Decimal
	KEY_KPHEX, // 0xdd  Keypad Hexadecimal
	KEY_RESERVEDDE,
	KEY_RESERVEDDF,
	KEY_LEFTCTRL, // Keyboard Left Control      //e0
	KEY_LEFTSHIFT, // Keyboard Left Shift
	KEY_LEFTALT, // Keyboard Left Alt
	KEY_LEFTMETA, // Keyboard Left GUI
	KEY_RIGHTCTRL, // Keyboard Right Control
	KEY_RIGHTSHIFT, // Keyboard Right Shift
	KEY_RIGHTALT, // Keyboard Right Alt
	KEY_RIGHTMETA, // Keyboard Right GUI
	KEY_MEDIA_PLAYPAUSE,
	KEY_MEDIA_STOPCD,
	KEY_MEDIA_PREVIOUSSONG,
	KEY_MEDIA_NEXTSONG,
	KEY_MEDIA_EJECTCD,
	KEY_MEDIA_VOLUMEUP,
	KEY_MEDIA_VOLUMEDOWN,
	KEY_MEDIA_MUTE,
	KEY_MEDIA_WWW,                         //f0
	KEY_MEDIA_BACK,
	KEY_MEDIA_FORWARD,
	KEY_MEDIA_STOPf3,
	KEY_MEDIA_FIND,
	KEY_MEDIA_SCROLLUP,
	KEY_MEDIA_SCROLLDOWN,
	KEY_MEDIA_EDIT,
	KEY_MEDIA_SLEEP,
	KEY_MEDIA_COFFEE,
	KEY_MEDIA_REFRESH,
	KEY_MEDIA_CALC
};

//LCL                		    `
const byte Lowr1[16] PROGMEM = {KEY_grave,KEY_A,KEY_B,KEY_C,KEY_D,KEY_E,KEY_F,KEY_G,KEY_H,KEY_I,KEY_J,KEY_K,KEY_L,KEY_M,KEY_N,KEY_O};
//LCU			       	    	                												     {       _         }       ~      CNTR (Ctrl)
const byte Lowr2[16] PROGMEM = {KEY_P,KEY_Q,KEY_R,KEY_S,KEY_T,KEY_U,KEY_V,KEY_W,KEY_X,KEY_Y,KEY_Z,KEY_lbr,KEY_minus,KEY_rbr,KEY_grave,0x00};

//HCL                   		   @
const byte Uppr1[16] PROGMEM = {KEY_2,KEY_A,KEY_B,KEY_C,KEY_D,KEY_E,KEY_F,KEY_G,KEY_H,KEY_I,KEY_J,KEY_K,KEY_L,KEY_M,KEY_N,KEY_O};
//HCU             			    													                 [       \           ]     ENDL    ENDP
const byte Uppr2[16] PROGMEM = {KEY_P,KEY_Q,KEY_R,KEY_S,KEY_T,KEY_U,KEY_V,KEY_W,KEY_X,KEY_Y,KEY_Z,KEY_lbr,KEY_bckslsh,KEY_rbr,KEY_end,KEY_NULL};

//NUM            		        															   :         ;         <         =         >       ?
const byte Numbr[16] PROGMEM = {KEY_0,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_smcol,KEY_smcol,KEY_comma,KEY_equal,KEY_dot,KEY_slash};
//SYM           		           SPC     !     "        #     $     %    &      '        (     )     *     +         ,         -          .      /
const byte Symbl[16] PROGMEM = {KEY_spc,KEY_1,KEY_ping,KEY_3,KEY_4,KEY_5,KEY_7,KEY_ping,KEY_9,KEY_0,KEY_8,KEY_equal,KEY_comma,KEY_minus,KEY_dot,KEY_slash};

//   Binding:    		        SUPR  TAB     ESC     DEL                        stik   Insrt        PGUP     FMOD  PGDN     BKSP
//               		        BLUE  TAB     CNCL    ERAP   ERAL PINK C+P  LBLU WHIT   INSR    COLR BLFT     TRAN  BRGT     RTN       CTRL+CNCL
const byte Ctrl1[16] PROGMEM = {0x00,KEY_tab,KEY_esc,KEY_del,0x00,0x00,0x00,0x00,KEY_00,KEY_ins,0x00,KEY_pgup,0x00,KEY_pgdn,KEY_bckspc,0x00};

//   Binding:     		        SHFT       HOME         ALT  LED0 LED1 LED3  RGHY          DOWN         LED2  ENTR      LEFT     UP
//                 		        CHAN C+Q   HOME    C+C  ALPA BLAK RED  GREN  RGHT     C+Y  DOWN    C+K  YELO  CR        LEFT     UP
const byte Ctrl2[16] PROGMEM = {0x00,0x00,KEY_home,0x00,0x00,0x00,0x00,0x00,KEY_rarr,0x00,KEY_darr,0x00,0x00,KEY_enter,KEY_larr,KEY_uarr};
//


//FMOD TABLES

//LCL              			     						   F15   				   F20  							F21
const byte FLowr1[16] PROGMEM = {0x00,0x00,0x00,0x00,0x00,KEY_F15,0x00,0x00,0x00,KEY_F20,0x00,0x00,0x00,0x00,0x00,KEY_F21};
//LCU         		              F22     F13     F16          F17     F19          F14          F18               F24         F12     CNTR (Ctrl)
const byte FLowr2[16] PROGMEM = {KEY_F22,KEY_F13,KEY_F16,0x00,KEY_F17,KEY_F19,0x00,KEY_F14,0x00,KEY_F18,0x00,0x00,KEY_F24,0x00,KEY_F12,0x00};

//HCL
const byte FUppr1[16] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//HCU
const byte FUppr2[16] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

//NUM         		              F10     F1     F2     F3     F4     F5     F6     F7     F8     F9     F23
const byte FNumbr[16] PROGMEM = {KEY_F10,KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F23,0x00,0x00,0x00,0x00,0x00};
//SYM             		          																   F11
const byte FSymbl[16] PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,KEY_F11,0x00,0x00};

//   Binding:    		        SUPR  TAB     ESC     DEL                        STIK Insrt       PGUP     FMOD  PGDN     BKSP
//               		        BLUE  TAB     CNCL    ERAP    ERAL PINK C+P  LBLU WHIT  INSR   COLR BLFT     TRAN  BRGT     RTN       CTRL+CNCL
const byte FCtrl1[16] PROGMEM = {0x00,KEY_tab,KEY_esc,KEY_del,0x00,0x00,0x00,0x00,0x00,KEY_ins,0x00,KEY_pgup,0x00,KEY_pgdn,KEY_bckspc,0x00};

//   Binding:     		        SHFT       HOME         ALT  LED0 LED1 LED3  RGHY          DOWN         LED2  ENTR      LEFT     UP
//                 		        CHAN C+Q   HOME    C+C  ALPA BLAK RED  GREN  RGHT     C+Y  DOWN    C+K  YELO  CR        LEFT     UP
const byte FCtrl2[16] PROGMEM = {0x00,0x00,KEY_home,0x00,0x00,0x00,0x00,0x00,KEY_rarr,0x00,KEY_darr,0x00,0x00,KEY_enter,KEY_larr,KEY_uarr};
//
