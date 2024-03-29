//
// Created by cecilio on 22/02/19.
//

#include "../include/main.h"


void BufferClear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void PRTerror(int code, char *msg) {
    printf(ALERT1"ERR%02d: %s\n"cRSET, code, msg);
}

int CHKinput(char *msg, int min, int max) {

    char *ptr, str[100];
    bool pass = false;
    int n;
    
    do {

		printf(DECO01"%s", msg);
        while (fgets(str,sizeof(str),stdin)) {
            n = strtol(str, &ptr, 10);
            if (ptr == str || *ptr != '\n') {
                //PRTerror(1,"CHAR INPUT");
                printf(ALERT1"Escolha um numero entre %d e %d.\n"cRSET, min, max);
                printf(DECO01"%s", msg);
            } else break;
        }
        // printf(DECO01" -> %d\n", n);

        pass = range(n,min,max);
        
        if (!pass) {
            //PRTerror(2,"INPUT VALUE");
            printf(ALERT1"Escolha um valor entre %d e %d.\n"cRSET, min, max);
        }

	} while (!pass);

    return n;
}

int CHKstart(user_t *agenda) {
    
    bool validTime = true;
    char *msg;
    int start;

    while (validTime) {
        msg = "Horario de Inicio (0-23): ";
        start = CHKinput(msg,0,23);
        validTime = agenda->avaliable[start];
        if (validTime) {
            //PRTerror(2,"INPUT VALUE");
            printf(DECO01 cRED"Horario de Inicio Invalido.\n"cRSET);
        }
        else validTime = false;
    }

    return start;
}

int CHKend(user_t *agenda, tinyN_t start) {
    
    bool validTime = true;
    char *msg;
    int end;

    while (validTime) {
        msg = "Horario de Termino (1-24): ";
        end = CHKinput(msg,1,24);
        validTime = end <= start || agenda->avaliable[end-1];
        if (validTime) {
            //PRTerror(2,"INPUT VALUE");
            printf(DECO01 cRED"Horario de Termino Invalido.\n"cRSET);
        }
        else validTime = false;
    }

    return end;
}

void CHKtime(user_t *agenda) {

    if (agenda->head == NULL) return;
    events_t *ptr = agenda->head;

    while (ptr != NULL) {

        for (int i = ptr->data.start; i < ptr->data.end; i++) {

            switch (ptr->data.event) {

                case todo:
                    agenda->avaliable[i] = todo;
                    break;

                case meeting:
                    agenda->avaliable[i] = meeting;
                    break;

                case birthday:
                    agenda->avaliable[i] = birthday;
                    break;
            
                default:
                    agenda->avaliable[i] = -1;
                    break;
            }
        }
        ptr = ptr->next;
    }
}