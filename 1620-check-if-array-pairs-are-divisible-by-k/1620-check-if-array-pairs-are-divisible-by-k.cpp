class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> remainder_count;
    
    // Count the frequency of each remainder when divided by k
    for (int num : arr) {
        int rem = ((num % k) + k) % k;  // To handle negative numbers correctly
        remainder_count[rem]++;
    }
    
    // Check if the array can be divided into pairs
    for (auto &[rem, count] : remainder_count) {
        if (rem == 0) {
            // For remainder 0, count should be even
            if (count % 2 != 0) return false;
        } else {
            // For remainder r1, we need remainder r2 = k - r1 to have the same count
            int complement = k - rem;
            if (remainder_count[rem] != remainder_count[complement]) return false;
        }
    }
    
    return true;
    }
};