#include "../include/Heap.h"

template <typename U>
Heap<U>::Heap()
{
    mHeap.resize(0);
    mFlag = false;
}
template <typename U>
Heap<U>::Heap(std::vector<U> heap,int flag)
{
    mHeap = heap;
    mFlag = flag;
}
template <typename U>
Heap<U>::~Heap()
{
    mHeap.clear();
}
template <typename U>
void Heap<U>::HeapifyUp(int index)
{
    if(index < 0)
        return;
    int parentIndex = (index - 1) / 2;
    if(mFlag)
    {
        if(parentIndex >= 0 && mHeap[parentIndex] < mHeap[index])
        {
            Swap(mHeap[parentIndex],mHeap[index]);
            HeapifyUp(parentIndex);
        }
    }else
    {
        if(parentIndex >= 0 && mHeap[parentIndex] > mHeap[index])
        {
            Swap(mHeap[parentIndex],mHeap[index]);
            HeapifyUp(parentIndex);
        }
    }
    
}
template <typename U>
void Heap<U>::Heapify(int index)
{
    if (index >= mHeap.size())
        return;
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int poleindex = index;
    if (mFlag)
    {
        if (left < mHeap.size() && mHeap[poleindex] < mHeap[left])
        {
            poleindex = left;
        }
        if (right < mHeap.size() && mHeap[poleindex] < mHeap[right])
        {
            poleindex = right;
        }
        if (poleindex < mHeap.size() && index != poleindex)
        {
            Swap(mHeap[index], mHeap[poleindex]);
            Heapify(poleindex);
        }
    }
    else
    {
        if (left < mHeap.size() && mHeap[poleindex] > mHeap[left])
        {
            poleindex = left;
        }
        if (right < mHeap.size() && mHeap[poleindex] > mHeap[right])
        {
            poleindex = right;
        }
        if (poleindex < mHeap.size() && index != poleindex)
        {
            Swap(mHeap[index], mHeap[poleindex]);
            Heapify(poleindex);
        }
    }
}
template <typename U>
void Heap<U>::Swap(U &a, U &b)
{
    U temp = a;
    a = b;
    b = temp;
}
template <typename U>
void Heap<U>::PushBack(U ele)
{
    mHeap.push_back(ele);
    CreateHeap();
}
template <typename U>
void Heap<U>::PopBack()
{
    mHeap[0] = mHeap.back();
    mHeap.pop_back();
    Heapify(0);
}
template <typename U>
void Heap<U>::CreateHeap()
{
    for(int index = mHeap.size()/2-1;index >= 0;index--)
    {
        Heapify(index);
    }
}
template <typename U>
void Heap<U>::HeapSort()
{
    CreateHeap();
    std::vector<U> ans;
    for(int i = mHeap.size()-1;i>=0;i--)
    {
        Swap(mHeap[0],mHeap[i]);
        ans.push_back(mHeap.back());
        mHeap.pop_back();
        Heapify(0);
    }
    mHeap = ans;
}
template <typename U>
void Heap<U>::PrintHeap()
{
    for(auto ele : mHeap)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}
