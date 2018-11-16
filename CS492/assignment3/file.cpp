#include "file.h"

using namespace std;

//constructor
File:File(string name, int byteSize, bool valid) {
	fileName = name;
	bytes = byteSize;
	isValid = valid;
	//set current time
	timestamp(&time);
	bytes = 0;
}

//just print everything
void File:print() {

	cout << "File name: " << fileName << " | Is Dir: " << isValid << " | Time: " << time << " | Block Size: " <<  bytes << " | Addresses:\n";

	for(list<int>::iterator i = blocks.begin(); i != blocks.end(); ++i) {
		cout << " " << *i << ", "; 
	}
	cout << "\n";

}