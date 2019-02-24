//
// Created by cecilio on 22/02/19.
//

#ifndef UFSJ_POO_TI_TOOLS_H
#define UFSJ_POO_TI_TOOLS_H

void BufferClear();
int CHKinput(char *msg, int min, int max);
int CHKstart(user_t *agenda);
int CHKend(user_t *agenda, tinyN_t start);
void CHKtime (user_t *agenda);

#endif //UFSJ_POO_TI_TOOLS_H