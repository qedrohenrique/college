/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 09/10 = Árvore AVL
*/

#include <stdio.h>
#include <stdlib.h>

struct No{
  int valor;
  struct No *esq;
  struct No *dir;
  int altura;
};

int altura(struct No *N)
{
  if (N == NULL)
    return 0;
  return N->altura;
}

int maximo(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

struct No *newNode(int valor)
{
  struct No *arvore = (struct No *)malloc(sizeof(struct No));
  arvore->valor = valor;
  arvore->esq = NULL;
  arvore->dir = NULL;
  arvore->altura = 1;
  return (arvore);
}

struct No *rotacaoDireita(struct No *aux2)
{
  struct No *aux1 = aux2->esq;
  struct No *T2 = aux1->dir;

  aux1->dir = aux2;
  aux2->esq = T2;

  aux2->altura = maximo(altura(aux2->esq), altura(aux2->dir)) + 1;
  aux1->altura = maximo(altura(aux1->esq), altura(aux1->dir)) + 1;

  return aux1;
}

struct No *rotacaoEsquerda(struct No *aux1)
{
  struct No *aux2 = aux1->dir;
  struct No *T2 = aux2->esq;

  aux2->esq = aux1;
  aux1->dir = T2;

  aux1->altura = maximo(altura(aux1->esq), altura(aux1->dir)) + 1;
  aux2->altura = maximo(altura(aux2->esq), altura(aux2->dir)) + 1;

  return aux2;
}

int balanceTree(struct No *N)
{
  if (N == NULL)
    return 0;
  return altura(N->esq) - altura(N->dir);
}

struct No *insertNode(struct No *arvore, int valor)
{
  if (arvore == NULL) return (newNode(valor));
  if (valor < arvore->valor) arvore->esq = insertNode(arvore->esq, valor);
  else if (valor > arvore->valor) arvore->dir = insertNode(arvore->dir, valor);
  else return arvore;

  arvore->altura = 1 + maximo(altura(arvore->esq), altura(arvore->dir));

  int balance = balanceTree(arvore);

  if (balance > 1 && valor < arvore->esq->valor) return rotacaoDireita(arvore);
  if (balance < -1 && valor > arvore->dir->valor) return rotacaoEsquerda(arvore);
  if (balance > 1 && valor > arvore->esq->valor){
    arvore->esq = rotacaoEsquerda(arvore->esq);
    return rotacaoDireita(arvore);
  }

  if (balance < -1 && valor < arvore->dir->valor)
  {
    arvore->dir = rotacaoDireita(arvore->dir);
    return rotacaoEsquerda(arvore);
  }

  return arvore;
}

struct No *minValueNode(struct No *arvore)
{
  struct No *atual = arvore;

  while (atual->esq != NULL)
    atual = atual->esq;

  return atual;
}

struct No *deleteNode(struct No *arvore, int valor){
  if (arvore == NULL)
    return arvore;

  if (valor < arvore->valor)
    arvore->esq = deleteNode(arvore->esq, valor);

  else if (valor > arvore->valor)
    arvore->dir = deleteNode(arvore->dir, valor);

  else
  {
    if ((arvore->esq == NULL) || (arvore->dir == NULL))
    {
      struct No *temp = arvore->esq ? arvore->esq : arvore->dir;

      if (temp == NULL)
      {
        temp = arvore;
        arvore = NULL;
      }
      else
        *arvore = *temp;
      free(temp);
    }
    else
    {
      struct No *temp = minValueNode(arvore->dir);

      arvore->valor = temp->valor;

      arvore->dir = deleteNode(arvore->dir, temp->valor);
    }
  }

  if (arvore == NULL)
    return arvore;

  arvore->altura = 1 + maximo(altura(arvore->esq),
                              altura(arvore->dir));

  int balance = balanceTree(arvore);

  if (balance > 1 && balanceTree(arvore->esq) >= 0)
    return rotacaoDireita(arvore);

  if (balance > 1 && balanceTree(arvore->esq) < 0)
  {
    arvore->esq = rotacaoEsquerda(arvore->esq);
    return rotacaoDireita(arvore);
  }

  if (balance < -1 && balanceTree(arvore->dir) <= 0)
    return rotacaoEsquerda(arvore);

  if (balance < -1 && balanceTree(arvore->dir) > 0)
  {
    arvore->dir = rotacaoDireita(arvore->dir);
    return rotacaoEsquerda(arvore);
  }

  return arvore;
}

struct No *pesquisaArvore(struct No *arvore, int v){
  if (arvore == NULL || v == arvore->valor)
    return arvore;

  if (v < arvore->valor)
    return pesquisaArvore(arvore->esq, v);
  else
    return pesquisaArvore(arvore->dir, v);

  return NULL;
}

void imprimirAltura(struct No *aux){
  if (aux->esq == NULL && aux->dir != NULL)
    printf("%d, 0, %d\n", aux->altura - 1, aux->dir->altura);
  else if (aux->dir == NULL && aux->esq != NULL)
    printf("%d, %d, 0\n", aux->altura - 1, aux->esq->altura);
  else if (aux->dir == NULL && aux->esq == NULL)
    printf("%d, 0, 0\n", aux->altura - 1);
  else
    printf("%d, %d, %d\n", aux->altura - 1, aux->esq->altura, aux->dir->altura);
}

int main(void){

  int i = 0, value;
  struct No *raiz = NULL;
  struct No *aux;

  while (value >= 0)
  {
    scanf("%d", &value);
    if (value < 0)
      break;
    raiz = insertNode(raiz, value);
  }

  imprimirAltura(raiz);
  scanf("%d", &value);

  while (value > 0)
  {
    aux = pesquisaArvore(raiz, value);
    
    if (aux != NULL) raiz = deleteNode(raiz, value);
    else raiz = insertNode(raiz, value);
  
    scanf("%d", &value);
  }

  scanf("%d", &value);

  if (pesquisaArvore(raiz, value) != NULL)
  {
    aux = pesquisaArvore(raiz, value);
    imprimirAltura(aux);
  }
  else printf("Valor nao encontrado\n");
  

  return 0;
}
