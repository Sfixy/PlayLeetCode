#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <Windows.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
//解题
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> res;

        inorder(root, res);
        return res;
    }

public: //递归
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        else
        {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }
};

//测试
//创建一颗二叉树
TreeNode *create(TreeNode **root)
{
    int a = 0;
    cout << "input number : ";
    cin >> a;

    if (a == -100)
    {
        (*root) = NULL;
    }
    else
    {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        if (*root == NULL)
        {
            return NULL;
        }
        else
        {
            (*root)->val = a;
            cout << "create " << a << " left child" << endl;
            create(&(*root)->left);
            cout << "create " << a << " right child" << endl;
            create(&(*root)->right);
        }
    }
    return (*root);
}

int main()
{
    TreeNode *root = NULL;
    Solution s;

    root = create(&root);
    vector<int> v = s.inorderTraversal(root);
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << ' ';
    }
    system("pause");
    return 0;
}