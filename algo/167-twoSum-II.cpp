#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using std::cout;
using std::endl;

// 与1-twoSum的不同之处在于本题数组已经有序。适合使用two pointers的思想
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high) {
        if(nums[low] + nums[high] == target) {
            res.push_back(low+1);
            res.push_back(high+1);
            return res;
        } else if(nums[low] + nums[high] > target) {
            high -= 1;
        } else {
            low += 1;
        }
    }
    return res;
}

int main(int argc, const char** argv) {
    int myints[] = {2, 7, 11, 15};
    int target = 8;

    vector<int> vec (myints, myints + sizeof(myints) / sizeof(int) );
    cout << vec.size() << endl;

    vector<int> res = twoSum(vec, target);
    

    cout << "result: " << endl;
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
        cout << ' ' << *it;

    cout << endl;
    return 0;
}