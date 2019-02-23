//
// Created by Mr.Hu on 2019/2/23.
//
// leetcode 39 combination sum
//

#include <iostream>
#include <vector>

using namespace std;
// class Solution {
// public:
//     vector<vector<int>> res;

//     void compute(vector<int>& candidates,int target,int idx){
//         vector<int> cur;    // 存储当前被选择的值
//         int sum=0, size=candidates.size();  // cur中所有数值的和，候选集的大小
//         set<int> has_visited;   // 已经被选择完的数据
//         while(true){
//             if(sum == target){
//                 res.push_back(cur);
//                 sum -= cur.back();
//                 has_visited.insert(cur.back());
//             }
//             // else if(sum>target){
//             //     sum -= cur.back();
//             //     has_visited.insert(cur.back());
//             // }
//             else if(has_visited.count(candidates[idx])){
//                 idx++;
//             }
//             else if(idx>=size){
//                 break;
//             }
//             else if(target-sum-candidates[idx]!=0 && target-sum-candidates[idx]<candidates[idx]){
//                 // sum -= cur.back();
//                 // has_visited.insert(cur.back());
//             }
//             else{
//                 cur.push_back(candidates[idx]);
//                 sum += candidates[idx];
//             }
//             cout<<sum<<endl;
//         }
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         // 此处进行for循环，以每个值作为开端
//         for(int i=0;i<candidates.size();i++){
//             if(candidates[i]>target){
//                 break;
//             }
//             compute(candidates,target,i);
//         }
//         return res;
//     }
// };

class Solution {
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &paths, int idx) {
        if (target == 0) {
            ans.push_back(paths);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            int diff = target - candidates[i];
            if (diff < 0) {
                break;
            }
            paths.push_back(candidates[i]);
            dfs(candidates, diff, ans, paths, i);
            paths.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> paths;
        vector<vector<int>> ans;
        if (candidates.size() == 0) {
            return {};
        }
        int index = 0;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, ans, paths, index);
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,5,3,7,9};
    int target = 10;
    vector<vector<int>> res = solution.combinationSum(nums,target);
    for(auto v:res){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
