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
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        vector<vector<int>> answer;
         if(root == NULL) return answer;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* currentNode = q.front();
                q.pop();
                if(currentNode->left != NULL) q.push(currentNode->left);
                if(currentNode->right != NULL) q.push(currentNode->right);
                
                level.push_back(currentNode->val);       
            }
            answer.push_back(level);
            
        }
        return answer;
    }
};