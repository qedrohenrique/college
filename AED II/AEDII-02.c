/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 02 = Recursao
*/

#include <stdio.h>

/*
Funcao recursiva que calcula o número
de livros adquiridos com vales.
*/

int calculoLivros(int numVales, int pVales){
    if (numVales >= pVales)
        return (1 + calculoLivros(numVales - pVales + 1, pVales));
    else return 0;
}

int main(){
    int n, i, d, p, v, totLivros;
    
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d %d %d", &d, &p, &v);
        totLivros = d/p + calculoLivros(d/p, v);
        printf("%d\n", totLivros);
    }
    return 0;
}
