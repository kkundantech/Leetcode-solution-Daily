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
    
    TreeNode* build(vector<int>& preorder,int inStart, int inEnd, int& preIndex, unordered_map<int,int>&mp) {

        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex];
        preIndex++; //  increament after using the current val of the preoder traversal 
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];
        // for (int i = inStart; i <= inEnd; i++) {
        //     if (inorder[i] == rootVal) {
        //         pos = i;
        //         break;
        //     }
        // }

        root->left = build(preorder,inStart, pos - 1, preIndex, mp);
        root->right = build(preorder,pos + 1, inEnd, preIndex, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i = 0; i < preorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        int preIndex = 0;  
        return build(preorder,0, inorder.size() - 1, preIndex,mp);
    }

};
