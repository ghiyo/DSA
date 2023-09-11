/*
Problem:
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the 
island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix 
heights where heights[r][c] represents the height above sea level of the cell at coordinate 
(r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly 
north, south, east, and west if the neighboring cell's height is less than or equal to the 
current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain 
water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

---
Solution:
Given the two oceans surround the island, we just need to see if every cell in the grid can
reach both Pacific and Atlantic ocean. For pacific we need to check if the i or j position ever
reaches 0, if so then we can reach the pacific. Similarly for Atlantic, we only need to check to
see if i or j ever reach n or m. 

One way we can do this is to see if there is a path from the node to the Pacific and the Atlantic 
with the current cell as our starting point. We can do a breadth first search until we hit both 
oceans. If we encounter a cell that is higher than the current cell, we do not traverse it. Once
we hit each ocean we can mark the current cell as a flow cell where water flows to both oceans.

The runtime of this should be O((n^2)*(m^2)) since we are checking every cell and doing a breadth
first search per cell on all adjacent cells.

This is the naive approach and is very slow. 

Another way is to start from each ocean and flip the 
condition (we check for higher height instead of lower height). We do this for each ocean and
every cell that flows into both oceans will be part of our solution. This should give a time complexity
of O(n*m). Since we will be using a queue for our BFS the space time complexity will be O(n*m).

Another approach is to use DFS (would be similar to the BFS solution) We would use a two sets of nxm 
vectors of boolean to keep track where where water can flow from to each ocean respectively, then we
would compare the two matrices and which ever cells both have true would be the heights that would
flow to both oceans.
*/

#include "pch.h"

std::set<std::vector<int>> bfs(std::queue<std::vector<int>>& queue, std::vector<std::vector<int>>& heights) {
  std::set<std::vector<int>> reachables = std::set<std::vector<int>>();
  while (queue.size() > 0) {
    std::vector<int> coords = queue.front();
    queue.pop();
    reachables.emplace(coords);
    int num_rows = heights.size(), num_cols = heights[0].size();
    std::vector<std::vector<int>> directions{ { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    for (std::vector<int> dir : directions) {
      int new_row = coords[0] + dir[0];
      int new_col = coords[1] + dir[1];
      // check for bounds
      if (new_row < 0 || new_row >= num_rows || new_col < 0 || new_col >= num_cols)
        continue;
      // check if already has been visited (is in reachables)
      if (reachables.count({new_row, new_col}))
        continue;
      // check if water cannot flow (new cell is lower than the original)
      if (heights[new_row][new_col] < heights[coords[0]][coords[1]])
        continue;
      // if reached this far then its a valid cell that water can flow from
      queue.push({ new_row, new_col });
    }
  }
  return reachables;
}

std::vector<std::vector<int>> Solution::pacificAtlantic(std::vector<std::vector<int>>& heights) {
  if (heights.size() == 0) {
    return std::vector<std::vector<int>>();
  }

  int num_rows = heights.size(), num_cols = heights[0].size();

  std::queue<std::vector<int>> pacific_queue;
  std::queue<std::vector<int>> atlantic_queue;

  for (int i = 0; i < num_rows; i++) {
    pacific_queue.push({ i, 0 });
    atlantic_queue.push({ i, num_cols - 1 });
  }
  for (int i = 0; i < num_cols; i++) {
    pacific_queue.push({ 0, i });
    atlantic_queue.push({ num_rows - 1, i });
  }

  std::set<std::vector<int>> pacific_solution = bfs(pacific_queue, heights);
  std::set<std::vector<int>> atlantic_solution = bfs(atlantic_queue, heights);

  std::vector<std::vector<int>> res;

  std::set_intersection(
    pacific_solution.begin(), pacific_solution.end(), 
    atlantic_solution.begin(), atlantic_solution.end(), 
    std::back_inserter(res)
  );

  return res;
}