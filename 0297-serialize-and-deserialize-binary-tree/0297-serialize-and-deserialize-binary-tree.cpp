/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == nullptr)
            return "null,";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                ans += "null,";
                continue;
            }

            ans += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data == "null,")
            return nullptr;

        vector<string> arr;
        string temp = "";

        for (char ch : data) {
            if (ch == ',') {
                arr.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        TreeNode* root = new TreeNode(stoi(arr[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (arr[i] != "null") {
                TreeNode* left = new TreeNode(stoi(arr[i])); // stoi convert string into int
                curr->left = left;
                q.push(left);
            }
            i++;

            if (arr[i] != "null") {
                TreeNode* right = new TreeNode(stoi(arr[i]));
                curr->right = right;
                q.push(right);
            }
            i++;
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));