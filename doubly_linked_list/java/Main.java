public class Main {
  static void printNode(ListNode<Integer> node) {
    if (node != null) {
      System.out.println(
          (node.prev == null ? "null" : node.prev.value) +
          " <- " + node.value + " -> " +
          (node.next == null ? "null" : node.next.value)
          );
    } else {
      System.out.println("null");
    }
  }

  static void printList(DoublyLinkedList<Integer> list) {
    ListNode<Integer> curr = list.head;
    while (curr != null) {
      printNode(curr);
      curr = curr.next;
    }
  }

  public static void main(String[] args) {
    DoublyLinkedList<Integer> list = new DoublyLinkedList<Integer>();

    System.out.println("Upon initializing the list, it's head is: " + list.head);
    System.out.println("----------------------------------------\n");

    System.out.println("Inserting nodes with values 1, 2, 3, 4, and 5 into the list");
    for (int i = 1; i <= 5; i++) {
      ListNode<Integer> node = new ListNode<Integer>();
      node.prev = null;
      node.next = null;
      node.value = i;

      list.insert(node);
    }
    System.out.println("----------------------------------------\n");

    System.out.println("The current list:");
    printList(list);
    System.out.println("----------------------------------------\n");


    System.out.println("list.search(5) returns:");
    printNode(list.search(5));

    System.out.println("");
    System.out.println("list.search(3) returns:");
    printNode(list.search(3));

    System.out.println("");
    System.out.println("list.search(99) returns:");
    printNode(list.search(99));
    System.out.println("----------------------------------------\n");

    System.out.println("After deleting node with value 5:");
    list.deleteByValue(5);
    printList(list);

    System.out.println("");
    System.out.println("After deleting node with value 3:");
    list.deleteByValue(3);
    printList(list);

    System.out.println("");
    System.out.println("After deleting node with value 99:");
    list.deleteByValue(99);
    printList(list);
  }
}
