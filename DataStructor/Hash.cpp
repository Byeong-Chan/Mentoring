#include <cstdio>
#include <cstring>

#include <vector> // ArrayList

using namespace std;

const int mod = 300007; // prime !!!

int Hash(char *str) {
    int sum = 0; // = 371;   you can use salt!
    while(*str != '\0') {
        sum = ((sum << 8) + sum + *str) % mod; // sum * 257 + *str
        str++;
    }
    return sum;
}

vector<int> hashtable[300007]; // Hash Table

char o[31][36];

int main() {
    printf("%d\n",Hash("Hello"));
    printf("%d\n",Hash("Hi"));
    printf("%d\n",Hash("Cash"));
    printf("%d\n",Hash("ababc"));
    printf("%d\n",Hash("banana"));
    printf("%d\n",Hash("Hello"));
    
    hashtable[Hash("Hello")].push_back(1);
    strcpy(o[1], "Hello");
    hashtable[Hash("Hi")].push_back(2);
    strcpy(o[2], "Hi");
    hashtable[Hash("Cash")].push_back(3);
    strcpy(o[3], "Cash");
    
    int tmp = Hash("Cash");
    if(hashtable[tmp].size() > 0) {
        for(int i = 0; i < hashtable[tmp].size(); i++) {
            printf("%s\n", o[hashtable[tmp][i]]);
        }
    }
    return 0;
}
