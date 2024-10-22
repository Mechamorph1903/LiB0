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
		bool addBook(string title, string author, int year, int ISBN) {
			//Adding a bok to the AVLTree
			if (root == nullptr) {
				root = new TreeNode;
				root->ISBN = ISBN;
				root->title = title;
				root->author = author;
				root->year = year;
				count++;
				return true;
			}
			else {
				return addBook(title, author, year, ISBN, root);
			}
		};

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
