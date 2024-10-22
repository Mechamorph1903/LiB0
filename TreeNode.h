#pragma once
#include <string>

using std::string;

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	string title;
	string author;
	int ISBN;
	int year;

};
