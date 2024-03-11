#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
template <typename T>
class Stack
{
public:
    Stack();
    Stack(int size);
    ~Stack();
    bool Push(T value);
    bool Pop();
    bool Empty();
    T Top();
    uint Size();

private:
    uint mIndex;
    T *mTop;
    uint32_t mSize;
};

template class Stack<int>;