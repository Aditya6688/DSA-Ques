class Solution {
public:
    int minimumOneBitOperations(int n) {
        long long k = n;

        // This loop performs the Gray-to-Binary conversion.
        // It's a bitwise implementation of the formula:
        // k_i = n_i ^ k_{i-1}
        // This propagates the most significant bit's value down.
        // We only need to shift up to 32, as 2^32 > 10^15 (which is ~2^50).
        // The shifts of 1, 2, 4, 8, 16, 32 will cover all 64 bits.
        
        // We can unroll the loop for maximum speed:
        k = k ^ (k >> 1);
        k = k ^ (k >> 2);
        k = k ^ (k >> 4);
        k = k ^ (k >> 8);
        k = k ^ (k >> 16);
        k = k ^ (k >> 32);

        return k;
    }
};