//
// Created by cecilio on 22/02/19.
//

#include "../include/main.h"


int main(void) {
    users_t *list = create();
    user_t *agenda;

    while (1) {
        agenda = menuLogin(list,agenda);
        menuEvent(list,agenda);
    }

    return 0;
}