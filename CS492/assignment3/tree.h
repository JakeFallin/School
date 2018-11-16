#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <vector>
#include "file.h"

using namespace std;

class Tree {

public:
	//tree node file info
	File *file;
	//parent of the tree
	Tree *parent;
	//childs of the tree
	vector<Tree*> children;

	//constructor
	Tree(File *myFile);

};

//add children
void addChildren(Tree *myParent, Tree *myChildren);
//delete children
Tree *deleteChildren(Tree *myParent, Tree *myChildren);
//search
Tree* searchTree(Tree *root, string myFile);
//print tree
void printTree(Tree *root);

#endif