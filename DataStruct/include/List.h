#include <vector>
#include <iostream>

template <typename T>
struct Node
{
    T val;
    Node<T> *next;
    Node(T value) : val(value), next(nullptr) {}
};
template <typename T>
class List
{
public:
    List() { mHead = nullptr; }
    ~List() {DestroyList();}
    void CreateListHeadInsert(std::vector<T> arr);
    void CreateListTailInsert(std::vector<T> arr);
    void PrintList();
    void DestroyList();
private:
    Node<T> *mHead;
};
template class List<int>;