#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct ListNode** head) {
    struct ListNode* cur = *head;
    while(cur) {
        struct ListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int remember = 0;
    struct ListNode* res = NULL;
    struct ListNode** cur = &res;
    
    while(l1 != NULL || l2 != NULL || remember == 1) {
        int a = (l1 != NULL) ? l1->val : 0;
        int b = (l2 != NULL) ? l2->val : 0;

        int sum = a + b + remember;
        remember = 0;
        if(sum >= 10) {
            sum %= 10;
            remember = 1;
        }
        
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        *cur = newNode;
        cur = &(*cur)->next;

        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }

    return res;
}

int main() {
    struct ListNode* l1 = createNode(9);
    struct ListNode* l2 = createNode(1);
    l2->next = createNode(9);
    l2->next->next = createNode(9);
    l2->next->next->next = createNode(9);
    l2->next->next->next->next = createNode(9);
    l2->next->next->next->next->next = createNode(9);
    l2->next->next->next->next->next->next = createNode(9);
    l2->next->next->next->next->next->next->next = createNode(9);
    l2->next->next->next->next->next->next->next->next = createNode(9);
    l2->next->next->next->next->next->next->next->next->next = createNode(9);

    printList(addTwoNumbers(l1, l2));
    freeList(&l1);
    freeList(&l2);
    return 0;
}