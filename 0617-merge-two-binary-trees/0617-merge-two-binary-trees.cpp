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
#include <iostream>

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }

        std::queue<TreeNode*> tree1;
        std::queue<TreeNode*> tree2;

        TreeNode* current1 = root1;
        TreeNode* current2 = root2;

        while (current1 != nullptr && current2 != nullptr) {
            TreeNode* left1 = current1->left;
            TreeNode* left2 = current2->left;

            TreeNode* right1 = current1->right;
            TreeNode* right2 = current2->right;
            
            if (left1 == nullptr && left2 != nullptr) {
                current1->left = left2;
            } else if (left1 != nullptr && left2 != nullptr) {
                tree1.push(left1);
                tree2.push(left2);
            }
            if (right1 == nullptr && right2 != nullptr) {
                current1->right = right2;
            } else if (right1 != nullptr && right2 != nullptr) {
                tree1.push(right1);
                tree2.push(right2);
            }
            current1->val += current2->val;
            if (tree1.empty()) {
                break;
            }
            current1 = tree1.front();
            tree1.pop();
            current2 = tree2.front();
            tree2.pop();
        }
        return root1;
    }
};