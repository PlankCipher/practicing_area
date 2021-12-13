import { ListNode, DoublyLinkedList } from './DoublyLinkedList';

const printNode = (node: ListNode) => {
  if (node) {
    console.log(
      `${node.prev === null ? 'null' : node.prev.value} <- ${node.value} -> ${
        node.next === null ? 'null' : node.next.value
      }`,
    );
  } else {
    console.log(null);
  }
};

const printList = (list: DoublyLinkedList) => {
  let curr = list.head;
  while (curr !== null) {
    printNode(curr);
    curr = curr.next;
  }
};

const list = new DoublyLinkedList();

console.log(`Upon initializing the list, it's head is: ${list.head}`);
console.log('----------------------------------------\n');

console.log('Inserting nodes with values 1, 2, 3, 4, and 5 into the list');
for (let i = 1; i <= 5; i++) {
  const node: ListNode = {
    prev: null,
    next: null,
    value: i,
  };

  list.insert(node);
}
console.log('----------------------------------------\n');

console.log('The current list:');
printList(list);
console.log('----------------------------------------\n');

console.log('list.search(5) returns:');
printNode(list.search(5));

console.log('');
console.log('list.search(3) returns:');
printNode(list.search(3));

console.log('');
console.log('list.search(99) returns:');
printNode(list.search(99));
console.log('----------------------------------------\n');

console.log('After deleting node with value 5:');
list.deleteByValue(5);
printList(list);

console.log('');
console.log('After deleting node with value 3:');
list.deleteByValue(3);
printList(list);

console.log('');
console.log('After deleting node with value 99:');
list.deleteByValue(99);
printList(list);
