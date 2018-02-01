#include <cstdio>

struct Node {
    int valid; // is valid string?
    int nxt[256]; // next link, or edge
    Node() { // constructor
        valid = 0;
        for(int i = 0; i < 256; i++) nxt[i] = -1;
    }
};

int m;
Node node[100010];

void create(char *str, int cur) {
    if(*str == '\0') {
        node[cur].valid = 1;
        return;
    }
    if(node[cur].nxt[*str] == -1) node[cur].nxt[*str] = m++; // if next link is NULL, make new node!
    create(str + 1, node[cur].nxt[*str]);
}

void clear(int cur) { // use DFS, and you must clear m = 0!!!
    for(int i = 0; i < 256; i++) {
        if(node[cur].nxt[i] != -1) clear(node[cur].nxt[i]);
        node[cur].nxt[i] = -1;
    }
}

bool find(char *str, int cur) {
    if(*str == '\0') return node[cur].valid == 1;
    
    if(node[cur].nxt[*str] == -1) return false; // no link!
    return find(str + 1, node[cur].nxt[*str]); // link exist so, we will search!
}

bool is_clear(int cur) { // no link, that node
    for(int i = 0; i < 256; i++) if(node[cur].nxt[i] != -1) return false;
    return true;
}

bool erase(char *str, int cur) {
    if(*str == '\0') {
        if(node[cur].valid) {
            node[cur].valid = 0;
            if(is_clear(cur)) return true;
            return false;
        }
        printf("there is no string!\n"); // Gardien
        return false;
    }
    if(node[cur].nxt[*str] == -1) {
        printf("there is no string!\n"); // Gardien
        return false;
    }
    if(erase(str + 1, node[cur].nxt[*str])) { // if delete link node
        node[cur].nxt[*str] = -1; // link is will -1
        if(is_clear(cur)) return true;
        return false;
    }
    return false;
}

int main() {
    int Root = m++;
    
    create("App", Root);
    create("Apple", Root);
    create("ApplePie", Root);
    create("Application", Root);
    create("Pie", Root);
    create("Python", Root);
    create("Ruby", Root);
    
    printf("%d\n", find("App", Root));
    printf("%d\n", find("app", Root));
    printf("%d\n", find("AppLe", Root));
    printf("%d\n", find("Apple", Root));
    printf("%d\n", find("ApplePie", Root));
    printf("%d\n", find("Python", Root));
    
    printf("\n");
    
    erase("app", Root);
    erase("App", Root);
    erase("Application", Root);
    
    printf("%d\n", find("Application", Root));
    printf("%d\n", find("App", Root));
    printf("%d\n", find("Apple", Root));
    
    printf("\n");
    clear(Root);
    m = 0;
    
    Root = m++;
    printf("%d\n", find("Apple", Root));
    
    return 0;
}
