#include <stdio.h>
#include <stdlib.h>

class ArrayList {
private:
    int _size;
    int _capacity;
    int *ptr;
public:
    // Constructor
    ArrayList() { ptr = new int[1]; _capacity = 1; _size = 0; }
    ArrayList(int n) {
        _capacity = n;
        _size = n;
        ptr = new int[n];
        for(int i = 0; i < n; i++) ptr[i] = 0;
    }
    ArrayList(int n, int val) {
        _capacity = n;
        _size = n;
        ptr = new int[n];
        for(int i = 0; i < n; i++) ptr[i] = val;
    }
    ~ArrayList() {
        delete []ptr;
        ptr = NULL;
    }
    
    int& operator[] (int i) {
        /*if(i >= _size) {
         printf("Bad Access!\n");
         exit(1);
         }*/
        return ptr[i];
    }
    
    void push_back(int val) {
        if(_size == _capacity) {
            _capacity *= 2;
            
            int *newptr = new int[_capacity];
            for(int i = 0; i < _size; i++) {
                newptr[i] = ptr[i];
                ptr[i] = 0;
            }
            
            delete []ptr;
            ptr = NULL;
            
            ptr = newptr;
        }
        ptr[_size++] = val;
    }
    
    void pop_back() {
        /*if(_size == 0) {
         printf("Nothing Figure!\n");
         exit(0);
         }*/
        ptr[--_size] = 0;
    }
    
    const int back() {
        /*if(_size == 0) {
         printf("Size is zero!\n");
         exit(0);
         }*/
        return ptr[_size - 1];
    }
    
    const int size() {
        return _size;
    }
    
    const bool empty() {
        return _size == 0;
    }
    
    void clear() {
        for(int i = 0; i < _size; i++) ptr[i] = 0;
        _size = 0;
    }
    
    void capacity_clear() {
        delete []ptr;
        ptr = new int[1];
        ptr[0] = 0;
        _size = 0;
        _capacity = 1;
    }
};

int main() {
    // push_back, pop_back example
    ArrayList A;
    A.push_back(4);
    A.push_back(6);
    A.push_back(3);
    printf("%d\n",A[1]);
    printf("%d %d\n", A.size(), A.back());
    A.pop_back();
    printf("%d %d\n", A.size(), A.back());
    
    
    //constructor example
    ArrayList B(100), C(100, 32);
    printf("%d\n",B[90]);
    printf("%d\n",C[31]);
    printf("%d %d\n",B.size(), C.size());
    
    //clear example
    C.clear();
    printf("%d\n",C.size());
    
    // memory leak test
    {
        ArrayList A;
        for(int i = 0; i < 1000000; i++) A.push_back(i + 1);
        //A.capacity_clear();
    }
    for(int i = 0; i < 1000000; i++) A.push_back(i + 1);
    
    return 0;
}
