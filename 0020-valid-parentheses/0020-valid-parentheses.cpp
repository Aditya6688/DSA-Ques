class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(i>0 && !st.empty() && (s[i] == ')' && st.top() == '(')){
                st.pop();
            }
            else if(i>0 && !st.empty() && (s[i] == '}' && st.top() == '{')){
                st.pop();
            }
            else if(i>0 && !st.empty() && (s[i] == ']' && st.top() == '[')){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};