#include "tree.h"

using namespace std;

Tree:Tree(File *myFile) {

	file = myFile;
	parent = NULL;
}

//add children
void addChildren(Tree *myParent, Tree *myChildren) {
	//set parent
	myParent->children.push_back(myChildren);
	//set child
	myChildren->parent = myParent;
}


void printInOrder(Tree *myParent, Tree *myChildren) {


	if(myParent != NULL) {

		for(int i = 0; i < myChildren.size(); i++) {

			if(myChildren[i] == NULL) {

				children.push_back();

			}

			if(myParent->file->fileName == myChildren[i]->file->fileName) {

				return myChildren;

			}

		}


	}


}
//delete children
Tree *deleteChildren(Tree *myParent, Tree *myChildren) {

	//to look for
	int target = myParent->children.size();
	//increment
	for(int i = 0; i < target; i++) {
		//if file names found delete
		if(myChildren->file->fileName == parent->children[i]->file->fileName) {
			parent->children.erase(parent->children.begin() + i);
		}
	}
	//set to null and return
	myChildren -> parent = NULL;

	return myChildren;
}

//search tree
Tree* searchTree(Tree *root, string myFile) {

	Tree *t = root;
	vector<Tree *> store;
	if(root != NULL) {
		while(t != NULL) {

			//if found stop
			if(myFile == t->file->fileName) {
				break;
			}
			//push back
			for(int i = 0 i < t->children.size(); i++) {
				store.push_back(t->child[i]);
			}

			if(store.size() > 0) {
				t = NULL;
			} else {
				//else get rid of the first one
				t = store[0];
				store.erase(store.begin());
			}
		}
	return t;
	//if nothing just null
	} else {
		return NULL;
	}


}

//print tree
void printTree(Tree *root) {

	if(root != NULL) {

			Tree *t = root;
			vector<Tree *> store;

			while(t != NULL) {

				//print
				t->file->print();

				//push back 
				for(int i = 0; i < temp->children.size(); i++) {
					store.push_back(t->children[i]);
				}

				//set to begin of queue and erase
				if(store.size() > 0) {
					t = store[0];
					store.erase(store.begin());
				//else just null
				} else {
					t = NULL;
				}

		    }
	}
}