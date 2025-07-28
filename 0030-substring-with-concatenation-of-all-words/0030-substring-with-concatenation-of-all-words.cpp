class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        // store freq of words in map
        unordered_map<string, int> mp;
        for (auto word : words) {
            mp[word]++;
        }

        int wordLength = words[0].length();

        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int> visited;
            
            int count = 0; // for track of ans

            for (int j = i; j + wordLength <= s.length(); j+=wordLength) {
                string substr = s.substr(j, wordLength);
                // check if substr valid or not

                if (mp.find(substr) == mp.end()) {
                    // invalid string
                    // remove all ans
                    visited.clear();
                    count = 0;
                    continue;
                }
                else {
                    // valid string
                    visited[substr]++;
                    count++;

                    while (visited[substr] > mp[substr]) {

                        string temp = s.substr(j - (count-1) * wordLength, wordLength);
                        visited[temp]--;
                        count--;
                    }


                    // is ans found
                    if (count == words.size()) {
                        ans.push_back(j - (count-1)*wordLength);
                    }
                }
            }
        }

        return ans;
    }
};