#include <iostream>
#include <cstring>
template <typename T>
class Queue
{
public:
    struct Node
    {
        T value;
        Node *next;
        Node(T val) : value(val), next(nullptr) {}
    };
    Queue();
    ~Queue();
    void Push(T value);
    bool Pop();
    T Front();
    T Back();

private:
    Node *mFront;
    Node *mRear;
};
template class Queue<int>;