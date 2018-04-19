//
// Created by Mr.Hu on 2018/4/19.
//
// leetcode 605 can place flower
//
// 题目要去：假设有一个条形花坛，现在要在花坛中种花，要去花与花之间最少要距离一个单位，这样花之间才不会争夺养分；
// 数值化：用数组表示花坛的所有位置，1表示已经种植，0表示为空位。
// 给出需要种植的花数n，判断当前这个花坛是否能够将n多花全部按要求种植下去，返回true或false
//
// 考虑除去花坛两边的花只需要一边没有花以外，其他中间的花都需要两边都没有花，即要求连续三个0，则可以种植一朵；
// 而且会出现连续多个0的情况，如连续五个0，连续五个0就可以种植2朵，因为中间的0可以公用，所以不能只考虑三个0的情况。
// 于是有了一种想法，就是两端的情况单独考虑，中间的情况一起考虑；
// 一端如果有连续的两个0，则说明可以种植1多花；
// 考虑完两端之后，则只需要考虑序列号[1,size-1]中连续0的情况，因为位置1和size-1处如果为0，则可以给中间连续的0使用，如果为1，
// 则可以给中间部分判断连续0最为终止条件，因为要想种植数最大，且两端都还未种植且满足种植情况，则必须种植，因为它们只需要一边为0，即可以少用一个位置。
// 遍历中间部分，判断连续0的个数，假设有一段有连续的count个0，观察发现3个0可种植1朵，5个0可种植2朵，7个0可种植3朵...
// n个连续的0则可以种植(count-1)/2朵。
// 每一段能种植的个数都累加到nums中，遍历完整个数组，比较nums与n的大小，nums>=n则说明能够在满足要求的情况下种植n朵。
//
// 感觉这种思路稍微有点复杂，网上查了一下，还有一种思路是使用贪心算法(greedy algorithm)，对flowerbed数组进行遍历，满足条件则在数组上将值给为1，
// 然后n--，直到n==0或者遍历完毕即可，要注意两端的情况。感觉这种做法更加直观。两种方法的时间复杂度都是O(n)，空间复杂度都是O(1)。
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