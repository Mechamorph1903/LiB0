#include <iostream>
#include "avlTreeImplementation.h"

void runLibrary(int& userChoice, AVLTree& library);
void addBook(AVLTree& library);
void searchBook(AVLTree& library);
void displayBooks(AVLTree& library);
//void updateBook(AVLTree& library);
//void deleteBook(AVLTree& library);

int main() {

	AVLTree library;
	int userChoice = -1;

	cout << "Welcome to Lib0" << endl;

	runLibrary(userChoice, library);

	return 0;
};


void runLibrary(int& userChoice, AVLTree& library) {
	while (userChoice != 6) {
		cout << "Please select an option :" << endl;
		cout << "1. Add a book" << endl;
		cout << "2. Search for a book" << endl;
		cout << "3. Display all books" << endl;
		cout << "4. Update a book" << endl;
		cout << "5. Delete a book" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> userChoice;
		cout << "\n";

		cin.clear();

		if (userChoice == 1) {
			cout << "Thanks for donating a book!" << endl;
			cout << "Let's get started!" << endl;
			cout << "====================" << endl;
			cout << "*NOTE: ISBN numbers must be greater than 9 digits and must be different from each entries respective ISBN number" << endl << "or else book addition will fail!*" << endl;
			addBook(library);
			cout << "\n";
			cout << "\n";
		}
		else if (userChoice == 2) {
			cout << "Searching for a book..." << endl;
			searchBook(library);
			cout << "\n";
			cout << "\n";
		}
		else if (userChoice == 3) {
			displayBooks(library);
			cout << "\n";
			cout << "\n";
		}
		else if (userChoice == 4) {
			cout << "Updating a book..." << endl;
			/*updateBook(library);*/
			cout << "\n";
			cout << "\n";
		}
		else if (userChoice == 5) {
			cout << "Deleting a book..." << endl;
			/*deleteBook(library);*/
			cout << "\n";
			cout << "\n";
		}
		else if (userChoice == 6) {
			cout << "Exiting the Lib0." << endl << "\n";
		}
		else {
			cout << "Invalid choice. Please try again." << endl << "\n";
		}
	}
};

void addBook(AVLTree& library) {
	string title = "";
	string author = "";
	int ISBN = 0;
	int year = 0;

	cout << "Enter book title: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, title);
	cout << "Enter book author: ";
	getline(cin, author);
	cout << "Enter book year: ";
	cin >> year;
	cout << "Enter book ISBN: ";
	cin >> ISBN;

	if ((title == "" && author == "" && year == 0 && ISBN == 0) || (title == " " && author == " " && year == 0 && ISBN == 0)) {
		cout << "You didn't even try, mate. Type the book details in! =(" << endl;
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
				cout << "Enter book ISBN: ";
				cin >> ISBN;
			}

		}
		cout << "All set! Adding your book to the library..." << endl;
		bool added = library.addBook(title, author, year, ISBN);
		if (added == true) {
			cout << "Book added successfully!" << endl;
			return;
		}
		else {
			cout << "Failed to add book. It may already exist." << endl;
			return;
		};
	}
};;

void searchBook(AVLTree& library) {
	int choice = 0;
	while (choice != 3) {
		cout << "How would you like to search for a book?" << endl;
		cout << "1. By ISBN" << endl;
		cout << "2. By Year" << endl;
		cout << "3. Exit to Main Menu" << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		if (choice == 1) {
			cout << "ISBN SEARCH" << endl;
			cout << "====================" << endl;
			int ISBN = 0;
			cout << "Enter ISBN: ";
			cin >> ISBN;

			while (ISBN < 1000000000) {
				cout << "Invalid ISBN. Please enter a valid ISBN (greater than 9 digits)." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter ISBN: ";
				cin >> ISBN;
			}

			vector<TreeNode*>result = library.searchBookByISBN(ISBN);

			if (result.empty()) {
				cout << "No book found with the given ISBN." << endl;
				return;
			}
			else {
				for (TreeNode* book : result) {
					cout << "Book found: " << endl;
					library.printBookdetails(book);
				}
				return;
			}
		} else if (choice == 2) {
			cout << "YEAR SEARCH" << endl;
			cout << "====================" << endl;
			int year = 0;
			cout << "Enter Year: ";
			cin >> year;
			while (year <= 0) {
				cout << "Invalid year. Please enter a valid year." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Enter Year: ";
				cin >> year;
			}
			vector<TreeNode*> result = library.searchBookbyYear(year);

			if (result.empty()) {
				cout << "No book found for the given year." << endl;
				return;
			}
			else {
				int count = 1;
				cout << "Books found for the year " << year << ":" << endl;
				for (TreeNode* book : result) {
					cout << "Book " << count << ": " << endl;
					library.printBookdetails(book);
					count++;
				}
				return;
			}
		}
		else if (choice == 3) {
			cout << "Returning to main menu..." << endl;
			return;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}
	}
};

void displayBooks(AVLTree& library) {
	cout << "Displaying all books in the library..." << endl;
	library.displayAllBooks();
};

