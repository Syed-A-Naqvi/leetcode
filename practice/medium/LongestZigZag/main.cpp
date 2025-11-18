#include<queue>

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode* left, TreeNode* right): val(0), left(left), right(right) {}
    TreeNode(TreeNode* left, int val): val(val), left(left) {}
    TreeNode(int val, TreeNode* right): val(val), right(right) {}
};

class Solution {
    public:
        int zigPathLength(TreeNode* root)
        {

            int lpath_length = 0;
            int rpath_length = 0;
            TreeNode* node = root;
            bool left;

            if((root->left != nullptr) && (root->left->val != root->val))
            {
                left = 1;
                while(1)
                {
                    if(left == 1)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node = node->right;
                    }
                    if(node == nullptr)
                    {
                        break;
                    }
                    else
                    {
                        lpath_length++;
                        node->val = root->val + 1;
                    }
                    left = 1 - left;
                }
            }

            node = root;
            if((root->right != nullptr) && (root->right->val != root->val))
            {
                left = 0;
                while(1)
                {
                    if(left == 1)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node = node->right;
                    }
                    if(node == nullptr)
                    {
                        break;
                    }
                    else
                    {
                        rpath_length++;
                        node->val = root->val + 1;
                    }
                    left = 1 - left;
                }
            }

            if(lpath_length > rpath_length)
            {
                return lpath_length;
            }
            else
            {
                return rpath_length;
            }

        }

        int longestZigZag(TreeNode* root) {

            std::queue<TreeNode*> q;
            TreeNode* currNode;
            int max_length = 0;
            int currmax;

            q.push(root);
            while(!q.empty())
            {
                currNode = q.front();
                q.pop();

                currNode->val = 0;
                if(currNode->left != nullptr)
                {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr)
                {
                    q.push(currNode->right);
                }
            }

            root->val++;
            q.push(root);

            while(!q.empty())
            {
                currNode = q.front();
                q.pop();
                currmax = zigPathLength(currNode);
                if (currmax > max_length) {max_length = currmax;}
                
                if(currNode->left != nullptr)
                {
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr)
                {
                    q.push(currNode->right);
                }
            }

            return max_length;
        }
};