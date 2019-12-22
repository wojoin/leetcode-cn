#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

I:nums = [3,2,2,3], val = 3,
O: 2, 并且 nums 中的前两个元素均为 2
I:nums = [0,1,2,2,3,0,4,2], val = 2,
O: 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。


*/

int removeElement(vector<int>& nums, int val) {
    int length = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[length] = nums[i];
            length++;
        }
    }
    return length;
}

int main(int argc, const char** argv) {
    //int nums[] = {3, 2, 2, 3};
    int nums[] = {0,1,2,2,3,0,4,2};
    
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    int val = 2;
    
    cout << removeElement(vec, val) << endl;

    for (int i = 0; i < removeElement(vec, val); i++) {
        cout << vec[i] << ' ';
    }

    cout << endl;

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}
