// Leetcode : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/****************************** Simple Appproach ********************/
// T.C = O(n)
// S.C = O(1)

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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder , int &index , int start ,int end){
        // base case
        if(start > end || index >= preorder.size()) return NULL;

        //solve 1 case

        int curr = preorder[index];
        int mid = start;
        for( ; mid <= end; mid++){
            if(curr == inorder[mid]) break;
        }
        TreeNode* root = new TreeNode(curr);
        index++;
        root -> left = construct(preorder ,inorder ,index, start , mid - 1);
        root -> right = construct(preorder ,inorder ,index, mid+1 , end);
        // return 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return construct(preorder , inorder , index , 0 , n-1);
        
    }
};