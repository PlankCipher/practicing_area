#include "doubly_linked_list.h"
#include <stdio.h>

int main() {
  DoublyLinkedList list = {NULL};

  printf("Upon initializing the list, it's head is: %s\n",
         list.head == NULL ? "null" : "not null");
  printf("----------------------------------------\n\n");

  printf("Inserting nodes with values 1, 2, 3, 4, and 5 into the list\n");
  ListNode node1 = {NULL, NULL, 1};
  list_insert(&list, &node1);

  ListNode node2 = {NULL, NULL, 2};
  list_insert(&list, &node2);

  ListNode node3 = {NULL, NULL, 3};
  list_insert(&list, &node3);

  ListNode node4 = {NULL, NULL, 4};
  list_insert(&list, &node4);

  ListNode node5 = {NULL, NULL, 5};
  list_insert(&list, &node5);
  printf("----------------------------------------\n\n");

  printf("The current list:\n");
  list_print(list);
  printf("----------------------------------------\n\n");

  printf("list_search(list, 5) returns:\n");
  node_print(list_search(list, 5));
  printf("\n");

  printf("list_search(list, 3) returns:\n");
  node_print(list_search(list, 3));
  printf("\n");

  printf("list_search(list, 99) returns:\n");
  node_print(list_search(list, 99));
  printf("\n----------------------------------------\n\n");

  printf("After deleting node with value 5:\n");
  list_delete(&list, list_search(list, 5));
  list_print(list);
  printf("\n");

  printf("After deleting node with value 3:\n");
  list_delete(&list, list_search(list, 3));
  list_print(list);
  printf("\n");

  printf("After deleting node with value 99:\n");
  list_delete(&list, list_search(list, 99));
  list_print(list);
  printf("\n");

  return 0;
}
