
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

class Solution {
    long total = 0, res = 0;    
public:
    long dfs(TreeNode *root){
        if(!root) return 0;
        int cSum = root -> val + dfs(root->left) + dfs(root->right);
        res = max(res, (total-cSum)*cSum);
        return cSum;
    }
    int maxProduct(TreeNode* root) {
        /*
            1. Firstly, calculate total Sum.
            2. Apply dfs to get result such that:
            3. dfs(root){    (declare res and total as global insted of passing as Referenced Variable)
                3.1. Calculate the sum of current subtree with root as Current root element
                3.2. Get the product by calculating CurrentSum and RemSum(total-CurrentSum)
                3.3. Maximize result accordingly.
            }
        */
        total = dfs(root);
        dfs(root);
        return res % int(1e9+7);
    }
};