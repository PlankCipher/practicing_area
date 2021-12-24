#include "doubly_linked_list.h"
#include <stdio.h>

ListNode *list_search(DoublyLinkedList list, int value) {
  ListNode *curr = list.head;
  while (curr != NULL && curr->value != value) {
    curr = curr->next;
  }
  return curr;
}

void list_insert(DoublyLinkedList *list, ListNode *node) {
  node->prev = NULL;
  if (list->head != NULL)
    list->head->prev = node;
  node->next = list->head;
  list->head = node;
}

void list_delete(DoublyLinkedList *list, ListNode *node) {
  if (node != NULL) {
    if (node->prev == NULL)
      list->head = node->next;
    else
      node->prev->next = node->next;

    if (node->next != NULL)
      node->next->prev = node->prev;
  }
}

void node_print(ListNode *node) {
  if (node != NULL) {
    if (node->prev == NULL)
      printf("null");
    else
      printf("%d", node->prev->value);

    printf(" <- %d -> ", node->value);

    if (node->next == NULL)
      printf("null\n");
    else
      printf("%d\n", node->next->value);
  } else {
    printf("null");
  }
}

void list_print(DoublyLinkedList list) {
  ListNode *curr = list.head;
  while (curr != NULL) {
    node_print(curr);
    curr = curr->next;
  }
}
