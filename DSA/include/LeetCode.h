#pragma once
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"

class Solution {
public:

  // Arrays & Hashing
  bool containsDuplicate(std::vector<int>& nums);                                                                 // LC 217
  bool isAnagram(std::string s, std::string t);                                                                   // LC 242
  std::vector<int> twoSum(std::vector<int>& nums, int target);                                                    // LC 1
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);                            // LC 49
  std::vector<int> topKFrequent(std::vector<int>& nums, int k);                                                   // LC 347
  std::vector<int> productExceptSelf(std::vector<int>& nums);                                                     // LC 238
  class Codec {                                                                                                   
  public:
    std::string encode(std::vector<std::string>& strs);                                                           // LC 271
    std::vector<std::string> decode(std::string s);                                                               // LC 271

    // Trees
    std::string serialize(TreeNode* root);                                                                        // LC 297
    TreeNode* deserialize(std::string data);                                                                      // LC 297
  };
  int longestConsecutive(std::vector<int>& nums);                                                                 // LC 128
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Two Pointers
  bool isPalindrome(std::string s);                                                                               // LC 125
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums);                                                 // LC 15
  int maxArea(std::vector<int>& height);                                                                          // LC 11
  // -----------------------------------------------------------------------------------------------------------------------

  // Sliding Window
  int maxProfit(std::vector<int>& prices);                                                                        // LC 121
  int lengthOfLongestSubstring(std::string s);                                                                    // LC 3
  int characterReplacement(std::string s, int k);                                                                 // LC 424
  std::string minWindow(std::string s, std::string t);                                                            // LC 76
  // -----------------------------------------------------------------------------------------------------------------------

  // Stack
  bool isValid(std::string s);                                                                                    // LC 20
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Binary Search
  int findMin(std::vector<int>& nums);                                                                            // LC 153
  int search(std::vector<int>& nums, int target);                                                                 // LC 33
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Linked List
  ListNode* reverseList(ListNode* head);                                                                          // LC 206
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);                                                      // LC 21
  void reorderList(ListNode* head);                                                                               // LC 143
  ListNode* removeNthFromEnd(ListNode* head, int n);                                                              // LC 19
  bool hasCycle(ListNode* head);                                                                                  // LC 141
  ListNode* mergeKLists(std::vector<ListNode*>& lists);                                                           // LC 23
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Trees
  TreeNode* invertTree(TreeNode* root);                                                                           // LC 226
  int maxDepth(TreeNode* root);                                                                                   // LC 104
  bool isSameTree(TreeNode* p, TreeNode* q);                                                                      // LC 100
  bool isSubtree(TreeNode* root, TreeNode* subRoot);                                                              // LC 572
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);                                       // LC 235
  std::vector<std::vector<int>> levelOrder(TreeNode* root);                                                       // LC 102
  bool isValidBST(TreeNode* root);                                                                                // LC 98
  int kthSmallest(TreeNode* root, int k);                                                                         // LC 230
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);                                     // LC 105
  int maxPathSum(TreeNode* root);                                                                                 // LC 124
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Tries
  class Trie {
  public:
    Trie();
    void insert(std::string word);                                                                                // LC 208
    bool search(std::string word);                                                                                // LC 208
    bool startsWith(std::string prefix);                                                                          // LC 208
  };
  class WordDictionary {
    WordDictionary();                                                                                             // LC 211
    void addWord(std::string word);                                                                               // LC 211
    bool search(std::string word);                                                                                // LC 211
  };
  std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);     // LC 212
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Heap / Priority Queue
  class MedianFinder {
    MedianFinder();                                                                                               // LC 295
    void addNum(int num);                                                                                         // LC 295
    double findMedian();                                                                                          // LC 295
  };
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Backtracking
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);                         // LC 39
  bool exist(std::vector<std::vector<char>>& board, std::string word);                                            // LC 79
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Graphs
  int numIslands(std::vector<std::vector<char>>& grid);                                                           // LC 200
  Node* cloneGraph(Node* node);                                                                                   // LC 133
  std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);                          // LC 417
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);                                   // LC 207
  int countComponents(int n, std::vector<std::vector<int>>& edges);                                               // LC 323
  bool validTree(int n, std::vector<std::vector<int>>& edges);                                                    // LC 261
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Advanced Graphs
  std::string alienOrder(std::vector<std::string>& words);                                                        // LC 269
  // -----------------------------------------------------------------------------------------------------------------------
  
  // 1D Dynamic Programming
  int climbStairs(int n);                                                                                         // LC 70
  int rob(std::vector<int>& nums);                                                                                // LC 198
  int rob2(std::vector<int>& nums);                                                                               // LC 213
  std::string longestPalindrome(std::string s);                                                                   // LC 5
  int countSubstrings(std::string s);                                                                             // LC 647
  int numDecodings(std::string s);                                                                                // LC 91
  int coinChange(std::vector<int>& coins, int amount);                                                            // LC 322
  int maxProduct(std::vector<int>& nums);                                                                         // LC 152
  bool wordBreak(std::string s, std::vector<std::string>& wordDict);                                              // LC 139
  int lengthOfLIS(std::vector<int>& nums);                                                                        // LC 300
  // -----------------------------------------------------------------------------------------------------------------------
  
  // 2D Dynamic Programming
  int uniquePaths(int m, int n);                                                                                  // LC 62
  int longestCommonSubsequence(std::string text1, std::string text2);                                             // LC 1143
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Greedy
  int maxSubArray(std::vector<int>& nums);                                                                        // LC 53
  bool canJump(std::vector<int>& nums);                                                                           // LC 55
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Intervals
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval);  // LC 57
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);                                  // LC 56
  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);                                            // LC 435
  bool canAttendMeetings(std::vector<std::vector<int>>& intervals);                                               // LC 252
  int minMeetingRooms(std::vector<std::vector<int>>& intervals);                                                  // LC 253
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Math & Geometry
  void rotate(std::vector<std::vector<int>>& matrix);                                                             // LC 48
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);                                            // LC 54
  void setZeroes(std::vector<std::vector<int>>& matrix);                                                          // LC 73
  // -----------------------------------------------------------------------------------------------------------------------
  
  // Bit Manipulation
  int hammingWeight(uint32_t n);                                                                                  // LC 191
  std::vector<int> countBits(int n);                                                                              // LC 338
  uint32_t reverseBits(uint32_t n);                                                                               // LC 190
  int missingNumber(std::vector<int>& nums);                                                                      // LC 268
  int getSum(int a, int b);                                                                                       // LC 371
  // -----------------------------------------------------------------------------------------------------------------------

};
