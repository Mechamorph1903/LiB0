#include <iostream>
#include "avlTreeImplementation.h"

void runLibrary(int userChoice, AVLTree& library);
void addBook(AVLTree& library);
//void searchBook(AVLTree& library);
//void displayBooks(AVLTree& library);
//void updateBook(AVLTree& library);
//void deleteBook(AVLTree& library);

int main() {

	AVLTree library;
	int userChoice = -1;

	cout << "Welcome to the Library Management System" << endl;

	runLibrary(userChoice, library);

	return 0;
};


void runLibrary(int userChoice, AVLTree& library) {
	while (userChoice != 6) {
		cout << "Please select an option :" << endl;
		cout << "1. Add a book" << endl;
		cout << "2. Search for a book" << endl;
		cout << "3. Display all books" << endl;
		cout << "4. Update a book" << endl;
		cout << "5. Delete a book" << endl;
		cout << "6. Exit" << endl;
		cin >> userChoice;

		cin.clear();

		if (userChoice == 1) {
			cout << "Thanks for donating a book!" << endl;
			cout << "Let's get started!" << endl;
			cout << "====================" << endl;
			cout << "*NOTE: ISBN numbers must be greater than 9 digits! and must be different from each entries respective ISBN number or else book addition will fail.*" << endl;
			addBook(library);
		}
		else if (userChoice == 2) {
			/*searchBook(library);*/
			return;
		}
		else if (userChoice == 3) {
			/*displayBooks(library);*/
			return;
		}
		else if (userChoice == 4) {
			/*updateBook(library);*/
			return;
		}
		else if (userChoice == 5) {
			/*deleteBook(library);*/
			return;
		}
		else if (userChoice == 6) {
			cout << "Exiting the Library Management System." << endl;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}
	}
};

void addBook(AVLTree& library) {
	string title = "";
	string author = "";
	int ISBN = 0;
	int year = 0;

	cout << "Enter book title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter book author: ";
	getline(cin, author);
	cout << "Enter book year: ";
	cin >> year;
	cout << "Enter book ISBN (must be greater than 9 figures to be valid): ";
	cin >> ISBN;

	if (title == "" && author == "" && year == 0 && ISBN == 0) {
		cout << "You didn't even try, mate. Type the book details in! =(" << endl;

		/*cout << "Enter book title: ";
		cin.ignore();
		getline(cin, title);
		cout << "Enter book author: ";
		getline(cin, author);
		cout << "Enter book year: ";
		cin >> year;
		cout << "Enter book ISBN: ";
		cin >> ISBN;*/

		addBook(library);
	}
	else {
		while (title == "" || author == "" || year <= 0 || ISBN <= 0) { // implement isbn less than 10 kater			cout << "Something(s) are missing. Let's find out what! =?" << endl;
			if (title == "") {
				cout << "Title is missing." << endl;
				cout << "Enter book title: ";
				cin.ignore();
				getline(cin, title);
			}
			if (author == "") {
				cout << "Author is missing." << endl;
				cout << "Enter book author: ";
				cin.ignore();
				getline(cin, author);
			}
			if (year <= 0) {
				cout << "Year is missing or invalid." << endl;
				cout << "Enter book year: ";
				cin >> year;
			}
			if (ISBN <= 0) {
				cout << "ISBN is missing or invalid." << endl;
				cout << "Enter book ISBN (must be 10 or more digits!): ";
				cin >> ISBN;
			}

		}
		cout << "All set! Adding your book to the library..." << endl;
		library.addBook(title, author, year, ISBN);
		if (library.addBook(title, author, year, ISBN)) {
			cout << "Book added successfully!" << endl;
			return;
		}
		else {
			cout << "Failed to add book. It may already exist." << endl;
			return;
		};
	}
}