class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        dfsHeight(root, sum);
        return sum;
    }

    int dfsHeight(TreeNode *node, int &sum)
    {
        if (!node)
            return 0;

        // ignore negative nodes
        int l = max(0, dfsHeight(node->left, sum));
        int r = max(0, dfsHeight(node->right, sum));

        // sum at every node
        sum = max(sum, l + r + node->val);

        return (node->val) + max(l, r);
    }
};