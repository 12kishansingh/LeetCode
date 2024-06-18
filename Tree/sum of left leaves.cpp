// 1. using parent pointer 
class Solution {
public:
int solve(TreeNode* curr, TreeNode* parent){
    if(curr==NULL){
        return 0;
    }
    //leaf node
    if(curr->left==NULL && curr->right==NULL){
        if(parent!=NULL && parent->left==curr){
            return curr->val;
        }
    }
    int left=solve(curr->left,curr);
    int right=solve(curr->right,curr);
    return left+right;
}
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,NULL);
        
    }
};
//2. using isleft variable
class Solution {
public:
int solve(TreeNode* curr, int isleft){
    if(curr==NULL){
        return 0;
    }
    //leaf node
    if(curr->left==NULL && curr->right==NULL && isleft==true){
            return curr->val;
    }
    int left=solve(curr->left,true);
    int right=solve(curr->right,false);
    return left+right;
}
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
        
    }
};
