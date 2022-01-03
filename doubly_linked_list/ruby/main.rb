require_relative "doubly_linked_list.rb"
require_relative "utils.rb"

include Utils

list = DoublyLinkedList.new

puts "Upon initializing the list, it's head is: #{list.head == nil ? "nil" : "not nil"}"
puts "----------------------------------------\n\n"

puts "Inserting nodes with values 1, 2, 3, 4, and 5 into the list"
for i in 1..5 do
  node = ListNode.new(nil, nil, i)
  list.insert(node)
end
puts "----------------------------------------\n\n"

puts "The current list:"
Utils.print_list(list)
puts "----------------------------------------\n\n"

puts "list.search(5) returns:"
Utils.print_node(list.search(5));
puts

puts "list.search(3) returns:"
Utils.print_node(list.search(3));
puts

puts "list.search(99) returns:"
Utils.print_node(list.search(99));
puts "----------------------------------------\n\n"

puts "After deleting node with value 5:"
list.delete(list.search(5))
print_list(list)
puts

puts "After deleting node with value 3:"
list.delete(list.search(3))
print_list(list)
puts

puts "After deleting node with value 99:"
list.delete(list.search(99))
print_list(list)
puts "----------------------------------------"
