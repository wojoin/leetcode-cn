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
    
    // if(nums.empty()) {
    //     return 0;
    // }

    // if(nums.size() == 1) {
    //     if (nums[0] == k)
    //         return 1;
    //     else
    //         return 0;
    // }

    // if(nums.size() == 2) {
    //     if (nums[0] + nums[1] == k)
    //         return 1;
    //     else
    //         return 0;
    // }

    // int count = 0, sum = 0, length = nums.size();
    
    // for(unsigned i = 0; i < length; ++i) {
    //     sum = 0;
    //     int j = i;
        
    //     // for itself
    //     if(nums[j] == k){
    //         count++;
    //         //cout << "i = " << i << ", j = " << j << endl;
    //     }

    //     while(j < length) {
    //         sum = sum + nums[j];
    //         int sub = k - sum;
    //         if( j + 1 != length && nums[j+1] == sub) {
    //             count++;
    //             //cout << "i = " << i << ", j = " << j+1 << endl;
    //         }
    //         j++;
    //     }
    // }


    // 考虑n个元素存在n*(n+1)/2种连续子数组的情况
    // int count = 0;

    // for(unsigned i = 0; i < nums.size(); ++i) { // n*(n+1)/2种子数组由i,j两个指针共同构成
    //     int sum = 0;
    //     for(unsigned j = i; j < nums.size(); ++j) { // 累计求和直至等于k
    //         sum += nums[j];
    //         if (sum == k) {
    //             count++;
    //         }
    //     }
    // }

    // 基于方法四, https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode/
    int count = 0;
    int sum = 0;

    unordered_map<int, int> sumMap; // <sum, sumCount>

    sumMap[0] = 1; // 和为0的,当前元素或者之前累加的和为k

    for(unsigned i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        unordered_map<int, int>::const_iterator it = sumMap.find(sum - k);
        if(it != sumMap.end()) {
            count += sumMap[sum-k];
        }
        sumMap[sum]++;
    }
    
    
    return count;
}

int main(int argc, const char** argv) {
    //int nums[] = {1, 2, 1, 2, 1};
    //int nums[] = {1, 2, 3};
    int nums[] = {28,54,7,-70,22,65,-6}; // k=100
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 100;
    cout << subarraySum(vec, k) << endl;
    return 0;
}
