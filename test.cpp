#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    // string strs[] = {"Number 1", "Number 2"};
    // string strs2[] = {"Number 3", "Number 4"};
    
    // const int SIZE1 = sizeof(strs)/sizeof(strs[0]);
    // const int SIZE2 = sizeof(strs2)/sizeof(strs2[0]);
    // const int SIZE3 = SIZE1 + SIZE2;
    // // for(int i = 0; i < sizeof(strs)/sizeof(strs[0]); i++){
    // //     cout<<"#"<<i+1<<": "<<strs[i]<<endl;
    // // }

    // string strTotal[SIZE3] = {};

    // for(int i = 0; i<SIZE3; i++){
    //     if(i < SIZE1){
    //         strTotal[i] = strs[i];
    //     }
    //     else{
    //         strTotal[i] = strs2[i-SIZE2];
    //     }
    // }

    // for(int i = 0; i<SIZE3; i++){
    //     cout<<strTotal[i]<<", ";
    // }

    // cin.get();
    string helloworld("Hey There What is up");

    helloworld += " ";
    // while(helloworld.find(" ") != -1){

    // }
    int ind = helloworld.find(" ");
    cout<<ind<<endl;
    cout<<helloworld.substr(0, ind);
    // cout<<helloworld.substr(ind, hello);
    int beg = 0;
    vector<string> tokenized;
    do{
        ind = helloworld.find(' ', beg == 0? beg: ++beg);
        if(ind >= 0){
            tokenized.push_back(helloworld.substr(beg, ind-beg));
        }
        beg = ind;

    }while(ind != -1);

    return 0;
}


/*
"Hi How are you"
beg = 0
find = find next space
substring from beg to find into tokenized[]
beg = find
find = find next space
until find = -1

*/
void something(string a){
    if(a.find(" ") == -1)
        return;
    //end if
    else{

    }
}

