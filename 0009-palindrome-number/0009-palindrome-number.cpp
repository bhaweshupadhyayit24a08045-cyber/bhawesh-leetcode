class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int length=0;
        int temp=x;
        while(temp>0){
            length++;
            temp/=10;
        }

        int divisor=pow(10, length-1);
        while(x>0){
            int first=x/divisor;
            int last=x%10;
            if (first==last){
                x%=divisor;      // remove kara first element
                x/=10;           // remove kara last element
                divisor/=100;
            }
            else return false;
        }
        return true;
    }
};