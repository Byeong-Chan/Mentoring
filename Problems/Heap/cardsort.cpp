#include <stdio.h>

class heap {
public:
    heap() { ptr = new int[2]; _size = 0, _capacity = 1; }
    ~heap() { delete ptr; }
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void push(int val) {
        if(_size == _capacity) {
            int *newptr = new int[(_capacity << 1) + 1];
            for(int i = 1; i <= _capacity; i++) newptr[i] = ptr[i];
            _capacity <<= 1;
            delete []ptr;
            ptr = newptr;
        }
        
        ptr[++_size] = val;
        int cur = _size;
        while(cur > 1) {
            if(ptr[cur] < ptr[cur >> 1]) swap(ptr[cur], ptr[cur >> 1]);
            else break;
            
            cur >>= 1;
        }
    }
    void pop() {
        if(_size == 0) return;
        
        swap(ptr[_size], ptr[1]);
        ptr[_size--] = 0;
        if(_size == 0) return;
        int cur = 1;
        while(1) {
            int l = cur << 1;
            int r = l + 1;
            if(r > _size && l > _size) break;
            if(r > _size && ptr[l] < ptr[cur]) {
                swap(ptr[cur], ptr[l]);
                cur = l;
                continue;
            }
            if(r > _size) break;
            int tmp = l;
            if(ptr[l] > ptr[r]) tmp = r;
            
            if(ptr[tmp] < ptr[cur]) {
                swap(ptr[cur], ptr[tmp]);
                cur = tmp;
                continue;
            }
            break;
        }
    }
    int top() {
        return ptr[1];
    }
    int size() {
        return _size;
    }
    bool empty() {
        return _size == 0;
    }
    void clear() {
        for(int i = 1; i <= _size; i++) ptr[i] = 0;
        _size = 0;
    }
private:
    int *ptr;
    int _size = 0;
    int _capacity;
};

int main() {
    int n;
    scanf("%d",&n);
    heap pq;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        pq.push(x);
    }
    int sum = 0;
    while(pq.size() > 1) {
        int x;
        int y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        sum += x + y;
        pq.push(x + y);
    }
    printf("%d",sum);
    return 0;
}
