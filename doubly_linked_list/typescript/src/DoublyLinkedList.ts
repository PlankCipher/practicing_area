export type ListNode<T> = ListNodeInterface<T> | null;

interface ListNodeInterface<T> {
  prev: ListNode<T>;
  next: ListNode<T>;
  value: T;
}

export class DoublyLinkedList<T> {
  public head: ListNode<T>;

  constructor() {
    this.head = null;
  }

  search(value: T): ListNode<T> {
    let curr = this.head;
    while (curr !== null && curr.value !== value) {
      curr = curr.next;
    }
    return curr;
  }

  insert(node: ListNodeInterface<T>) {
    node.prev = null;
    if (this.head !== null) {
      this.head.prev = node;
    }
    node.next = this.head;
    this.head = node;
  }

  deleteByValue(value: T) {
    const node = this.search(value);
    if (node !== null) {
      if (node.prev !== null) {
        node.prev.next = node.next;
      } else {
        this.head = node.next;
      }

      if (node.next !== null) {
        node.next.prev = node.prev;
      }
    }
  }
}
