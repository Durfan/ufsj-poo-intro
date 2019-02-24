//
// Created by cecilio on 22/02/19.
//

#ifndef POOTIV2_TOOLS_H
#define POOTIV2_TI_TOOLS_H

void BufferClear();
int CHKinput(char *msg, int min, int max);
int CHKstart(user_t *agenda);
int CHKend(user_t *agenda, tinyN_t start);
void CHKtime (user_t *agenda);

#endif //POOTIV2_TOOLS_H