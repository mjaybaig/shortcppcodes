#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

bool findElement(vector<string> els, string el);

int main()
{
    vector<vector<string>> meals { {"spam", "sausages", "egg"} };
    meals.push_back({"egg", "sausages", "bacon"});
    meals.push_back({"egg", "meat", "spam"});
    meals.push_back({"eggs", "sausages"});

    for(int i = 0; i<meals.capacity(); i++){
        if(!findElement(meals[i], "spam")){
            for(int j = 0; j<meals[i].capacity(); j++){
                cout<<meals[i][j]<<endl;
            }
        }
    }
    cin.get(); 
    return 0;
}

bool findElement(vector<string> els, string el){
    for(int i = 0; i<els.capacity(); i++){
        if(els[i] == el){
            return true;
        }
    }
    return false;
}