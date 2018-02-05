#include <cstdio>
#include <cstring>

int fail[1000010];
int ans[1000010], cnt = 0;
char o[1000010];
char u[1000010];

void make_fail(int m) {
    int i = -1;
    int j = 0;
    fail[j] = i;
    while(j < m) {
        if(i < 0) {
            i++;
            j++;
            fail[j] = i;
        }
        else if(u[i] == u[j]) {
            i++;
            j++;
            fail[j] = i;
        }
        else {
            i = fail[i];
        }
    }
}

void match(int n, int m) {
    int i = 0;
    int j = 0;
    u[m] = '#';
    while(j < n) {
        if(i < 0) {
            i++;
            j++;
        }
        else if(u[i] == o[j]) {
            i++;
            j++;
        }
        else {
            i = fail[i];
        }
        if(i == m) {
            ans[cnt] = j - m + 2;
            cnt++;
        }
    }
}

int main() {
    int i;
    int n, m;
    scanf("%[^\n]%*c%[^\n]",o,u);
    n = strlen(o);
    m = strlen(u);
    make_fail(m);
    match(n, m);
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++) printf("%d\n", ans[i]-1);
    return 0;
}