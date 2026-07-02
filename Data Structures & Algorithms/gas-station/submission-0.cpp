class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if(cost[i]>gas[i])
                continue;
            else{
                int tank=gas[i]-cost[i];
                int j=(i+1)%n;
                while(j!=i){
                    tank+=(gas[j]-cost[j]);
                    if(tank<0)
                        break;
                    j=(j+1)%n;
                }
                if(tank>=0)
                    return i;
            }
        }
        return -1;
    }
};
