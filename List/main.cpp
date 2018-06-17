#include <iostream>
#include <assert.h>
#include "list.hpp"

using namespace std;

int main() {
	node<int>* head = new node<int>(5);

	List<int> L1;

	for(int i = 0; i < 10; ++i) {
		L1.push_front(i);
	}

	assert(L1.size() == 10);

	while (L1.size() > 0) {
		cout << L1.back() << endl;
		L1.pop_back();
	}

	return 0;
}
