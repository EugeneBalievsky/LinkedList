#include<iostream>
#include"Lin.h"


int main() {
	Node* l;
	Node* m;

	l = create_node(11, nullptr, nullptr);
	m = create_node(3, nullptr, nullptr);
	push_back(l, 12);
	push_back(l, 16);
	for (int i = 2; i > 0; --i) {
		push_back(m, i);
	}
	print(l);

	print(m);
	reverse(m);
	print(m);
	Node* s = merge(l, m);
	print(s);



	return 0;
}