#include <cstdio>

struct Node {
    int valid; // is valid string?
    Node *nxt[256]; // next link, or edge
    Node() { // constructor
        valid = 0;
        for(int i = 0; i < 256; i++) nxt[i] = NULL;
    }
};

void create(char *str, Node *cur) {
    if(*str == '\0') {
        cur->valid = 1;
        return;
    }
    if(cur->nxt[*str] == NULL) cur->nxt[*str] = new Node; // if next link is NULL, make new node!
    create(str + 1, cur->nxt[*str]);
}

void clear(Node *cur) { // use DFS
    for(int i = 0; i < 256; i++) if(cur->nxt[i] != NULL) clear(cur->nxt[i]);
    delete cur;
}

bool find(char *str, Node *cur) {
    if(*str == '\0') return cur->valid == 1;
    
    if(cur->nxt[*str] == NULL) return false; // no link!
    return find(str + 1, cur->nxt[*str]); // link exist so, we will search!
}

bool is_clear(Node *cur) { // no link, that node
    for(int i = 0; i < 256; i++) if(cur->nxt[i] != NULL) return false;
    return true;
}

bool erase(char *str, Node *cur) {
    if(*str == '\0') {
        if(cur->valid) {
            cur->valid = 0;
            if(is_clear(cur)) {
                delete cur; // will delete, because that is not necessary
                return true;
            }
            return false;
        }
        printf("there is no string!\n"); // Gardien
        return false;
    }
    if(cur->nxt[*str] == NULL) {
        printf("there is no string!\n"); // Gardien
        return false;
    }
    if(erase(str + 1, cur->nxt[*str])) { // if delete link node
        cur->nxt[*str] = NULL; // link is will NULL
        if(is_clear(cur)) {
            delete cur;
            return true;
        }
        return false;
    }
    return false;
}

int main() {
    Node *Root = new Node;
    
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
    
    printf("%d\n", find("Apple", Root));
    
    return 0;
}
