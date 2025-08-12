
class Solution {
    // Recursive function to calculate the maximum path sum
    int maxPathSumUtil(Node *root, int &res) {
        // Base case: if root is NULL, return 0
        if (root == NULL)
            return 0;
        
        // Base case: if root is a leaf node, return its value
        if (!root->left && !root->right)
            return root->data;

        // Find the maximum path sum in the left and right subtrees
        int ls = maxPathSumUtil(root->left, res);
        int rs = maxPathSumUtil(root->right, res);

        // Update the result with the maximum sum path passing through the current root node
        if (root->left && root->right) {
            res = max(res, ls + rs + root->data);
            return max(ls, rs) + root->data;
        }
        
        // Return the sum of the maximum sum path till the current root node
        return (!root->left) ? rs + root->data : ls + root->data;
    }
public:
    // Function to find the maximum path sum
    int maxPathSum(Node *root) {
        int res = INT_MIN;
        // Call the recursive utility function to calculate the maximum path sum
        int h = maxPathSumUtil(root, res);
        
        // Update the result with the maximum sum path from root to leaf
        if (root->left == NULL || root->right == NULL) {
            res = max(res, h);
        }
        
        // Return the result with the maximum path sum
        return res;
    }
};
