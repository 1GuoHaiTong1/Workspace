#include "../include/BSTree.h"

template <typename T>
BSTree<T>::BSTree()
{
    mRoot = nullptr;
}
template <typename T>
BSTree<T>::BSTree(T value)
{
    mRoot = new BSTreeNode(value);
}
template <typename T>
BSTree<T>::~BSTree()
{
}
template <typename T>
typename BSTree<T>::BSTreeNode *BSTree<T>::Insert(T value, BSTreeNode *root)
{
    if (!root)
        return new BSTreeNode(value);
    if (root->value > value)
        root->left = Insert(value, root->left);
    else if (root->value < value)
        root->right = Insert(value, root->right);
    else
        return root;
    UpdateHeight(root);
    int balanceFactor = GetBalanceFactor(root);
    // 左左
    if (balanceFactor > 1 && GetBalanceFactor(root->left) > 0)
    {
        return RightRotate(root);
    }
    else if (balanceFactor < -1 && GetBalanceFactor(root->right) < 0)
    {
        return LeftRotate(root);
    }
    else if (balanceFactor > 1 && GetBalanceFactor(root->left) < 0)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    else if (balanceFactor < -1 && GetBalanceFactor(root->left) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

template <typename T>
typename BSTree<T>::BSTreeNode *BSTree<T>::Delete(T value, BSTreeNode *root)
{
    if (!root)
        return root;
    if (value < root->value)
    {
        root->left = Delete(value, root->left);
    }
    else if (value > root->value)
    {
        root->right = Delete(value, root->right);
    }
    else
    {
        if (!root->right && !root->left)
        {
            delete root;
            root = nullptr;
            return root;
        }
        else if (!root->left || !root->right)
        {
            BSTreeNode *node = root->left ? root->left : root->right;
            *root = *node;
            delete node;
            node = nullptr;
        }
        else
        {
            // find left subtree min node
            BSTreeNode *node = FindMinNode(root->right);
            root->value = node->value;
            root->right = Delete(node->value,root->right);
        }
    }
    UpdateHeight(root);
    int balanceFactor = GetBalanceFactor(root);
    if (balanceFactor > 1 && GetBalanceFactor(root->left) > 0)
    {
        return RightRotate(root);
    }
    else if (balanceFactor < -1 && GetBalanceFactor(root->right) < 0)
    {
        return LeftRotate(root);
    }
    else if (balanceFactor > 1 && GetBalanceFactor(root->left) < 0)
    {
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    else if (balanceFactor < 1 && GetBalanceFactor(root->right) > 0)
    {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}
template <typename T>
typename BSTree<T>::BSTreeNode *BSTree<T>::Search(T value, BSTreeNode *root)
{
    if(!root)
        return root;
    if(value > root->value)
        return Search(value, root->right);
    else if(value < root->value)
        return Search(value, root->left);
    else
        return root;
}