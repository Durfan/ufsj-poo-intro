//
// Created by cecilio on 22/02/19.
//

#ifndef POOTIV2_MENUS_H
#define POOTIV2_MENUS_H

user_t *menuLogin (users_t *list, user_t *agenda);
userdata_t menuADDuser(userdata_t data);
event_t menuADDevent(user_t *agenda, event_t data);

void menuTitle(users_t *list, user_t *agenda, tinyN_t title);
void eventBAR(user_t *agenda);
void menuEvent(users_t *list, user_t *agenda);
void viewEvents(user_t *agenda);
void voltar();

#endif //POOTIV2_MENUS_H