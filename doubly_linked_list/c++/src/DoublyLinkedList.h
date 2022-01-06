#pragma once

#include <cstddef>
#include <iostream>

using namespace std;

template <typename T> struct ListNode {
  ListNode<T> *prev;
  ListNode<T> *next;
  T value;
};

template <typename T> class DoublyLinkedList {
public:
  ListNode<T> *head;

  DoublyLinkedList(ListNode<T> *head) { this->head = head; }

  ListNode<T> *search(T value) {
    ListNode<T> *curr = this->head;
    while (curr != NULL && curr->value != value) {
      curr = curr->next;
    }
    return curr;
  }

  void insert_node(ListNode<T> *node) {
    node->prev = NULL;
    if (this->head != NULL)
      this->head->prev = node;
    node->next = this->head;
    this->head = node;
  }

  void delete_node(ListNode<T> *node) {
    if (node != NULL) {
      if (node->prev != NULL)
        node->prev->next = node->next;
      else
        this->head = node->next;

      if (node->next != NULL)
        node->next->prev = node->prev;
    }
  }

  void print_node(ListNode<T> *node) {
    if (node != NULL) {
      if (node->prev == NULL)
        cout << "NULL";
      else
        cout << node->prev->value;

      cout << " <- " << node->value << " -> ";

      if (node->next == NULL)
        cout << "NULL" << endl;
      else
        cout << node->next->value << endl;
    } else {
      cout << "NULL" << endl;
    }
  }

  void print_list() {
    ListNode<T> *curr = this->head;
    while (curr != NULL) {
      this->print_node(curr);
      curr = curr->next;
    }
  }
};
