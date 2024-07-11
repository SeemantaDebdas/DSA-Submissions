class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0 ; i < matrix.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0 ; i < matrix.size(); i++)
        {
            int start = 0, end = matrix[0].size() - 1;

            while(start < end)
            {
                swap(matrix[i][start++], matrix[i][end--]);
            }
        }
    }
};