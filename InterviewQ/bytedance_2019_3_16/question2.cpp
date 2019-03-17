#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;


// 三个相同的字母去掉一个；
// 两对一样的字母aabb，去掉第二对的第一个即可
// 上面的两个规则都优先"从左到右"

string repair(string s) {


    if(s.length()<=2){
        return s;
    }

    for(int i=0;i<s.length();i++){
        if(i+3<s.length()){
            if(s[i]== s[i+1] && s[i]==s[i+2] || s[i]==s[i+1] && s[i+2]==s[i+3]){
                s.erase(i+2,1);
                i--;
            }
        }
        else if(i+2<s.length()){
            if(s[i]== s[i+1] && s[i]==s[i+2]){
                s.erase(i+2,1);
                i--;
            }
        }
    }
    return s;
}


int main() {
    // 准备数据
    int num;
    cin >> num;
    vector<string> cases;
    string tmp;
    for (int i = 0; i < num; i++) {
        cin >> tmp;
        cases.push_back(tmp);
    }

    // 进行修复
    for (int i = 0; i < num; i++) {
        if (i != num - 1) {

            cout << repair(cases[i]) << endl;
        } else {
            cout << repair(cases[i]);
        }
    }
    return 0;
}