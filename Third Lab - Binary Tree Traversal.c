//144. Binary Tree Preorder Traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* result = (int*)malloc(sizeof(int) * 200);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 200);
    int top = -1;
    struct TreeNode* cur = root;
    while (cur != NULL || top != -1) {
        if (cur != NULL) {
            result[(*returnSize)++] = cur->val;
            if (cur->right != NULL) {
                stack[++top] = cur->right;
            }
            cur = cur->left;
        } else {
            cur = stack[top--];
        }
    }
    free(stack);
    return result;
}

//94. Binary Tree Inorder Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* result = (int*)malloc(sizeof(int) * 200);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 200);
    int top = -1;
    struct TreeNode* cur = root;
    while (cur != NULL || top != -1) {
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        result[(*returnSize)++] = cur->val;
        cur = cur->right;
    }
    free(stack);
    return result;
}
