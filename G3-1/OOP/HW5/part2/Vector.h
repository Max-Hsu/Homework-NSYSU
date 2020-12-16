#ifndef __MY_VECTOR__
#define __MY_VECTOR__
#include <iostream>
#include "Trace.h"

using namespace std;

int void_star_counter = 1;

template <class T>
class vector{
private:
    T *v;
    int sz;
public:
    vector(){
        TRACE(dummy, "vector<T>::vector(int)");
        v = nullptr;
        sz = -1;
        cout<<"\tcount = "<<void_star_counter<< endl;
    }
    vector(int size){
        TRACE(dummy, "vector<T>::vector(int)");
        v = new T[size];
        sz = size;
        cout<<"\tcount = "<<void_star_counter<< endl;
    }
    ~vector(){
        TRACE(dummy, "vector<T>::~vector");
        delete [] v;
        v = nullptr;
        sz = -1;
        cout<<"\tcount = "<<void_star_counter<< endl;
    }

    T &elem(int i){
        return v[i];
    }
    T &operator[](int i){
        return v[i];
    }
};

template <>
class vector<void *>
{
private:
    void **v;
    int sz;
public:
    vector(){
        TRACE(dummy, "vector<void*>::vector(int)");
        v = nullptr;
        sz = -1;
        cout<<"\tcount = "<<void_star_counter<<endl;
        void_star_counter+=1;
    }
    explicit vector(int i){
        TRACE(dummy, "vector<void*>::vector(int)");
        v = new void* [i];
        sz = i;
        cout<<"\tcount = "<<void_star_counter<<endl;
        void_star_counter += 1;
    }
    ~vector(){
        TRACE(dummy, "vector<void*>::~vector");
        delete [] v;
        v = nullptr;
        sz = -1;
        void_star_counter -= 1;
        cout<<"\tcount = "<<void_star_counter<<endl;
    }
    void *&elem(int i){
        return static_cast<void *&>(v[i]);
    }
    void *&operator[](int i){
        return static_cast<void *&>(v[i]);
    }
};

template <class T>
class vector<T *> : private vector<void *>
{
private:
    T **v;
    int sz;
public:
    vector(){
        TRACE(dummy, "vector<T*>::vector(int)");
        v = nullptr;
        sz = -1;
    }
    explicit vector(int i){
        TRACE(dummy, "vector<T*>::vector(int)");
        v = new T* [i];
        sz = i;
    }
    ~vector(){
        TRACE(dummy, "vector<T*>::~vector");
        delete [] v;
        v = nullptr;
        sz = -1;
    }

    T *&elem(int i){
        return static_cast<T *&>(v[i]);
    }
    T *&operator[](int i){
        return static_cast<T *&>(v[i]);
    }
};

#endif
