//
// Created by cecilio on 22/02/19.
//

#include "../include/main.h"

#define FOREVER 1


int main(void) {
    users_t *list = create();
    user_t *agenda;

    while (FOREVER) {
        agenda = menuLogin(list,agenda);
        menuEvent(list,agenda);
    }

    return 0;
}