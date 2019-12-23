#include <iostream>
#include <vector>

using namespace std;
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
*/
int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int mid = 0;
    int insertIndex = 0;
    while (low <= high) {
        mid = low + (high-low)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main(int argc, const char** argv) {
    int nums[] = {1, 3, 5, 6};
    int target = 7;
    
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    
    cout << searchInsert(vec, target) << endl;

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}
