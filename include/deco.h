//
// Created by cecilio on 22/02/19.
//

#ifndef POOTIV2_TCOLORS_H
#define POOTIV2_TCOLORS_H

#define cRED  "\x1b[31m"
#define cGREN "\x1b[32m"
#define cYELL "\x1b[33m"
#define cBLUE "\x1b[36m"
#define cRSET "\x1b[0m"

#define PTITLE cYELL " " PROJECT_NAME cRSET "\n\n"
#define DECO00 cBLUE " \u2502\n" cRSET
#define DECO01 cBLUE " \u2502 " cRSET
#define DECO02 cBLUE " \u2514 " cRSET
#define DECO03 cBLUE " \u251C " cRSET
#define DECO04 cBLUE "\n \u2502\n" cRSET
#define DECO05 cBLUE "\n \u2502 " cRSET
#define DECO06 cBLUE " \u250C\u2500 " cRSET
#define BLOCK0 "\u2588\u2588"
#define BLOCK1 "\u2591\u2591"
#define ALERT1 DECO01 cRED
#define ALERTA(msg) msg

#endif //POOTIV2_TCOLORS_H