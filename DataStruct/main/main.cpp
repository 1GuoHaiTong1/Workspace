#include<iostream>
#include "../include/List.h"

int main()
{
    List<int> list;
    std::vector<int> arr = {1,2,3,4,5};
    list.CreateListHeadInsert(arr);
    list.PrintList();
    list.DestroyList();
    list.PrintList();
    return 0;
}