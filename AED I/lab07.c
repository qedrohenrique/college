/*
Programa: Lab 07 - Arvore binaria de busca
Autor: Pedro Henrique de Almeida
Versao: 1.0 - 31/07/2021
*/
 
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
typedef int IntChave;
typedef struct NoArvoreABB {
IntChave chave;
struct aux *esq, *dir;
} NoArvoreABB;
typedef NoArvoreABB* tipoABB;
// ###################### Funcoes e Procedimentos do programa ##############
tipoABB AddNewNode (tipoABB raiz, tipoABB no){
    if(raiz==NULL) return no;
    if(no->chave<raiz->chave) raiz->esq = AddNewNode (raiz->esq,no);
    else raiz->dir=AddNewNode(raiz->dir,no);
    return(raiz);
}
tipoABB createNewNode(IntChave ch){
    tipoABB novoNo = (tipoABB)malloc(sizeof(NoArvoreABB));
    novoNo->esq=NULL;
    novoNo->dir=NULL;
    novoNo->chave=ch;
    return(novoNo);
}

tipoABB searchNode(IntChave ch, tipoABB root){
    while(root != NULL && ch !=root->chave){
        if(ch<root->chave) root = root->esq;
        else root = root->dir;
    }
    return root;
}
 
tipoABB minValueNode(tipoABB node){
    tipoABB aux = node;
    while (aux && aux->esq != NULL) aux = aux->esq;
    return aux;
}
 
tipoABB deleteNode(tipoABB root, IntChave chave){
    if (root == NULL)
        return root;
 
    if (chave < root->chave)
        root->esq = deleteNode(root->esq, chave);
 
    else if (chave > root->chave)
        root->dir = deleteNode(root->dir, chave);
 
    else {
        if (root->esq == NULL) {
            tipoABB temp = root->dir;
            free(root);
            return temp;
        }
        else if (root->dir == NULL) {
            tipoABB temp = root->esq;
            free(root);
            return temp;
        }
        tipoABB temp = minValueNode(root->dir);
 
        root->chave = temp->chave;
 
        root->dir = deleteNode(root->dir, temp->chave);
    }
    return root;
}

void printInorder(tipoABB node){
    if (node == NULL)
        return;
    printInorder(node->esq);
    printf("%d ", node->chave);
    printInorder(node->dir);
}
// ########################## MAIN ######################################
int main(){

    int count, instancias, key;
    char op;
    IntChave busca;

    tipoABB root = NULL;

    scanf("%d",&instancias);

    for(count = 0; count < instancias; count++){
        scanf(" %c %d", &op, &key);
        switch(op){
            case 'B':{
                if(searchNode(key,root) != 0)printf("S\n");
                else printf("N\n");
                break;
            }
            case 'I':{
                tipoABB node = createNewNode(key);
                root = AddNewNode(root,node);
                break;
            }
            case 'R':{
                root = deleteNode(root, key);
                break;
            }
            case 'M':{
                printInorder(root);
                printf("\n");
                break;
            }
        }
    }
}
