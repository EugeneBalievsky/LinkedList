#ifndef _LIN_H
#define _LIN_H

struct Node {
	int value;
	Node* next;
	Node* prev;
};

Node* create_node(int value, Node* next = nullptr, Node* prev = nullptr);
void free(Node*& head);
Node* find_node(Node* head, int value);
void push_front(Node*& head, int value);
void push_back(Node*& head, int value);
void remove(Node*& head, Node* target);
void print(Node* head);
void reverse(Node*& head);
Node* merge(Node* first, Node* second);

#endif
