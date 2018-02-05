#include <stdio.h>

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int o[1010][1010];
int n, m;

int qx[1000010], qy[1000010], qd[1000010];

void bfs() {
    int tail = 0, head = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(o[i][j] == 1) {
                o[i][j] = -1;
                qx[tail] = i;
                qy[tail] = j;
                qd[tail] = 0;
                tail++;
            }
        }
    }
    
    while(head < tail) {
        int x = qx[head];
        int y = qy[head];
        int d = qd[head];
        head++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(o[nx][ny] == -1) continue;
            o[nx][ny] = -1;
            qx[tail] = nx;
            qy[tail] = ny;
            qd[tail] = d + 1;
            tail++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(o[i][j] == 0) {
                printf("-1\n");
                return;
            }
        }
    }
    if(tail > 0) printf("%d\n",qd[tail-1]);
    else printf("0\n");
} 


int main() {
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d",&o[i][j]);
        }
    }
    bfs();
    return 0;
}