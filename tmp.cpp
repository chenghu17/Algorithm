#include <iostream>
using namespace std;

class Book{
public:
    int number=0;
    int title=0;
};
int main(){
    // this space is used to do something unclear;
    //Book book = Book();
    Book book;
    cout<<book.number;
    int a=0,b=3;
    if(a==3 || b==3){
        cout<<a<<endl;
    }

    return 0;
}
