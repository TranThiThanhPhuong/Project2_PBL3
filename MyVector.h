#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;
template <class T>
class MyVector {
private:
    int size;
    T* data;

public:
    MyVector();
    ~MyVector();

    int getSize() const;
    bool isEmpty() const;
    void clear();
    void pushBack(const T&);
    void popBack();
    T& at(int );
    const T& at(int ) const;
    // void insert(int , const T& value);
    void remove(const int);
    // void resize(int newCapacity);
    T& operator[](const int& ) ;
    void print() const;
    bool contains(const T&) const ;
    MyVector<T>& operator=(const MyVector<T>&);
    
};

// ... Rest of your template implementation

#endif // MYVECTOR_H
