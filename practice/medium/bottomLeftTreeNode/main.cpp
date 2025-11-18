#include <cstdio>
#include <queue>


struct TreeNode
{
    // fields
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* right) : val(x), left(nullptr), right(right) {}
    TreeNode(TreeNode* left, int x) : val(x), left(left), right(nullptr) {}
    TreeNode(TreeNode* left, int x, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
        int findBottomLeftValue(TreeNode* root)
        {
            std::queue<TreeNode*> nodeQ;
            nodeQ.push(root);

            TreeNode* node;
            while(!nodeQ.empty())
            {
                node = nodeQ.front();
                nodeQ.pop();

                if(node->right) { nodeQ.push(node->right);}
                if(node->left) { nodeQ.push(node->left);}
            }

            return node->val;
        }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

