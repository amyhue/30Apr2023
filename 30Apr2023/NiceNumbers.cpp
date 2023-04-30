#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int adjust2048(int num) {
	int size = 0;
	int tempnum = num;
	while (tempnum > 0) {
		tempnum = tempnum / 10;
		size++;
	}

	stack<int> numStack;
	for (int i = size - 1; i >= 0; i--) {
		int x = num / pow(10.0, i);
		x = x % 10;
		numStack.push(x);
	}
	
	// numStack is now a stack of digits that form num
	
	// check and modify numStack accordingly
	stack<int> modified2048;
	while(modified2048.size() >= 2) {
		// get top two numbers in the stack
		int x = numStack.top();
		numStack.pop();
		int y = numStack.top();
		numStack.pop();
		
		// see if can combine
		if (x == y) {
			modified2048.push(x);
			modified2048.push(y);
		}
		else {
			if (x == 2) { // y = 4 or 8
				modified2048.push(x);
				modified2048.push(x);
				//return y back to original stack
				numStack.push(y);
			}
			if (x == 4 && y == 8) {
				modified2048.push(x);
				modified2048.push(x);
				numStack.push(y);
			}






		}
	}

	// debugging
	/*for (int i = 0; i < size; i++) {
		int x = modified2048.top();
		cerr << x;
		modified2048.pop();
	}*/
	return 0;

}

void NiceNumbers() {
	int numTests;
	cin >> numTests;

	/*adjust2048(numTests);
	cout << endl<< "finished" << endl;*/

	queue<int> tests;
	for (int i = 0; i < numTests; i++) {
		int x;
		cin >> x;
		tests.push(x);
	}

	//for()

}