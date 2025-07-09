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
        int preIndex = 0;
        unordered_map<int, int> inorderIndex;
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         for(int i=0; i<inorder.size(); i++){
                inorderIndex[inorder[i]] = i;
            }
            return build(preorder,0,inorder.size()-1);
        }

        TreeNode* build(vector<int>& preorder, int start, int end){
            if(start> end || preIndex >= preorder.size()) return nullptr;
            int rootval = preorder[preIndex++];
            TreeNode* root = new TreeNode(rootval);
            int inIndex = inorderIndex[rootval];

            root->left = build(preorder, start, inIndex-1);
            root->right = build(preorder, inIndex+1, end);

            return root;
        }
};