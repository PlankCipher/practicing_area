#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
  DoublyLinkedList<int> the_list(NULL);

  cout << "Upon initializing the list, it's head is: ";
  the_list.print_node(the_list.head);
  cout << "----------------------------------------" << endl << endl;

  cout << "Inserting nodes with values 1, 2, 3, 4, and 5 into the list" << endl;
  ListNode<int> node1 = {NULL, NULL, 1};
  the_list.insert_node(&node1);

  ListNode<int> node2 = {NULL, NULL, 2};
  the_list.insert_node(&node2);

  ListNode<int> node3 = {NULL, NULL, 3};
  the_list.insert_node(&node3);

  ListNode<int> node4 = {NULL, NULL, 4};
  the_list.insert_node(&node4);

  ListNode<int> node5 = {NULL, NULL, 5};
  the_list.insert_node(&node5);
  cout << "----------------------------------------" << endl << endl;

  cout << "The current list:" << endl;
  the_list.print_list();
  cout << "----------------------------------------" << endl << endl;

  cout << "the_list.search(5) returns:" << endl;
  the_list.print_node(the_list.search(5));
  cout << endl;

  cout << "the_list.search(3) returns:" << endl;
  the_list.print_node(the_list.search(3));
  cout << endl;

  cout << "the_list.search(99) returns:" << endl;
  the_list.print_node(the_list.search(99));
  cout << "----------------------------------------" << endl << endl;

  cout << "After deleting node with value 5:" << endl;
  the_list.delete_node(the_list.search(5));
  the_list.print_list();
  cout << endl;

  cout << "After deleting node with value 3:" << endl;
  the_list.delete_node(the_list.search(3));
  the_list.print_list();
  cout << endl;

  cout << "After deleting node with value 99:" << endl;
  the_list.delete_node(the_list.search(99));
  the_list.print_list();

  return 0;
}
