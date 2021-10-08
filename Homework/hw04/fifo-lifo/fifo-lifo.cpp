// fifo-lifo.cpp
// Bernard Laughlin 10/7/2021
// Implements LIFO and FIFO functionality for cs201

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

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

// Test for Fifo functions
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

// Test for Lifo functions
bool TestLifo() {
    bool pass = false;
    string item;
    vector<string> key = {"D", "C", "B", "A"};
    vector<string> test;
    LifoPush(test, "A");
    LifoPush(test, "B");
    LifoPush(test, "C");
    LifoPush(test, "D");
    if (test == key) pass = true;
    LifoPop(test, item);
    if (item == "D"){
        pass = true;
    } else {
        pass = false;
    }
    LifoPop(test, item);
    if (item == "C"){
        pass = true;
    } else {
        pass = false;
    }
    LifoPop(test, item);
    if (item == "B"){
        pass = true;
    } else {
        pass = false;
    }
    LifoPop(test, item);
    if (item == "A"){
        pass = true;
    } else {
        pass = false;
    }
    return pass;
}

void PrintMenu(int &input) {
    cout << "*******************************" << endl;
    cout << "1. FifoPush" << endl;
    cout << "2. FifoPop" << endl;
    cout << "3. LifoPush" << endl;
    cout << "4. LifoPop" << endl;
    cout << "5. Print container" << endl;
    cout << "6. Quit" << endl;
    cout << "*******************************" << endl;
    cout << "Enter 1 through 6: ";
    string line;
    std::getline(cin, line);
    istringstream instream(line);
    instream >> input;
    if (!instream){
        cout << "Invalid input." << endl;
    }
}

void getInput(string &input){
    std::getline(cin, input);
    istringstream instream(input);
    instream >> input;
    if (!instream){
        cout << "Invalid input." << endl;
    }
}

int main() {
    string input;
    string myString;
    vector<string> empty;
    int choice;
     while (choice != 6) {
         PrintMenu(choice);
         switch(choice) {
             case 1: {
                 cout << "Type item to FifoPush ";
                 getInput(input);
                 FifoPush(empty, input);
                 break;
             }
             case 2:
                 if (!IsContainerEmpty(empty)) {
                     FifoPop(empty, myString);
                     cout << myString << " removed." << endl;
                 } else  cout << "Container is empty" << endl;
                 break;
             case 3:
                 cout << "Type item to LifoPush ";
                 getInput(input);
                 LifoPush(empty, input);
                 break;
             case 4:
                 if (!IsContainerEmpty(empty)) {
                     LifoPop(empty, myString);
                     cout << myString << " removed." << endl;
                 } else cout << "Container is empty" << endl;
                 break;
             case 5:
                 PrintContainer(empty);
                 break;
             default:
                 if (choice != 6) cout << "Invalid input" << endl;
                 break;
         }
     }
    return 0;
}
