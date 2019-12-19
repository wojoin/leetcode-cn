#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using std::cout;
using std::endl;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int target = 0;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i) {
        // remove duplicate
        if ( i > 0 && nums[i] == nums[i-1])
            continue;
            
        int low = i + 1, high = nums.size() - 1;
        while(low < high) {
            int twoSum = nums[low] + nums[high];
            if( twoSum == target - nums[i]) {
                vector<int> v{nums[i], nums[low], nums[high]};
                res.push_back(v);

                low++;
                high--;
                while(low < high && nums[low] == nums[low - 1])
                    low++;
                while(low < high && nums[high] == nums[high + 1])
                    high--;

                
                
                // for case num=[-2,0,0,2,2]
                // for case num=[-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0]
                // if( low < high && (nums[low] == nums[low+1] && nums[high] != nums[high-1]) ) {
                //     low++;
                // } else if(low < high && (nums[low] == nums[low+1] && nums[high] != nums[high-1]) ) { // for case num=[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
                //     high--;
                // } else if(low < high && (nums[low] == nums[low+1] && nums[high] == nums[high-1])) {
                //     low++;
                //     high--;
                // }
            } else if(low < high && twoSum > target - nums[i]) {
                high--;
            } else {
                low++;
            }
        }
    }
    
    return res;
}

int main(int argc, const char** argv) {
    //int myints[] = {-1, 0, 1, 2, -1, -4};
    //int myints[] = {-2,0,0,2,2};
    int myints[] = {-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};

    vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int) );

    vector<vector<int>> res = threeSum(fifth);
    
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it) {
        for(vector<int>::iterator iter = (*it).begin();iter != (*it).end();iter++)
            cout << ' ' << *iter;
        cout << endl;
    }
    return 0;
}
