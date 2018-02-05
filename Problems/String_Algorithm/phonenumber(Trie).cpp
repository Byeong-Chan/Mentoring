#include <cstdio>

struct Node {
    int valid;
    Node *nxt[10];
    Node() {
        valid = 0;
        for(int i = 0; i < 10; i++) nxt[i] = NULL; 
    }
};

void create(char *str, Node *cur) {
    if(*str == '\0') {
        cur->valid = 1;
        return;
    }
    if(cur->nxt[*str - '0'] == NULL) cur->nxt[*str - '0'] = new Node;
    create(str + 1, cur->nxt[*str - '0']);
}

bool dfs(Node *cur) {
    int flag = 0;
    bool impossible = false;
    if(cur->valid == 1) flag = 1;
    for(int i = 0; i < 10; i++) {
        if(cur->nxt[i] == NULL) continue;
        if(flag) impossible = true;
        if(dfs(cur->nxt[i])) impossible = true;
    }
    delete cur;
    return impossible;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        char o[11];
        Node *Root = new Node;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            scanf("%s",o);
            create(o, Root);
        }
        if(dfs(Root)) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}