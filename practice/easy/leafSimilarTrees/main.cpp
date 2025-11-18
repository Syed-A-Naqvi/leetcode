#include <cstdlib>
#include <cstdio>
#include "../cusutils.hpp"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    public:
        static bool leafSimilar(TreeNode* root1, TreeNode* root2, std::vector<int> &tree1_leafs, std::vector<int> &tree2_leafs) {
            
            // std::vector<int> tree1_leafs;
            // std::vector<int> tree2_leafs;

            getLeafs(root1, &tree1_leafs);
            getLeafs(root2, &tree2_leafs);

            if(tree1_leafs == tree2_leafs)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

    private:
        static void getLeafs(const TreeNode* const &root1, std::vector<int>* const &leafs){
            
            if(root1 == nullptr){
                return;
            }

            if ( (root1->left == nullptr) && (root1->right == nullptr) )
            {
                leafs->push_back(root1->val);
                return;
            }

            // search leaft tree
            getLeafs(root1->left, leafs);
            
            //search right tree
            getLeafs(root1->right, leafs);
            
        } 

};

void deleteTree(TreeNode* root){
    
    if (root == nullptr)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    
}

int main(int argc, char const *argv[])
{

    // tree 1
    TreeNode* root1 = new TreeNode(3);

    root1->left = new TreeNode(5);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    root1->right = new TreeNode(1);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    
    // tree 2
    TreeNode* root2 = new TreeNode(3);

    root2->left = new TreeNode(5);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);

    root2->right = new TreeNode(1);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    std::vector<int> tree1_leafs;
    std::vector<int> tree2_leafs;

    printf("trees are leaf similar? %d\n", Solution::leafSimilar(root1, root2, tree1_leafs, tree2_leafs));
    printf("tree1 leafs: %s\n", vec_to_string(tree1_leafs).c_str());
    printf("tree2 leafs: %s\n", vec_to_string(tree2_leafs).c_str());

    deleteTree(root1);
    deleteTree(root2);

    return 0;
}
