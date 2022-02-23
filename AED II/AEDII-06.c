/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 06: Ordenando Palavras
*/
#include <stdio.h>
#include <string.h>

//Swap de palavras (Usa funçoes da biblioteca string.h)
void swap(char *a, char *b)
{
  char aux[21];
  strcpy(aux, a);
  strcpy(a, b);
  strcpy(b, aux);
}
//Funcoes de heapsort inspiradas na aula do professor e na implementação no do geeksforgeeks
void heapify(char arr[][21], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && strcmp(arr[l], arr[largest]) > 0)
    largest = l;

  if (r < n && strcmp(arr[r], arr[largest]) > 0)
    largest = r;

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(char arr[][21], int n)
{
  int i;

  for (i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  for (i = 0; i < n; i++)
    printf("%s ", arr[i]);

  for (i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main(void)
{
  int n, m, i, aux, j;
  char temp[21];

  scanf("%d", &n);

  char arr[n][21];

  for (i = 0; i < n; i++)
  {
    scanf("%s", &temp);
    strcpy(arr[i], temp);
  }

  scanf("%d", &m);
  char vet[m][21];

  for (i = 0; i < m; i++)
  {
    scanf("%d", &aux);
    strcpy(vet[i], arr[aux]);
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < strlen(arr[i]); j++)
    {
      if (arr[i][j] < 'a' || arr[i][j] > 'z')
      {
        printf("a palavra %s eh invalida", arr[i]);
        return 0;
      }
    }
  }

  printf("build_heap: ");
  heapSort(vet, m);
  printf("\npalavras: ");
  for (i = 0; i < m; i++)
  {
    printf("%s ", vet[i]);
  }
  return 0;
}