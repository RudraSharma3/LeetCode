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
    int cameraCount = 0;
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameraCount++; 
        return cameraCount;
    }

    int dfs(TreeNode* node) {
        if (!node) return 2;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            cameraCount++;
            return 1;
        }
        if (left == 1 || right == 1) return 2;
        return 0;
    }
};