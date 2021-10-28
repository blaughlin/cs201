// book-db.cpp
// Bernard Laughlin 10/26/2021
// Books database program that lists all books owned, loaned out, not loaned out. You can
// also search for book by ISBN, Title, Author, Year
// todo Pretty up output
// todo Make function to return lowercase

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
#include <iomanip>

struct Book {
    int isbn;
    string title;
    string author;
    int year;
    bool isLoanedOut;
};

// Returns a vector of 20 books
vector<Book> CreateBooks() {
    vector<Book> library;
    library.push_back({123, "To Kill a Mockingbird", "Harper Lee", 1960, false });
    library.push_back({124, "Great Expectations", "Charles Dickens", 1861, true });
    library.push_back({125, "Moby Dick", "Herman Melville", 1851, false });
    library.push_back({126, "The Old Man and the Sea", "Ernest Hemingway", 1952, false });
    library.push_back({127, "The Grapes of Wrath", "John Steinbeck", 1939, true });
    library.push_back({128, "I Know Why the Caged Bird Sings", "Maya Angelou", 1969, false });
    library.push_back({129, "The Hours", "Michael Cunningham", 1998, false });
    library.push_back({130, "The Shipping News", "Annie Proulx", 1993, false });
    library.push_back({131, "The Fountainhead", "Ayn Rand", 1943, false });
    library.push_back({132, "The Painted Bird", "Jerzy Kosinski", 1965, true });
    library.push_back({133, "Middlesex", "Jeffrey Eugenides", 2002, false });
    library.push_back({134, "Things Fall Apart", "Chinua Achebe", 1958, false });
    library.push_back({135, "The Great Gatsby", "F. Scott Fitzgerald", 1925, false });
    library.push_back({136, "Oliver Twist", "Charles Dickens", 1838, true });
    library.push_back({137, "Tortilla Flat", "John Steinbeck", 1935, false });
    library.push_back({138, "Cannery Row", "John Steinbeck", 1945, false });
    library.push_back({139, "The Firm", "John Grisham", 1991, false });
    library.push_back({140, "Three Junes", "Julia Glass", 2002, false });
    library.push_back({141, "The Lovely Bones", "Alice Sebold", 2002, false });
    library.push_back({142, "Salem's Lot", "Stephen King", 1975, false });
    library.push_back({143, "It", "Stephen King", 1986, true });
    return library;
}

// Print Header
void PrintHeader() {
    cout << "____________________________________________________________________________" << endl;
    cout << std::left << std::setw(35) << "TITLE";
    cout << std::left << std::setw(25) << "AUTHOR";
    cout << std::left << std::setw(10) << "YEAR";
    cout << std::left << std::setw(10) << "ISBN" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

// Prints out books with formatting applied
void PrintBook(const Book & i) {
    cout << std::left << std::setw(35) << i.title;
    cout << std::left << std::setw(25) << i.author;
    cout << std::left << std::setw(10) << i.year;
    cout << std::left << std::setw(10) << i.isbn << endl;
}

// Prints out all books owned
void ListAllBooksOwned(const vector<Book> & books){
    PrintHeader();
    for(const auto & i : books){
        PrintBook(i);
    }
}

// Prints out all books loaned out
void ListBooksLoanedOut(const vector<Book> & books){
    PrintHeader();
    for (const auto & i : books){
        if (i.isLoanedOut) {
            PrintBook(i);
        }
    }
}

// Prints out all books not loaned out
void ListBooksNotLoanedOut(const vector<Book> & books){
    PrintHeader();
    for (const auto & i : books){
        if (!i.isLoanedOut) {
            PrintBook(i);
        }
    }
}

// Search for title, author, year, and isbn and returns true and vector of book results
// found and false and empty vector if nothing is found
std::pair<bool, vector<Book>> Search(const string & key, const vector<Book> & books ){
    vector<Book> results;
    for(const auto & i : books){
        std::size_t foundTitle = i.title.find(key);
        std::size_t foundAuthor = i.author.find(key);
        std::size_t foundYear = std::to_string(i.year).find(key);
        std::size_t foundISBN = std::to_string(i.isbn).find(key);
        if (foundTitle !=std::string::npos || foundAuthor !=std::string::npos ||
         foundYear !=std::string::npos || foundISBN !=std::string::npos) results.push_back(i);
    }
    if (!results.empty()) return std::make_pair(true, results);
    return std::make_pair(false, results);
}


// Prints menu options and prompts user for selection and returns int selected
int GetInput(){
    int choice;
    string input;
    while (true){
        cout << "**************************************************" << endl;
        cout << "* 1. List all books I own.                       *" << endl;
        cout << "* 2. List all books loaned out.                  *" << endl;
        cout << "* 3. List all books not loaned out.              *" << endl;
        cout << "* 4. Search for a book.                          *" << endl;
        cout << "* 5. Quit.                                       *" << endl;
        cout << "**************************************************" << endl;
        cout << "Please make a selection: ";
        std::getline(cin, input);
        std::istringstream istream(input);
        istream >> choice;
        if (!istream) cout << "Invalid input. Please try again." << endl;
        if (choice >= 1 && choice <= 5) break;
        cout << "Please enter a number between 1 and 5." << endl;
    }
    return choice;
}

int main() {
    string key;
    int choice;
    bool isDone = false;
    vector<Book> library = CreateBooks();
    while (!isDone) {
        choice = GetInput();
        switch (choice) {
            case 1:
                ListAllBooksOwned(library);
                break;
            case 2:
                ListBooksLoanedOut(library);
                break;
            case 3:
                ListBooksNotLoanedOut(library);
                break;
            case 4: {
                while (true) {
                    cout << "Please enter search term: " << endl;
                    std::getline(cin, key);
                    // Prevent from displaying all books if a blank space is entered or nothing is entered
                    if (!key.empty()  && key != " ") break;
                }

                std::pair<bool, vector<Book>> results = Search(key, library);
                if (results.first) {
                    PrintHeader();
                    for (const auto & i : results.second){
                        PrintBook(i);
                    }
                } else { cout << "Nothing found." << endl; }
            }
            break;

            default:
                isDone = true;
        }
    }
    return 0;
}
