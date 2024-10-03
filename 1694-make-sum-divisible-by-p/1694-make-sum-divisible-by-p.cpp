class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    
    // Compute total sum of the array and mod it by p
    int total_sum = accumulate(nums.begin(), nums.end(), 0LL) % p;
    if (total_sum == 0) return 0;  // If the total sum is already divisible by p
    
    // Hash map to store the last occurrence of prefix mod value
    unordered_map<int, int> last_index;
    last_index[0] = -1;  // Initialize for the case where prefix itself is the solution
    int prefix_sum = 0;
    int min_len = n;
    
    // Traverse the array and compute prefix sums modulo p
    for (int i = 0; i < n; ++i) {
        prefix_sum = (prefix_sum + nums[i]) % p;
        int target = (prefix_sum - total_sum + p) % p;
        
        if (last_index.find(target) != last_index.end()) {
            min_len = min(min_len, i - last_index[target]);
        }
        
        // Update the hash map with the current prefix mod value
        last_index[prefix_sum] = i;
    }
    
    return (min_len == n) ? -1 : min_len;
    }
};