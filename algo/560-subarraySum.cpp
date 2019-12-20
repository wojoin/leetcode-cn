/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。


想法:
这有点类似于twoSum的题, 采用排序和双指针思想，细节是注意连续子数组
方案:
1. 和为k
2. 连续子数组
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int subarraySum(vector<int>& nums, int k) {

    int count = 0;
    // int sum = 0;
    // unordered_map<int, int> sumCount; // <sum, count>
    
    // sumCount[0] = 1;

    // for(unsigned i = 0; i < nums.size(); ++i) {
    //     sum += nums[i];
    //     unordered_map<int, int>::const_iterator it = sumCount.find(sum - k);
    //     if( it != sumCount.end()) {
    //         count += sumCount[sum - k];
    //     }
    //     sumCount[sum]++;
    // }
    
    for(unsigned i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for(unsigned j = i; j < nums.size(); ++j) {
            sum += nums[j];
            if (sum == k){
                count++;
            }
        }
    }

    return count;
}

int main(int argc, const char** argv) {
    //int nums[] = {1, 2, 1, 2, 1};
    //int nums[] = {1, 2, 3};
    int nums[] = {28,54,7,-70,22,65,-6, 100}; // k=100
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 100;
    cout << subarraySum(vec, k) << endl;
    return 0;
}
