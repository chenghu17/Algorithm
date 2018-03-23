#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(){

    int t=0;
    cin>>t;
    vector<int> x[t];
    vector<int> y[t];
    vector<double> sides[t];
    for(int i=0;i<t;i++){
        //输入具体的数据
        for(int j=0;j<4;j++){
            int x_num=0;
            cin>>x_num;
            x[i].push_back(x_num);
        }
        for(int k=0;k<4;k++){
            int y_num=0;
            cin>>y_num;
            y[i].push_back(y_num);
        }
    }


    for(int i=0;i<t;i++){
        for(int j=0,k=0;j<4,k<4;j++,k++){
            for(int m=j+1,n=k+1;m<4,n<4;m++,n++){

                //绝对值还有问题
                double side = pow(abs(x[i][j]-x[i][m]),2)+pow(abs(y[i][m]-y[i][n]),2);

                sides[i].push_back(side);
            }
        }
    }
}
