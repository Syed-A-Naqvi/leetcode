struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode *left, int x, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(TreeNode *left, int x) : val(x), left(left), right(nullptr) {}
    TreeNode(int x, TreeNode *right) : val(x), left(nullptr), right(right) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        // no idea how to do this.
    }
};