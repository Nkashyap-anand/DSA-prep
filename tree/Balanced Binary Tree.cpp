class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode *node)
    {
        if (node == NULL)
            return 0;

        int l = dfsHeight(node->left);
        if (l == -1)
            return -1;

        int r = dfsHeight(node->right);
        if (r == -1)
            return -1;

        if (abs(r - l) > 1)
            return -1;

        return 1 + max(l, r);
    }
};

// o(n) TC