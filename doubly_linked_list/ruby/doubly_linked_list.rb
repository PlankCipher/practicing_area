class ListNode
  attr_accessor :prev_node, :next_node, :value

  def initialize(prev_node, next_node, value)
    @prev_node = prev_node
    @next_node = next_node
    @value = value
  end
end

class DoublyLinkedList
  attr_accessor :head

  def initialize
    @head = nil
  end

  def search(value)
    curr = @head
    while curr != nil and curr.value != value
      curr = curr.next_node
    end
    return curr
  end

  def insert(node)
    node.prev_node = nil
    if @head != nil
      @head.prev_node = node
    end
    node.next_node = @head
    @head = node
  end

  def delete(node)
    if node != nil
      if node.prev_node != nil
        node.prev_node.next_node = node.next_node
      else
        @head = node.next_node
      end

      if node.next_node != nil
        node.next_node.prev_node = node.prev_node
      end
    end
  end
end
