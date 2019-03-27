#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int START = 3;
const int STOP = 40;
const int STEP = 3;
const int VSIZE = ( STOP - START ) / STEP + 1;

void doSomething(int a){
    cout<<"Wut"<<a<<endl;
}

int main(){
    vector<int> myRange;

    myRange.reserve(VSIZE);

    for(int i = START; i <= STOP; i += STEP){
        myRange.push_back(i);
    }

    // for(const auto el : myRange){
    //     cout<<el<<endl;
    // }
    for_each(myRange.begin(), myRange.end(), [](int a){ cout<<"Hello"<<a<<endl;});
    cin.get();
    return 0;
}