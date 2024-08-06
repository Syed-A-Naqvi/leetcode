#include"../../cusutils.hpp"
#include<queue>

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
        
        std::vector<TreeNode*> nodeOrder;
        this->inorder(nodeOrder, root);
        
        printf("[ ");
        for(auto& n : nodeOrder)
        {
            n->left = nullptr;
            n->right = nullptr;
            printf("%d ", n->val);
        }
        printf("]\n");

        root = this->build(nodeOrder, 0, nodeOrder.size()-1);
        nodeOrder.resize(0);

        this->inorder(nodeOrder, root);
        printf("[ ");
        for(auto& n : nodeOrder)
        {
            printf("%d ", n->val);
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
    void inorder(std::vector<TreeNode*>& nodeOrder, TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        this->inorder(nodeOrder, root->left);
        nodeOrder.push_back(root);
        this->inorder(nodeOrder, root->right);
    }
    TreeNode* build(std::vector<TreeNode*>& nodeOrder, int start, int end)
    {
        if(start > end)
        {
            return nullptr;
        }
        else if(start == end)
        {
            return nodeOrder[start];
        }
        else
        {
            int mid = (start+end)/2;

            TreeNode* root = nodeOrder[mid];
            root->left = build(nodeOrder, start, mid-1);
            root->right = build(nodeOrder, mid+1, end);

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

    three.left = &one;
    one.right = &two;
    three.right = &four;

    Solution balancer;

    TreeNode* node = balancer.balanceBST(&three);
    balancer.levelPrint(node);

    return 0;
}
