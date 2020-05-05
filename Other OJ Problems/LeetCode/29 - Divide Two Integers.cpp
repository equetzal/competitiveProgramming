//LC 29 - Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        else if (divisor == 1)
            return dividend;
        else if (divisor == -1 && dividend == numeric_limits<int>::min())
            return numeric_limits<int>::max();
        else if (divisor == -1)
            return -dividend;
        
        bool isNegative = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            isNegative = true;
        
        unsigned int a = (unsigned int)(dividend);
        unsigned int b = (unsigned int)(divisor);
        
        if(dividend < 0)
            a = (unsigned int)(((long long int)(dividend+1)*-1) +1);
        if(divisor < 0)
            b = (unsigned int)(((long long int)(divisor+1)*-1) +1);
        
        //cout << "a=" << a << " b=" << b << endl;
        
        long long int divs = 0;
        while(a >= b){
            a -= b;
            divs++;
            if(divs > numeric_limits<int>::max())
                return numeric_limits<int>::max();
        }
        
        if(isNegative)
            divs *= -1;
        
        return divs;
    }
};
