#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void sol(vector<int> nums, int index, vector<vector<int>>& ans, vector<int> subset){
        //base case
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }

        //exclude
        sol(nums,index+1,ans,subset);

        //include
        subset.push_back(nums[index]);
        sol(nums,index+1,ans,subset);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<int> subset;
        vector<vector<int>> ans;
        sol(nums,index,ans,subset);
        return ans;
    }
};

int main(){



    return 0;
}