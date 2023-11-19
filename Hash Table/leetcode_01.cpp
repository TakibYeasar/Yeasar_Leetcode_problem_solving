// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,and you may not use the same element twice.
//  can return the answer in any order.

// ===================>>>
// The LeetCode Two Sum 1 problem is a popular coding challenge that requires finding the indices of two numbers in an array 
// that add up to a specific target. The problem statement provides an array of integers and a target value, and the task is to 
// return the indices of the two numbers that sum up to the target.

// One approach to solve this problem efficiently is by using a hash map or dictionary. We can iterate through the given array, 
// checking if the complement of each element (target minus current element) exists in our hash map. If it does, we have found our 
// solution and can return the indices. Otherwise, we add the current element and its index to our hash map for future reference.

// Another possible solution is by using two pointers. We can sort the array first and then initialize two pointers at the 
// beginning and end of the array. By comparing their sum with the target value, we can move either pointer closer to each other 
// until we find a match or exhaust all possibilities.

// Both approaches have a time complexity of O(n), where n is the length of the input array. However, using a hash map might be 
// more efficient when dealing with large arrays or when multiple solutions are expected.

// ===================>>>
// Time Complexity :
// Bruteforce : O(n ^ 2)
// HashMap : O(n)
// Two pass Hashmap : O(n)
//  Two Pointer : O(n log n)


// ===================>>> Solution 2 : (Hash Table)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++)
        {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i)
            {
                return {i, numMap[complement]};
            }
        }

        return {}; // No solution found
    }
};

// ===================>>> Solution 3: (One-pass Hash Table)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.count(complement))
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};

// ===================>>>
// Intuition
// The Two Sum problem asks us to find two numbers in an array that sum up to a given target value. We need to
// return the indices of these two numbers.

// Approach
// One brute force approach is to consider every pair of elements and check if their sum equals the target.
// This can be done using nested loops, where the outer loop iterates from the first element to the
// second-to-last element, and the inner loop iterates from the next element to the last element. However, this approach 
// has a time complexity of O(n^2).
// A more efficient approach is to use a hash table (unordered_map in C++). We can iterate through the array once,
// and for each element, check if the target minus the current element exists in the hash table.
// If it does, we have found a valid pair of numbers. If not, we add the current element to the hash table.
// Approach using a hash table:

// Create an empty hash table to store elements and their indices.
// Iterate through the array from left to right.
// For each element nums[i], calculate the complement by subtracting it from the target: complement = target - nums[i].
// Check if the complement exists in the hash table. If it does, we have found a solution.
// If the complement does not exist in the hash table, add the current element nums[i] to the hash table with its index as the value.
// Repeat steps 3-5 until we find a solution or reach the end of the array.
// If no solution is found, return an empty array or an appropriate indicator.
// This approach has a time complexity of O(n)
// since hash table lookups take constant time on average.It allows us to solve the Two Sum problem efficiently by
// making just one pass through the array.

// ===================>>>
// Way 1 -- > Brute force-- > O(n2) simply check if ith element is making a pair with any of the
// other element on the right side

// Way 2 -- > Using Two Pointer approach-- > O(n log n) time complexity is nlogn because in this approach,
// the array will be first sorted and then, two pointer approach will be used

// Way 3 -- > Using HashMap-- > O(n) keep on storing the elements that we reach, also keep on check
// if target - element is already present in the hashmap or not, if it is, then we found a pair
