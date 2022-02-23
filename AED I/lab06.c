/*
Programa: Lab 06 - Fila
Autor: Pedro Henrique de Almeida
Versao: 1.0 - 14/07/2021
*/

// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ########################## TAD X.h ######################################

typedef struct elemento {
    int digito;
    struct elemento *ant;
} tipoElemento;
typedef struct pilha{
int tamanhoPilha;
tipoElemento *topo;
} tipoPilha;
// ###################### Funcoes e Procedimentos do programa ##############

void inicializaPilha (tipoPilha *pilhaAux){
    pilhaAux->topo = NULL;
    pilhaAux->tamanhoPilha = 0;
}

void Push (tipoPilha *pilhaAux, int valor){
    tipoElemento *novoDigito = malloc(sizeof(tipoElemento));
    novoDigito->digito = valor;
    if(pilhaAux->tamanhoPilha == 0){
        novoDigito->ant = NULL;
    }else{
        novoDigito->ant = pilhaAux->topo;
    }
    pilhaAux->topo = novoDigito;
    pilhaAux->tamanhoPilha++;
}

void Pop (tipoPilha *pilhaAux){ 
    tipoElemento *Aux = pilhaAux->topo;
    pilhaAux->topo = Aux->ant;
    free(Aux);
    pilhaAux->tamanhoPilha--;
}

void fullPop (tipoPilha *pilhaAux){
    while(pilhaAux->tamanhoPilha != 0){
        Pop(pilhaAux);
    }
}

void DecToBin(tipoPilha *pilhaAux, int num){
    int decNum = num, resto;
    while(decNum != 0){
        resto = decNum % 2;
        Push(pilhaAux, resto);
        decNum = decNum / 2;
    }
}

void BinToBin(tipoPilha *pilhaAux){
    tipoElemento *aux = pilhaAux->topo;
    while(aux != NULL){
        if(aux->digito == 1){
            aux->digito = 0;
            aux = aux->ant;
        }else if(aux->digito == 0){
            aux->digito = 1;
            aux= aux->ant;
        }
    }
}

void BinToDec(tipoPilha *pilhaAux){
    int i = 0, sum = 0;
    tipoElemento *aux = pilhaAux->topo;
    while(aux != NULL){
        i++;
        aux = aux->ant;
    }
    aux = pilhaAux->topo;
    while(aux != NULL){
        if(aux->digito == 1) sum += pow(2,i-1);
        aux = aux->ant;
        i--;
    }
    printf("%d\n", sum);
}

void List(tipoPilha *pilhaAux){
    tipoElemento *Aux = pilhaAux->topo;
    while(Aux->ant != NULL){
        printf("%d", Aux->digito);
        Aux = Aux->ant;
    }
    printf("%d ", Aux->digito);
}


int main(){
    int L, i, num;
    tipoPilha minhaPilha;
    inicializaPilha(&minhaPilha);

    scanf("%d", &L);

    for (i = 0; i < L; i++){
        scanf("%d", &num);
        DecToBin(&minhaPilha, num);
        printf("%d ", num);
        List(&minhaPilha);
        BinToBin(&minhaPilha);
        List(&minhaPilha);
        BinToDec(&minhaPilha);
        fullPop(&minhaPilha);
    }
    return 0;
}