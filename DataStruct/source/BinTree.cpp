#include "../include/BinTree.h"

template <typename T>
BinTree<T>::BinTree()
{
    mRoot = nullptr;
}
template <typename T>
BinTree<T>::~BinTree()
{
}
template <typename T>
void BinTree<T>::DestroyTree()
{
}
template <typename T>
typename BinTree<T>::TreeNode *BinTree<T>::Create(std::vector<T> arr, TreeNode *root, int &index)
{
    if (index >= arr.size())
        return nullptr;
    if (arr[index] == '*')
        return nullptr;
    root = new TreeNode(arr[index]);
    root->left = Create(arr, root->left, ++index);
    root->right = Create(arr, root->right, ++index);
    return root;
}
template <typename T>
void BinTree<T>::CreateTree(std::vector<T> arr)
{
    if (arr.size() > 0)
    {
        int index = 0;
        mRoot = Create(arr, mRoot, index);
    }
    else
        return;
}
template <typename T>
typename BinTree<T>::TreeNode *BinTree<T>::Find(TreeNode *root, T value)
{
    if (!root || root->val == value)
    {
        return root;
    }
    return Find(root->left, value) ? Find(root->left, value) : Find(root->right, value);
}
template <typename T>
bool BinTree<T>::Search(T value)
{
    TreeNode *tempNode = Find(mRoot, value);
    std::cout << "find node addr " << tempNode << std::endl;
    if (tempNode)
    {
        std::cout << "node value " << tempNode->val << std::endl;
    }
    if (tempNode)
        return true;
    return false;
}
template <typename T>
typename BinTree<T>::TreeNode *BinTree<T>::FindLeftNode(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return root;

    TreeNode *leftNode = FindLeftNode(root->left);
    TreeNode *rightNode = FindLeftNode(root->right);
    return leftNode ? leftNode : rightNode;
}
template <typename T>
typename BinTree<T>::TreeNode *BinTree<T>::DeleteNode(TreeNode *root, T value)
{
    if (!root)
        return root;
    if (root->val != value)
    {
        root->left = DeleteNode(root->left, value);
        root->right = DeleteNode(root->right, value);
    }
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left && !root->right)
        {
            TreeNode *tempNode = root;
            root = root->left;
            delete tempNode;
        }
        else if (!root->left && root->right)
        {
            TreeNode *tempNode = root;
            root = root->right;
            delete tempNode;
        }
        else
        {
           TreeNode*tempNode =  FindLeftNode(root->left);
           root->val = tempNode->val;
           root->left = DeleteNode(root->left,tempNode->val);
        }
    }
    return root;
}
template <typename T>
void BinTree<T>::Delete(T value)
{
    if(!mRoot)
        return;
    mRoot = DeleteNode(mRoot,value);
}
template <typename T>
void BinTree<T>::PreorderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->val << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
template <typename T>
void BinTree<T>::InorderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    PreorderTraversal(root->left);
    std::cout << root->val << " ";
    PreorderTraversal(root->right);
}
template <typename T>
void BinTree<T>::PostorderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    std::cout << root->val << " ";
}
template <typename T>
void BinTree<T>::LevelorderTaversal(TreeNode *root)
{
    std::queue<BinTree<T>::TreeNode *> qu;
    if (root)
        qu.push(root);
    while (qu.size())
    {
        int size = qu.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *tempNode = qu.front();
            qu.pop();
            std::cout << tempNode->val << " ";
            if (tempNode->left)
                qu.push(tempNode->left);
            if (tempNode->right)
                qu.push(tempNode->right);
        }
    }
}
template <typename T>
void BinTree<T>::Print(int TraversalMode)
{
    switch (TraversalMode)
    {
    case Preorder_Traversal:
        PreorderTraversal(mRoot);
        break;
    case Inorder_Traversal:
        InorderTraversal(mRoot);
        break;
    case Postorder_Traversal:
        PostorderTraversal(mRoot);
        break;
    case Levelorder_Taversal:
        LevelorderTaversal(mRoot);
        break;
    case Preorder_TraversalIterate:

        break;
    case Inorder_TraversalIterate:

        break;
    case Postorder_TraversalIterate:

        break;
    default:
        break;
    }
    std::cout<<std::endl;
}