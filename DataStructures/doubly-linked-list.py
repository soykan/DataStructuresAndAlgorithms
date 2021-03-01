class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add(self, node):
        if (self.head != None):
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
            self.tail.next = None
        else:
            self.head = node
            self.tail = node
            self.head.next = None
            self.head.prev = None
    
    def list_nodes(self):
        h = self.head
        if (h == None):
            return -1
        while (h != None):
            print("Data: {0}".format(h.data))
            h = h.next
        return 0
    
    def search(self, value):
        h = self.head
        while (h != None):
            if (h.data == value):
                return h
            h = h.next
        return None
    
    def delete(self, value):
        h = self.search(value)
        if (h == None):
            return None
        
        if (self.head == h):
            if (self.head.next != None):
                self.head = h.next
                self.head.prev = None
            else:
                self.head = None
                self.tail = None
        else:
            h.prev.next = h.next
            if (h == self.tail):
                self.tail = self.tail.prev
            else:
                h.next.prev = h.prev
        return h

if __name__ == '__main__':
    doublyLinkedList = DoublyLinkedList()

    node1 = Node("Merhaba")
    node2 = Node("Nasılsın")

    doublyLinkedList.add(node1)
    doublyLinkedList.add(node2)

    doublyLinkedList.list_nodes()

    value = doublyLinkedList.search("Nasılsın").data
    print("Found {0}".format(value))

    doublyLinkedList.delete("Nasılsın")
    print("Datas after delete operation")
    doublyLinkedList.list_nodes()
