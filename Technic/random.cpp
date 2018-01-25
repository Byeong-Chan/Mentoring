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

static unsigned long int next = 1; // this is seed
int rnd2(void) // RAND_MAX assumed to be 32767
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

int main() {
    double prob = 1.0 / 6; // compare 1.0/10, 1.0/100, 1.0/1000, 1.0/10000, 1.0/100000
    
    int cnt = 0;
    for(int i = 0; i < 100000000; i++) if((double)rnd() / mod < prob) cnt++;
    printf("%d/100000000\n",cnt);
    
    cnt = 0;
    for(int i = 0; i < 100000000; i++) if((double)rnd2() / 32768 < prob) cnt++;
    printf("%d/100000000\n",cnt);
    return 0;
}
