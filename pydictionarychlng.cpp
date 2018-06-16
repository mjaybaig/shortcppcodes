#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef map<int, string> t_intmap;
typedef map<int, map<string, int>> t_strmap;

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
    cout<<locations[loc]<<endl;

    return 0;
}