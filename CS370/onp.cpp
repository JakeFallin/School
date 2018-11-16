#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int getOP(char c) {

	if(c == '*') {
		return 4;
	} else if(c == '/') {
		return 3;
	} else if(c == '+') {
		return 2;
	} else if(c == '-') {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	
	int count;
	cin << count;


	for(int i = 0; i < count; i++) {

		string input;
		getline(cin, input);
		queue<char> q;
		stack<char> s;
		int l = length(input);
		
		for(int j = 0; j < l; j++) {
			int opP = getOP(input[j]);
			if(opP > 0) {
				while(s.top() != '' && s.top() >= opP) {
					q.push(s.top());
					s.pop();
				}
				s.push(opP);
			}
			if(input[j] == '(') {
				s.push(input[j]);
			}

			if(input[j] == ')') {
				while(s.top() == '(') {
					if(getOP(s.pop()) > 0) {
						q.push(s.top());
					} 
				}
				if(s.top() == '(') {
					s.pop();
				}
			}
		}
		while(s.top() != "") {
			q.push(s.top());
			s.pop();
		}

		while(q.front() != "") {
			printf("%c", q.front());
			q.pop();
		}
		printf("\n");

	}

	return 0;
}
