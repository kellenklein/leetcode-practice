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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        vector<TreeNode*> queue = {root};
        vector<int> heights = {1};
        int index = 0;
        
        while (queue[index] != nullptr) {
            if (queue[index]->left == nullptr && queue[index]->right == nullptr) 
                return heights[index];
            if (queue[index]->left != nullptr) {
                queue.push_back(queue[index]->left);
                heights.push_back(heights[index] + 1);
            }
            if (queue[index]->right != nullptr) {
                queue.push_back(queue[index]->right);
                heights.push_back(heights[index] + 1);
            }
            index++;
        }
        return heights[index];
    }
};