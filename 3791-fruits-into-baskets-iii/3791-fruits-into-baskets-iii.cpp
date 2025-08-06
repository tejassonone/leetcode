class Solution {
public:
    
    int numOfUnplacedFruits(vector<int>& ft, vector<int>& bt) {
        int n = ft.size();
        // to make tc n*sqrt(n) - i need to divide it into equal size of block with equal number
        int block_sz = sqrt(n);
        int block_cnt = (n+block_sz-1)/block_sz; 
        vector<int> block_mx(block_cnt, 0);
        for(int i=0; i<n; i++){
            int idx = i/block_sz;
            block_mx[idx] = max(block_mx[idx], bt[i]);
        }
        int res = 0;
        for(int f : ft){
            bool placed = false;
            for(int j=0; j<block_cnt; j++){
                if(f <= block_mx[j]){
                    int start = block_sz*j;
                    int end = min(block_sz*(j+1), n);
                    for(int k=start; k<end; k++){
                        if(f<=bt[k]){
                            placed = true;
                            bt[k] = 0;
                            block_mx[j]=0;
                            for(int i=start; i<end; i++){
                                block_mx[j] = max(block_mx[j], bt[i]);
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            if(!placed) res++;
        }
        return res;
    }
};