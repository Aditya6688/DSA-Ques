class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string prev = countAndSay(n - 1);
        string res = "";
        int len = prev.size();
        for (int i = 0; i < len; ) {
            char c = prev[i];
            int count = 0;
            while (i < len && prev[i] == c) {
                count++;
                i++;
            }
            res += to_string(count) + c;
        }
        return res;
    }
};