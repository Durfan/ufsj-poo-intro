//
// Created by cecilio on 21/02/19.
//

#ifndef POOTIV2_AGENDA_H
#define POOTIV2_AGENDA_H

users_t *create();
user_t *UatPos(users_t* list, int index);
events_t *EatPos(user_t *agenda, int index);
events_t *LLmin(user_t *agenda, int index);

int IDuser(users_t *list, user_t *user);
int IDtask(user_t *agenda, events_t *event);

void ADDuser(users_t *list, userdata_t data);
void ADDevent(user_t *user, event_t data);
void PRTusers(users_t *list);
void PRTevents(user_t *events);

void LLinc(user_t *agenda);
void LLchg(user_t *agenda, events_t *nodeA, events_t *nodeB);

void freeMEM(users_t *list);

#endif //POOTIV2_AGENDA_H
