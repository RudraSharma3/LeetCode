class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int m = baskets.size();
        int a = 100; 
        vector<int> sect_mx;
        for (int i = 0; i < m; i += a) {
            int mx = 0;
            for (int j = i; j < min(i + a, m); j++) {
                mx = max(mx, baskets[j]);
            }
            sect_mx.push_back(mx);
        }
        int remain = 0;
        for(int i = 0; i < fruits.size(); i++){
            int k = 0, set = 1;
            for(int j = 0; j < m; j+=a){
                if(sect_mx[k] < fruits[i]){
                    k++;
                    continue;
                }

                for(int r = j; r < min(j+a,m); r++){
                    if(baskets[r]>=fruits[i]){
                        set = 0;
                        baskets[r] = 0;
                        break;
                    }
                }

                if(set==0){
                    sect_mx[k] = 0;
                    for(int r = j; r < min(j+a,m); r++){
                        sect_mx[k] = max(baskets[r], sect_mx[k]);
                    }
                    break;
                }
                k++;
            }
            remain += set;
        }
        return remain;
    }
};