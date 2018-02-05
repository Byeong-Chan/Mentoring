#include <cstdio>
#include <cstring>

int fail[1000010]; // failure function
char o[1000010]; // String
char u[1000010]; // Patern

void make_fail(int m) { // make failure function with Patern
    int i = -1;
    int j = 0;
    fail[j] = i;
    while(j < m) {
        if(i < 0) { // if i equal -1
            i++;
            j++;
            fail[j] = i; // fail(j) <- i !!
        }
        else if(u[i] == u[j]) { // i > 0 && u[i] == u[j]
            i++;
            j++;
            fail[j] = i; // fail(j) <- i !!
        }
        else {
            i = fail[i]; // i > 0 && u[i] != u[j], goto failure funtion
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
            i = fail[i]; // goto failure funtion
        }
        if(i == m) {
            printf("find %d!\n", j - m); // 0-base
            // i = fail[i];    // if using all of char, then erase "u[m] = '#';" and adding this line.
        }
    }
}

int main() {
    int n, m;
    
    strcpy(o, "ananabanabananabanana");
    strcpy(u, "banana");
    
    n = strlen(o);
    m = strlen(u);
    
    make_fail(m);
    match(n, m);
    
    return 0;
}
