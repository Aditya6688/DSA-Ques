class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(),products.end());
        int n = products.size();
        int m = searchWord.size();

        for (int j = 0; j < m; ++j) {
        string prefix = searchWord.substr(0, j + 1);
        vector<string> suggestions;
        
        for (int i = 0; i < n; ++i) {
            if (products[i].substr(0, j + 1) == prefix) {
                suggestions.push_back(products[i]);
                if (suggestions.size() == 3) break; // Only take up to 3 suggestions
            }
        }
        
        res.push_back(suggestions);
    }
    
    return res;
    }
};