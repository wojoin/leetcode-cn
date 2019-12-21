#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int removeDuplicates(vector<int>& nums) {
        int length = 0;
        if(nums.empty())    return length;
        if(nums.size() == 1)    return length+1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != nums[length]) {
                length++;
                nums[length] = nums[i];
            }
        }
        return length+1;
    }

int main(int argc, const char** argv) {
    //int nums[] = {1, 1, 2};
    int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
    
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    
    cout << removeDuplicates(vec) << endl;

    for (int i = 0; i < removeDuplicates(vec); i++) {
        cout << vec[i] << ' ';
    }
    return 0;
}
