/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 05: K-Ésimo Elemento
*/

#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int setposvotPos(int arr[], int menor, int maior)
{
  int posvo = arr[maior];
  int i = (menor - 1); //Posição do menor elemento no array.

  for (int j = menor; j <= maior - 1; j++)
  {
    if (arr[j] < posvo)
    {
      i++;                    //Mover a "barra" que separa o pivô
      swap(&arr[i], &arr[j]); //dos subarrays e troca de lugar o próximo elemento.
    }
  }
  swap(&arr[i + 1], &arr[maior]);
  return (i + 1);
}

void quickSort(int arr[], int menor, int maior, int k)
{
  if (menor < maior)
  {
    int pos = setposvotPos(arr, menor, maior);

    if (pos > k - 1)
      return quickSort(arr, menor, pos - 1, k);

    if (pos < k - 1)
      return quickSort(arr, pos + 1, maior, k);

    if (pos == k - 1)
      return; //Único elemento ou lista já ordenada
  }
}

void printArray(int arr[], int size, int k)
{
  int i;
  printf("%do menor elemento eh o %d\n", k, arr[k - 1]);
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{

  int i, n, k;

  scanf("%d", &k);
  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  quickSort(arr, 0, n - 1, k);
  printArray(arr, n, k);

  return 0;
}
