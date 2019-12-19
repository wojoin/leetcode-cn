#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using std::cout;
using std::endl;

// brute force for just for compeleteness, O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    // for (size_t i = 0; i < nums.size(); i++) {
    //     // 在剩余子数组[i+1, n]中查找另一个元素target-nums[i]
    //     for(size_t j = i + 1; j < nums.size(); ++j) {
    //         if (nums[j] == target - nums[i]) {
    //             res.push_back(i);
    //             res.push_back(j);
    //         }
    //     }
    // }

    // using map for searching addend, T(n)=O(n)
    //unordered_map<int, int> numsMap;
    
    // for(unsigned i = 0; i < nums.size(); ++i) {
    //     numsMap.insert({nums[i], i});
    // }
    
    // for(unsigned i = 0; i < nums.size(); ++i) {
    //     int temp = target - nums[i];
    //     unordered_map<int, int>::const_iterator got = numsMap.find(temp);

    //     if( got != numsMap.end() &&  got->second != i ) {
    //         res.push_back(i);
    //         res.push_back(got->second);
    //         return res;
    //     }
    // }

    // using binary search , T(n)=O(nlgn)
    // keep index of origin array
    unordered_map<int, int> numsMap;
    
    for(unsigned i = 0; i < nums.size(); ++i) {
        numsMap.insert({nums[i], i});
    }

    sort(nums.begin(), nums.end());
    
    for(unsigned i = 0; i < nums.size(); ++i) {
        int low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            if( nums[low] + nums[high] == target) {
                res.push_back(numsMap.find(nums[low])->second);
                res.push_back(numsMap.find(nums[high])->second);
                return res;
            } else if (low <= high && nums[low] + nums[high] > target) {
                high--;
            } else if (low <= high && nums[low] + nums[high] < target) {
                low++;
            }           
        }
        
    }
    
    return res;
}

int main(int argc, const char** argv) {
    int myints[] = {3, 3};
    int target = 6;

    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    vector<int> res = twoSum(fifth, target);
    
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
        cout << ' ' << *it;

    cout << endl;
    return 0;
}