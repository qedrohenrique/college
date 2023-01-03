#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int key;
    int fixed_point;
    int flag; 
} backtrackTree;
 
int loadEntries(backtrackTree **root){
    int i, N, M, xpos, ypos;
 
    scanf("%d %d", &N, &M);
    N = N + 1;
 
    if(N > 0) (*root) = (backtrackTree *) malloc(N * sizeof(backtrackTree));
 
    for(i = 0; i < N; i++) {
        (*root)[i].fixed_point = 0;
        (*root)[i].flag = 0;
    }
 
    for (i = 0; i < M; i++) {
        scanf("%d %d", &xpos, &ypos);
        (*root)[ypos].fixed_point = xpos;
    }
 
    return N;
}
 
void make_move(backtrackTree *A, int i, int c[]) {
    A[c[i]].flag = 1;
}
 
void unmake_move(backtrackTree *A, int i, int c[]) {
   A[c[i]].flag = 0;
}
 
void printOutput(backtrackTree *A, int n){
    int i;
    if (n > 0) {
        printf("%d", A[1].key);
        for (i = 2; i < n; i++) printf(" %d", A[i].key);
    }
    printf("\n");
}
 
int isSolution(int k, int N) {
    if(k == N-1) return 1;
    else return 0;
}
 
void computeSolution(backtrackTree *root, int k, int N) {
    int i, flagSolution = 1;
 
    for(i = 1; i < N; i++) {
        if(root[i].fixed_point != 0 && root[i].fixed_point != root[i].key) {
            flagSolution = 0;
            break;
        }
    }
 
    if(flagSolution) printOutput(root, N);
}
 
void generateCandidates(backtrackTree *root, int k, int N, int candidates[], int *numCand) {
    int i; 
    *numCand = 1;
 
    for(i = 1; i < N; i++) {
        if(root[i].flag == 0) {
            candidates[*numCand] = i;
            *numCand += 1;
        }
    }
}
 
void backtrack(backtrackTree *root, int k, int N) {
    int candidates[N]; 
    int numCand;
    int i;
 
    if(isSolution(k, N)) computeSolution(root, k, N);
    else {
        k++;
        generateCandidates(root, k, N, candidates, &numCand);
 
        for(i = 1; i < numCand; i++) {
            root[k].key = candidates[i];
            make_move(root, i, candidates);
            backtrack(root, k, N);
            unmake_move(root, i, candidates);
        }
    }
 
}
 
int main() {
    int n;  
    backtrackTree *root;
    
    n = loadEntries(&root);
 
    backtrack(root, 0, n);
    return 0;
}