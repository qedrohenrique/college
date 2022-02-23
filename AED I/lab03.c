/* Programa: Lab 03 - LDE
   Autor: Pedro Henrique de Almeida
   Versao: 1.0 - 02/06/2021
*/
#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
struct info{
    int ID;
    int quantidade;
    float lucro;
    float lucroTotal;
    struct info *prox;
}; typedef struct info produto;
 
struct listaDE{
    produto *primeiro;
    produto *ultimo;
    int tamanhoLista;
}; typedef struct listaDE produtosLista;
// ###################### Funcoes e Procedimentos do programa ##############
void inicializaLista(produtosLista *listaAux){
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanhoLista = 0;
}
 
produto * procuraProduto(produtosLista *listaAux, int IDAux){
    produto *p = listaAux->primeiro;
    while(p != NULL){
        if(p->ID == IDAux){
            return p;
        }
            p = p->prox;
    }
    return NULL;
}
 
produto * procuraPos(produtosLista *listaAux, float lucroAux){
    produto *p = listaAux->primeiro;
    while(p != NULL){
        if(lucroAux >= p->prox->lucro){
            return p;
        } else{ 
        p = p->prox;
        }
    }
    return NULL;
}
 
produto * insere(produtosLista *listaAux, int IDAux, int quantAux, float lucroAux){
    produto *novoProduto = malloc(sizeof(produto));
    novoProduto->ID = IDAux;
    novoProduto->quantidade = quantAux;
    novoProduto->lucro = lucroAux;
    novoProduto->lucroTotal = 0;
    listaAux->tamanhoLista++;
    return novoProduto;
}
 
void insereNovoProduto (produtosLista *listaAux, int IDAux, int quantAux, float lucroAux){
    produto *p = procuraProduto(listaAux, IDAux);
    produto *novaPos;
    if(p != NULL){
        printf("ja existe\n");
        return;
    } if(listaAux->tamanhoLista == 0){
        novaPos = insere(listaAux, IDAux, quantAux, lucroAux);
        novaPos->prox = NULL;
        listaAux->primeiro = novaPos;
        listaAux->ultimo = novaPos;
    } else if(lucroAux < listaAux->ultimo->lucro){ //  Insere no final da lista
        novaPos = insere(listaAux, IDAux, quantAux, lucroAux);
        novaPos->prox = NULL;
        listaAux->ultimo->prox = novaPos;
        listaAux->ultimo = novaPos;
        return;
    } else if(lucroAux >= listaAux->primeiro->lucro){ //    Insere no inicio da lista
        novaPos = insere(listaAux, IDAux, quantAux, lucroAux);
        novaPos->prox = listaAux->primeiro;
        listaAux->primeiro = novaPos;
        return;
    } else{
        produto *p = listaAux->primeiro;
        produto *pAnterior = p;
        while(p != NULL){
            if(lucroAux >= p->lucro){
                break;
            } 
            pAnterior = p;
            p = p->prox;
        }
        if(lucroAux >= p->lucro){
            novaPos = insere(listaAux, IDAux, quantAux, lucroAux);
            novaPos->prox = pAnterior->prox;
            pAnterior->prox = novaPos;
        }
    }
}
 
void aumentaQuantidade (produtosLista *listaAux, int IDAux, int quantAux){
    produto *p = procuraProduto(listaAux, IDAux);
    if(p == NULL || listaAux->tamanhoLista == 0){
        printf("nao existe\n");
        return;
    }
    p->quantidade += quantAux;
}
 
void compraProduto (produtosLista *listaAux, int IDAux){
    produto *p = procuraProduto(listaAux, IDAux);
    if(p == NULL || listaAux->tamanhoLista == 0 || p->quantidade == 0){
        printf("nao existe\n");
        return;
    } else{
        p->lucroTotal += p->lucro;
        p->quantidade--;
    }   
}
 
void removeProdutoPrimeiro(produtosLista *listaAux){
    produto *temp;
    temp = listaAux->primeiro;
    listaAux->primeiro = listaAux->primeiro->prox;
    listaAux->tamanhoLista--;
    free(temp);
}
 
void removeProdutoUltimo(produtosLista *listaAux){
    produto *pAnterior = listaAux->primeiro;
    produto *temp;
    while(pAnterior->prox != listaAux->ultimo){
        pAnterior = pAnterior->prox;
    }
    temp = listaAux->ultimo;
    listaAux->ultimo = pAnterior;
    listaAux->ultimo->prox = NULL;
    listaAux->tamanhoLista--;
    free(temp);
}
 
void removeProdutoIntermediario(produtosLista *listaAux, produto *p){
    produto *pAnterior, *aux;
    aux = p;
    pAnterior = listaAux->primeiro;
    while(pAnterior->prox != p){
        pAnterior = pAnterior->prox;
    }
    pAnterior->prox = p->prox;
    listaAux->tamanhoLista--;
    free(aux);
}
 
void removeProduto(produtosLista *listaAux, int IDAux){
    produto *p = procuraProduto(listaAux, IDAux);
 
    if(p == NULL || listaAux->tamanhoLista == 0){
        printf("nao existe\n");
        return;
    } else if(p == listaAux->primeiro){
        removeProdutoPrimeiro(listaAux);
    } else if(p == listaAux->ultimo){
        removeProdutoUltimo(listaAux);
    } else{
        removeProdutoIntermediario(listaAux, p);
    }
}
 
// ############################ Principal ###################################
int main(){
 
    int movimentos, tipoMovimento, ID, quantProduto;
    int i;
    float lucroProduto;
    produtosLista minhaLista;
 
    inicializaLista(&minhaLista);
 
    scanf("%d", &movimentos);
 
    for(i = 0; i < movimentos; i++){
 
        scanf("%d", &tipoMovimento);
 
        if(tipoMovimento == 1){
            scanf("%d %d", &ID, &quantProduto);
            scanf("%f", &lucroProduto);
            insereNovoProduto(&minhaLista, ID, quantProduto, lucroProduto);
        }
 
        if(tipoMovimento == 2){
            scanf("%d %d", &ID, &quantProduto);
            aumentaQuantidade(&minhaLista, ID, quantProduto);
        }
 
        if(tipoMovimento == 3){
            scanf("%d", &ID);
            compraProduto(&minhaLista, ID);
        }
 
        if(tipoMovimento == 4){
            scanf("%d", &ID);
            removeProduto(&minhaLista, ID);
        }
    }
 
    produto *p = minhaLista.primeiro;
    if(minhaLista.tamanhoLista == 0){
        printf("nao existe\n");
    } else{
        for(i = 0; i<minhaLista.tamanhoLista; i++){
            printf("%d %f\n", p->ID, p->lucroTotal);
            p = p->prox;
        }
    }
 
    return 0;
}