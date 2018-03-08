#include <cstdio>

long long seed = 1987152371; // as possible as BIG!
long long mod = 1000000007; // random range, PRIME NUMBER, example (1e9 + 7)
long long salt = 101; // Salt, Coprime with seed

long long rnd() {  // (x^2 + salt) % mod
    seed *= seed;
    seed %= mod;
    seed += salt;
    seed %= mod;
    return seed;
}

int o[1000010];
void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void quick(int l, int r) {
    if(r - l + 1 == 2) {
        if(o[l] > o[r]) swap(o[l], o[r]);
        return ;
    }
    if(r - l + 1 <= 1) return;
    
    int pivot = rnd() % (r - l + 1) + l;
    swap(o[l], o[pivot]);
    
    int i = l + 1;
    int j = r;
    
    int equal_l = 0;
    int equal_r = 0;
    
    while(i <= j) {
        if(o[i] == o[l] && equal_l <= equal_r) {
            equal_l++;
            i++;
        }
        else if(o[j] == o[l] && equal_l >= equal_r) {
            equal_r++;
            j--;
            continue;
        }
        else if(o[i] < o[l]) i++;
        else if(o[j] > o[l]) j--;
        else swap(o[i], o[j]);
    }
    swap(o[l], o[j]);
    quick(l, j - 1);
    quick(j + 1, r);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&o[i]);
    quick(0, n - 1);
    for(int i = 0; i < n; i++) printf("%d\n",o[i]);
    return 0;
}
