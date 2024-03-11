#include "../include/Stack.h"

template <typename T>
Stack<T>::Stack()
{
    mSize = 1024;
    mIndex = 0;
    T *p = new T[mSize];
    memset(p, 0, 1024);
    mTop = p;
}
template <typename T>
Stack<T>::Stack(int size)
{
    mSize = size;
    mIndex = 0;
    T *p = new T[size];
    memset(p, 0, size);
    mTop = p;
}
template <typename T>
Stack<T>::~Stack()
{
    delete[] mTop;
}
template <typename T>
bool Stack<T>::Empty()
{
    if (mIndex <= 0)
        return true;
    else
        return false;
}
template <typename T>
bool Stack<T>::Push(T value)
{
    if (mIndex >= mSize)
    {
        std::cout << "stack is full..." << std::endl;
        return false;
    }
    mTop[mIndex] = value;
    mIndex++;
    return true;
}
template <typename T>
bool Stack<T>::Pop()
{
    if (Empty())
    {
        std::cout << "stack is empty..." << std::endl;
        return false;
    }
    mIndex--;
    return true;
}
template <typename T>
T Stack<T>::Top()
{
    if (Empty())
    {
        throw std::runtime_error("Stack is empty");
    }
    return mTop[mIndex - 1];
}
template <typename T>
uint Stack<T>::Size()
{
    return mIndex;
}