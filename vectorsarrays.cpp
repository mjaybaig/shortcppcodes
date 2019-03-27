#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
int main(){
    int arr1[] = {2, 5, 78, 10};
    int arr2[] = {1, 67, 89};

    vector<int> arr3;

    int totalSize = ( sizeof(arr1)/sizeof(arr1[0]) ) + ( sizeof(arr2) / sizeof(arr2[0]) );
    arr3.reserve( totalSize );

    // cout<<totalSize<<endl;
    cout<<arr3.capacity()<<endl;
    cout<<sizeof(int)<<endl;
    cout<<endl;

    for(int i = 0; i<totalSize; i++){
        if(i < sizeof(arr1) / sizeof(arr1[0]) ){
            arr3.push_back(arr1[i]);
        }
        else{
            arr3.push_back(arr2[i - sizeof(arr2)/sizeof(arr2[0])-1]);
        }
    }

    for(int i = 0; i<totalSize; i++){
        cout<<arr3[i]<<endl;
    }

    array<int, 5> stdArray = {7, 6, 5, 4, 3};

    cout<<&stdArray+1<<endl;
    
    cin.get();
    return 0;
}