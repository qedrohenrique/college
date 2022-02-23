/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 3.2 - Insertion Sort Recursivo
*/
 
#include <stdio.h>
 
int binarySearch(int vet[], int chave, int low, int high)
{
  if (high <= low)
  {
    if (chave > vet[low])
      return (low + 1);
    else
      return low;
  }
 
  int mid = (low + high) / 2;
  if (chave == vet[mid])
    return mid + 1;
  if (chave > vet[mid])
    return binarySearch(vet, chave, mid + 1, high);
 
  return binarySearch(vet, chave, low, mid - 1);
}
 
void insertionSort(int vet[], int tamVet, int tamVetAux)
{
 
  if (tamVet <= 1)
    return;
  insertionSort(vet, tamVet - 1, tamVetAux);
 
  int chave = vet[tamVet - 1];
  int i = tamVet - 2;
  int pos = binarySearch(vet, chave, 0, i);
  while (i >= pos)
  {
    vet[i + 1] = vet[i];
    i--;
  }
  vet[i + 1] = chave;
 
  printf("%d ", tamVetAux - tamVet);
  printf("%d ", chave);
  printf("%d\n", i + 1);
}
 
int main()
{
 
  int n, i;
 
  scanf("%d", &n);
 
  int vet[n];
 
  for (i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }
 
  insertionSort(vet, n, n + 1);
 
  for (i = 0; i < n; i++)
  {
    printf("%d ", vet[i]);
  }
 
  return 0;
}
