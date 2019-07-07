#include <stdio.h>

void cadastrar_usuario();
void listar_usuarios();

void cadastrar_tarefa();
void imprimir_tarefas();

void cadastrar_reuniao();
void imprimir_reuniao();

void cadastrar_aniversario();
void imprimir_aniversario();

char usuarios_nome[100][100];
char usuarios_email[100][100];

char tarefas_assunto[100][100][100];
int tarefas_hora_inicio[100][100];
int tarefas_hora_fim[100][100];
int tarefas_esforco[100][100];
int tarefas_prioridade[100][100];

char reuniao_assunto[100][100][100];
char reuniao_local[100][100][100];
int reuniao_obrigatoriedade[100][100];
int reuniao_hora_inicio[100][100];
int reuniao_hora_fim[100][100];

char aniversario_assunto[100][100][100];
int aniversario_hora_inicio[100][100];
int aniversario_hora_fim[100][100];
char aniversario_local[100][100][100];
char aniversario_aniversariante[100][100][100];

int num_tarefas_usuarios[100] = {0};

int num_reunioes_usuarios[100] = {0};

int num_aniversarios_usuarios[100] = {0};

int num_usuarios = 0;

int main() {

    int opcao = 0;

    do {

        printf(" 1 - Cadastrar Usuario\n");
        printf(" 2 - Listar Usuarios\n");
        printf(" 3 - Cadastrar Tarefa\n");
        printf(" 4 - Imprimir Tarefa\n");
        printf(" 5 - Cadastrar Reuniao\n");
        printf(" 6 - Imprimir Reuniao\n");
        printf(" 7 - Cadastrar Aniversario\n");
        printf(" 8 - Imprimir Aniversario\n");
        printf(" 30 - Sair \n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch ( opcao ) {
            case 1 :
                cadastrar_usuario();
                break;
            case 2 :
                listar_usuarios();
                break;
            case 3 :
                cadastrar_tarefa();
                break;
            case 4 :
                imprimir_tarefas();
                break;
            case 5 :
                cadastrar_reuniao();
                break;
            case 6 :
                imprimir_reuniao();
                break;
             case 7 :
                cadastrar_aniversario();
                break;
            case 8 :
                imprimir_aniversario();
    			break;
        }

    } while( opcao != 30 );

    return 0;
}

void cadastrar_usuario() {

    printf(" Nome: ");
    scanf("%s", usuarios_nome[num_usuarios]);

    printf(" Email: ");
    scanf("%s", usuarios_email[num_usuarios]);

    num_usuarios++;
}

void listar_usuarios() {
	int i;
    for (i = 0; i < num_usuarios; i++ ) {
        printf("Nome: %s \t Email: %s \n", usuarios_nome[i], usuarios_email[i]);
    }
}

void cadastrar_tarefa() {

    int codigo_usuario = 0, i;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);

    int num_tarefas_usuario;
    num_tarefas_usuario = num_tarefas_usuarios[codigo_usuario]++;

    printf(" Assunto: ");
    scanf("%s", tarefas_assunto[codigo_usuario][num_tarefas_usuario]);
    
	i = 25;
	printf(" Hora Inicio: ");
	while(i>23){
		scanf("%d",&i);
	}
	tarefas_hora_inicio[codigo_usuario][num_tarefas_usuario] = i;
	
	i = 25;
	printf(" Hora Fim: ");
	while(i>24 && i!=0){
		scanf("%d",&i);
	}
	tarefas_hora_fim[codigo_usuario][num_tarefas_usuario] = i;
	
    printf(" Esforco: ");
    i = 6;
    while(i>5){
    	scanf("%d", &i);
	}
	tarefas_esforco[codigo_usuario][num_tarefas_usuario] = i;
	
	i=11;

    printf(" Prioridade: ");
    while(i>10){
   		scanf("%d", &i);
   	}
   	tarefas_prioridade[codigo_usuario][num_tarefas_usuario] = i;
}


