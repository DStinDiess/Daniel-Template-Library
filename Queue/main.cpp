#include <iostream>
#include <assert.h>
#include "queue.hpp"

using namespace std;

int main() {
	Queue<int> Q1;

	for(int i = 0; i < 10; ++i) {
		Q1.enqueue(i);
	}

	assert(Q1.size() == 10);

	while (!Q1.empty()) {
		cout << Q1.front() << endl;
		Q1.dequeue();
	}

	return 0;
}
