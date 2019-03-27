#include <iostream>
#include <vector>

using namespace std;


template<class T> class dictionaryItem{
    private:
        string key;
        T value;
    public:
        dictionaryItem(string k, T &v){
            key = k;
            value = v;
        }
        string getKey(){
            return key;
        }
        T getValue(){
            return value;
        }
};

template<class F> class dictionary{
    private:
        vector<dictionaryItem<F>> items;

    public:
        bool addItem(string key, F value){
            try{
                dictionaryItem<F> * newItem = new dictionaryItem<F>(key, &value);
                items.push_back(*newItem);
            }
            catch(exception e){
                cout<<e.what()<<endl;
                return false;
            }
            return true;
        }
        vector<dictionaryItem<F>> getList(){
            return items;
        }

        void printItems(){
            for(int i = 0; i<items.capacity(); i++){
                cout<<items[i].getKey()<<endl;
            }
        }
};


int main(){
    dictionary<int> newDict;

    newDict.addItem("Hello", 5);
    newDict.addItem("Something", 10);

    newDict.printItems();
    
    return 0;    
}