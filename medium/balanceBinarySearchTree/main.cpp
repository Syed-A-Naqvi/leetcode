#include"../../cusutils.hpp"
#include<queue>
#include<stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class Solution
{
    public:
    TreeNode* balanceBST(TreeNode* root) {
        
        std::vector<int> nodeOrder;
        this->inorder(nodeOrder, root);
        
        printf("[ ");
        for(auto& n : nodeOrder)
        {
            printf("%d ", n);
        }
        printf("]\n");

        root = this->build(nodeOrder, 0, nodeOrder.size()-1);
        nodeOrder.resize(0);

        this->inorder(nodeOrder, root);
        printf("[ ");
        for(auto& n : nodeOrder)
        {
            printf("%d ", n);
        }
        printf("]\n");

        return root;
    }
    void levelPrint(TreeNode* root)
    {
        std::queue<TreeNode*> q;
        q.push(root);

        printf("[ ");
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(!node)
            {
                printf("null ");
            }
            else
            {
                printf("%d ", node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        printf("]\n");
    }

    private:
    void inorder(std::vector<int>& nodeOrder, TreeNode* root)
    {
        std::stack<TreeNode*> nodeStack;
        TreeNode* node = root;

        while(node || !nodeStack.empty())
        {
            while(node)
            {
                nodeStack.push(node);
                node = node->left;
            }

            node = nodeStack.top();
            nodeStack.pop();
            nodeOrder.push_back(node->val);

            node = node->right;
        }

    }
    TreeNode* build(std::vector<int>& nodeOrder, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        else if(start == end)
        {
            return new TreeNode(nodeOrder[start]);
        }
        else
        {
            int mid = (start+end)/2;

            TreeNode* root = new TreeNode(nodeOrder[mid]);
            root->left = this->build(nodeOrder, start, mid-1);
            root->right = this->build(nodeOrder, mid+1, end);

            return root;
        }
    }
};


int main(int argc, char const *argv[])
{
    
    TreeNode three(3);
    TreeNode one(1);
    TreeNode two(2);
    TreeNode four(4);

    one.right = &two;
    two.right = &three;
    three.right = &four;

    Solution balancer;

    TreeNode* node = balancer.balanceBST(&one);
    balancer.levelPrint(node);

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class Solution {
// public:
//     vector<int>a;
//     void inorder(TreeNode*root)
//     {
//         if(root)
//         {
//             inorder(root->left);
//             a.push_back(root->val);
//             inorder(root->right);
//         }
//     }

//     TreeNode* buildTree(int s, int e)
//     {
//         if(s > e) return NULL;
//         int mid = (s+e)/2;
//         TreeNode* root = new TreeNode(a[mid]);
//         root->left = buildTree(s, mid-1);
//         root->right = buildTree(mid+1, e);
//         return root;
//     }

//     TreeNode* balanceBST(TreeNode* root) 
//     {
//         inorder(root);
//         return buildTree(0, a.size()-1);
//     }
// };