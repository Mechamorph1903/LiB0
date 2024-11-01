#pragma once
#include <iostream>
#include <vector>

#include "TreeNode.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::getline;

class AVLTree {
	private:
		TreeNode* root = nullptr;
		int count = 0;
		

	public:
        bool addBook(std::string title, std::string author, int year, int ISBN) {
            // Adding a book to the AVLTree
            if (root == nullptr) {
                root = new TreeNode;
                root->ISBN = ISBN;
                root->title = title;
                root->author = author;
                root->year = year;
                count++;
                return true;
            } else {
                bool added = addBook(title, author, year, ISBN, root);
                if (added) {
                    // Update height of this ancestor node
                    root->height = 1 + std::max(height(root->left), height(root->right));

                    // Get the balance factor of this ancestor node
                    int balance = getBalance(root);

                    // If this node becomes unbalanced, then there are 4 cases

                    // Left Left Case
                    if (balance > 1 && ISBN < root->left->ISBN)
                        root = rightRotate(root);

                    // Right Right Case
                    if (balance < -1 && ISBN > root->right->ISBN)
                        root = leftRotate(root);

                    // Left Right Case
                    if (balance > 1 && ISBN > root->left->ISBN) {
                        root->left = leftRotate(root->left);
                        root = rightRotate(root);
                    }

                    // Right Left Case
                    if (balance < -1 && ISBN < root->right->ISBN) {
                        root->right = rightRotate(root->right);
                        root = leftRotate(root);
                    }
                }
                return added;
            }
        }

		bool deleteBook(int ISBN) {
			int originalCount = count;
			root = deleteNode(root, ISBN);
			return count < originalCount;  // Return true if a node was deleted
		}

		vector<TreeNode*> searchBookByISBN(int ISBN) {
			vector<TreeNode*> result;

			if (root == nullptr) {
				return result;
			}
			else {
				return searchBookByISBN(ISBN, root);
			}

		};

		vector<TreeNode*> searchBookbyYear(int year) {
			vector<TreeNode*> result;

			if (root == nullptr) {
				return result;
			}
			else {
				return searchBookByYear(year, root);
			}

		};

		void displayAllBooks() {
			if (root == nullptr) {
				cout << "No books in the library." << endl;
				return;
			}
			else {
				int counter = 1;
				displayAllBooks(root, counter);
			}
		};

		void printBookdetails(TreeNode* node) {
			cout << "Title: " << node->title << endl
				<< "\t" << "Author: " << node->author << endl
				<< "\t" << "Publication Year: " << node->year << endl
				<< "\t" << "ISBN: " << node->ISBN << endl
				<< "\n";
		};

		bool updateBook(int ISBN) {
			vector<TreeNode*> result = searchBookByISBN(ISBN);
			if (result.empty()) {
				cout << "No book found with the given ISBN." << endl;
				return false;
			}
			else {
					/*char userSelect;
					cout << "Do you want to update the ISBN no? (Y/N): ";
				cin >> userSelect;
				userSelect = toupper(userSelect);*/
				for (TreeNode* book : result) {
					cout << "Book found: " << endl;
					printBookdetails(book);

					cin.ignore();
					cout << "Enter new title: ";
					getline(cin, book->title);
					cout << "Enter new author: ";
					getline(cin, book->author);
					cout << "Enter new publication year: ";
					cin >> book->year;
					cin.ignore();
				
					//if (userSelect == 'Y') {
					//	int newISBN;
					//	cout << "Enter new ISBN: ";
					//	cin >> newISBN;

					//	// Remove node with the old ISBN and reinsert with new ISBN
					//	deleteBook(book->ISBN);
					//	if (!addBook(book->title, book->author, book->year, newISBN)) {
					//		cout << "Error updating book with new ISBN." << endl;
					//		return false;
					//	}
					//} will fix soon, causing errors as of now

					cout << "Book updated successfully." << endl;
				}
				return true;

			}
		}

	private:
		//utility functions

		// Get the height of the tree
		int height(TreeNode* N) {
			if (N == nullptr)
				return 0;
			return N->height;
		}

		// Right rotate subtree rooted with y
		TreeNode* rightRotate(TreeNode* y) {
			TreeNode* x = y->left;
			TreeNode* T2 = x->right;

			// Perform rotation
			x->right = y;
			y->left = T2;

			// Update heights
			y->height = std::max(height(y->left), height(y->right)) + 1;
			x->height = std::max(height(x->left), height(x->right)) + 1;

			// Return new root
			return x;
		}

