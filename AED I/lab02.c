/* Programa: LEE lab2
   Autor: Pedro Henrique de Almeida
   Versao: 1.0 - 30/05/2021
*/
 
 
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
// ########################## TAD X.h ######################################
struct info{
    int valor;
    int proximo;
}; typedef struct info tipoinfo;
struct ListaEE{
    int tamanhoLista;
    int primeiro;
    int ultimo;
    int posLivre[10];
    tipoinfo elemento[10];
}; typedef struct ListaEE tipolistaEE;
 
int proxPosLivre(tipolistaEE *listaAux){
    int i;
    for (i = 0; i < 10; i++){
        if (listaAux->posLivre[i] == 1){
            return i;
        }
    }
    return -1;
}
 
void inicializalistaEE(tipolistaEE *listaAux){
    int i;
    listaAux->tamanhoLista = 0;
    listaAux->primeiro = -1;
    listaAux->ultimo = -1;
    for (i = 0; i < 10; i++){
        listaAux->elemento[i].valor = 0;
        listaAux->elemento[i].proximo = -1;
        listaAux->posLivre[i] = 1;
    }
}
 
int listaCheia(tipolistaEE *listaAux){
    if (listaAux->tamanhoLista < 10){
        return 0;
    }
    else{
        return 1;
    }
}
 
int procuraLista(tipolistaEE *listaAux, int element){
    int i;
    for (i = 0; i <= 10; i++){
        if (listaAux->elemento[i].valor == element){
            return i;
        }
    }
    return -1;
}
 
void insere(tipolistaEE *listaAux, int element){
    int posicao;
    posicao = proxPosLivre(listaAux);
    if (posicao != -1){
        if (listaAux->tamanhoLista == 0){
            listaAux->primeiro = posicao;
        }
        else{
            listaAux->elemento[listaAux->ultimo].proximo = posicao;
        }
        listaAux->elemento[posicao].valor = element;
        listaAux->elemento[posicao].proximo = -1;
        listaAux->tamanhoLista++;
        listaAux->posLivre[posicao] = 0;
    }
}
 
void insereInicio(tipolistaEE *listaAux, int element){
    int pos, primeiroPassado;
    if (listaAux->tamanhoLista == 0){
        pos = proxPosLivre(listaAux);
        insere(listaAux, element);
        listaAux->ultimo = pos;
        listaAux->primeiro = pos;
    }
    else{
        primeiroPassado = listaAux->primeiro;
        pos = proxPosLivre(listaAux);
        insere(listaAux, element);
        listaAux->elemento[pos].proximo = primeiroPassado;
        listaAux->primeiro = pos;
        listaAux->elemento[listaAux->ultimo].proximo = -1;
    }
}
 
void insereIntermediario(tipolistaEE *listaAux, int element, int posInicio, int posFim){
    int posicao;
    insere(listaAux, element);
    posicao = procuraLista(listaAux, element);
    listaAux->elemento[posInicio].proximo = posicao;
    listaAux->elemento[posicao].proximo = posFim;
    if (posFim == listaAux->ultimo)
    {
        listaAux->elemento[posFim].proximo = -1;
    }
}
 
void insereFinal(tipolistaEE *listaAux, int element){
    int ultimoAntigo, posUltimoAtual;
    ultimoAntigo = listaAux->ultimo;
    insere(listaAux, element);
    posUltimoAtual = procuraLista(listaAux, element);
    listaAux->elemento[ultimoAntigo].proximo = posUltimoAtual;
    listaAux->ultimo = posUltimoAtual;
    listaAux->elemento[posUltimoAtual].proximo = -1;
}
 
void InsereOrganizaLista(tipolistaEE *listaAux, int element){
    int anterior, proximo, i, controle = 0;
    if (listaAux->primeiro == -1){
        insereInicio(listaAux, element);
    }
    else{
        for (i = 0; i < listaAux->tamanhoLista; i++){
            if (element > listaAux->elemento[listaAux->ultimo].valor){
                insereFinal(listaAux, element);
                controle = -999;
            }
            else if (element < listaAux->elemento[listaAux->primeiro].valor){
                insereInicio(listaAux, element);
                controle = -999;
            }
            else{
                proximo = listaAux->elemento[listaAux->primeiro].proximo;
                anterior = listaAux->primeiro;
                while (controle != -999){
                    if (listaAux->elemento[proximo].valor > element && listaAux->elemento[anterior].valor < element){
                            insereIntermediario(listaAux, element, anterior, proximo);
                            controle = -999;
                            break;
                    }
                    proximo = listaAux->elemento[proximo].proximo;
                    anterior = listaAux->elemento[anterior].proximo;
                }
            }
        }
    }
}
 
void removePrimeiro(tipolistaEE *listaAux){
    int posElemento, posSeguinte;
    posElemento = listaAux->primeiro;
    posSeguinte = listaAux->elemento[posElemento].proximo;
    listaAux->elemento[posElemento].valor = 0;
    listaAux->elemento[posElemento].proximo = -1;
    listaAux->tamanhoLista--;
    listaAux->primeiro = posSeguinte;
    listaAux->posLivre[posElemento] = 1;
}
 
