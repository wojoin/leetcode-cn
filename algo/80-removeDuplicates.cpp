#include <iostream>
#include <vector>

using namespace std;

/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定 nums = [1,1,1,2,2,3],
函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

示例 2:
给定 nums = [0,0,1,1,1,1,2,3,3],
函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
*/

int removeDuplicates(vector<int>& nums) {
    
    if(nums.size() <= 2)    return nums.size();

    int length = 1;
    for(int i = 2;i < nums.size();i++){
        if (nums[i] != nums[length-1]) {
            length++;
            nums[length] = nums[i];
        }
        
    }

    return length+1;
}

int main(int argc, const char** argv) {
    int nums[] = {1, 1, 1, 2, 2, 3};
    //int nums[] = { 0,0,1,1,1,1,2,3,3 };
    
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    
    cout << removeDuplicates(vec) << endl;

    for (int i = 0; i < removeDuplicates(vec); i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}
