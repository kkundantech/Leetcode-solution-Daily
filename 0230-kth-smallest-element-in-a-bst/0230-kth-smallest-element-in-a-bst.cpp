/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0; // for count the current state 
    int ans = 0; // for store the ans 

    void Helper(TreeNode* root, int k) { // then use inorder traversal 
        if (root == NULL)
            return;

        Helper(root->left, k);  // go to left

        count++; // count increament 
        if (count == k) { // if count  is equal  to k then move 
            ans = root->val;
            return;
        }

        Helper(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        Helper(root, k);
        return ans;
    }
};