void removeIntermediario(tipolistaEE *listaAux, int posicao){
    int anterior, pos, resp = 0;
    pos = listaAux->primeiro;
    while (resp != -999){
        if (listaAux->elemento[pos].proximo == posicao){
            anterior = pos;
            resp = -999;
        }
        pos = listaAux->elemento[pos].proximo;
    }
    listaAux->elemento[anterior].proximo = listaAux->elemento[posicao].proximo;
    listaAux->tamanhoLista--;
}
 
void removeUltimo(tipolistaEE *listaAux, int posicao){
    int anterior, controleWhile = 0;
    anterior = listaAux->primeiro;
    while (controleWhile != -999){
        if (listaAux->elemento[anterior].proximo == posicao){
            listaAux->elemento[posicao].valor = 0;
            listaAux->elemento[anterior].proximo = -1;
            listaAux->posLivre[posicao] = 1;
            listaAux->ultimo = anterior;
            listaAux->tamanhoLista--;
            controleWhile = -999;
        }
        anterior = listaAux->elemento[anterior].proximo;
    }
}
 
void removeElemento(tipolistaEE *listaAux, int pos){
 
    if (pos == listaAux->primeiro){             //Remove primeiro
            int posElemento, posSeguinte;
    posElemento = listaAux->primeiro;
    posSeguinte = listaAux->elemento[posElemento].proximo;
    listaAux->elemento[posElemento].valor = 0;
    listaAux->elemento[posElemento].proximo = -1;
    listaAux->tamanhoLista--;
    listaAux->primeiro = posSeguinte;
    listaAux->posLivre[posElemento] = 1;
    }
 
    else if (pos == listaAux->ultimo){                  //Remove ultimo
        int anterior, controleWhile = 0;
        anterior = listaAux->primeiro;
        while (controleWhile != -999){
            if (listaAux->elemento[anterior].proximo == pos){
                listaAux->elemento[pos].valor = 0;
                listaAux->elemento[anterior].proximo = -1;
                listaAux->posLivre[pos] = 1;
                listaAux->ultimo = anterior;
                listaAux->tamanhoLista--;
                controleWhile = -999;
            }
        anterior = listaAux->elemento[anterior].proximo;
        }
    }else{
        int anterior, sucessor, pos, resp = 0;
        pos = listaAux->primeiro;
        while (resp != -999){
            if (listaAux->elemento[pos].proximo == pos){
                anterior = pos;
                resp = -999;
            }
            pos = listaAux->elemento[pos].proximo;
        }
        sucessor = listaAux->elemento[pos].proximo;
        listaAux->elemento[anterior].proximo = sucessor;
        listaAux->tamanhoLista--;
    }
}
 
void imprimeLista(tipolistaEE *listaAux){
    int pos, resposta = 0;
    listaAux->elemento[listaAux->ultimo].proximo = -1;
    pos = listaAux->primeiro;
    if(listaAux->tamanhoLista == 0){
        printf("\n");
    }else{
        while (resposta != -999){
            if(listaAux->elemento[pos].proximo == -1){
                printf("%d\n", listaAux->elemento[pos].valor);
                resposta = -999;
            }else{
                printf("%d ", listaAux->elemento[pos].valor);
                pos = listaAux->elemento[pos].proximo;
            }
        }
    }
}
 
int dividePor1000(int element){
    int divisao;
    divisao = (element) / 1000;
    return divisao;
}
// ############################ Principal ###################################
int main(){
 
    int moviments, tipoMovimento, RA, i, divisao, resp, pos;
    int ano[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    tipolistaEE myList;
    inicializalistaEE(&myList);
 
    scanf("%d", &moviments);
 
    for (i = 0; i < moviments; i++){
        
        scanf("%d %d", &tipoMovimento, &RA);
        
        if (tipoMovimento == 1){
            if (listaCheia(&myList )){
                printf("lista cheia\n");
                imprimeLista(&myList);
            }
 
            else{
                InsereOrganizaLista(&myList, RA);
                imprimeLista(&myList);
                divisao = dividePor1000(RA);
                switch (divisao){
                case 66:
                    ano[0]++;
                    break;
                case 76:
                    ano[1]++;
                    break;
                case 86:
                    ano[2]++;
                    break;
                case 96:
                    ano[3]++;
                    break;
                case 106:
                    ano[4]++;
                    break;
                case 116:
                    ano[5]++;
                    break;
                case 126:
                    ano[6]++;
                    break;
                case 136:
                    ano[7]++;
                    break;
                }
            }
        }
 
        else if (tipoMovimento == 2){
            resp = procuraLista(&myList, RA);
            if (resp == -1){
                printf("nao existe\n");
                imprimeLista(&myList);
            }
            else{
                pos = procuraLista(&myList, RA);
                if (pos == -1){
                    printf("nao existe\n");
                    imprimeLista(&myList);
                }
                else{
                    removeElemento(&myList, pos);
                    imprimeLista(&myList);
                }
            }
        }
    
    }
 
    for (i = 0; i < 8; i++){
        printf("%d: %d\n", 2011 + i, ano[i]);
    }
 
    return 0;
}
