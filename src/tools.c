//
// Created by cecilio on 22/02/19.
//

#include "main.h"

void clearInputBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int CHKinput(char *msg, int min, int max) {
    int temp;
	while (1) {
		printf("%s", msg);
		scanf(" %d", &temp);
		if (temp >= min && temp <= max)
			return temp;
		else {
            clearInputBuffer();
            printf(cBLUE" \u2502");
            printf(cRED" Escolha um valor entre %d e %d.\n"cRSET, min, max);
        }

	}
}

int *CHKtime(user_t *agenda) {
    if (agenda->head == NULL) return NULL;
    int *freetime = calloc(24,sizeof(int));
    events_t *ptr = agenda->head;

    while (ptr != NULL) {
        for (int i = ptr->data.start-1; i <= ptr->data.end-1; i++)
            switch (ptr->data.event) {
                case todo:
                    freetime[i] = todo;
                    break;
                case meeting:
                    freetime[i] = meeting;
                    break;
                case birthday:
                    freetime[i] = birthday;
                    break;
            
                default:
                    freetime[i] = -1;
                    break;
            }
        ptr = ptr->next;
    }

    return freetime;
}