void imprimir_tarefas() {

    int codigo_usuario = 0;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);

    int num_tarefas_usuario = num_tarefas_usuarios[codigo_usuario];
	int i;
    for ( i = 0; i < num_tarefas_usuario; i++ ) {
        printf(" Assunto: %s \t Hora Inicio: %d \t Hora Fim: %d \t Esforco: %d \t Prioridade: %d \n ",
               tarefas_assunto[codigo_usuario][i],
               tarefas_hora_inicio[codigo_usuario][i],
               tarefas_hora_fim[codigo_usuario][i],            
               tarefas_esforco[codigo_usuario][i],
               tarefas_prioridade[codigo_usuario][i]);
    }
}

void cadastrar_reuniao() {

    int codigo_usuario = 0,i;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);

    int num_reunioes_usuario;
    num_reunioes_usuario = num_reunioes_usuarios[codigo_usuario]++;

    printf(" Assunto: ");
    scanf("%s", reuniao_assunto[codigo_usuario][num_reunioes_usuario]);
	
	i = 25;
	while(i>23){
		printf(" Hora Inicio: ");
		scanf("%d",&i);
	}
	reuniao_hora_inicio[codigo_usuario][num_reunioes_usuario] = i;
	
	i = 25;
	while(i>24 && i!=0){
		printf(" Hora Fim: ");
		scanf("%d",&i);
	}
	reuniao_hora_fim[codigo_usuario][num_reunioes_usuario] = i;
    
    printf(" Local: ");
    scanf("%s", reuniao_local[codigo_usuario][num_reunioes_usuario]);
    
    i=2;
    while(i>1){
    	printf(" Obrigatorio: ");
         scanf("%d", &i);
    }
    reuniao_obrigatoriedade[codigo_usuario][num_reunioes_usuario]=i;
}


void imprimir_reuniao() {

    int codigo_usuario = 0;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);

    int num_reunioes_usuario = num_reunioes_usuarios[codigo_usuario];
	int i;
    for ( i = 0; i < num_reunioes_usuario; i++ ) {
        printf(" Assunto: %s \t Hora Inicio: %d \t Hora Fim: %d \t Local: %s \t Obrigatoriedade: %d \n ",
               reuniao_assunto[codigo_usuario][i],
               reuniao_hora_inicio[codigo_usuario][i],
               reuniao_hora_fim[codigo_usuario][i],
               reuniao_local[codigo_usuario][i],
               reuniao_obrigatoriedade[codigo_usuario][i]);
    }
}

void cadastrar_aniversario() {

    int codigo_usuario = 0,i;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);

    int num_aniversario_usuario;
    num_aniversario_usuario = num_aniversarios_usuarios[codigo_usuario]++;

    printf(" Assunto: ");
    scanf("%s", aniversario_assunto[codigo_usuario][num_aniversario_usuario]);

	i=25;
	while(i>23){
		printf(" Hora Inicio: ");
		scanf("%d",&i);
	}
	aniversario_hora_inicio[codigo_usuario][num_aniversario_usuario] = i;
	
	i = 25;
	while(i>24 && i!=0){
		printf(" Hora Fim: ");
		scanf("%d",&i);
	}
	aniversario_hora_fim[codigo_usuario][num_aniversario_usuario] = i;
    
    printf(" Local: ");
    scanf("%s", aniversario_local[codigo_usuario][num_aniversario_usuario]);
    
    printf(" Aniversariante: ");
    scanf("%s", aniversario_aniversariante[codigo_usuario][num_aniversario_usuario]);
    
}


void imprimir_aniversario() {

    int codigo_usuario = 0;

    printf(" Codigo do Usuario: ");
    scanf("%d", &codigo_usuario);
    int num_aniversario_usuario = num_aniversarios_usuarios[codigo_usuario];
	int i;
    for ( i = 0; i < num_aniversario_usuario; i++ ) {
        printf(" Assunto: %s \t Hora Inicio: %d \t Hora Fim: %d \t Local: %s \t Nome: %s \n ",
               aniversario_assunto[codigo_usuario][i],
               aniversario_hora_inicio[codigo_usuario][i],
               aniversario_hora_fim[codigo_usuario][i],
               aniversario_local[codigo_usuario][i],
               aniversario_aniversariante[codigo_usuario][i]);
    }
}
