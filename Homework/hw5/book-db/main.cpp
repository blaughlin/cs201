// book-db.cpp
// Bernard Laughlin 10/26/2021
// Books database program that lists all books owned, loaned out, not loaned out. You can
// also search for book by ISBN, Title, Author, Year

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

struct Book {
    int isbn;
    string title;
    string author;
    int year;
    bool isLoanedOut;
};

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

void ListAllBooksOwned(const vector<Book> & books){
    for(auto i : books){
        cout << i.title << ", " << i.author << ", " << i.year  << ", ISBN: " << i.isbn << endl;
    }
}

int main() {
    vector<Book> library = CreateBooks();
    ListAllBooksOwned(library);
    return 0;
}
