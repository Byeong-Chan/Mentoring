#include <stdio.h>
#include <stdlib.h>

class List {
public:
    struct container {
        int _val;
        container* _prev;
        container* _next;
        container() {
            _val = 0;
            _prev = NULL;
            _next = NULL;
        }
        container* next() { return _next; }
        container* prev() { return _prev; }
        int get_val() { return _val; }
    };
    
    List() { _size = 0; _begin = _end = new container; }
    ~List() { clear(); delete _end; }
    
    int front() {
        /*if(_size == 0) {
         printf("front empty!\n");
         exit(0);
         }*/
        return _begin->_val;
    }
    int back() {
        /*if(_size == 0) {
         printf("back empty!\n");
         exit(0);
         }*/
        return _end->_prev->_val;
    }
    void push_front(int val) {
        container *new_container = new container;
        if(_size == 0) {
            _size++;
            _begin = new_container;
            _begin->_val = val;
            _begin->_next = _end;
            _end->_prev = _begin;
            return;
        }
        
        _size++;
        _begin->_prev = new_container;
        new_container->_next = _begin;
        new_container->_val = val;
        _begin = new_container;
    }
    void push_back(int val) {
        container *new_container = new container;
        if(_size == 0) {
            push_front(val);
            return;
        }
        
        _size++;
        _end->_prev->_next = new_container;
        new_container->_prev = _end->_prev;
        new_container->_next = _end;
        _end->_prev = new_container;
        new_container->_val = val;
    }
    void pop_front() {
        /*if(_size == 0) {
         printf("can't replace front!\n");
         exit(0);
         }*/
        
        if(_size == 1) {
            _size--;
            //_begin->_prev = NULL;
            //_begin->_next = NULL;
            delete _begin;
            //_end->_prev = NULL;
            _begin = _end;
            return;
        }
        
        _size--;
        container* sav = _begin->_next;
        
        //_begin->_prev = NULL;
        //_begin->_next = NULL;
        delete _begin;
        
        //sav->_prev = NULL;
        _begin = sav;
    }
    void pop_back() {
        /*if(_size == 0) {
         printf("can't replace back!\n");
         exit(0);
         }*/
        
        if(_size == 1) {
            pop_front();
            return;
        }
        
        _size--;
        container* sav = _end->_prev->_prev;
        
        //_end->_prev->_prev = NULL;
        //_end->_prev->_next = NULL;
        delete _end->_prev;
        
        _end->_prev = sav;
        sav->_next = _end;
    }
    void insert(container *it, int val) {
        /*if(it == NULL) {
         printf("NULL point exception\n");
         exit(0);
         }
         if(it == _end) {
         printf("end point adding!\n");
         exit(0);
         }*/
        
        _size++;
        container *new_container = new container;
        container *sav = it->_next;
        
        it->_next = new_container;
        new_container->_prev = it;
        
        sav->_prev = new_container;
        new_container->_next = sav;
        
        new_container->_val = val;
    }
    void erase(container *it) {
        /*if(it == NULL) {
         printf("NULL point exception\n");
         exit(0);
         }
         if(it == _end) {
         printf("end point erasing!\n");
         exit(0);
         }*/
        
        if(it == _begin) {
            pop_front();
            return;
        }
        
        _size--;
        container* sav1 = it->_prev;
        container* sav2 = it->_next;
        //it->_prev = NULL;
        //it->_next = NULL;
        delete it;
        
        sav1->_next = sav2;
        sav2->_prev = sav1;
    }
    container* find(int val) {
        for(container *it = _begin; it != _end ; it = it->_next) if(it->_val == val) return it;
        return _end;
    }
    container* findat(container *it, int val) {
        if(it == _end) return _end;
        for(it = it->_next; it != _end; it = it->_next) if(it->_val == val) return it;
        return _end;
    }
    container* begin() { return _begin; }
    container* end() { return _end; }
    int size() { return _size; }
    bool empty() { return _size == 0; }
    void clear() {
        _size = 0;
        container *it = _begin;
        while(it != _end) {
            container *sav = it->_next;
            delete it;
            it = sav;
        }
        _begin = _end;
        //_end->_prev = NULL;
    }
private:
    int _size;
    container* _begin;
    container* _end;
};

int main() {
    // push_back, push_front example
    List li;
    li.push_front(2);
    li.push_front(3);
    li.push_back(1);
    printf("%d %d %d\n",li.size(), li.back(), li.front());
    
    for(List::container *it = li.begin(); it != li.end(); it = it->next()) printf("%d ",it->get_val());
    printf("\n");
    
    // pop_back, pop_front example
    li.pop_front();
    li.pop_back();
    printf("%d %d\n",li.size(),li.front());
    
    for(List::container *it = li.begin(); it != li.end(); it = it->next()) printf("%d ",it->get_val());
    printf("\n");
    
    li.clear();
    
    // find example
    li.push_back(4);
    li.push_back(1);
    li.push_back(3);
    li.push_back(2);
    li.push_back(1);
    List::container *it = li.find(1);
    printf("%d %d\n", it->get_val(), (it->prev())->get_val());
    it = li.findat(it, 1);
    printf("%d %d\n", it->get_val(), (it->prev())->get_val());
    it = li.find(6);
    if(it == li.end()) printf("not find!\n");
    
    { // memory leak test
        List li;
        for(int i = 0; i < 1000000; i++) li.push_back(i+1);
    }
    
    return 0;
}
