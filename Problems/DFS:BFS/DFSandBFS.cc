#include <stdio.h>

int n, m;
int matrix[1010][1010];
int check_dfs[1010];

void dfs(int u) {
    printf("%d ",u);
    check_dfs[u] = 1;
    for(int v = 1; v <= n; v++) {
        if(matrix[u][v] == 0) continue;
        if(check_dfs[v] == 1) continue;
        dfs(v);
    }
}

int Q[1010];
int check_bfs[1010];
void bfs(int u) {
    int tail = 0, head = 0;
    Q[tail] = u;
    tail++;
    check_bfs[u] = 1;
    while(head < tail) {
        u = Q[head];
        head++;
        printf("%d ",u);
        
        for(int v = 1; v <= n; v++) {
            if(matrix[u][v] == 0) continue;
            if(check_bfs[v] == 1) continue;
            check_bfs[v] = 1;
            Q[tail] = v;
            tail++;
        }
    }
}

int main() {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    dfs(k);
    printf("\n");
    bfs(k);
    printf("\n");
    return 0;
}