class Solution {
public:

    vector<string> result;
    string curr;
    bool isValid(string& curr) {
        stack<char> st;
        for(auto it:curr){
            if(it=='('){ 
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        return(st.empty());
    }
    void solve(string& curr, int n){
        if(curr.length()==2*n){
            if(isValid(curr)) result.push_back(curr);
            return;
        }

        curr.push_back('(');
        solve(curr, n);

        curr.pop_back(); // undo(backtracking)

        curr.push_back(')');
        solve(curr, n);

        curr.pop_back(); // undo(backtracking)
    }
    vector<string> generateParenthesis(int n) {
        solve(curr, n);
        return result;
    }
};