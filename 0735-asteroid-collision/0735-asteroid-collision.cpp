class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> v;
    stack<int> s;
    int n = asteroids.size();
    
    for(int i = 0; i < n; i++) {
        // Handle the current asteroid
        if (asteroids[i] > 0) {
            // Positive asteroid, just push to stack
            s.push(asteroids[i]);
        } else {
            // Negative asteroid, handle collisions
            while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
                s.pop();  // Pop smaller positive asteroids
            }
            
            // If stack is empty or top is a negative asteroid, push current
            if (s.empty() || s.top() < 0) {
                s.push(asteroids[i]);
            } 
            // If the top of the stack equals the negative asteroid, pop it
            else if (s.top() == abs(asteroids[i])) {
                s.pop();
            }
        }
    }

    // Transfer the remaining asteroids from stack to vector
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    
    reverse(v.begin(), v.end());  // Reverse to get correct order
    return v;
    }
};