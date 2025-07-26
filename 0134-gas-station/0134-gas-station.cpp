class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0, currp = 0, pp = 0;
        int n = gas.size();

        for(int i=0;i<n;i++){
            currp += (gas[i]-cost[i]);

            if(currp<0){
                s = i+1;
                pp += currp;
                currp = 0;
            }
        }
        if(currp+pp>=0) return s;
        else return -1;
    }
};