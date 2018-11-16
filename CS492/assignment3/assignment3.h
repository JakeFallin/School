#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <string>
#include <iosteam>
#include <fstream>
#include <vector>
#include <time.h>
#include <queue>
#include <cmath>
#include <list>
#include "file.h"
#include "block.h"
#include "tree.h"

using namespace std;

//main
int main(int, char**);

//helper functions
void cd(vector<string> str);
void ls(vector<string> str);
void dir(vector<string> str);
void mkdir(vector<string> str);
void append(vector<string> str);
void remove(vector<string> str);
void deleteFile(vector<string> str);
void exitFile(vector<string> str);
void printFile(vector<string> str);
void printDisk(vector<string> str);

void allocate(File *myFile);
void deallocate(File *myFile);
void merge();

extern Tree* myRoot;
extern Tree* myCurrentNode;
extern int myBlockSize;
extern int myDirSize;
extern list<Block> myDisk;

#endif