/*
Pedro Henrique de Almeida
RA 148526
AED2 2021 (2s) - Tarefa 01 = Número Primos
*/

#include <stdio.h>

// Calcula se dado número 
// é divisível por outro número 
// além de um e ele próprio.

int Solve(int num){
    int i;
    if(num <= 1){
        return 0;
    }
    for(i = 2; i < num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, i, num;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &num);
        if(Solve(num)){
            printf("%d 1\n", num);
        }else{
            printf("%d 0\n", num);
        }
    }

    return 0;
}