class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // queue<TreeNode*> q;
        // q.push(root);

        // int ans = root->val;

        // while (!q.empty()) {
        //     int size = q.size();

        //     for (int i = 0; i < size; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();

        //         // First node of the current level
        //         if (i == 0)
        //             ans = node->val;

        //         if (node->left)
        //             q.push(node->left);

        //         if (node->right)
        //             q.push(node->right);
        //     }
        // }

        // return ans;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            if (node->right)
                q.push(node->right);

            if (node->left)
                q.push(node->left);
        }

        return node->val;
    }
};