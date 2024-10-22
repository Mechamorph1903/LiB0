#pragma once
#include <iostream>
#include "TreeNode.h"

using std::cout;
using std::cin;
using std::endl;

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

		bool searchBookbyISBN(int ISBN) {
			if (root == nullptr) {
				return false;
			}
			else {
				return searchBookByISBN(ISBN, root);
			}

		};

		void displayAllBooks() {
			if (root == nullptr) {
				cout << "No books in the library." << endl;
				return;
			}
			else {
				displayAllBooks(root);
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


		bool searchBookByISBN(int ISBN, TreeNode* node) {
			if (node == nullptr) {
				return false;
			}
			if (node->ISBN == ISBN) {
				return true;
			}
			else if (ISBN < node->ISBN) {
				return searchBookByISBN(ISBN, node->left);
			}
			else {
				return searchBookByISBN(ISBN, node->right);
			}
		};

		void displayAllBooks(TreeNode* node) {
			if (node == nullptr){
				return;
			}
			cout << "Title: " << node->title << endl<< "\t" << "Author: " << node->author << endl << "Publication Year: " << node->year << endl << "ISBN: " << node->ISBN << endl << "\n";
			displayAllBooks(node->left);
			displayAllBooks(node->right);
		};
};
