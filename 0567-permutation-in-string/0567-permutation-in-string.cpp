class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> s1Count(26, 0), s2Count(26, 0);
    
    // Initialize the frequency counts for s1 and the first window of s2
    for (int i = 0; i < s1.size(); i++) {
        s1Count[s1[i] - 'a']++;
        s2Count[s2[i] - 'a']++;
    }
    
    // Check if the current window matches
    if (s1Count == s2Count) return true;
    
    // Start sliding the window over s2
    for (int i = s1.size(); i < s2.size(); i++) {
        // Include a new character from the right side of the window
        s2Count[s2[i] - 'a']++;
        // Exclude the character from the left side of the window
        s2Count[s2[i - s1.size()] - 'a']--;
        
        // Check if the new window matches
        if (s1Count == s2Count) return true;
    }

    return false;
    }
};