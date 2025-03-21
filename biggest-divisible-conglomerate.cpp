#include "bdc.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Helper function to find the largest divisible subset using recursion
void findLargestConglomerate(const vector<int>& nums, vector<int>& current, vector<int>& best, int index) {
    if (current.size() > best.size()) {
        best = current;
    }

    for (int i = index; i < nums.size(); i++) {
        bool valid = true;
        for (int num : current) {
            if (nums[i] % num != 0 && num % nums[i] != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            current.push_back(nums[i]);
            findLargestConglomerate(nums, current, best, i + 1);
            current.pop_back();
        }
    }
}

// Main function to get the largest divisible subset
vector<int> biggest_divisible_conglomerate(vector<int> nums) {
    if (nums.empty()) return {};
    sort(nums.begin(), nums.end()); // Sort the numbers to ensure divisibility order
    
    vector<int> best, current;
    findLargestConglomerate(nums, current, best, 0);
    return best;
}

// Function to convert vector to string for output
string vec_to_string(vector<int> v) {
    string result = "[";
    for (size_t i = 0; i < v.size(); i++) {
        result += to_string(v[i]);
        if (i != v.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
