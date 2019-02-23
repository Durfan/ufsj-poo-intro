//
// Created by cecilio on 22/02/19.
//

#include "main.h"

user_t *menuLogin (users_t *list, user_t *agenda) {
    userdata_t userdata;
    bool selected = false;
    int IDuser;
    char choice;

    while (!selected) {
        system("clear");
        printf(cYELL" POO Trabalho Inicial\n\n"cRSET);
        printf(cBLUE" \u250C\u2500 Agendas \u2500 %d\n"cRSET, list->size);

        if (list->head == NULL) {
            printf(cBLUE" \u2502\n"cRSET);
            printf(cBLUE" \u2502"cRSET" (empty)\n");
            printf(cBLUE" \u2502\n"cRSET);
            printf(cBLUE" \u251C"cRSET" [A] Adicionar Usuario\n");
            printf(cBLUE" \u251C"cRSET" [S] Sair\n");
        }
        else {
            printf(cBLUE" \u2502\n"cRSET);
            PRTusers(list);
            printf(cBLUE" \u2502\n"cRSET);
            printf(cBLUE" \u251C"cRSET" [A] Adicionar Usuario\n");
            printf(cBLUE" \u251C"cRSET" [S] Sair\n");
        }

        printf(cBLUE" \u2514"cRSET " [ ] Selecione: ");

        scanf(" %c", &choice);
        switch (choice) {
            case 'A': case 'a':
                userdata = menuADDuser(userdata);
                ADDuser(list,userdata);
                break;

            case 'S': case 's':
                freeMEM(list);
                exit(0);

            default:
                IDuser = (choice) - '0';
                if (isdigit(choice) && IDuser > 0 && IDuser <= list->size) {
                    agenda = UatPos(list,IDuser-1);
                    selected = true;
                }
                break;  
        }
    }

    return agenda;
} 

userdata_t menuADDuser(userdata_t data) {
    printf(cBLUE"\n \u250C\u2500 Adicionar usuario:\n"cRSET);
    printf(cBLUE" \u2502"cRSET" Nome: ");
    scanf (" %[^\n]%*c", data.name);
    printf(cBLUE" \u2514"cRSET" Email: ");
    scanf (" %[^\n]%*c", data.email);

    return data;
}

event_t menuADDevent(user_t *agenda, event_t data) {
    char c;
    char *msg;

    system("clear");
    printf(cYELL" POO Trabalho Inicial\n\n"cRSET);
    printf(cBLUE" \u250C\u2500 %s", agenda->data.name);
    printf(" (%s)\n"cRSET, agenda->data.email);

    printf(cBLUE" \u2502\n"cRSET);
    eventBAR(agenda);
    printf(cBLUE"\n \u2502\n"cRSET);

    printf(" \u2502 [1] Tarefa\n");
    printf(" \u2502 [2] Reunião\n");
    printf(" \u2502 [3] Aniversário\n");

    msg = " \u2502 [ ] Tipo de Evento: ";
    evenType_t = CHKinput(msg,1,3);
    switch (evenType_t) {
        case todo:
            data.event = todo;
            msg = " \u2502 Grau de Esforco (1-5): ";
            data.effort = CHKinput(msg,1,5);
            msg = " \u2502 Prioridade (1-10): ";
            data.priority = CHKinput(msg,1,10);
            break;

        case meeting:
            data.event = meeting;
            printf(" \u2502 Presença Obrigatoria (s/n): ");
            scanf (" %c", &c);
            if (c == 's' || c == 'S') data.required = true;
            else data.required = false;
            break;

        case birthday:
            data.event = birthday;
            printf(" \u2502 Aniversariante: ");
            scanf (" %[^\n]%*c", data.birtPerson);
            break;

        default:
            break;
    }

    printf(" \u2502 Assunto: ");
    scanf ("  %[^\n]%*c", data.about);

    if (data.event == meeting || data.event == birthday) {
        printf(" \u2502 Local: ");
        scanf (" %[^\n]%*c", data.place);
    }

    msg = " \u2502 Horario de Inicio (1-24): ";
    data.start = CHKinput(msg,1,24);
    // if (agenda->avaliable[data.start])
    msg = " \u2514 Horario de Termino (1-24): ";
    data.end = CHKinput(msg,1,24);

    bool validatermino = data.end < data.start;
    while (validatermino) {
        clearInputBuffer();
        printf(cBLUE" \u2502");
        printf(cRED" Horario de Termino Invalido.\n"cRSET);
        data.end = CHKinput(msg,1,24);
        validatermino = data.end < data.start;
    }

    return data;
}

