#include <cstdio>
#include <cstring>
#define mod 1000000007
char o[1000010], u[1000010];

int main() {
    int n, m;
    
    strcpy(o, "ananabanabananabanana");
    strcpy(u, "banana");
    
    n = strlen(o);
    m = strlen(u);
    
    long long rep = 1; // repeated squaring number
    
    long long hash = u[m - 1]; // last char
    long long hash2 = o[m - 1];
    
    for(int i = m - 2; i >= 0; i--) {
        rep = (rep << 8) + rep; // rep * 257
        hash = (hash + u[i] * rep) % mod;
        hash2 = (hash2 + o[i] * rep) % mod;
    }
    
    if(hash == hash2) { // matching , [0, m - 1]
        printf("find 0!\n");
    }
    for(int i = m; i < n; i++) {
        hash2 -= (o[i - m] * rep) % mod; // rep be using here, delete (first char * 257^(m-1))
        hash2 = (hash2 + mod) % mod; // negative number handling
        hash2 = (hash2 << 8) + hash2; // hash2 * 257
        hash2 %= mod;
        hash2 += o[i]; // adding next char
        hash2 %= mod;
        
        if(hash == hash2) {
            printf("find %d!\n", i - m + 1); // 0-base
        }
    }
    return 0;
}
