class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if(st.empty()) return false;  // no opening bracket to match
                char top = st.top();
                if((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                    return false;  // mismatched pair
                }
                st.pop();  // matched, so pop the opening bracket
            }
        }
        return st.empty();  // valid if nothing is left unmatched
    }
};