/*
Programa: Lab 05 - Fila Estática Circular
Autor: Pedro Henrique de Almeida
Versao: 1.0 - 04/07/2021
*/

// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################
struct filaCircular{
    int primeiro;
    int ultimo;
    int elementos[100];
};
typedef struct filaCircular tipoFEC;
// ###################### Funcoes e Procedimentos do programa ###############
void inicializaFila(tipoFEC *filaAux){
    int i;
    filaAux->primeiro = -1;
    filaAux->ultimo = -1;
    for(i = 0; i < 100; i++){
        filaAux->elementos[i] = 0;
    }
}

int filaVazia(tipoFEC *filaAux){
    if((filaAux->primeiro) == filaAux->ultimo && (filaAux->ultimo) == -1) return 1; //vazio 
    else return 0; // nao vazio
}

void insereTarefa(tipoFEC *filaAux, int info){
    if (filaAux->primeiro == -1 && filaAux->ultimo == -1){
        filaAux->elementos[0] = info;
        filaAux->primeiro = 0;
        filaAux->ultimo = 0;
    }else{
        filaAux->elementos[(filaAux->ultimo + 1) % 100] = info;
        filaAux->ultimo = (filaAux->ultimo + 1) % 100;
    }
}

int removeTarefa(tipoFEC *filaAux){
    int temp = filaAux->elementos[filaAux->primeiro];
    if (filaAux->primeiro == filaAux->ultimo){
        filaAux->elementos[filaAux->primeiro] = 0;
        filaAux->primeiro = -1;
        filaAux->ultimo = -1;
    }else{
        filaAux->elementos[filaAux->primeiro] = 0;
        filaAux->primeiro = (filaAux->primeiro + 1) % 100;
    }
    return temp;
}

void concluiTarefa(tipoFEC *filaAux){
        int temp;
        temp = removeTarefa(filaAux);
        insereTarefa(filaAux, temp);
}

void imprimeFila(tipoFEC *filaAux){
    int i;
    for (i = filaAux->ultimo; i > filaAux->primeiro; i = ((100 + i) - 1) % 100){
        printf("%d ", filaAux->elementos[i]);
    }
    printf("%d\n", filaAux->elementos[filaAux->primeiro]);
}
// ############################ Principal ###################################
int main(){

    int i;
    int operacao, id, num;
    tipoFEC minhaFila;

    inicializaFila(&minhaFila);

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%d", &operacao);

        if(operacao == 1){
            scanf("%d", &id);
            insereTarefa(&minhaFila, id);
        }

        if(operacao == 2){
            if(filaVazia(&minhaFila) == 1) printf("vazia\n");
            else removeTarefa(&minhaFila); 
        }

        if(operacao == 3){
            if(filaVazia(&minhaFila) == 1) printf("vazia\n");
            else concluiTarefa(&minhaFila);
        } 
    }

    imprimeFila(&minhaFila);

    return 0;
}