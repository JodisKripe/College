#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int coef;
    int exp;
    struct node *next;
};

node *createNode(int coef, int exp) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node *head, int coef, int exp) {
    node *newNode = createNode(coef, exp);
    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next = newNode;
    }
}

void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp->next != NULL) {
            printf(" + ");
        }
    }
    printf("");
}

node *addPolynomial(node *head1, node *head2) {
    node *head3 = NULL;
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            insertNode(head3, temp1->coef + temp2->coef, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            insertNode(head3, temp1->coef, temp1->exp);
            temp1 = temp1->next;
        } else {
            insertNode(head3, temp2->coef, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) {
        insertNode(head3, temp1->coef, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        insertNode(head3, temp2->coef, temp2->exp);
        temp2 = temp2->next;
    }
    return head3;
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    insertNode(head1, 2, 3);
    insertNode(head1, 3, 2);
    insertNode(head1, 4, 1);
    insertNode(head1, 5, 0);
    insertNode(head2, 3, 2);
    insertNode(head2, 4, 1);
    insertNode(head2, 5, 0);
    display(head1);
    display(head2);
    head3 = addPolynomial(head1, head2);
    display(head3);
}