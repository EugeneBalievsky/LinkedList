#include <iostream>

#include "Lin.h"

Node* create_node(int value, Node* next, Node* prev) {
	Node* ptr = new Node;
	ptr->value = value;
	ptr->next = next;
	ptr->prev = prev;
	return ptr;
}

void free(Node*& head) {
	if (!head) {
		return;
	}
	free(head->next);
	delete head;
	head = nullptr;
}

Node* find_node(Node* head, int value) {
	for (Node* it = head; it != nullptr; it = it->next) {
		if (it->value == value) {
			return it;
		}
	}
	return nullptr;
}

void push_front(Node*& head, int value) {
	Node* ptr = create_node(value);
	if (!head) {
		head = ptr;
		return;
	}
	ptr->next = head;
	head->prev = ptr;
	head = ptr;
}

void push_back(Node*& head, int value) {
	Node* ptr = create_node(value);
	if (!head) {
		head = ptr;
		return;
	}
	Node* it = head;
	for (it; it->next != nullptr; it = it->next);
	it->next = ptr;
	ptr->prev = it;

}

void remove(Node*& head, Node* target) {
	Node* it = head;
	for (it; it != target; it = it->next);

	it->prev->next = it->next;
	it->next->prev = it->prev;
	delete it;
}

void print(Node* head) {
	for (Node* it = head; it != nullptr; it = it->next) {
		std::cout << it->value << ' ';
	}
	std::cout << '\n';
}
void reverse(Node*& head) {
	Node* temp = NULL;
	Node* it = head;

	while(it != nullptr) { 
		temp = it->prev;
		it->prev = it->next;
		it->next = temp;
		it = it->prev;	
	}
	if (temp != NULL)
		head = temp->prev;
}
Node* merge(Node* first, Node* second) {
	Node* ans = new Node;
	Node* it = ans;

	while (first || second) {
		if (first && (!second || first->value < second->value)) {
			it->value = first->value;
			first = first->next;
		}
		else {
			it->value = second-> value;
			second  = second->next;
		}

 		it->next = (first || second ? new Node : nullptr);
		it = it->next;
	}
	return ans;
}