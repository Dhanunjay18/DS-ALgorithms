#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1


class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n  = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> dist(n, vector<int>(m));  // Basically a resultant array 
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;    // {{row, col}, step}
	    // Initially push all the positions into the queue which are
	    // 1 in the grid with step as 0
	    for(int i=0; i<n; ++i){         
	        for(int j=0; j<m; ++j){
	            if(grid[i][j]==1) {
	                vis[i][j] = 1;
	                q.push({{i,j}, 0});     // step as 0 intitally for all ones
	            }
	        }
	    }
	    // Basically a track for index position to move left right top bottom
	    int rowTrack[] ={-1,1,0,0};
	    int colTrack[] = {0,0,1,-1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        dist[row][col] = step;       // Insert the current step into the resultant grid
	        for(int i=0; i<4; ++i){
	            int currRow = row + rowTrack[i];
	            int currCol = col + colTrack[i];
	            if(currRow>=0 and currRow<n and currCol>=0 and currCol<m){
	                if(!vis[currRow][currCol]){
	                    vis[currRow][currCol] = 1;
	                    q.push({{currRow, currCol}, step+1});    // Increase the step by one and push into the queue 
	                }
	            }
	        }
	    }
	    return dist;
	}
};