#include "../include/Queue.h"

template <typename T>
Queue<T>::Queue()
{
    mRear = nullptr;
    mFront = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while (mRear != mFront)
    {
        Node *tempFront = mFront;
        mFront = mFront->next;
        delete tempFront;
    }
    if (mRear == mFront && mFront)
    {
        delete mRear;
    }
}
template <typename T>
void Queue<T>::Push(T value)
{
    if (!mRear && !mFront)
    {
        mRear = mFront = new Node(value);
    }
    else
    {
        mRear->next = new Node(value);
        mRear = mRear->next;
    }
}
template <typename T>
bool Queue<T>::Pop()
{
    if (!mFront)
        throw std::runtime_error("Queue is empty");
    return false;
    Node *tempFront = mFront;
    mFront = mFront->next;
    delete tempFront;
    return true;
}
template <typename T>
T Queue<T>::Front()
{
    if (!mFront)
        throw std::runtime_error("Queue is empty");
    return mFront->value;
}
template <typename T>
T Queue<T>::Back()
{
    if (mRear)
        throw std::runtime_error("Queue is empty");
    return mRear->value;
}