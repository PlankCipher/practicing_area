type ListNodeValue = any;
export type ListNode = ListNodeInterface | null;

interface ListNodeInterface {
  prev: ListNode;
  next: ListNode;
  value: ListNodeValue;
}

export class DoublyLinkedList {
  public head: ListNode;

  constructor() {
    this.head = null;
  }

  search(value: ListNodeValue): ListNode {
    let curr = this.head;
    while (curr !== null && curr.value !== value) {
      curr = curr.next;
    }
    return curr;
  }

  insert(node: ListNodeInterface) {
    node.prev = null;
    if (this.head !== null) {
      this.head.prev = node;
    }
    node.next = this.head;
    this.head = node;
  }

  deleteByValue(value: ListNodeValue) {
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
