//
// Created by Mr.Hu on 2018/4/19.
//
// leetcode 605 can place flower
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int nums = 0;
        if(n==0)
            return true;
        if(size==1){
            if(flowerbed[0]==0)
                nums = 1;
        }
        else if(size==2){
            if(flowerbed[0]==0 && flowerbed[1]==0)
                nums = 1;
        }
        else{
            if(flowerbed[0]==0 && flowerbed[1]==0){
                nums++;
            }
            if(flowerbed[size-1]==0 && flowerbed[size-2]==0){
                nums++;
            }
            int count = 0;
            bool isContinuous=false;
            for(int i=1;i<size-1;i++){
                if(flowerbed[i]==0){
                    if(isContinuous){
                        count++;
                    }
                    else{
                        count = 1;
                        isContinuous = true;
                    }
                }
                else{
                    isContinuous = false;
                    int result = (count-1)/2;
                    if(result>0){
                        nums += result;
                    }
                    count = 0;
                }
            }
            if(count!=0){
                int result = (count-1)/2;
                if(result>0){
                    nums += result;
                }
            }
        }
        if(nums>=n) {
            return true;
        }
        return false;
    }
};

int main(){
    vector<int> flowerbed = {1,0,0,0,0,1};
    int n = 1;
    Solution solution;
    bool result = solution.canPlaceFlowers(flowerbed,n);
    cout<<result<<endl;
    return 0;
}