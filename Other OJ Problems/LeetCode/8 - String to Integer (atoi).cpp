//LC 8 - String to Integer (atoi)

class Solution {
public:
    int myAtoi(string str) {
        bool isNegative = false;
        
        long long int i = 0;
        for(; i<str.size(); i++){
            if(str[i] == ' ')
                continue;
            if(str[i] == 0)
                continue;
            if(str[i] == '-'){
                isNegative = true;
                i++;
                break;
            }
            if(str[i] == '+'){
                isNegative = false;
                i++;
                break;
            }
            if(!isdigit(str[i])){
                return 0;
            }
            if(isdigit(str[i]))
                break;
        }
        
        string num;
        for(; i<str.size(); i++){
            if(str[i]  == ' ')
                break;
            if(str[i] == '.')
                break;
            if(!isdigit(str[i]))
                break;
            if(isdigit(str[i]))
                num.push_back(str[i]);
        }
        
        long long int ans = 0;
        for(auto c:num){
            ans *= 10;
            ans += int(c-'0');
        
            if(ans > numeric_limits<int>::max())
                break;            
        }
        
        if(isNegative)
            ans *= -1;
        
        if(ans > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        if(ans < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        return ans;
    }
};
