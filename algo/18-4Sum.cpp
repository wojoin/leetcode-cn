#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using std::cout;
using std::endl;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // vector<vector<int>> res;

    // sort(nums.begin(), nums.end());
    // unordered_map<int, int> numsMap;
    
    // for(unsigned i = 0; i < nums.size(); ++i) {
    //     numsMap.insert({nums[i], i});
    // }

    
    // for(unsigned i = 0; i < nums.size(); ++i) {
    //     for(unsigned j = i + 1; j < nums.size(); ++j) {
    //         int low = j + 1, high = nums.size() - 1;
    //         // for case nums=[0,0,0,0], target=0
    //         if(nums.size() == 4 && nums[0] + nums[1] + nums[2] + nums[3] == target) {
    //             res.push_back({nums[0], nums[1], nums[2], nums[3]});
    //             return res;
    //         }
                
    //         // remove duplicatge except for zero
    //         if(j > 0 && (nums[j] != target && nums[j] == nums[j-1]))
    //             continue;
            
    //         while(low < high) {
    //             int threeSum = nums[i] + nums[low] + nums[high];
    //             if (threeSum == (target - nums[j])) {
    //                 res.push_back({nums[i], nums[j], nums[low], nums[high]});
    //                 high--;
    //                 low++;
                    
    //                 while(low < high && (nums[low] == nums[low-1] || nums[j] == target) )
    //                     low++;
    //                 while(low < high && (nums[high] == nums[high+1] || nums[j] == target) )
    //                     high--;
    //             } else if (low < high && threeSum > target - nums[j] ) {
    //                 high--;
    //             } else if(low < high && threeSum < target - nums[j] ) {
    //                 low++;
    //             }
                
    //         }

    //     }
    // }
    
    // return res;

    
        vector<vector<int>> res;
    
        if(nums.size() < 4) {
            return res;
        }

        // for case nums=[0,0,0,0], target=0
        if(nums.size() == 4 && nums[0] + nums[1] + nums[2] + nums[3] == target) {
            res.push_back({nums[0], nums[1], nums[2], nums[3]});
            return res;
        }

        sort(nums.begin(), nums.end());

        for(unsigned i = 0; i < nums.size()-3; ++i) {
            // invalid
            if (target <= 0 && nums[i] > 0) 
                break;
            // remove duplicate
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;

            for(unsigned j = i + 1; j < nums.size()-2; ++j) {
                // invalid
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;
                if(nums[i]+nums[j]+nums[nums.size()-2]+nums[nums.size()-1] < target) 
                    continue;
                // remove duplicate
                if(j > i + 1 && nums[j] == nums[j-1] ) 
                    continue;
                
                int low = j + 1, high = nums.size() - 1;
                
                while(low < high) {     
                    int twoSum = nums[low] + nums[high];
                    if (twoSum == target - nums[i] - nums[j] ) {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        high--;
                        low++;
                        
                        while(low < high && nums[low] == nums[low-1] )
                            low++;
                        while(low < high && nums[high] == nums[high+1] )
                            high--;
                    } else if (low < high && twoSum > target - nums[i] - nums[j] ) {
                        high--;
                    } else if(low < high && twoSum < target - nums[i] - nums[j] ) {
                        low++;
                    }
                    
                }

            }
        }
        
        return res;
    
}

int main(int argc, const char** argv) {
    //int myints[] = {1, 0, -1, 0, -2, 2};// target = 0
    //int myints[] = {-1, 0, 1, 2, -1, -4}; //target = -1
    int myints[] = {-3,-2,-1,0,0,1,2,3};
    //int myints[] = {0, 0, 0, 0};
    //int myints[] = {1,0,-1,0,-2,2}; // target=-1
    int target = 0;

    vector<int> vec(myints, myints + sizeof(myints) / sizeof(int) );

    vector<vector<int>> res = fourSum(vec, target);
    
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it) {
        for(vector<int>::iterator iter = (*it).begin();iter != (*it).end();iter++)
            cout << ' ' << *iter;
        cout << endl;
    }
    return 0;
}
