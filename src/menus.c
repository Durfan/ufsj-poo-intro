//
// Created by cecilio on 22/02/19.
//

#include "../include/main.h"


user_t *menuLogin(users_t *list, user_t *agenda) {

    userdata_t userdata;
    bool selected = false;
    int IDuser;
    char choice;

    while (!selected) {

        system("clear");
        menuTitle(list,agenda,0);

        printf(DECO00);
        if (isNULL(list->head))
            printf(DECO01" (empty)\n");
        else PRTusers(list);

        printf(DECO00);
        printf(DECO03"[A] Adicionar Usuario\n");
        printf(DECO03"[S] Sair\n");
        
        printf(DECO02"[ ] Selecione: ");
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
                selected = isdigit(choice) && range(IDuser,1,list->size);
                if (selected) agenda = UatPos(list,IDuser-1);
                break;
        }
    }

    return agenda;
} 

userdata_t menuADDuser(userdata_t data) {
    printf("\n");
    printf(DECO06"Adicionar usuario:\n");
    printf(DECO01"Nome: ");
    scanf (" %[^\n]%*c", data.name);
    printf(DECO02"Email: ");
    scanf (" %[^\n]%*c", data.email);
    return data;
}

event_t menuADDevent(user_t *agenda, event_t data) {

    char c, *msg;

    system("clear");
    menuTitle(NULL,agenda,1);

    eventBAR(agenda);

    printf(DECO03"Adicionar:\n");
    printf(DECO01"[1] Tarefa\n");
    printf(DECO01"[2] Reunião\n");
    printf(DECO01"[3] Aniversário\n");

    msg = "[ ] Tipo de Evento: ";
    evenType_t = CHKinput(msg,1,3);

    switch (evenType_t) {

        case todo:
            data.event = todo;
            msg = "Grau de Esforco (1-5): ";
            data.effort = CHKinput(msg,1,5);
            msg = "Prioridade (1-10): ";
            data.priority = CHKinput(msg,1,10);
            break;

        case meeting:
            data.event = meeting;
            printf(DECO01"Presença Obrigatoria (S/n): ");
            scanf (" %c", &c);
            if (c == 's' || c == 'S') data.required = true;
            else data.required = false;
            break;

        case birthday:
            data.event = birthday;
            printf(DECO01"Aniversariante: ");
            scanf (" %[^\n]%*c", data.birtPerson);
            break;

        default:
            break;
    }

    printf(DECO01"Assunto: ");
    scanf (" %[^\n]%*c", data.about);

    if (data.event == meeting || data.event == birthday) {
        printf(DECO01"Local: ");
        scanf (" %[^\n]%*c", data.place);
    }

    data.start = CHKstart(agenda);
    data.end = CHKend(agenda,data.start);

    return data;
}

void eventBAR(user_t *agenda) {

    printf(DECO00 DECO01);

    for (int i = 0; i < 24; i++) {
        if (i < 10) printf(!divOne(i)?"%d ":"  ", i);
        else printf(!divOne(i)?"%d":"  ", i);
    }

    printf(DECO05);

    for (int i = 0; i < 24; i++) {

        if (!isNULL(agenda->avaliable) && agenda->avaliable[i]) {

            switch (agenda->avaliable[i]) {

                case     todo: printf(cGREN BLOCK0 cRSET); break;
                case  meeting: printf(cYELL BLOCK0 cRSET); break;
                case birthday: printf(cBLUE BLOCK0 cRSET); break;
            
                default: printf("??"); break;
            }
        }
        else printf(BLOCK1);
    }

    printf(DECO05);

    for (int i = 0; i < 24; i++) {
        if (i < 10) printf(divOne(i)?"%d ":"  ", i);
        else printf(divOne(i)?"%d":"  ", i);
    }

    printf(DECO04);
}

void viewEvents(user_t *agenda) {
    system("clear");
    menuTitle(NULL,agenda,2);
    PRTevents(agenda);
    voltar();
}

void menuEvent(users_t *list, user_t *agenda) {

    event_t event;
    bool selected = false;
    char choice;

    while (!selected) {

        system("clear");
        menuTitle(NULL,agenda,2);

        eventBAR(agenda);

        printf(DECO03"[A] Adicionar Evento\n");
        printf(DECO03"[L] Listar Eventos\n");
        printf(DECO03"[M] Mudar Usuario\n");
        printf(DECO03"[S] Sair\n");

        printf(DECO02"[ ] Selecione: ");
        scanf(" %c", &choice);
        BufferClear();
    
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

void menuTitle(users_t *list, user_t *agenda, tinyN_t title) {

    switch (title) {

        case 0:
            printf(PTITLE);
            printf(DECO06"Agendas \u2500 %d\n", list->size);
            break;

        case 1:
            printf(PTITLE);
            printf(DECO06"%s", agenda->data.name);
            printf(" (%s)\n", agenda->data.email);
            break;

        case 2:
            printf(PTITLE);
            printf(DECO06"%s", agenda->data.name);
            printf(" (%s)", agenda->data.email);
            printf(" \u2500 %d eventos\n", agenda->size);
            break;
    
        default:
            break;
    }
}

void voltar() {
    printf(DECO00 DECO02);
    printf("ENTER para voltar...");
    getchar();
}