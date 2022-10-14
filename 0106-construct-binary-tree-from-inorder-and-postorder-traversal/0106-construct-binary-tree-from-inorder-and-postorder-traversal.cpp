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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    if(inorder.size()!=postorder.size())
        return NULL;
    map<int,int> m;
    
    for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]]=i;
    }
    
    return BuildsTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
}
TreeNode *BuildsTree(vector<int> &inorder,int instart,int inend,vector<int> &postorder,int poststart,int postend,map<int,int> &m)
{
    if(instart>inend || poststart>postend)
        return NULL;
    
    TreeNode *curr=new TreeNode(postorder[postend]);
    
    int inroot=m[curr->val];
    int numleft=inroot-instart;
    
    curr->left=BuildsTree(inorder,instart,inroot-1,postorder,poststart,poststart+numleft-1,m);
    curr->right=BuildsTree(inorder,inroot+1,inend,postorder,poststart+numleft,postend-1,m);
    
    return curr;
}
};