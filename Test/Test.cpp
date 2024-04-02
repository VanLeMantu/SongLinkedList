#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
typedef int ItemType;
struct SNode {
	ItemType coeff;
	ItemType  degree;
	SNode* next;
};
struct SList {
	SNode* Head;
	SNode* Tail;
};
void initSList(SList& sl) {
	sl.Head = NULL;
	sl.Tail = NULL;
}
bool isEmpty(SList& sl) {
	if (sl.Head == NULL)
		return true;
	return false;
}
SNode* create_SNode(ItemType& coeff, ItemType& degree) {
	SNode* p = new SNode;
	if (p == NULL) {
		printf( "\n khong du bo nho de cap phap");
		return  0;
	}
	p->coeff = coeff;
	p->degree = degree;
	p->next = nullptr;
	return p;
}
void show_SList(SList& sl) {
	SNode* p = new SNode;
	p = sl.Head;
	while (p) {
		printf("  % dx^%d", p->coeff, p->degree);
		if (p->next) {
			printf(" +");
		}
		p = p->next;
		
	}
}
void swap_SList(SNode* p, SNode* q) {
	int temp_coeff = p->coeff;
	int temp_degree = p->degree;
	p->coeff = q->coeff;
	p->degree = q->degree;
	q->coeff = temp_coeff;
	q->degree = temp_degree;
}

void sort_SList(SList& sl) {
	for (SNode* p = sl.Head; p->next != nullptr; p = p->next) {
		for (SNode* q = p->next; q != nullptr; q = q->next) {
			if (p->degree < q->degree) {
				swap_SList(p, q);
			}
		}
	}
}



void insert_Head(SList& sl, SNode* p) {
	if (p == NULL) {
		printf( "\n khong du bo nho de cap phap");
		return;
	}
	if (isEmpty(sl)) {
		sl.Head = sl.Tail = p;
	}
	else {
		p->next = sl.Head;
		sl.Head = p;

	}
}
void Simlify(SList& sl) {
	if (isEmpty(sl)) {
		return;
	}
	SNode* q = sl.Head;
	SNode* p = q->next;
	while (q->next && p->next) {
		if (q->degree == p->degree) {
			q->coeff += p->coeff;
			SNode* temp = p;
			p = p->next;
			q->next = p;
			delete temp;
		}
		else {
			q = q->next;
			p = p->next;
		}
	}
}
void insertInOrder(SList &sl, ItemType coeff, int degree) {
	SNode* p = create_SNode(coeff, degree);
	if (isEmpty(sl)) {
		sl.Head = sl.Tail = p;
	}
	else {
		SNode* curr = sl.Head;
		while (curr->next && curr->next->degree >= degree) {
			curr = curr->next;
		}
		p->next = curr->next;
		curr->next = p;
	}
}
void deleteMonomail(SList& sl, ItemType x) {
	if (isEmpty(sl)) {
		return;
	}
	if (sl.Head == sl.Tail && sl.Head->degree == x) {
		sl.Head = sl.Tail = nullptr;
		return;
	}
	SNode* q = sl.Head;
	SNode* p =q->next;
	SNode* current = sl.Head;
	while (current != NULL && current->next != NULL) {
		if (current->next->degree == x) {
			SNode* temp = current->next;
			current->next = current->next->next;
			delete(temp);
		}
		else {
			current = current->next;
		}
	}
}
void evaluatePolynomial(SList& sl, ItemType x) {
	double result = 0.0;

	SNode* p = sl.Head;
	while (p ) {
		result += p->coeff * pow(x, p->degree);
		p = p->next;
	}
	printf("\n gia tri cua bieu thuc khi x = %d  la %.3f ", x, result);
}

void addPolynomials(SList& slp, SList& slq) {
	SList slr;
	initSList(slr); 

	SNode* p = slp.Head;
	SNode* q = slq.Head;

	while (p && q) {
		if (p->degree == q->degree) {
			ItemType x = p->coeff + q->coeff;
			SNode* newNode = create_SNode(x, p->degree);
			insert_Head(slr, newNode);
			p = p->next;
			q = q->next;
		}
		else if (p->degree > q->degree) {
			
			insert_Head(slr, create_SNode(p->coeff, p->degree));
			p = p->next;
		}
		else {
			
			insert_Head(slr, create_SNode(q->coeff, q->degree));
			q = q->next;
		}
	}

	
	while (p) {
		insert_Head(slr, create_SNode(p->coeff, p->degree));
		p = p->next;
	}
	while (q) {
		insert_Head(slr, create_SNode(q->coeff, q->degree));
		q = q->next;
	}

	Simlify(slr); 
	printf("\n sau khi Q+P = \n");
	show_SList(slr);
}


void createSList_ByRandom(SList& sl) {
	int n;
	do {
		printf("\n nhap do dai cua linked list: ");
		scanf_s("%d", &n);
	} while (n <= 0);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		ItemType coeff = rand() % 199;
		ItemType  degree = rand() % 10;
		SNode* p = create_SNode(coeff,degree);
		insert_Head(sl, p);
	}
}
void subtractPolynomials(SList& slp, SList& slq) {
	SList slr;
	initSList(slr);

	SNode* p = slp.Head;
	SNode* q = slq.Head;

	while (p && q) {
		if (p->degree == q->degree) {
			ItemType x = p->coeff - q->coeff; 
			SNode* newNode = create_SNode(x, p->degree);
			insert_Head(slr, newNode);
			p = p->next;
			q = q->next;
		}
		else if (p->degree > q->degree) {
			insert_Head(slr, create_SNode(p->coeff, p->degree));
			p = p->next;
		}
		else {
			insert_Head(slr, create_SNode(q->coeff, q->degree));
			q = q->next;
		}
	}

	while (p) {
		insert_Head(slr, create_SNode(p->coeff, p->degree));
		p = p->next;
	}

	while (q) {
		
		insert_Head(slr, create_SNode(q->coeff, q->degree));
		q = q->next;
	}

	printf("\n P - Q = \n");
	show_SList(slr);
}

int main() {
	SList sl;
	initSList(sl);
	createSList_ByRandom(sl);
	show_SList(sl);
	sort_SList(sl);
	show_SList(sl);
	printf("\n giam dan bac mu ");
	show_SList(sl);
	Simlify(sl);
	printf("\n toi gian ");
	show_SList(sl);
	insertInOrder(sl, 5, 3);
	printf("\n sau khi them %dx^%d \n", 5, 3);
	show_SList(sl);
	deleteMonomail(sl, 2);
	printf("\n sau khi xoa  mu %d \n",2);
	show_SList(sl);
	evaluatePolynomial(sl,8);
	SList slp;
	initSList(slp);
	printf("\nda thuc ban dau la P:\n");
	createSList_ByRandom(slp);
	show_SList(slp);
	SList slq;
	initSList(slq);
	printf("\nda thuc ban dau la Q:\n");
	createSList_ByRandom(slq);
	show_SList(slq);
	//addPolynomials(slp, slq);
	subtractPolynomials(slp, slq);
	return 0;
}