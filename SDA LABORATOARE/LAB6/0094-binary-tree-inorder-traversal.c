/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* root, int* res, int* size) {
    if (!root) return;
    helper(root->left, res, size);
    res[(*size)++] = root->val;
    helper(root->right, res, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    helper(root, res, returnSize);
    return res;
}