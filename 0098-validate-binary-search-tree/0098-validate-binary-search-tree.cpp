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
    bool solve(TreeNode* root, long long low, long long high) {
        if (root == NULL)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }

     bool isValidBST(TreeNode* root) {
    // Case 1 recursive mathod 

    //     return solve(root, LLONG_MIN, LLONG_MAX); // -∞ to +∞

    // Case 2 interative  mathod
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (curr != NULL || !st.empty()) {

            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (prev != NULL && prev->val >= curr->val)
                return false;

            prev = curr;
            curr = curr->right;
        }

        return true;
     }
    
};