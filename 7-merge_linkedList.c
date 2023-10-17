#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    struct Node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            if (mergedList == NULL) {
                mergedList = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (mergedList == NULL) {
                mergedList = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    return mergedList;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    list1 = append(list1, 1);
    list1 = append(list1, 3);
    list1 = append(list1, 5);

    list2 = append(list2, 2);
    list2 = append(list2, 4);
    list2 = append(list2, 6);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    displayList(mergedList);

    return 0;
}
