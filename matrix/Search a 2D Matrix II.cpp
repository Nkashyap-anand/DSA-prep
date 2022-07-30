class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.size() == 0)
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int rowId = 0, colId = col - 1;

        while (rowId < row && colId >= 0)
        {
            int elm = matrix[rowId][colId];

            if (elm == target)
                return 1;
            if (elm < target)
                rowId++;
            else
                colId--;
        }
        return 0;
    }
};