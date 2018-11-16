#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

class File {

	public:
	//name of file
	string fileName;
	//bytes
	int bytes;
	//valid directory
	bool isValid;
	//timestamp
	time_t time;
	//blocks
	list<int> blocks;

	//constructor
	File(string name, int byteSize, bool valid);

	//to print file
	void printFile();

}

#endif