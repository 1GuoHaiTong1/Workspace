#include <iostream>
template <typename T>
class BSTree
{
public:
    struct BSTreeNode
    {
        BSTreeNode *left;
        BSTreeNode *right;
        T value;
        int height;
        BSTreeNode(T val): value(val),height(1),left(nullptr),right(nullptr){}
    };
    BSTree();
    BSTree(T value);
    ~BSTree();
    void Print()
    {
        Print(mRoot);
        std::cout<<std::endl;
    }
    void Insert(T value)
    {
        mRoot =  Insert(value, mRoot);
    }
    void Delete(T value)
    {
        mRoot =  Delete(value, mRoot);
    }
    BSTreeNode* Search(T value)
    {
        return Search(value, mRoot);
    }
    
private:
    int GetHeight(BSTreeNode *root)
    {
        if(!root) return 0;
        return root->height;
    }
    void Print(BSTreeNode *root)
    {
        if(!root)
            return;
        Print(root->left);
        std::cout<<root->value<<" ";
        Print(root->right);
    }
    BSTreeNode* Insert(T value,BSTreeNode *root );
    BSTreeNode* Delete(T value,BSTreeNode *root );
    BSTreeNode* Search(T value,BSTreeNode *root );
    void UpdateHeight(BSTreeNode *root)
    {
        if(!root) return;
        int left = GetHeight(root->left);
        int right = GetHeight(root->right);
        root->height = left > right ? (left+1) : (right+1);
    }
    int GetBalanceFactor(BSTreeNode *root)
    {
        if(!root) return 0;
        return GetHeight(root->left) - GetHeight(root->right);
    }
    BSTreeNode* LeftRotate(BSTreeNode *root)
    {
        
        BSTreeNode* newroot = root->right;
        root->right = newroot->left;
        newroot->left = root;
        UpdateHeight(root);
        UpdateHeight(newroot);
        return newroot;
    }
    BSTreeNode* RightRotate(BSTreeNode *root)
    {
        BSTreeNode* newroot = root->left;
        root->left = newroot->right;
        newroot->right = root;
        
        UpdateHeight(root);
        UpdateHeight(newroot);
        return newroot;
    }
    BSTreeNode* FindMinNode(BSTreeNode *root)
    {
        if(!root->left) return root;
        return FindMinNode(root->left);
    }
    BSTreeNode *mRoot;
};
template class BSTree<int>;