class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        std::vector<int> time_to_city(n);
        
        for (int i = 0; i < n; ++i) {
            time_to_city[i] = (dist[i]-1) / speed[i];
        }
        
        std::sort(time_to_city.begin(), time_to_city.end());
        
        for (int i = 0; i < n; ++i) {
            if (time_to_city[i] < i) {
                return i;
            }
        }
        
        return n;
            
    }
};