/*
*pydictionarychlng.cpp
*redoing a python dictionary challenge in C++
* a tiny simulation that gives you a situation and possible options from that situation. Kind of like a directed graph, except it is modeled using a dictionary
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

const size_t VOCABSIZE = 5;

typedef map<int, string>                        t_intmap;
typedef map<int, map<string, int>>              t_strmap;
typedef map<array<string, VOCABSIZE>, string>   t_vecmap;

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

    //vocab map with vocabulary words corresponding to a valid intended direction
    t_vecmap vocab = {
        { {"NORTH", "UP"}, "N" },
        { {"EAST", "RIGHT"}, "E" },
        { {"SOUTH", "DOWN"}, "S" },
        { {"WEST", "LEFT"}, "W" },
        { {"QUIT", "EXIT", "X"}, "Q" }
    };

    // current location of user
    int loc = 1;

    // display current (initial) location to user
    cout<<locations[loc]<<endl;
    
    // main game loop
    do{
        // stores intended direction input by user
        string direction = " ";

        // stores list of available options stored by program
        vector<string> exitKeys = {};

        // flag true when direction entered by user matches any one from available exitKeys
        bool validEntry = false;

        //Iterate through the current available exits, print them to user and populate the vector used for testing input validity also
        for(map<string, int>::iterator it = exits[loc].begin(); it != exits[loc].end(); it++){
            cout<<it->first<<", ";
            exitKeys.push_back(it->first);
        }
        cout<<": ";

        //receive user input for intended direction and uppercase it
        getline(cin, direction);
        transform(direction.begin(), direction.end(), direction.begin(), [](unsigned char c) -> unsigned char { return toupper(c); } );
        
        // in case user entered more than one word, take each word into account. 
        int beg = 0;
        int ind = 0;
        vector<string> tokenized;
        string tempDirection = direction + " ";
        if(tempDirection[0] == ' '){
            tempDirection = tempDirection.substr(1, tempDirection.length()-1);
        }
        do{
            ind = tempDirection.find(' ', beg == 0? beg: ++beg);
            if(ind >= 0){
                tokenized.push_back(tempDirection.substr(beg, ind-beg));
            }
            beg = ind;

        }while(ind != -1);
        //determine if user entered anything from the vocab list
        for(auto temp: tokenized){
            for(t_vecmap::iterator vic = vocab.begin(); vic != vocab.end(); vic++){
                if(find(vic->first.begin(), vic->first.end(), temp) != vic->first.end()){
                    direction = vic->second;
                }
            }
            //end for
        }

        //iterate through available exits in vector to determine whether user entered
        // a valid input. If valid input, location is updated and flag is set
        for(auto i: exitKeys){
            if(i == direction){
                loc = exits[loc][direction];
                validEntry = true;
                break;
            }       
            //end if
        }
        // end for

        // direction entered by user did not match any of the available exits. flag is still false, user should try again
        if(!validEntry)
            cout<<"Invalid entry: Try again"<<endl;
        else
            cout<<locations[loc]<<endl;
        //end if
    } while(loc != 0);   

    return 0;
}