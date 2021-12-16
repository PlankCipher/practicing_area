class ListNode<T> {
  public ListNode<T> prev;
  public ListNode<T> next;
  public T value;
}

public class DoublyLinkedList<T> {
  public ListNode<T> head;

  public DoublyLinkedList() {
    head = null;
  }

  public ListNode<T> search(T value) {
    ListNode<T> current = head;
    while (current != null && current.value != value) {
      current = current.next;
    }
    return current;
  }

  public void insert(ListNode<T> node) {
    node.prev = null;
    if (head != null) {
      head.prev = node;
    }
    node.next = head;
    head = node;
  }

  public void deleteByValue(T value) {
    ListNode<T> node = search(value);
    if (node != null) {
      if (node.prev != null) {
        node.prev.next = node.next;
      } else {
        head = node.next;
      }

      if (node.next != null) {
        node.next.prev = node.prev;
      }
    }
  }
}
