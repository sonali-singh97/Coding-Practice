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
    int PathSumHelper(TreeNode* root, int* maxSum){
        if (root == NULL) return 0;
        
        int left = PathSumHelper(root->left, maxSum);
        int right = PathSumHelper(root->right, maxSum);
        int leftPath = root->val, rightPath = root -> val;
        if (left > 0 ){
            leftPath += left ;
        }
        
        if (right > 0){
             rightPath += right;
        }
        
        int maxRootPath = max (root -> val ,leftPath + rightPath-root->val );
        
        *maxSum = max(*maxSum, leftPath + rightPath - root->val);
        return max(leftPath, rightPath)  ; 
    }
    
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        PathSumHelper(root, &maxPath);
        return maxPath;
        
    }
};