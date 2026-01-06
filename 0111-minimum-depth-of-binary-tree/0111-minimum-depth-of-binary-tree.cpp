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
#include <queue>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        std::queue<TreeNode*> queue;
        std::queue<int> heights;
        int index = 0;
        TreeNode* current = root;
        int depth = 1;
        
        while (current != nullptr) {
            if (current->left == nullptr && current->right == nullptr) 
                return depth;
            if (current->left != nullptr) {
                queue.push(current->left);
                heights.push(depth + 1);
            }
            if (current->right != nullptr) {
                queue.push(current->right);
                heights.push(depth + 1);
            }
            current = queue.front();
            queue.pop();
            depth = heights.front();
            heights.pop();
        }
        return depth;
    }
};