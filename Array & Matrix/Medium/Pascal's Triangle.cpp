class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        for (int i = 1; i <= numRows; i++)
        {
            vector<int> inner;
            int innerRes = 1;
            inner.push_back(innerRes);
            for (int j = 1; j < i; j++)
            {
                innerRes *= (i - j);
                innerRes /= j;

                inner.push_back(innerRes);
            }

            answer.push_back(inner);
        }

        return answer;
    }
};