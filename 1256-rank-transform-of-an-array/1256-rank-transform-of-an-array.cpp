class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> v(arr.begin(), arr.end());
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    int k = 1;
    
    for (int i = 0; i < v.size(); ++i) {
        if (mp.find(v[i]) == mp.end()) {  // Only assign rank if the value is not in the map
            mp[v[i]] = k;
            k++;
        }
    }

    vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        res[i] = mp[arr[i]];
    }

    return res;
    }
};