class Solution {
public:
    string reversePrefix(string s, int k) {
        int st=0;
        int end=k-1;
        while(st<end){
            swap(s[st], s[end]);
            st++;
            end--;      
        }
        return s;
    }
};