#include <cstdio>
#include <cstring>
#define mod 1000000007
char o[1000010], u[1000010];
long long table[1000010];
int ans[10000010];
int cnt = 0;
int main() {
    int n, m;
    scanf("%[^\n]%*c%[^\n]",o,u);
    n = strlen(o);
    m = strlen(u);
    table[m - 1] = 1;
    for(int i = m - 2; i >= 0; i--) {
        table[i] = table[i + 1] * 257 % mod;
    }
    long long hash = 0;
    for(int i = 0; i < m; i++) {
        hash += table[i] * u[i];
        hash %= mod;
    }
    long long hash2 = 0;
    for(int i = 0; i < m; i++) {
        hash2 += table[i] * o[i];
        hash2 %= mod;
    }
    if(hash == hash2) {
        ans[cnt] = 1;
        cnt++;
    }
    for(int i = m; i < n; i++) {
        hash2 -= (o[i - m] * table[0]) % mod;
        hash2 = (hash2 + mod) % mod;
        hash2 *= 257;
        hash2 %= mod;
        hash2 += o[i];
        hash2 %= mod;
        
        if(hash == hash2) {
            ans[cnt] = i - m + 2;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; i++) printf("%d\n",ans[i]);
    return 0;
}