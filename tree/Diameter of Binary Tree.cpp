class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {

        int maxi = 0;

        dfsHeight(root, maxi);

        return maxi;
    }

    int dfsHeight(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int l = dfsHeight(root->left, maxi);
        int r = dfsHeight(root->right, maxi);

        maxi = max(maxi, l + r);

        return 1 + max(l, r);
    }
};