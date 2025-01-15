//Iterative
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

    vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    if(root!=NULL){s1.push(root);}

    while(!s1.empty()){
        TreeNode* t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left!=NULL){
            s1.push(t->left);
        }
        if(t->right!=NULL){
            s1.push(t->right);
        }
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->val);
        s2.pop();
    }
    return ans;
    }
};

// recursive
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
void solve(TreeNode* root){
    if(root==NULL){
        return;
    }
    //left right root
    solve(root->left);
    solve(root->right);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        
        solve(root);
        return ans;
    }
};
