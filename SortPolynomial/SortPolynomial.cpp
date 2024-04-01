#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int degree;
    struct Node* next;
} Node;

static Node* createNode(int coeff, int degree) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->degree = degree;
    newNode->next = NULL;
    return newNode;
}

static void insertFront(Node** head, int coeff, int degree) {
    Node* newNode = createNode(coeff, degree);
    newNode->next = *head;
    *head = newNode;
}

static void printPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->degree);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

static void sortPolynomial(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node* sorted = NULL;

    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;

        if (sorted == NULL || sorted->degree < current->degree) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->degree >= current->degree) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    *head = sorted;
}

int main() {
    Node* head = NULL;

    insertFront(&head, 5, 0);
    insertFront(&head, 2, 3);
    insertFront(&head, 3, 2);

    printf("Original Polynomial:\n");
    printPolynomial(head);

    sortPolynomial(&head);

    printf("Sorted Polynomial in Descending Order:\n");
    printPolynomial(head);

    return 0;
}
