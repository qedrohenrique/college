#include <limits.h>
#include <stdio.h>
 
#define N 1025
 
int grid[N][N];
int stripSum[N][N];
 
void init_grid(){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            grid[i][j] = 0;
        }
    }
}
 
void printMaxSumSub(int mat[][N], int k){
 
    if (k > N)
        return;
 
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += mat[i][j];
 
        stripSum[0][j] = sum;
 
        for (int i = 1; i < N - k + 1; i++) {
            sum += (mat[i + k - 1][j] - mat[i - 1][j]);
            stripSum[i][j] = sum;
        }
    }
 
    int max_sum = INT_MIN, pos_x = 0, pos_y = 0, *pos = NULL;
 
    for (int i = 0; i < N - k + 1; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += stripSum[i][j];
 
        if (sum > max_sum) {
            max_sum = sum;
            pos_x = i;
        }
 
        for (int j = 1; j < N - k + 1; j++) {
            sum += (stripSum[i][j + k - 1]
                    - stripSum[i][j - 1]);
 
            if (sum > max_sum) {
                max_sum = sum;
                pos_x = i;
                pos_y = j;
                pos = &(mat[i][j]);
            }
        }
    }
 
    printf("%d %d %d", pos_x+((k-1)/2), pos_y+((k-1)/2), max_sum);
}
 
int main(){
 
    int d, n, x, y, i, users;
    scanf("%d", &d);
 
    d = (d*2)+1;
 
    init_grid();
    
    scanf("%d", &n);
 
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &x,&y, &users);
        grid[x][y] = users;
    }
 
    printMaxSumSub(grid, d);
 
    return 0;
}