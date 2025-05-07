// 101. Symmetric Tree
bool isMirror(struct TreeNode* t1, struct TreeNode* t2);

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// 200. Number of Islands
void isMirror(char** grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    isMirror(grid, i + 1, j, rows, cols);
    isMirror(grid, i - 1, j, rows, cols);
    isMirror(grid, i, j + 1, rows, cols);
    isMirror(grid, i, j - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                isMirror(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }

    return count;
}
