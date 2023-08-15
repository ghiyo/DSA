/*
Problem:
There is a new alien language that uses the English alphabet. 
However, the order of the letters is unknown to you.

You are given a list of strings words from the alien language's 
dictionary. Now it is claimed that the strings in words 
are sorted lexicographically by the rules of this new language.

If this claim is incorrect, and the given arrangement of string 
in words cannot correspond to any order of letters, return "".

Otherwise, return a string of the unique letters in the new alien 
language sorted in lexicographically increasing order by the new 
language's rules. If there are multiple solutions, return any of them.

example:
Input:  words = ["wrt", "wrf", "er", "ett", "rftt"]
Output: "werft"

Input:  words = ["z", "x"]
Output: "zx"

Input:  words = ["z","x","z"]
Output: ""

Input:  words = ["abc","ab"]
Output: ""

Note for the last two the order is invalid so return ""

Solution:
The one solution for this problem is to find a topological ordering
of the characters. For example for the first two words in the array
we can see that both have "wr" so we do not know what the ordering between
w and r are but we know that since "t" comes first, it preceeds "f".

Using this we can construct a directed graph. Using this directed graph,
we can detect invalid orderings if there is a cycle within this directed graph.
If you look at the third example, since "z" already came before "x" we know
that "z" should preceed "x". But "x" appears after "z" again which implies a
cycle in the graph that we have constructed. 

Given that a topological ordering would give us exactly what we are looking for,
if we can prove that the graph is a directed acyclic graph, then we can find a
topological ordering that would also be a lexicographically increasing order that
would satisfy the new languages's rules.

If there is a cycle we return "". Another edge case if the fourth example where
"abc" comes before "ab" even though "ab" is a substring of "abc" which means it should
come first based on the rule of lexicographically increasing order. So it is not a valid
order. We can do this test by comparing first the length of each word, and whether
the second word is a prefix of the first word.
*/

#include "pch.h"

bool dfs(const char& node, const std::unordered_map<char,std::vector<char>>& reverseAdjList, std::unordered_map<char, bool>& seen, std::string& output) { 
  if (seen.count(node)) { // we have already seen this node, but this does not mean its a cycle yet
    return seen[node];
  }
  seen[node] = false;
  for (const char& adjNode : reverseAdjList.at(node)) {
    bool result = dfs(adjNode, reverseAdjList, seen, output);
    if (!result) {
      return false; // cycle was found since we saw a node and are still not done with this path yet
    }
  }
  seen[node] = true; // no more adjacent nodes so we can mark it as done and add it to our output
  output += node;
  return true;
}

std::string Solution::alienOrder(std::vector<std::string>& words) {
  std::unordered_map<char, std::vector<char>> reverseAdjList;

  // construct a adjacency list of all unique characters as nodes
  for (const std::string& word : words) {
    for (char c : word) {
      reverseAdjList[c] = std::vector<char>();
    }
  }

  // compare words to find the edges for our reversed adjacency list
  // note that we make it reversed so we don't have to reverse our final result
  // this is because we are gonna use a DFS which will return our ordering in reverse normally
  long long int n = words.size();
  for (long long int i = 0; i < n - 1; i++) {
    if (words[i + 1].length() < words[i].length() && words[i].rfind(words[i + 1], 0) == 0) { // check if second word is a prefix of first
      return "";
    }
    long long int m = std::min(words[i].length(), words[i + 1].length());
    for (long long int j = 0; j < m; j++) {
      if (words[i][j] != words[i + 1][j]) { // edge found
        reverseAdjList[words[i + 1][j]].emplace_back(words[i][j]);
        break; // we don't care for the rest of the characters since we can't really tell much in terms of their ordering
      }
    }
  }

  // we now have a directed graph, we must now check for cycles, if there is none, then we can find a topological ordering
  std::unordered_map<char, bool> seen;
  std::string output = "";
  bool hasNoCycle = true; // assume there is no cycle
  for (const auto& node : reverseAdjList) {
    hasNoCycle = dfs(node.first, reverseAdjList, seen, output);
    if (!hasNoCycle) {
      return "";
    }
  }
  return output;
}