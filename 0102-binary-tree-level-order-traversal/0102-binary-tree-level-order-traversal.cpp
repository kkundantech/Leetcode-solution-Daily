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
    vector<vector<int>> levelOrder(TreeNode* root) {
    // vector<vector<int>> ans; //  for store the ans.
    // if(root == nullptr) return ans;

    // queue<TreeNode*> q;
    // q.push(root); //  first push the root node

    // while(!q.empty()){
    //     int size = q.size();        // nodes in current level
    //     vector<int> level;

    //     for(int i = 0; i < size; i++){
    //         TreeNode* first = q.front(); // take the front of queue 
    //         q.pop(); // then delete it 

    //         level.push_back(first->val); //  and push to the level ans 

    //         if(first->left)  q.push(first->left); //  then next push the left of the root 
    //         if(first->right) q.push(first->right); //  then push the right of the root 
    //     }

    //     ans.push_back(level);
    // }

    // return ans;


    // lets revise the same concept

    vector<vector<int>>ans;
    if(root == NULL){
        return ans;
    }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>level;

            for(int i = 0 ; i < size ; i++){
                TreeNode* currNode = q.front();
                q.pop();

                level.push_back(currNode->val);

                if(currNode->left){
                    q.push(currNode->left);
                }

                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
   
}

};