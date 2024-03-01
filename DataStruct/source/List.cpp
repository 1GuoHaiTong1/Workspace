#include "../include/List.h"
template <typename T>
List<T>::~List()
{
    DestroyList(mHead);
}
template <typename T>
void List<T>::CreateListHeadInsert(std::vector<T> arr)
{
    for (auto ele : arr)
    {
        Node<T> *tempNode = new Node(ele);
        tempNode->next = mHead;
        mHead = tempNode;
    }
}
template <typename T>
void List<T>::CreateListTailInsert(std::vector<T> arr)
{
    if (!mHead && arr.size() > 0)
    {
        mHead = new Node(arr[0]);
    }
    Node<T> *preHead = mHead;
    for (int i = 1; i < arr.size(); i++)
    {
        Node<T> *tempNode = new Node(arr[i]);
        mHead->next = tempNode;
    }
}
template <typename T>
void List<T>::PrintList()
{
    Node<T> *tempHead = mHead;
    while (tempHead)
    {
        std::cout << tempHead->val << " -> ";
        tempHead = tempHead->next;
    }
    std::cout << "nullptr" << std::endl;
}
template <typename T>
void List<T>::DestroyList(Node<T> *head)
{
    if (!head)
        return;
    DestroyList(head->next);
    delete head;
}