//Iterrative 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root!=NULL)st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            // root left right
            ans.push_back(root->val);
            if (root->right != NULL)
                st.push(root->right);
            if (root->left != NULL)
                st.push(root->left);
        }
        return ans;
    }
};

// Recursive
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
vector<int>ans;
void sovle(TreeNode* root){
    if(root==NULL){
        return;
    }
    ans.push_back(root->val);
    sovle(root->left);
    sovle(root->right);
}
    vector<int> preorderTraversal(TreeNode* root) {
        sovle(root);
        return ans;
    }
};
