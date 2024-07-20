class Solution {
public:
    string reorganizeString(string s) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char c : s) {
        frequencyMap[c]++;
    }

    // Step 2: Create a max heap based on frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : frequencyMap) {
        maxHeap.push({entry.second, entry.first});
    }

    // Step 3: Reconstruct the string
    string result;
    pair<int, char> prev = {-1, '#'}; // previous character with its frequency

    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();
        
        // Append current character to the result
        result += current.second;
        
        // Decrease frequency and push the previous character back if it can still be used
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        
        // Update previous character
        current.first--;
        prev = current;
    }

    // Step 4: Check if the result is valid
    if (result.length() == s.length()) {
        return result;
    } else {
        return "";
    }
    }
};