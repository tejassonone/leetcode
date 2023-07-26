class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1;
        int r = 1e7+1; 
        while(l<=r){
            int mid = l + (r-l)/2;
            double time = 0;
            for(int i=0; i<dist.size()-1; i++){
                time += ceil((double)dist[i]/mid);
            }
            time += (double)dist.back()/mid;
            if(time<=hour){
                ans = mid;
                r=mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};