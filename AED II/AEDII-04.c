/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 04: Contando Pares
*/

#include <stdio.h>

// Os pares são contados usando uma função comum de
// Merge Sort, com o diferencial de que a "ordenação
// feita com base na Regra do enunciado.

void merge(int arr[], int l, int m, int r, int kConst, int *counter)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2)
  {
    if (L[i] > R[j] * kConst)
    {
      j++;
      *counter = *counter + (n1 - i);
    }
    else
    {
      i++;
    }
    k++;
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int left, int right, int k, int *counter)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, k, counter);
    mergeSort(arr, mid + 1, right, k, counter);

    merge(arr, left, mid, right, k, counter);
  }
}

int main()
{
  int n, k, i, counter = 0;

  scanf("%d", &n);
  scanf("%d", &k);

  int arr[n];

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  mergeSort(arr, 0, n - 1, k, &counter);

  printf("%d", counter);
  return 0;
}
