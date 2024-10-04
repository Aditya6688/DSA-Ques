class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int a = skill[0]+skill[n-1];
        long long sum = (skill[0]*skill[n-1]);

        int i=1, j= n-2;
        while(i<=j){
            int b = skill[i]+skill[j];
            if(a != b) return -1;

            sum += (skill[i]*skill[j]);
            i++; j--;
        }
        return sum;
    }
};