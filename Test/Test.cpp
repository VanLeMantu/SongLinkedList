#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
typedef char ItemType;
struct StackNode {
	ItemType info;
	StackNode* next;
};
struct Stack {
	StackNode* top;
};
void  initStack(Stack& st) {
	st.top = NULL;
}
int  isEmpty(Stack& st) {
	if (!st.top) {
		return 1;
	}
	return 0;
}
void show_Menu() {
	cout << "\n-----------------------------\n";
	cout << "\n 0: to end program ";
	cout << "\n 1: created stack by hand ";
	cout << "\n 2: created  a random stack  ";
	cout << "\n 3: find 1 Stack Node in stack's list  ";
	cout << "\n 4:convert interget to binary number";
	cout << "\n 5:reverse string ";
	cout << "\n-----------------------------\n";
}
StackNode* create_Stack(ItemType& x) {
	StackNode* p = new StackNode;
	if (!p) {
		cout << "\n khong du bo nho de cap phap";
		return 0;
	}
	p->info = x;
	p->next = nullptr;
}
void push(Stack& st, StackNode* p) {
	if (isEmpty(st)) {
		st.top = p;
	}
	else {
		p->next = st.top;
		st.top = p;
	}
}
void createStack_ByHand(Stack& st) {
	int n;
	do {
		cout << "\n nhap do dai cua stack: ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		ItemType x;
		cout << "\n nhap gia tri cua phan tu cua Stack ";
		cin >> x;
		StackNode* p = create_Stack(x);
		push(st, p);
	}
}
void createStack_Random(Stack& st) {
	int n;
	do {
		cout << "\n nhap do dai cua stack: ";
		cin >> n;
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		ItemType x = rand() % 199 - 99;
		StackNode* p = create_Stack(x);
		push(st, p);
	}
}
int pop(Stack& st, ItemType& x) {
	StackNode* p = new StackNode;
	if (isEmpty(st) == 1) {
		return 0;
	}
	p = st.top;
	st.top = st.top->next;
	x = p->info;
	delete(p);
	return 1;
}
void show_Stack(Stack st) {
	if (isEmpty(st)) {
		cout << "\n Stack is empty ";
		return;
	}
	cout << "\n Stack : ";
	StackNode* temp = st.top;
	while (temp) {
		cout << temp->info << "\t ";
		temp = temp->next;
	}
}
static StackNode* FindStack(Stack& st, ItemType x) {
	if (isEmpty(st)) {
		cout << "\n can't find the stack node";
		return NULL;
	}
	StackNode* p = st.top;
	while (p) {
		if (p->info == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void reverse_Stack(char* str) {
	ItemType ch;
	StackNode* p;
	Stack st;
	initStack(st);
	for (int i = 0; i < strlen(str); i++) {
		p = create_Stack(str[i]);
		push(st, p);
	}
	cout << "\n after reversing: ";
	while (true) {
		if (pop(st, ch) == 0) {
			break;
		}
		cout << ch; // Move cout outside the loop
	}
}
void showStackNode(StackNode* p) {
	cout << "\n Stack just created is : " << p->info;
}
bool check_Bracket(char* bracket) {
	char check;
	Stack st;
	initStack(st);
	for (int i = 0; i < strlen(bracket); i++) {
		char x = bracket[i];
		if (x == '(' || x == '{' || x == '[') {
			StackNode* p = create_Stack(bracket[i]);
			push(st, p);
		}
		else if (!isEmpty(st) && pop(st, check)) {
			if ((x == ')' && check != '(') ||
				(x == '}' && check != '{') ||
				(x == ']' && check != '[')) {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return isEmpty(st);
}

//void BinaryNumber(ItemType x, int a) {
//	Stack st;
//	initStack(st);
//	int temp = x;
//	while (temp > 0) {
//		int x = temp % a;
//		StackNode* p = create_Stack(x);
//		push(st, p);
//		temp /= a;
//	}
//	while (true) {
//		if (pop(st, x) == 0) {
//			break;
//		}
//		if (x < 10) {
//			cout << x;
//		}
//		else {
//			switch (x) {
//
//			case 10:
//				cout << "A";
//				break;
//			case 11:
//				cout << "B";
//				break;
//			case 12:
//				cout << "C";
//				break;
//			case 13:
//				cout << "D";
//				break;
//			case 14:
//				cout << "E";
//				break;
//			case 15:
//				cout << "F";
//				break;
//			}
//		}
//	}
//}
void bai1() {
	int choice;
	Stack st;
	initStack(st);
	do {
		show_Menu();
		cout << "\n Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			createStack_ByHand(st);
			show_Stack(st);
			break;
		case 2:
			createStack_Random(st);
			show_Stack(st);
			break;
			/*case 3: {
				ItemType x;
				cout << "\n Enter the value to search for: ";
				cin >> x;
				StackNode* p = FindStack(st, x);
				if (p) {
					cout << "\n" << p->info << " has inside  Stack Node";
				}
				else {
					cout << "\n" << x << " doesn't exist inside Stack Node";
				}
				break;
			}*/
			/*case 4:
				int a;
				ItemType X;
				do {
					cout << "\n enter integer: ";
					cin >> X;
				} while (X <= 0);
				do {
					cout << "\n enter base: ";
					cin >> a;
				} while (a <= 1);
				BinaryNumber(X, a);
				break;*/
		case 5:
			cin.ignore();
			char str[50];
			cout << "\ enter the string you want reverse:  \n";
			cin.getline(str, 50);
			reverse_Stack(str);
			break;
		case 6:
			cin.ignore();
			char bracket[100];
			cout << "\n enter the bracket to check! ";
			cin.getline(bracket, 100);
			if (check_Bracket(bracket)) {
				cout << "\n the expression is balanced ";
			}
			else {
				cout << "\n the expression isn't balanced ";
			}
			break;
		}

	} while (choice != 0);
}

int main() {
	bai1();
	return 0;
}