		// Left rotate subtree rooted with x
		TreeNode* leftRotate(TreeNode* x) {
			TreeNode* y = x->right;
			TreeNode* T2 = y->left;

			// Perform rotation
			y->left = x;
			x->right = T2;

			// Update heights
			x->height = std::max(height(x->left), height(x->right)) + 1;
			y->height = std::max(height(y->left), height(y->right)) + 1;

			// Return new root
			return y;
		}

		// Get balance factor of node N
		int getBalance(TreeNode* N) {
			if (N == nullptr)
				return 0;
			return height(N->left) - height(N->right);
		}






		//Recursive Functions
		bool addBook(string title, string author, int year, int ISBN, TreeNode* node) {
			if (ISBN < node->ISBN) {
				if (node->left == nullptr) {
					node->left = new TreeNode;
					node->left->ISBN = ISBN;
					node->left->title = title;
					node->left->author = author;
					node->left->year = year;
					node->left->parent = node;
					count++;
					return true;
				}
				else {
					return addBook(title, author, year, ISBN, node->left);
				}
			}
			else if (ISBN > node->ISBN) {
				if (node->right == nullptr) {
					node->right = new TreeNode;
					node->right->ISBN = ISBN;
					node->right->title = title;
					node->right->author = author;
					node->right->year = year;
					node->right->parent = node;
					count++;
					return true;
				}
				else {
					return addBook(title, author, year, ISBN, node->right);
				}
			}
			else {
				// ISBN already exists
				return false;
			}
		}

		TreeNode* deleteNode(TreeNode* node, int ISBN) {
			if (node == nullptr)
				return node;

			// Traverse the tree to find the node
			if (ISBN < node->ISBN)
				node->left = deleteNode(node->left, ISBN);
			else if (ISBN > node->ISBN)
				node->right = deleteNode(node->right, ISBN);
			else {
				// Node with only one child or no child
				if (node->left == nullptr || node->right == nullptr) {
					TreeNode* temp = node->left ? node->left : node->right;
					if (temp == nullptr) {  // No child case
						temp = node;
						node = nullptr;
					}
					else {  // One child case
						*node = *temp;
					}
					delete temp;
					count--;  // Decrement count of nodes
				}
				else {
					// Node with two children
					TreeNode* temp = minValueNode(node->right);

					// Copy the in-order successor's data
					node->ISBN = temp->ISBN;
					node->title = temp->title;
					node->author = temp->author;
					node->year = temp->year;

					// Delete the in-order successor
					node->right = deleteNode(node->right, temp->ISBN);
				}
			}

			// If the tree had only one node, return
			if (node == nullptr)
				return node;

			// Update height and balance the tree
			node->height = 1 + std::max(height(node->left), height(node->right));
			int balance = getBalance(node);

			// Perform rotations to balance the tree
			if (balance > 1 && getBalance(node->left) >= 0)
				return rightRotate(node);

			if (balance > 1 && getBalance(node->left) < 0) {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}

			if (balance < -1 && getBalance(node->right) <= 0)
				return leftRotate(node);

			if (balance < -1 && getBalance(node->right) > 0) {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}

			return node;
		}

		// Find the node with the minimum ISBN in the tree
		TreeNode* minValueNode(TreeNode* node) {
			TreeNode* current = node;
			while (current->left != nullptr)
				current = current->left;
			return current;
		}



		vector<TreeNode*> searchBookByISBN(int ISBN, TreeNode* node) {
			vector<TreeNode*> result;
			if (node == nullptr) {
				return result;
			}
			if (node->ISBN == ISBN) {
				result.push_back(node);
				return result;
			}
			else if (ISBN < node->ISBN) {
				return searchBookByISBN(ISBN, node->left);
			}
			else {
				return searchBookByISBN(ISBN, node->right);
			}
		};


		vector<TreeNode*> searchBookByYear(int year, TreeNode* node) {
			vector<TreeNode*> result;
			if (node == nullptr) {
				return result;
			}
			if (node->year == year) {
				result.push_back(node);
			}
			vector<TreeNode*> leftResult = searchBookByYear(year, node->left);
			vector<TreeNode*> rightResult = searchBookByYear(year, node->right);
			result.insert(result.end(), leftResult.begin(), leftResult.end());
			result.insert(result.end(), rightResult.begin(), rightResult.end());
			return result;
		};

		void displayAllBooks(TreeNode* node, int &counter) {
			if (node == nullptr){
				return;
			}
			displayAllBooks(node->left, counter);
			cout << counter << ". Title: " << node->title << endl
				<< "\t" << "Author: " << node->author << endl
				<< "\t" << "Publication Year: " << node->year << endl
				<< "\t" << "ISBN: " << node->ISBN << endl
				<< "\n";			counter++;
			displayAllBooks(node->right, counter);
		};
};
