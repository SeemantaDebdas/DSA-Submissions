class Solution {
public:
    double myPow(double x, int n) {
        long long tempN = n;
        if(n < 1) tempN *= -1;
        double ans = 1;

        while(tempN != 0)
        {
            if(tempN % 2 == 0)
            {
                tempN /= 2;
                x *= x;
            }
            else
            {
                ans *= x;
                tempN -= 1;
            }
        }

        if(n < 1)
            return 1/ans;
            
        return ans;
    }
};