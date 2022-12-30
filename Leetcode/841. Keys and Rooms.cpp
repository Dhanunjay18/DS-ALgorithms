
// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
        vector<int> vis;
public:
    void dfs(int i, vector<vector<int>> rooms) {
        if(vis[i]) return;
        vis[i] = 1;
        for(auto it: rooms[i]) {
            dfs(it, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.resize(n, 0);
        vis[0] = 1;
        // First get all the keys from room[0]
        // And recurively make call to all rooms[i] 
        for(auto i: rooms[0]) dfs(i, rooms);
        // After completion of getting all keys
        // Check for any room is not able to visit or not 
        // It can be done if the room is not yet visited
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};