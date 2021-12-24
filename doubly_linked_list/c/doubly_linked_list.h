#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

typedef struct ListNode {
  struct ListNode *prev;
  struct ListNode *next;
  int value;
} ListNode;

typedef struct DoublyLinkedList {
  ListNode *head;
} DoublyLinkedList;

ListNode *list_search(DoublyLinkedList list, int value);
void list_insert(DoublyLinkedList *list, ListNode *node);
void list_delete(DoublyLinkedList *list, ListNode *node);

void node_print(ListNode *node);
void list_print(DoublyLinkedList list);

#endif // _DOUBLY_LINKED_LIST_H_
