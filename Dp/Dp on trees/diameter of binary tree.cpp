
class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if (root == nullptr) return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = 1 + max(l, r);       // height including current node
        int ans = max(temp, 1 + l + r); // longest path through current node (nodes count)
        res = max(ans, res);

        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0; // start from 0 instead of INT_MIN
        solve(root, ans);
        return ans - 1; // convert nodes count to edges count
    }
};
