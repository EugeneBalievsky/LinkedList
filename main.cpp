#include<iostream>
#include"Lin.h"


int main() {
	Node* l;
	Node* m;

	l = create_node(2, nullptr, nullptr);
	m = create_node(10, nullptr, nullptr);
	push_back(l, 8);
	push_back(l, 16);
	for (int i = 9; i > 0; --i) {
		push_back(m, i);
	}
	print(l);

	print(m);
	reverse(m);
	print(m);
	merge(l, m);



	return 0;
}