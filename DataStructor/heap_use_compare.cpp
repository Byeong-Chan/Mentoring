#include <stdio.h>

class heap {
public:
    heap() { ptr = new long long[2]; _size = 0, _capacity = 1; }
    ~heap() { delete ptr; }
    long long abs(long long x) {
        if(x < 0) return -x;
        return x;
    }
    int compare(long long x, long long y) { // Absolute heap, using compare function.
        if(abs(x) < abs(y)) return -1;
        if(abs(x) > abs(y)) return 1;
        if(x < y) return -1;
        if(x > y) return 1;
        return 0;
    }
    void swap(long long &a, long long &b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    void push(long long val) {
        if(_size == _capacity) {
            long long *newptr = new long long[(_capacity << 1) + 1];
            for(int i = 1; i <= _capacity; i++) newptr[i] = ptr[i];
            _capacity <<= 1;
            delete []ptr;
            ptr = newptr;
        }
        
        ptr[++_size] = val;
        int cur = _size;
        while(cur > 1) {
            if(compare(ptr[cur], ptr[cur >> 1]) < 0) swap(ptr[cur], ptr[cur >> 1]);
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
            if(r > _size && compare(ptr[l], ptr[cur]) < 0) {
                swap(ptr[cur], ptr[l]);
                cur = l;
                continue;
            }
            if(r > _size) break;
            int tmp = l;
            if(compare(ptr[r], ptr[l]) < 0) tmp = r;
            
            if(compare(ptr[tmp], ptr[cur]) < 0) {
                swap(ptr[cur], ptr[tmp]);
                cur = tmp;
                continue;
            }
            break;
        }
    }
    long long top() {
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
    long long *ptr;
    int _size = 0;
    int _capacity;
};

int main() {
    int n;
    scanf("%d",&n);
    heap pq;
    for(int i = 0; i < n; i++) {
        long long x;
        scanf("%lld",&x);
        if(x == 0) {
            if(pq.empty()) printf("0\n");
            else {
                printf("%lld\n",pq.top());
                pq.pop();
            }
            continue;
        }
        pq.push(x);
    }
    return 0;
}
