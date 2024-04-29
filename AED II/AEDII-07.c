/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 07: Ordenando palavras 2.0
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define RANGE 255
 
void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}
 
int getMax(char array[][21], int n)
{
  int max = strlen(array[0]), i;
  for (i = 1; i < n; i++)
  {
    if (strlen(array[i]) > max)
      max = strlen(array[i]);
  }
  printf("%d\n", max);
  return max;
}
 
void countingSort(char array[][21], int size, int place)
{
  char output[size][21], aux;
  int max = 27, i, j;
  int count[max];
  int digito = place - 1;
 
  for (i = 0; i < max; i++)
    count[i] = 0;
 
  for (i = 0; i < size; i++)
  {
    if (array[i][digito] >= 97 && array[i][digito] <= 122 && strlen(array[i]) >= digito)
    {
      count[array[i][digito] - 96]++;
    }
    else
    {
      count[0]++;
    }
  }
 
  for (i = 1; i < 27; i++)
    count[i] += count[i - 1];
 
  printArray(count, 27);
 
  for (i = size - 1; i >= 0; i--)
  {
    if (array[i][digito] >= 97 && array[i][digito] <= 122 && strlen(array[i]) >= digito)
    {
      strcpy(output[count[array[i][place - 1] - 96] - 1], array[i]); //r pos 18
      count[array[i][place - 1] - 96]--;
    }
    else
    {
      strcpy(output[count[0] - 1], array[i]);
      count[0]--;
    }
  }
 
  for (i = 0; i < size; i++)
    strcpy(array[i], output[i]);
}
 
void radixsort(char array[][21], int size)
{
  int max = getMax(array, size), place;
  for (place = max; place > 0; place--)
    countingSort(array, size, place);
}
 
int main()
{
  int N, M, P, i, j;
 
  scanf("%d", &N);
 
  char arr[N][21];
  char aux[21];
 
  for (i = 0; i < N; i++)
    scanf("%s", &arr[i]);
 
  scanf("%d %d", &P, &M);
 
  for (i = 0; i < N; i++)
  {
    strcpy(aux, arr[i]);
    for (j = 0; aux[j]; j++)
    {
      aux[j] = tolower(aux[j]);
      strcpy(arr[i], aux);
    }
  }
 
  for (i = 0; i < N; i++)
    printf("%s.\n", arr[i]);
 
  radixsort(arr, N);
 
  j = P - 1;
 
  for (i = 0; i < M; i++)
  {
    printf("%s\n", arr[j]);
    j++;
  }
 
  return 0;
}