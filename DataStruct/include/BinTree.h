#include <iostream>
#include <vector>
#include <queue>
template <typename T>
class BinTree
{
public:
    enum
    {
        Preorder_Traversal,
        Inorder_Traversal,
        Postorder_Traversal,
        Levelorder_Taversal,
        Preorder_TraversalIterate,
        Inorder_TraversalIterate,
        Postorder_TraversalIterate,
    };
    struct TreeNode
    {
        T val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
    };

    BinTree();
    ~BinTree();
    void CreateTree(std::vector<T> arr);
    void DestroyTree();
    void Insert(T value);
    bool Search(T value);
    void Delete(T value);
    void Print(int TraversalMode);
private:
    TreeNode *Find(TreeNode* root,T value);
    TreeNode *DeleteNode(TreeNode* root,T value);
    TreeNode *FindLeftNode(TreeNode* root);
    void InorderTraversal(TreeNode* root);
    void PreorderTraversal(TreeNode* root);
    void PostorderTraversal(TreeNode* root);
    void LevelorderTaversal(TreeNode* root);
    TreeNode *Create(std::vector<T> arr, TreeNode* root, int &index);
    TreeNode *mRoot;
};
template class BinTree<char>;