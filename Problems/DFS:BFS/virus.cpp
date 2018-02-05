#include <stdio.h>
#include <vector>

using namespace std;

int cnt;
vector<int> edge[110];
int check[110];

void dfs(int u) {
    cnt++;
    check[u] = 1;
    for(auto &v : edge[u]) {
        if(check[v] == 1) continue;
        dfs(v);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    printf("%d\n",cnt - 1);
    return 0;
}