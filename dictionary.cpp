#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> something;

    string newWorld("Hello World");
    something["Hello"] = newWorld;

    cout<<something["Hello"]<<endl;
    cin.get();
    return 0;
}