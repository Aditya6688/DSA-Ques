class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
            }
            if(s[i] == ')'){
                if(st.size() == 0){
                    cnt++;
                }
                else{
                    char ch = st.top();
                    st.pop();
                }
            }
        }
        int a = st.size();
        int ans = cnt+a;
        return ans;
    }
};