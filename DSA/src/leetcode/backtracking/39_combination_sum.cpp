/*
Problem:
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen 
numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen 
numbers is different.

The test cases are generated such that the number of unique combinations 
that sum up to target is less than 150 combinations for the given input.

examples:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

---
Solution:
For each candidate we traverse a tree of possibilities to find combinations that add up
to the target. We will use a depth first search and include the current candidate in the
solution if we are going left, but we will exclude it when going right so that we don't 
get duplicate answers.

Further improvements can be made to make sure we only recurse on values that are worth it.
We do not want to recurse on values that exceed the target if we can avoid it.
*/

#include "pch.h"

void dfs(
  int index,
  std::vector<int>& candidates,
  int target,
  std::vector<std::vector<int>>& solutions,
  int total,
  std::vector<int>& cur_sol
) {
  if (total > target || index >= candidates.size())
    return;
  if (total == target) {
    solutions.emplace_back(cur_sol);
    return;
  }

  cur_sol.emplace_back(candidates[index]);
  dfs(index, candidates, target, solutions, total + candidates[index], cur_sol); // left
  cur_sol.pop_back();
  dfs(index+1, candidates, target, solutions, total, cur_sol); // right
}

std::vector<std::vector<int>> Solution::combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int>> solutions;
  std::vector<int> sol = std::vector<int>();
  dfs(0, candidates, target, solutions, 0, sol);
  return solutions;
}