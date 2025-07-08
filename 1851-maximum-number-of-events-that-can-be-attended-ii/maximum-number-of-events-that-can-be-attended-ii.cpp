class Solution {
    vector<vector<int>> mem;
    vector<int> n_event;
    int n;

    int attendEve(vector<vector<int>>& events, int pos, int k){
        if (k==0||pos>=n) return 0;
        if(mem[pos][k]!= -1) return mem[pos][k];

        int skipEve = attendEve(events,pos+1,k);
        int next = n_event[pos];
        int attend_event = attendEve(events,next,k-1) + events[pos][2];
        return mem[pos][k] = max(skipEve, attend_event);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(),events.end());
        mem.assign(n,vector<int>(k+1,-1));

        n_event = vector<int>(n);
        for(int i=0;i<n;++i)
            n_event[i] = upper_bound(events.begin()+i,events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
        
        return attendEve(events,0,k);
    }
};