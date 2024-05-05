#include <iostream>
#include "../include/List.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/BinTree.h"

int main()
{
    // List<int> list;
    // std::vector<int> arr = {1, 2, 3, 4, 5};
    // list.CreateListHeadInsert(arr);
    // list.PrintList();
    // list.DestroyList();
    // list.PrintList();
    // Stack<int> stack;
    // stack.Top();
    // Queue<int> queue;
    // queue.Push(1);
    // int a = queue.Front();
    // std::cout << "a = " << a << std::endl;
    BinTree<char> tree;
    std::vector<char> treearr = {'1', '2', '*', '3', '*', '*', '4', '5', '*', '*', '*'};
    tree.CreateTree(treearr);
    tree.Print(BinTree<char>::Preorder_TraversalIterate);
    tree.Search('5');
    tree.Delete('1');
    tree.Print(BinTree<char>::Inorder_TraversalIterate);
    return 0;
}