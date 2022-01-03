module Utils
  def print_node(node)
    if node != nil
      puts "#{node.prev_node == nil ? "nil" : node.prev_node.value} <- #{node.value} -> #{node.next_node == nil ? "nil" : node.next_node.value}"
    else
      puts "nil"
    end
  end

  def print_list(list)
    curr = list.head
    while curr != nil
      print_node(curr)
      curr = curr.next_node
    end
  end
end
