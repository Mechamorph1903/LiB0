#pragma once
#include <string>

using std::string;

class TreeNode {
public:
	int height;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	string title;
	string author;
	int ISBN;
	int year;

};
