
class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if (root == nullptr) return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        // Choose max path starting at current node
        int temp = max(root->val + max(l, r), root->val);

        // Max path passing through current node
        int ans = max(temp, root->val + l + r);

        res = max(res, ans);
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN; // fix: handle all-negative cases
        solve(root, res);
        return res;
    }
};
