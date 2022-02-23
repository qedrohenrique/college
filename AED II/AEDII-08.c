/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 08: ÁRVORE BINARIA DE BUSCA
*/
 
// ##################### Bibliotecas Externas ##############################
#include <stdio.h>
#include <stdlib.h>
int altura = 0;
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
 
int calculaAltura(tipoABB node, int aux)
{
  if (node == NULL)
    return -1;
 
  if (node->esq != NULL)
    calculaAltura(node->esq, aux + 1);
  if (node->dir != NULL)
    calculaAltura(node->dir, aux + 1);
  if (aux >= altura)
  {
    altura = aux;
    return aux;
  }
}
 
void printaAltura(tipoABB root)
{
  altura = 0;
  int h = 0, hd = 0, he = 0;
  h = calculaAltura(root, h);
  altura = 0;
  hd = calculaAltura(root->dir, hd);
  altura = 0;
  he = calculaAltura(root->esq, he);
  printf("%d, %d, %d\n", h, he + 1, hd + 1);
}
 
int maxDepth(tipoABB node)
{
    if (node == NULL)
        return -1;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->esq);
        int rDepth = maxDepth(node->dir);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
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
 
  int key;
  tipoABB root = NULL;
 
  scanf("%d",&key);
  tipoABB node = createNewNode(key);
  root = AddNewNode(root,node);
 
  while(key > 0){
    scanf("%d",&key);
    if(key < 0) break;
    node = createNewNode(key);
    root = AddNewNode(root,node);
  }
 
  printf("%d, %d, %d\n", maxDepth(root), maxDepth(root->esq)+1, maxDepth(root->dir)+1); 
 
  tipoABB nodeAux;
  scanf("%d",&key);
    nodeAux = searchNode(key, root);
  if(nodeAux == NULL){
    node = createNewNode(key);
    root = AddNewNode(root,node);
  }else{
    deleteNode(root, nodeAux->chave);
  }
 
 
  while(key > 0){
    scanf("%d",&key);
    if(key < 0) break;
    nodeAux = searchNode(key, root);
    if(nodeAux == NULL){
      node = createNewNode(key);
      root = AddNewNode(root,node);
    }else{
      deleteNode(root, nodeAux->chave);
    }
  }
 
  scanf("%d",&key);
  nodeAux = searchNode(key, root);
 
  if(nodeAux == NULL) printf("Valor nao encontrado\n");
  else printf("%d, %d, %d\n", maxDepth(nodeAux), maxDepth(nodeAux->esq)+1, maxDepth(nodeAux->dir)+1); 
 
}