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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* tnode;

        while(!q.empty())
        {
            tnode = q.front();
            q.pop();

            if(tnode->val == head->val && this->pathSearch(head, tnode))
            {
                return true;
            }
            
            if(tnode->left){q.push(tnode->left);}
            if(tnode->right){q.push(tnode->right);}
        }
        return false;
    }

    bool pathSearch(ListNode* lnode, TreeNode* tnode)
    {
        std::stack<TreeNode*> tstack;
        std::stack<ListNode*> lstack;

        while(1)
        {
            while(tnode && lnode && (tnode->val == lnode->val))
            {
                tstack.push(tnode);
                lstack.push(lnode);
                tnode = tnode->left;
                lnode = lnode->next;
            }

            if(lnode == nullptr)
            {
                return true;
            }

            if(!tstack.empty())
            {
                tnode = tstack.top();
                lnode = lstack.top();
                tstack.pop();
                lstack.pop();

                tnode = tnode->right;
                lnode = lnode->next;
            }
            else
            {
                return false;
            }
            
        }
    }
};