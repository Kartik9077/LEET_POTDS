class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
    
        pq.push({0, 0, 0});
        
    
        vector<vector<int>> earliestTime(n, vector<int>(m, INT_MAX));
        earliestTime[0][0] = 0;
        
        while (!pq.empty()) {
            auto [currentTime, x, y] = pq.top();
            pq.pop();
            
            
            if (x == n - 1 && y == m - 1) {
                return currentTime;
            }
            
    
            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
            
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                
                    int waitTime = max(currentTime, moveTime[newX][newY]);
                    int newTime = waitTime + 1; 
                    if (newTime < earliestTime[newX][newY]) {
                        earliestTime[newX][newY] = newTime;
                        pq.push({newTime, newX, newY});
                    }
                }
            }
        }
        

        return -1;
    }
};