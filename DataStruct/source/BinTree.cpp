#include "../include/BinTree.h"

template <typename T>
BinTree<T>::BinTree()
{
    mRoot = nullptr;
}
template <typename T>
BinTree<T>::~BinTree()
{
    DestroyTree(mRoot);
}
template <typename T>
void BinTree<T>::DestroyTree(TreeNode *root)
{
    if (!root)
        return;
    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
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
        return true;
    }
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
            TreeNode *tempNode = FindLeftNode(root->left);
            root->val = tempNode->val;
            root->left = DeleteNode(root->left, tempNode->val);
        }
    }
    return root;
}
template <typename T>
void BinTree<T>::Delete(T value)
{
    if (!mRoot)
        return;
    mRoot = DeleteNode(mRoot, value);
}
template <typename T>
void BinTree<T>::PreorderTraversalIteration(TreeNode *root)
{
    if (!root)
        return;
    std::vector<TreeNode *> st;
    st.push_back(root);
    while (st.size())
    {
        TreeNode *tempNode = st.back();
        st.pop_back();
        std::cout << tempNode->val << " ";
        if (tempNode->right)
            st.push_back(tempNode->right);
        if (tempNode->left)
            st.push_back(tempNode->left);
    }
    std::cout << std::endl;
}
template <typename T>
void BinTree<T>::InorderTraversalIteration(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *node = root;
    std::vector<TreeNode *> st;
    while (st.size() || node)
    {
        if (node)
        {
            st.push_back(node);
            node = node->left;
        }
        else
        {
            node = st.back();
            st.pop_back();
            std::cout << node->val << " ";
            node = node->right;
        }
    }
    std::cout << std::endl;
}
template <typename T>
void BinTree<T>::PostorderTraversalIteration(TreeNode *root)
{
    if (!root)
        return;
    std::vector<T> result;
    std::vector<TreeNode *> st;
    st.push_back(root);
    while (st.size())
    {
        TreeNode *node = st.back();
        result.push_back(node->val);
        st.pop_back();
        if (node->left)
            node = node->left;
        if (node->right)
            node = node->right;
    }
    reverse(result.begin(), result.end());
    for (auto res : result)
    {
        std::cout << res << " ";
    }
    std::cout << std::endl;
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
        std::cout << std::endl;
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
        PreorderTraversalIteration(mRoot);
        break;
    case Inorder_TraversalIterate:
        InorderTraversalIteration(mRoot);
        break;
    case Postorder_TraversalIterate:
        PostorderTraversalIteration(mRoot);
        break;
    default:
        break;
    }
}