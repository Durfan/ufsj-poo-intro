#ifndef POOTIV2_DATASTRUCT_H
#define POOTIV2_DATASTRUCT_H

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

#endif //POOTIV2_DATASTRUCT_H