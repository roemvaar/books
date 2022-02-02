/* Height of a Tree - (Maximum Depth of a Binary Tree on Leetcode)
 * The height of a tree (binary or not) is defined to be the number
 * of nodes along the longest path from the root node to any leaf node.
 *
 * The height of a tree equals the height of its tallest subtree plus one.
 */

/* 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;
      
        return 1 + (max(maxDepth(root->left),
                        maxDepth(root->right));
    }  
};
       
