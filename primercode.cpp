#include <iostream>
#include <string>

using namespace std;

void remodel(string & str){
    string * ps = new string(str);
    // cout<<ps[2]<<endl;
    (*ps)[0] = 'n';
    // ps->at(1) = 'e';
    // cout<<*ps<<endl;
    // if(ps[1] == 'a'){
    //     cout<<"Yes"<<endl;
    // }
    cout<<*ps<<endl;
    delete ps;
}

int main(){
    // string str = "Hello world";

    // remodel(str);
    // int a = 9;
    // int *ptA = &a;
    char ch[5];
    // if(s == nullptr){
    //     cout<<"hi"<<endl;
    // }
    cout<<ch<<endl;
    // cout<<ptA<<endl;
    // cout<<str<<endl;
    cin.get();
    return 0;
}