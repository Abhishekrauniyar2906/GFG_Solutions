class Solution {
  public:
    int myAtoi(char *s) {
     
     
     int i = 0;
     int result = 0;
     
     int sign = 1;

     
     while(s[i] == ' '){
      i++;    
     }
        
         //. check if the sign is postive or negative
        if(s[i] == '-' || s[i] == '+'){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        while(isdigit(s[i])){
            int digit = s[i] - '0';
            
            if(result > (INT_MAX - digit) / 10){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
     
        return result * sign;
    }
};