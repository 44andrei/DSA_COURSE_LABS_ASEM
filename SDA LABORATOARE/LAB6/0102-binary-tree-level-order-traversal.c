/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays returned in *returnSize and *returnColumnSizes must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode* queue[2005];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    int** res = (int**)malloc(2005 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2005 * sizeof(int));
    *returnSize = 0;
    
    while (front < rear) {
        int levelSize = rear - front;
        res[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        (*returnSize)++;
    }
    
    return res;
}