void eventBAR(user_t *agenda) {
    printf(cBLUE" \u2502 "cRSET);
    for (int i = 0; i < 24; i++) {
        if (i < 10) printf(i%2!=0?"%d ":"  ", i+1);
        else printf(i%2!=0?"%d":"  ", i+1);
    }

    printf(cBLUE"\n \u2502 "cRSET);
    for (int i = 0; i < 24; i++) {
        if (agenda->avaliable != NULL && agenda->avaliable[i]) {
            switch (agenda->avaliable[i]) {
                case todo:
                    printf(cGREN"\u2588\u2588"cRSET);
                    break;
                case meeting:
                    printf(cYELL"\u2588\u2588"cRSET);
                    break;
                case birthday:
                    printf(cBLUE"\u2588\u2588"cRSET);
                    break;
            
                default:
                    printf("??");
                    break;
            }
        }
        else printf("\u2588\u2588");
    }
    
    printf(cBLUE"\n \u2502 "cRSET);
    for (int i = 0; i < 24; i++) {
        if (i < 10) printf(i%2==0?"%d ":"  ",i+1);
        else printf(i%2==0?"%d":"  ",i+1);
    }
}

void viewEvents(user_t *agenda) {
    system("clear");
    printf(cYELL" POO Trabalho Inicial\n\n"cRSET);
    printf(cBLUE" \u250C\u2500 %s", agenda->data.name);
    printf(" (%s) \u2500 %d eventos\n"cRSET, agenda->data.email, agenda->size);
    PRTevents(agenda);
    voltar();
}

void menuEvent(users_t *list, user_t *agenda) {
    event_t event;
    bool selected = false;
    char choice;

    while (!selected) {
        system("clear");
        printf(cYELL" POO Trabalho Inicial\n\n"cRSET);
        printf(cBLUE" \u250C\u2500 %s", agenda->data.name);
        printf(" (%s) \u2500 %d eventos\n"cRSET, agenda->data.email, agenda->size);

        printf(cBLUE" \u2502\n"cRSET);
        eventBAR(agenda);
        printf(cBLUE"\n \u2502\n"cRSET);
        CHKtime(agenda);

        printf(cBLUE" \u251C"cRSET" [A] Adicionar Evento\n");
        printf(cBLUE" \u251C"cRSET" [L] Listar Eventos\n");
        printf(cBLUE" \u251C"cRSET" [M] Mudar Usuario\n");
        printf(cBLUE" \u251C"cRSET" [S] Sair\n");
        printf(cBLUE" \u2514"cRSET " [ ] Selecione: ");
        
        scanf(" %c", &choice);
        switch (choice) {
            case 'A': case 'a':
                event = menuADDevent(agenda,event);
                ADDevent(agenda,event);
                LLinc(agenda);
                CHKtime(agenda);
                break;

            case 'L': case 'l':
                viewEvents(agenda);
                break;

            case 'M': case 'm':
                selected = true;
                break;

            case 'S': case 's':
                freeMEM(list);
                exit(0);

            default:
                break;  
        }
    }
}

void voltar() {
    printf(cBLUE" \u2502\n \u2514"cRSET);
    printf(cYELL" ENTER para voltar..."cRSET);
    clearInputBuffer();
    getchar();
}