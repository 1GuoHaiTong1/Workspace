#include <iostream>
#include "../include/List.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
int main()
{
    List<int> list;
    std::vector<int> arr = {1, 2, 3, 4, 5};
    list.CreateListHeadInsert(arr);
    list.PrintList();
    list.DestroyList();
    list.PrintList();
    // Stack<int> stack;
    // stack.Top();
    Queue<int> queue;
    queue.Push(1);
    int a = queue.Front();
    std::cout << "a = " << a << std::endl;
    return 0;
}