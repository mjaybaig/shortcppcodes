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


    bool validEntry = false;
    string canGo = "";
    cout<<"Where would you like to go from here: ";
    
    for(map<string, int>::iterator it = exits[loc].begin(); it != exits[loc].end(); ++it){
        cout<<it->first<<", ";
    }

    cout<<": ";
    getline(cin, direction);
    transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) -> unsigned char{ return toupper(c); } );
    
    for(map<string, int>::iterator it = exits[loc].begin(); it != exits[loc].end(); ++it){
        canGo += it->first + ", ";
        if(it->first == direction)
            validEntry = true;
        // end if
    }

    do{
        if(validEntry == false){
            cout<<"You cannot go here. Please try again"<<endl;
        }
        else{
            validEntry = false;
            loc = exits[loc][direction];

            cout<<locations[loc]<<endl;

            for(map<string, int>::iterator it = exits[loc].begin(); it != exits[loc].end(); ++it){
                canGo = "";
                canGo += it->first + ", ";
                if(it->first == direction)
                    validEntry = true;
                // end if
            }
        }
        cout<<"Where would you like to go from here: "<<canGo<<": ";
        getline(cin, direction);
        transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) -> unsigned char{ return toupper(c); } );
    } while (loc != 0);

    return 0;
}