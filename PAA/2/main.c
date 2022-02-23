#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
typedef struct {
    int val;
    int idx;
} heapStructure; 
 
void minHeapify(heapStructure *heap, int i, int size) {
    int left = (i*2)+1, right = (i*2)+2;
    int highest;
    heapStructure swap;
 
    if(left < size && heap[left].val <= heap[i].val)
        highest = left;
    else
        highest = i;
    if (right < size && heap[right].val <= heap[highest].val) 
        highest = right;
 
    if(highest != i) {
        swap = heap[highest];
        heap[highest] = heap[i];
        heap[i] = swap;
        minHeapify(heap, highest, size);
    }
}
 
void buildMinHeap (heapStructure *heap, int n) {
    int size = n, i;
    for(i = n/2; i >= 0; i--) minHeapify(heap, i, size);
}
 
int main() {
 
    int **Aux; 
    int *Tam;
    heapStructure *H;
    int k, i;
    int j, z, x, y;
 
    scanf("%d %d", &k, &i); 
 
    Tam = (int*)malloc(k*sizeof(int)); 
    Aux = (int**)malloc(k*sizeof(int*)); 
 
    for(j = 0; j < k; j++) {
        scanf("%d", &Tam[j]);
        Aux[j] = (int*) malloc(Tam[j]*sizeof(int)); 
 
        if(Tam[j] > 0) {  
            for(z = 0; z < Tam[j]; z++)
                scanf("%d", &Aux[j][z]);
        }
    }
 
    H = (heapStructure*)malloc(k*sizeof(heapStructure));
    for(x = 0; x < k; x++) {
        if(Tam[x] > 0) H[x].val = Aux[x][0]; 
        else H[x].val = INT_MAX; 
        H[x].idx = x;
    }
 
    buildMinHeap(H, k);
 
    for(x = 0; x < i; x++) {
 
        Tam[H[0].idx] -= 1; 
 
        if(Tam[H[0].idx] == 0) 
            Aux[H[0].idx][0] = INT_MAX;
 
        for(y = 0; y < (Tam[H[0].idx]); y++) 
            Aux[H[0].idx][y] = Aux[H[0].idx][y+1];
 
        if(x < i-1)
            H[0].val = Aux[H[0].idx][0]; 
 
        minHeapify(H, 0, k); 
    }
    
    long sum = 0;
 
    for(j = 0; j < k; j++) {
        if(H[j].val < INT_MAX){
            sum += H[j].val;
        } 
    }
        printf("%ld\n", sum);
 
    return(0);
}