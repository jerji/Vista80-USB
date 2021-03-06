//LCL              `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
const char Lowr1[16] = {0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F};
//LCU              p    q    r    s    t    u    v    w    x    y    z    {    _    }    ~   CNTR (Ctrl)
const char Lowr2[16] = {0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x5F,0x7D,0x7E,0x00};

//HCL              @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
const char Uppr1[16] = {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F};
//HCU              P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]   ENDL ENDP
const char Uppr2[16] = {0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0xD5,0x00};

//NUM              0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
const char Numbr[16] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F};
//SYM             SPC   !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
const char Symbl[16] = {0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F};

//   Binding:     SUPR TAB  ESC  DEL                          Insrt      PGUP FMOD PGDN BKSP
//                BLUE TAB  CNCL ERAP ERAL PINK C+P  LBLU WHIT INSR COLR BLFT TRAN BRGT RTN  CTRL+CNCL
const char Ctrl1[16] = {0x00,0xB3,0xB1,0xD4,0x00,0x00,0x00,0x00,0x00,0xD1,0x00,0xD3,0x00,0xD6,0xB2,0x00};

//   Binding:     SHFT      HOME      ALT                 RGHY      DOWN           ENTR LEFT  UP
//                CHAN C+Q  HOME C+C  ALPA BLAK RED  GREN RGHT C+Y  DOWN C+K  YELO  CR  LEFT  UP
const char Ctrl2[16] = {0x00,0x00,0xD2,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0xD9,0x00,0x00,0xB0,0xD8,0xDA};
//


//FMOD TABLES

//LCL               `    a    b    c    d    F15  f    g    h    F20  j    k    l    m    n    F21
const char FLowr1[16] = {0x00,0x00,0x00,0x00,0x00,0xF2,0x00,0x00,0x00,0xF7,0x00,0x00,0x00,0x00,0x00,0xF8};
//LCU               F22  F13  F16  s    F17  F19  v    F14  x    F18  z    {    F24  }    F12 CNTR (Ctrl)
const char FLowr2[16] = {0xF9,0xF0,0xF3,0x00,0xF4,0xF6,0x00,0xF1,0x00,0xF5,0x00,0x00,0xFB,0x00,0xCD,0x00};

//HCL              @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
const char FUppr1[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//HCU              P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]   ENDL ENDP
const char FUppr2[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

//NUM              F10   F1   F2   F3   F4   F5   F6   F7   F8   F9   F23   ;    <    =    >    ?
const char FNumbr[16] = {0xCB,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xFA,0x00,0x00,0x00,0x00,0x00};
//SYM               SPC  !    "    #    $    %    &    '    (    )    *    +    ,    F11  .    /
const char FSymbl[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x00,0x00};

//   Binding:      SUPR TAB  ESC  DEL                          Insrt      PGUP FMOD PGDN BKSP
//                 BLUE TAB  CNCL ERAP ERAL PINK C+P  LBLU WHIT INSR COLR BLFT TRAN BRGT RTN  CTRL+CNCL
const char FCtrl1[16] = {0x00,0xB3,0xB1,0xD4,0x00,0x00,0x00,0x00,0x00,0xD1,0x00,0xD3,0x00,0xD6,0xB2,0x00};

//   Binding:            SHFT      HOME      ALT                 RGHY      DOWN           ENTR LEFT  UP
//                       CHAN C+Q  HOME C+C  ALPA BLAK RED  GREN RGHT C+Y  DOWN C+K YELO  CR   LEFT  UP
const char FCtrl2[16] = {0x00,0x00,0xD2,0x00,0x00,0x00,0x00,0x00,0xD7,0x00,0xD9,0x00,0x00,0xB0,0xD8,0xDA};

//Yes

//const uint8_t fuck[0] = "";
