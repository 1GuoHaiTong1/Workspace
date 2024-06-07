#include <iostream>
#include <vector>

template<typename U>
class Heap
{
public:
    Heap();
    Heap(std::vector<U> heap,int flag = false);
    ~Heap();
    void PushBack(U ele);
    void PopBack();
    void HeapSort();
    void PrintHeap();
private:
    void CreateHeap();
    void Heapify(int index);
    void HeapifyUp(int index);
    void Swap(U &a, U &b);
    bool mFlag;
    std::vector<U> mHeap;
};
template class Heap<int>;