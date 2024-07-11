class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i = matrix.size() - 1;
        int j = 0;

        while(i >= 0 && j <= matrix[0].size() - 1)
        {
            if(matrix[i][j] == target)
                return true;

            if(matrix[i][j] > target)
            {
                i--;
            }
            else
            {
                j++;
            }
        }

        return false;
    }
};