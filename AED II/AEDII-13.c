/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 13: Tabela Hash
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int key;
  int value;
  int notEmptyList;
  struct hashElement *next;
} hashElement;

int hashingFunction(int value, int tableSize){
  return value % tableSize;
}

int insertHash(hashElement *tabelaHash, int tableSize, int value){
  hashElement *pAux;
  if (tabelaHash[hashingFunction(value, tableSize)].notEmptyList == 0){
    tabelaHash[hashingFunction(value, tableSize)].key = hashingFunction(value, tableSize);
    tabelaHash[hashingFunction(value, tableSize)].value = value;
    tabelaHash[hashingFunction(value, tableSize)].notEmptyList = 1;
  }else{
    pAux = &tabelaHash[hashingFunction(value, tableSize)];
    while (pAux->next != NULL) pAux = pAux->next;
    pAux->next = (hashElement *)malloc(sizeof(hashElement));
    pAux = pAux->next;
    pAux->value = value;
    pAux->key = hashingFunction(value, tableSize);
    pAux->next = NULL;
  }
}

int removeHash(hashElement *tabelaHash, int value, int tableSize, hashElement *pRemove){
  hashElement *pAux, *pAux2 = pRemove;
  if (pRemove->next != NULL){
    while (pRemove->next != NULL){
      pAux2 = pRemove;
      pAux = pRemove->next;
      pRemove->value = pAux->value;
      pRemove = pRemove->next;
    }
    pAux2->next = NULL;
    pAux->value = 0;
    free(pRemove);
  }else{
    pAux = &tabelaHash[hashingFunction(value, tableSize)];
    if (tabelaHash[hashingFunction(value, tableSize)].next == NULL) pAux->notEmptyList = 0;
    else{
      while (pAux->next != pRemove) pAux = pAux->next;
      pAux->next = NULL;
      free(pRemove);
    }
  }
}

int searchHash(hashElement *tabelaHash, int value, int tableSize){
  hashElement *pAux = &tabelaHash[hashingFunction(value, tableSize)];
  if (tabelaHash[hashingFunction(value, tableSize)].notEmptyList == 0) return 1;
  else{
    while (pAux != NULL){
      if (pAux->value == value){
        removeHash(tabelaHash, value, tableSize, pAux);
        return 0;
      }
      pAux = pAux->next;
    }
  }
  return 1;
}

int printLine(hashElement *tabelaHash, int tableSize, int linhaExibida){
  hashElement *pAux = &tabelaHash[linhaExibida];

  printf("[%d]", linhaExibida);

  if (pAux->notEmptyList != 0) printf(" %d", pAux->value);
  while (pAux->next != NULL){
    pAux = pAux->next;
    printf(" %d", pAux->value);
  }
  printf("\n");
}

void initializeTable(hashElement *tabelaHash, int tableSize){
  int i;
  for (i = 0; i < tableSize; i++)
  {
    tabelaHash[i].key = i;
    tabelaHash[i].next = NULL;
    tabelaHash[i].notEmptyList = 0;
  }
}

int main(){
  int tableSize, value;
  hashElement *tabelaHash;

  scanf("%d", &tableSize);

  tabelaHash = (hashElement *)malloc(tableSize * sizeof(hashElement));

  initializeTable(tabelaHash, tableSize);

  while (1){
    scanf("%d", &value);
    if (value < 0) break;
    insertHash(tabelaHash, tableSize, value);
  }

  scanf("%d", &value);

  if (searchHash(tabelaHash, value, tableSize) == 1){
    printf("Valor nao encontrado\n");
  }

  scanf("%d", &value);

  printLine(tabelaHash, tableSize, value);
}