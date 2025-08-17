class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string rev = num;
        reverse(num.begin(),num.end());
        return num == rev;
    }
};