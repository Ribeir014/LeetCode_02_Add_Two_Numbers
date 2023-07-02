#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode head  = { .next = NULL }, *result = &head;
    int carry = 0, total = 0;
    
    while(l1 != NULL || l2 != NULL || carry) {
        int val1 = 0, val2 = 0;
        if (l1) {
            val1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val2 = l2->val;
            l2 = l2->next;
        }
        total = val1 + val2;
        if (carry) {
            carry = 0;
            total++;
        }
        if (total >= 10) {
            total = total - 10;
            carry = 1;
        }
        result = result->next = malloc(sizeof(struct ListNode));
        result->val = total;
        result->next = NULL;
    }
    return head.next;
}

struct ListNode *makeListFromChars(const char *array, int size) {
    struct ListNode anchor  = { .next = NULL }, *curr = &anchor;

    for(int i = 0; i < size; i++) {
        curr = curr->next = malloc(sizeof(struct ListNode));//Creating lists and adding data is a separate function.
        curr->val = array[i];
        curr->next = NULL;
    }
    return anchor.next;
}

void printList(struct ListNode *p) {
    for(; p; p = p->next)
        printf("%d ", p->val);
    printf("\n");
}

int main(void){
    char lista1[9] = {4,5,2,2,9,3,8,9,2};
    char lista2[9] = {0,7,6,1,6,5,0,6,7};
    struct ListNode *l1 = makeListFromChars(lista1, 9);
    struct ListNode *l2 = makeListFromChars(lista2, 9);

    printList(l1);
    printList(l2);

    struct ListNode *answer = addTwoNumbers(l1, l2);
    printList(answer);
    //freeList(l1);freeList(l2);freeList(answer);
    return 0;
} 