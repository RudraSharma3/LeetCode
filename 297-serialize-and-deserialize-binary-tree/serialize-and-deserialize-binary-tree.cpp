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

    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Deserialize using recursive reconstruction from preorder string
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data, ',');
        int index = 0;
        return buildTree(nodes, index);
    }

private:
    TreeNode* buildTree(vector<string>& nodes, int& index) {
        if (nodes[index] == "null") {
            index++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(nodes[index++]));
        node->left = buildTree(nodes, index);
        node->right = buildTree(nodes, index);
        return node;
    }

    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));