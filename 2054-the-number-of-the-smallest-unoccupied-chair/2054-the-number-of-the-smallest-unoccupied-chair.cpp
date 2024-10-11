class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios::sync_with_stdio(false);
        
        auto frnd = times[targetFriend];
        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> emptySeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> takenSeats;

        for (int i = 0; i < times.size(); ++i) emptySeats.push(i);

        for (auto &vec : times) {
            int arrival = vec[0], leave = vec[1];

            while (!takenSeats.empty() && takenSeats.top().first <= arrival) {
                emptySeats.push(takenSeats.top().second);
                takenSeats.pop();
            }

            int seat = emptySeats.top();
            emptySeats.pop();

            if (arrival == frnd[0] and leave == frnd[1]) return seat;

            takenSeats.push({leave, seat});
        }

        return -1;  
    }
};