
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

class Node {
public:
    std::map<std::string, Node*> children;
    bool deleted = false;
    
    Node() = default;
    ~Node() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

class Solution {
public:
    std::vector<std::vector<std::string>> deleteDuplicateFolder(
        std::vector<std::vector<std::string>>& paths) {
        
        Node* root = new Node();
        
        // Build the tree structure
        for (const auto& path : paths) {
            Node* curr = root;
            for (const std::string& name : path) {
                if (curr->children.find(name) == curr->children.end()) {
                    curr->children[name] = new Node();
                }
                curr = curr->children[name];
            }
        }
        
        // Encode each subtree and group nodes with identical structures
        std::unordered_map<std::string, std::vector<Node*>> map;
        encode(root, map);
        
        // Mark duplicate subtrees for deletion
        for (const auto& group : map) {
            if (group.second.size() > 1) {
                for (Node* n : group.second) {
                    n->deleted = true;
                }
            }
        }
        
        // Collect all non-deleted paths
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        collect(root, path, result);
        
        delete root;
        return result;
    }
    
private:
    std::string encode(Node* node, std::unordered_map<std::string, std::vector<Node*>>& map) {
        if (node->children.empty()) return "()";
        
        std::vector<std::string> parts;
        for (const auto& entry : node->children) {
            std::string sub = encode(entry.second, map);
            parts.push_back(entry.first + sub);
        }
        std::sort(parts.begin(), parts.end());
        
        std::string sign = "(";
        for (const std::string& part : parts) {
            sign += part;
        }
        sign += ")";
        
        map[sign].push_back(node);
        return sign;
    }
    
    void collect(Node* node, std::vector<std::string>& path, 
                 std::vector<std::vector<std::string>>& res) {
        for (const auto& entry : node->children) {
            if (entry.second->deleted) continue;
            path.push_back(entry.first);
            res.push_back(path);
            collect(entry.second, path, res);
            path.pop_back();
        }
    }
};