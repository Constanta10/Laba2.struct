#include<iostream>
#include<list>
#include <fstream>

using namespace std;

struct Node {
	int a;
	Node* next;
};
Node* create(int value) {
	Node* newNode = new Node();
	newNode->a = value;
	newNode->next = nullptr;
	return newNode;
}


void append(Node*& head, int value) {
	Node* newNode = create(value);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
}
void Reverse(Node** Head) {
	Node* prev = nullptr;
	Node* current = *Head;
	Node* nextNode = nullptr;
	while (current != nullptr) {
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
		*Head = prev;
	}
}
void Print(Node* Head) {
	if (Head != NULL) {
		cout << Head->a << "\t";
		Print(Head->next);
		//переход к следующему элементу
	}
}
void Delete_Node(Node *Head) {
	if (Head != NULL) {
		Delete_Node(Head->next);
		delete Head;

	}
}


int main() {
	setlocale(LC_ALL, "ru");
	Node* Head = nullptr;


	ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	int value;
	while (inputFile >> value) {
		append(Head, value);
	}
	inputFile.close();
	cout << "текущий список:"; Print(Head);
	Reverse(&Head);
	cout << endl << "перевёрнутый список:"; Print(Head);
	Delete_Node(Head);
}
