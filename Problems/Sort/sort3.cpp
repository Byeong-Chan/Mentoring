#include <cstdio>
int k[10010];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        k[x]++;
    }
    for(int i = 0; i <= 10000; i++) {
        for(int j = 0; j < k[i]; j++) printf("%d\n", i);
    }
    return 0;
}
