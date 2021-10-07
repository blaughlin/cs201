#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


// Returns true if container is empty
bool IsContainerEmpty(const vector<string> & container){
    if (container.size() == 0) return true;
    return false;
}

// Appends item to beginning of vector
void FifoPush(vector<string> & container, const string & item){
    auto it = container.begin();
    it = container.insert(it, item);
}

// Removes first element from vector and assigns it to item
void FifoPop(vector<string> & container,  string & item){
    if (!IsContainerEmpty(container)) {
        item = container[0];
        container.erase(container.begin());
    } else {
        cout << "Error: Container is empty!" << endl;
    }
}

//void LifoPush(vector<string> & container, const string & item){
//
//}
//
//void LifoPop(vector<string> & container,  string & item){
//
//}


// Prints out content of container
void PrintContainer(const vector<string> & container){
    for (auto i : container) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    string myString;
    vector<string> empty;
    vector<string> myVector = {"one", "two", "three"};
    FifoPush(myVector, "four");
    PrintContainer(myVector);
    FifoPop(empty, myString);
    PrintContainer(myVector);
    cout << myString;

    return 0;
}
