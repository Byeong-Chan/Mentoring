#include <stdio.h>

int o[110][110];
int cnt;
int n;
int m = 0;
int ans[10010];

void dfs(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) return;
    if(o[x][y] == 0) return;
    o[x][y] = 0;
    cnt++;
    
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%1d",&o[i][j]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(o[i][j] == 1) {
                cnt = 0;
                dfs(i, j);
                ans[m++] = cnt;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m - i - 1; j++) {
            if(ans[j] > ans[j+1]) {
                int tmp = ans[j];
                ans[j] = ans[j+1];
                ans[j+1] = tmp;
            }
        }
    }
    printf("%d\n",m);
    for(int i = 0; i < m; i++) printf("%d\n",ans[i]);
    return 0;
}