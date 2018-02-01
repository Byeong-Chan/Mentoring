#include <cstdio>
#include <vector>

using namespace std;

int limit;
int cnt;
int p[11100];

void back_track(int len, int sum) {
    if(cnt == 0) return;
    if(len == 1 && p[0] == 0) return;
    if(sum < 0) return;
    if(len == limit) {
        if(sum > 0) return;
        cnt--;
        if(cnt == 0) {
            for(int i = 0; i < len; i++) printf("%d",p[i]);
            printf("\n");
        }
        return;
    }
    for(int i = 0; i < 10; i++) {
        p[len] = i;
        back_track(len + 1, sum - i);
    }
}

int main() {
    int k;
    scanf("%d",&k);
    cnt = k;
    for(int d = 2; ; d++) {
        limit = d;
        back_track(0, 10);
        if(cnt == 0) break;
    }
    return 0;
}
