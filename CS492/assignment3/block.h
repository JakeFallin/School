#ifndef _BLOCK_H_
#define _BLOCK_H_

class Block {

	public:

	//start pos
	int starting;
	//ending pos
	int ending;
	//valid
	bool validBlock;

	//constructor
	Block(int myStart, int myEnd, bool myBlock);

};

#endif
