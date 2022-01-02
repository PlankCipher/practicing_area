package main

import "fmt"

func main() {
  list := DoublyLinkedList{nil}

  head_msg := "nil"
  if list.head != nil {
    head_msg = "not nil"
  }

  fmt.Printf("Upon initializing the list, it's head is: %s\n", head_msg)
  fmt.Printf("----------------------------------------\n\n")

  fmt.Printf("Inserting nodes with values 1, 2, 3, 4, and 5 into the list\n")
  for i := 1; i <= 5; i++ {
    node := ListNode{nil, nil, i}
    list_insert(&list, &node)
  }
  fmt.Printf("----------------------------------------\n\n")

  fmt.Printf("The current list:\n")
  list_print(list)
  fmt.Printf("----------------------------------------\n\n")

  fmt.Printf("list_search(list, 5) returns:\n")
  node_print(list_search(list, 5))
  fmt.Printf("\n")

  fmt.Printf("list_search(list, 3) returns:\n")
  node_print(list_search(list, 3))
  fmt.Printf("\n")

  fmt.Printf("list_search(list, 99) returns:\n")
  node_print(list_search(list, 99))
  fmt.Printf("----------------------------------------\n\n")

  fmt.Printf("After deleting node with value 5:\n")
  list_delete(&list, list_search(list, 5))
  list_print(list)
  fmt.Printf("\n")

  fmt.Printf("After deleting node with value 3:\n")
  list_delete(&list, list_search(list, 3))
  list_print(list)
  fmt.Printf("\n")

  fmt.Printf("After deleting node with value 99:\n")
  list_delete(&list, list_search(list, 99))
  list_print(list)
  fmt.Printf("\n")
}

type ListNode struct {
  prev *ListNode
  next *ListNode
  value int
}

type DoublyLinkedList struct {
  head *ListNode
}

func list_search(list DoublyLinkedList, value int) *ListNode {
  curr := list.head
  for curr != nil && curr.value != value {
    curr = curr.next
  }
  return curr
}

func list_insert(list *DoublyLinkedList, node *ListNode) {
  node.prev = nil
  if list.head != nil {
    list.head.prev = node
  }
  node.next = list.head
  list.head = node
}

func list_delete(list *DoublyLinkedList, node *ListNode) {
  if node != nil {
    if node.prev != nil {
      node.prev.next = node.next
    } else {
      list.head = node.next
    }

    if node.next != nil {
      node.next.prev = node.prev
    }
  }
}

func node_print(node *ListNode) {
  if node != nil {
    if node.prev == nil {
      fmt.Print("nil")
    } else {
      fmt.Printf("%d", node.prev.value)
    }

    fmt.Printf(" <- %d -> ", node.value)

    if node.next == nil {
      fmt.Print("nil")
    } else {
      fmt.Printf("%d", node.next.value)
    }

    fmt.Print("\n");
  } else {
    fmt.Println("nil")
  }
}

func list_print(list DoublyLinkedList) {
  curr := list.head
  for curr != nil {
    node_print(curr)
    curr = curr.next
  }
}
