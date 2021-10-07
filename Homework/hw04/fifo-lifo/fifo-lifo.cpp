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
    container.push_back(item);

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

// appends item to end of container
void LifoPush(vector<string> & container, const string & item){
    auto it = container.begin();
    it = container.insert(it, item);
}

// Removes last element from vector and assigns it to item
void LifoPop(vector<string> & container,  string & item) {
    if (!IsContainerEmpty(container)) {
        item = container[0];
        container.erase(container.begin());
    } else {
        cout << "Error: Container is empty!" << endl;
    }
}

// Prints out content of container
void PrintContainer(const vector<string> & container){
    for (auto i : container) {
        cout << i << " ";
    }
    cout << endl;
}

bool TestFifo() {
    bool pass = false;
    string item;
    vector<string> key = {"A", "B", "C", "D"};
    vector<string> test;
    FifoPush(test, "A");
    FifoPush(test, "B");
    FifoPush(test, "C");
    FifoPush(test, "D");
    if (test == key) pass = true;
    FifoPop(test, item);
    if (item == "A"){
        pass = true;
    } else {
        pass = false;
    }
    FifoPop(test, item);
    if (item == "B"){
        pass = true;
    } else {
        pass = false;
    }
    FifoPop(test, item);
    if (item == "C"){
        pass = true;
    } else {
        pass = false;
    }
    FifoPop(test, item);
    if (item == "D"){
        pass = true;
    } else {
        pass = false;
    }
    return pass;
}

int main() {
    string myString;
    vector<string> empty;
    vector<string> myVector = {"one", "two", "three"};
    LifoPush(empty, "A");
    LifoPush(empty, "B");
    LifoPush(empty, "C");
    LifoPush(empty, "D");
    PrintContainer(empty);
    LifoPop(empty, myString);
    PrintContainer(empty);



    cout << TestFifo();
    return 0;
}
