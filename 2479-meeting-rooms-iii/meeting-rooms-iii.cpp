class Solution {
public:
typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));
        vector<int> roomsUsedCount(n,0);

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        for(int room = 0; room < n; room++){
            availableRooms.push(room);
        }
        for(vector<int>& meet : meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            }else{
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + duration, room});
                roomsUsedCount[room]++;
            }
        }
        
        int resultRoom = -1;
        int maxUse = 0;

        for(int room = 0; room < n; room++){
            if(roomsUsedCount[room]>maxUse){
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};