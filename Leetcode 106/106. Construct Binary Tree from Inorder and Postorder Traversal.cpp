// Leetcode : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder , int &index , int start, int end){
        // base case
        if(start > end || index < 0 ) return NULL;

        // solve 1 case
        int curr = postorder[index];
        index--;
        int mid = start;
        for( ; mid <= end; mid++){
            if(curr == inorder[mid]) break;
        }

        TreeNode* root = new TreeNode(curr);
        root -> right = construct(inorder ,postorder , index, mid + 1 , end);
        root -> left = construct(inorder ,postorder , index, start, mid - 1);
        // return 
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n-1;
        return construct(inorder , postorder , index , 0 , n-1); 
    }
};

