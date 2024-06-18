//dfs 
class Solution {
public:string res="";
void dfs(TreeNode* root,string curr){
    if(!root){
        return;
    }
    curr=char(root->val+'a')+curr;
    if(root->left==NULL && root->right==NULL){
        if(res==""|| res>curr){
            res=curr;
        }
        return;
    }
    dfs(root->left,curr);
    dfs(root->right,curr);
}
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return res;
    }
};
