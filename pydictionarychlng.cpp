#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
// #include <array>

using namespace std;

typedef map<int, string> t_intmap;
typedef map<int, map<string, int>> t_strmap;
// const size_t ARRBUFFSIZE = 50;
int main(){
    
    t_intmap locations = {
        { 0, "You are sitting in front of a computer" },
        { 1, "You are standing in front of a road" },
        { 2, "You are at the top of a hill" },
        { 3, "You are inside a building" },
        { 4, "You are in a valley beside a stream" },
        { 5, "You are in the forest" }
    };

    t_strmap exits = {
        { 0, { { "Q", 0 } } },
        { 1, { { "W", 2 }, { "E", 3 }, { "N", 5 }, { "S", 4 }, {"Q", 0} } },
        { 2, { { "N", 5 }, { "Q", 0 } } },
        { 3, { { "W", 1 }, { "Q", 0 } } },
        { 4, { { "N", 1 }, { "W", 2 }, { "Q", 0} } },
        { 5, { { "W", 2 }, { "S", 1 }, { "Q", 0} } }
    };

    int loc = 1;
    string direction = " ";
    string goptions = "";
    vector<string> exitKeys = {};
    bool validEntry = false;
    // array<string, ARRBUFFSIZE> exitKeys = {};
    cout<<locations[loc]<<endl;

    // size_t one = sizeof(map<string, int>::iterator);

    //Iterate through the current available exits and prepare the string of options, and populate the vector also
    for(map<string, int>::iterator it = exits[loc].begin(); it != exits[loc].end(); it++){
        goptions += it->first + ", ";
        exitKeys.push_back(it->first);
    }
    cout<<goptions<<": ";

    //receive user input for intended direction and uppercase it
    getline(cin, direction);
    transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) -> unsigned char { return toupper(c); } );

    //iterate through available exits in vector
    for(auto i: exitKeys){
        if(i == direction){
            loc = exits[loc][direction];
            validEntry = true;
        }       
        //end if
    }
    // end for

    if(!validEntry)
        cout<<"Invalid entry: Try again"<<endl;
    else
        cout<<locations[loc]<<endl;
    //end if
    

    return 0;
}