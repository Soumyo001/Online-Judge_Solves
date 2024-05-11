#include<iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int val) {
		this->val = val;
		next = NULL;
	}
};
Node* head;
void push_b(int key) {
	Node* p = new Node(key);
	if (head == NULL) {
		head = p;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = p;
}
void push_f(int key) {
	Node* p = new Node(key);
	if (head == NULL) {
		head = p;
		return;
	}
	p->next = head;
	head = p;
}
int Count(Node* node) {
	static int ct = 0;
	if (node == NULL) return ct;
	ct++;
	return Count(node->next);
}
int mid_val() {
    int size = Count(head);
	int mid = 0;
	if (size & 1) mid = (size + 1) / 2;
	else mid = size / 2, mid++;
	Node* temp = head;
	int ct = 0;
	while (temp != NULL) {
		ct++;
		if (ct == mid) return temp->val;
		temp = temp->next;
	}
	return -1;
}
int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		push_b(x);
	}
	cout << mid_val() << endl;
}