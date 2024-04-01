#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coeff;
    int degree;
    struct Node* next;
} Node;

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY
} Operation;

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

static void simplifyPolynomial(Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->degree == current->next->degree) {
            current->coeff += current->next->coeff;

            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

static void insertInOrder(Node** head, int coeff, int degree) {
    Node* newNode = createNode(coeff, degree);

    if (*head == NULL || (*head)->degree < degree) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && current->next->degree >= degree) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

static void deleteMonomial(Node** head, int degree) {
    while (*head != NULL && (*head)->degree == degree) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->degree == degree) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

static double evaluatePolynomial(Node* head, double x) {
    double result = 0.0;

    Node* current = head;
    while (current != NULL) {
        result += current->coeff * pow(x, current->degree);
        current = current->next;
    }

    return result;
}

static Node* multiplyMonomials(Node* R, int coeff, int degree) {
    Node* current = R;
    Node* prev = NULL;

    while (current != NULL && current->degree > degree) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->degree == degree) {
        current->coeff += coeff;
    }
    else {
        Node* newNode = createNode(coeff, degree);
        if (prev == NULL) {
            newNode->next = R;
            R = newNode;
        }
        else {
            newNode->next = current;
            prev->next = newNode;
        }
    }
    return R;
}

static void multiplyPolynomials(Node* P, Node* Q, Node** R) {
    Node* pCurrent = P;
    Node* qCurrent;

    while (pCurrent != NULL) {
        qCurrent = Q;
        while (qCurrent != NULL) {
            int newCoeff = pCurrent->coeff * qCurrent->coeff;
            int newDegree = pCurrent->degree + qCurrent->degree;

            *R = multiplyMonomials(*R, newCoeff, newDegree);

            qCurrent = qCurrent->next;
        }
        pCurrent = pCurrent->next;
    }
}

static Node* operatePolynomials(Node* P, Node* Q, Operation op) {
    Node* R = NULL;

    if (op == ADD || op == SUBTRACT) {
        Node* pCurrent = P, * qCurrent = Q;
        while (pCurrent != NULL && qCurrent != NULL) {
            if (pCurrent->degree > qCurrent->degree) {
                insertInOrder(&R, pCurrent->coeff, pCurrent->degree);
                pCurrent = pCurrent->next;
            }
            else if (pCurrent->degree < qCurrent->degree) {
                int coeff = (op == SUBTRACT) ? -qCurrent->coeff : qCurrent->coeff;
                insertInOrder(&R, coeff, qCurrent->degree);
                qCurrent = qCurrent->next;
            }
            else {
                int coeff = pCurrent->coeff + ((op == SUBTRACT) ? -qCurrent->coeff : qCurrent->coeff);
                if (coeff != 0) {
                    insertInOrder(&R, coeff, pCurrent->degree);
                }
                pCurrent = pCurrent->next;
                qCurrent = qCurrent->next;
            }
        }

        while (pCurrent != NULL) {
            insertInOrder(&R, pCurrent->coeff, pCurrent->degree);
            pCurrent = pCurrent->next;
        }

        while (qCurrent != NULL) {
            int coeff = (op == SUBTRACT) ? -qCurrent->coeff : qCurrent->coeff;
            insertInOrder(&R, coeff, qCurrent->degree);
            qCurrent = qCurrent->next;
        }
    }
    else if (op == MULTIPLY) {
        multiplyPolynomials(P, Q, &R);
    }

    return R;
}



int main() {
    Node* head = NULL;

    insertFront(&head, 3, 3);
    insertFront(&head, 5, 0);
    insertFront(&head, 5, 0);
    insertFront(&head, 2, 2);
    insertFront(&head, 3, 2);

    printf("Original Polynomial:\n");
    printPolynomial(head);

    sortPolynomial(&head);

    printf("5a. Sorted Polynomial in Descending Order:\n");
    printPolynomial(head);

    simplifyPolynomial(&head);

    printf("5b. Simplified Polynomial:\n");
    printPolynomial(head);

    insertInOrder(&head, 4, 1);

    printf("5c. Polynomial after inserting 4x^1:\n");
    printPolynomial(head);

    deleteMonomial(&head, 2);

    printf("5d. Polynomial after deleting monomials with degree 2:\n");
    printPolynomial(head);

    double x = 2.0;
    double value = evaluatePolynomial(head, x);

    printf("5e. Value of the polynomial at x = %.2f: %.2f\n", x, value);

    Node* P = NULL;
    insertInOrder(&P, 1, 3);
    insertInOrder(&P, 2, 1);

    Node* Q = NULL;
    insertInOrder(&Q, 3, 2);
    insertInOrder(&Q, 4, 0);

    printf("Polynomial P:\n");
    printPolynomial(P);

    printf("Polynomial Q:\n");
    printPolynomial(Q);

    Node* R = operatePolynomials(P, Q, ADD);

    printf("5f. Polynomial R = P + Q:\n");
    printPolynomial(R);

    Node* R1 = operatePolynomials(P, Q, SUBTRACT);

    printf("5g. Polynomial R1 = P - Q:\n");
    printPolynomial(R1);

    Node* R2 = operatePolynomials(P, Q, MULTIPLY);

    printf("5h. Polynomial R2 = P * Q:\n");
    printPolynomial(R2);
    return 0;
}
