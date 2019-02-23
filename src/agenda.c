//
// Created by cecilio on 21/02/19.
//

#include "main.h"


users_t *create() {
    users_t *list = (users_t*) malloc(sizeof(users_t));
    assert(list);
    list->size = 0;
    list->head = NULL;
    return list;
}

user_t *UatPos(users_t *list, int index) {
    if (index >= 0 && index < list->size) {
        user_t *user = list->head;
        for (int i = 0; i < index; i++)
            user = user->next;
        return user;
    }
    return NULL;
}

events_t *EatPos(user_t *agenda, int index) {
    if (index >= 0 && index < agenda->size) {
        events_t *event = agenda->head;
        for (int i = 0; i < index; i++)
            event = event->next;
        return event;
    }
    return NULL;
}

int IDuser(users_t *list, user_t *user) {
    if (user != NULL) {
        user_t *ptr = list->head;
        int index = 0;
        while (ptr != user && ptr != NULL) {
            ptr = ptr->next;
            index++;
        }
        if (ptr != NULL) return index;
    }
    return -1;
}

int IDtask(user_t *agenda, events_t *event) {
    if (event != NULL) {
        events_t *ptr = agenda->head;
        int index = 0;
        while (ptr != event && ptr != NULL) {
            ptr = ptr->next;
            index++;
        }
        if (ptr != NULL) return index;
    }
    return -1;
}

void ADDuser(users_t *list, userdata_t data) {
    user_t *user = (user_t*) malloc(sizeof(user_t));
    assert(user);
    user->avaliable = calloc(24,sizeof(int));
    assert(user->avaliable);
    user->head = NULL;
    user->data = data;
    user->next = list->head;
    list->head = user;
    list->size++;
}

void ADDevent(user_t *user, event_t data) {
    events_t *event = (events_t*) malloc(sizeof(events_t));
    assert(event);
    event->data = data;
    event->next = user->head;
    user->head = event;
    user->size++;
}

void PRTusers(users_t *list) {
    if (list->head == NULL) return;
    user_t *ptr = list->head;

    while (ptr != NULL) {
        printf(cBLUE" \u251C"cRSET" [%d]", IDuser(list,ptr)+1);
        printf(" %s", ptr->data.name);
        printf(" (%s)\n", ptr->data.email);
        ptr = ptr->next;
    }
}

void PRTevents(user_t *agenda) {
    if (agenda->head == NULL) return;
    events_t *ptr = agenda->head;

    while (ptr != NULL) {
        printf(cBLUE" \u2502\n \u251C");
        // printf(" [%d]", IDtask(agenda,ptr));
        printf(" De %02d as %02d", ptr->data.start, ptr->data.end);
        switch (ptr->data.event) {
            case 1:
                printf(" [Tarefa]\n"cRSET);
                printf(cBLUE" \u2502"cRSET" Esforco: %d\n", ptr->data.effort);
                printf(cBLUE" \u2502"cRSET" Prioridade: %d\n", ptr->data.priority);
                break;

            case 2:
                printf (" [Reuniao]\n"cRSET);
                printf(cBLUE" \u2502"cRSET" Presença Obrigatoria?");
                if (ptr->data.required) printf(cRED" Sim\n"cRSET);
                else printf(" Nao\n");
                break;

            case 3:
                printf (" [Aniversario]\n"cRSET);
                printf(cBLUE" \u2502"cRSET" Aniversariante: %s\n", ptr->data.birtPerson);
                break;
        
            default:
                break;
        }
            
        printf(cBLUE" \u2502"cRSET" Assunto: %s\n", ptr->data.about);

        if (ptr->data.event == meeting || ptr->data.event == birthday)
            printf(cBLUE" \u2502"cRSET" Local: %s\n", ptr->data.place);

        ptr = ptr->next;
    }
}

void LLchg(user_t *agenda, events_t *nodeA, events_t *nodeB) {
    if (nodeA == nodeB) return;
    int indexA = IDtask(agenda,nodeA);
    int indexB = IDtask(agenda,nodeB);

    if (indexA == -1 || indexB == -1) return;

    if (indexA > indexB) {
        nodeA = nodeB;
        nodeB = EatPos(agenda,indexA);
        indexA = indexB;
        indexB = IDtask(agenda,nodeB);
    }

    events_t *pb = EatPos(agenda,indexB-1);

    if (nodeA == agenda->head) agenda->head = nodeB;
    else {
        events_t *pa = EatPos(agenda,indexA-1);
        pa->next = nodeB;
    }

    pb->next = nodeA;
    events_t *ptr = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = ptr;
}

events_t *LLmin(user_t *agenda, int index) {
    events_t *ptr = EatPos(agenda,index);
    if (ptr != NULL) {
        events_t *minNode = ptr;
        while (ptr != NULL) {
            if (ptr->data.start < minNode->data.start)
                minNode = ptr;
            ptr = ptr->next;
        }
        return minNode;
    }
    return NULL;
}

void LLinc(user_t *agenda) {
    for (int i = 0; i < agenda->size-1; i++)
        LLchg(agenda,EatPos(agenda,i),LLmin(agenda,i));
}

void freeMEM(users_t *list) {
    if (list->head == NULL) {
        free(list);
        return;
    }
    user_t *delUser;
    events_t *delEvent;

    while (list->head->head != NULL) {
        delEvent = list->head->head;
        list->head->head = list->head->head->next;
        free(delEvent);
    }

    while (list->head != NULL) {
        delUser = list->head;
        free(delUser->avaliable);
        list->head = list->head->next;
        free(delUser);
    }

    free(list);
}
