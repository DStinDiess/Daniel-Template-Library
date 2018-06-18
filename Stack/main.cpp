#include <iostream>
#include <assert.h>
#include "stack.hpp"

using namespace std;

int main() {
	Stack<int> S1;

	for(int i = 0; i < 10; ++i) {
		S1.push(i);
	}

	assert(S1.size() == 10);

	while (!S1.empty()) {
		cout << S1.top() << endl;
		S1.pop();
	}

	return 0;
}
