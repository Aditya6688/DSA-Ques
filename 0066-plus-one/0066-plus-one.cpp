class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;  // because we want to add 1

        for (int i = n - 1; i >= 0 && carry; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry) {  // if still carry remains, e.g., 999 + 1 = 1000
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};