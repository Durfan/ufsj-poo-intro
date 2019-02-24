//
// Created by cecilio on 21/02/19.
//

#ifndef POOTIV2_AGENDA_H
#define POOTIV2_AGENDA_H

enum evenType {todo = 1, meeting, birthday} evenType_t;
typedef unsigned short tinyN_t;

typedef struct event {
    tinyN_t event;
    char about[80];
    char place[80];
    char birtPerson[50];
    bool required;
    tinyN_t start;
    tinyN_t end;
    tinyN_t effort;
    tinyN_t priority;
} event_t;

typedef struct events {
    event_t data;
    struct events *next;
} events_t;

typedef struct userdata {
    char name[50];
    char email[30];
} userdata_t;

typedef struct user {
    userdata_t data;
    events_t *head;
    int *avaliable;
    tinyN_t size;
    struct user *next;
} user_t;

typedef struct users {
    tinyN_t size;
    user_t *head;
} users_t;

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
