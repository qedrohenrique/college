/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 3.1 = Jogo das Bolhas
*/

#include <stdio.h>

// Função auxiliar para Bubble Sort
// Responsável por trocar dois inteiros dados.

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

/*
Função Bubble Sort convencional, porém
conta cada troca de valores para o cálculo
do vencedor.
*/

int bubbleSort(int vetorSeq[], int tamSeq)
{
  int i, j;
  int vencedor = 0;
  for (i = 0; i < tamSeq - 1; i++)
  {
    for (j = 0; j < tamSeq - i - 1; j++)
    {
      if (vetorSeq[j] > vetorSeq[j + 1])
      {
        swap(&vetorSeq[j], &vetorSeq[j + 1]);
        vencedor++;
      }
    }
  }
  return vencedor;
}

int main()
{

  int i, n, vencedor;

  scanf("%d", &n);

  int vetorSeq[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &vetorSeq[i]);
  }

  vencedor = bubbleSort(vetorSeq, n);

  for (i = 0; i < n; i++)
  {
    printf("%d ", vetorSeq[i]);
  }

  if (vencedor % 2)
  {
    printf("\nMarcelo");
  }
  else
  {
    printf("\nCarlos");
  }

  return 0;
}
