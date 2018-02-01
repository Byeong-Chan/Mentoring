#include <stdio.h>
int n, k;
char arr[15];
char c[15];
char moum[6] = "aeiou";
void func(int index, int b) {
    if(index == k) {
        int mo = 0, za = 0;
        for(int i = 0; i < k; i++) {
            int flag = 0;
            for(int j = 0; j < 5; j++) if(moum[j] == c[i]) flag = 1;
            mo += flag;
            za += 1 - flag;
        }
        if(mo < 1 || za < 2) return;
        for(int i = 0; i < k; i++) printf("%c",c[i]);
        printf("\n");
        return;
    }
    for(int i = b; i < n; i++) {
        c[index] = arr[i];
        func(index + 1, i + 1);
        c[index] = 0;
    }
}
int main() {
    scanf("%d %d",&k,&n);
    for(int i = 0; i < n; i++) scanf(" %c",&arr[i]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                char tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    func(0, 0);
    return 0;
}