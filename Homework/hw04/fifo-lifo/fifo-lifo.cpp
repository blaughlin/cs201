#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void FifoPush(vector<string> & container, const string & item){

}

void FifoPop(vector<string> & container,  string & item){

}

void LifoPush(vector<string> & container, const string & item){

}

void LifoPop(vector<string> & container,  string & item){

}

bool IsContainerEmpty(const vector<string> & container){

}

// Prints out content of container
void PrintContainer(const vector<string> & container){
    for (auto i : container) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<string> myVector = {"one", "two", "three"};
    PrintContainer(myVector);
    return 0;
}
