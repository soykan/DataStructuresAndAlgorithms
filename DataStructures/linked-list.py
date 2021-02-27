class Node: 
    def __init__(self, data): 
        self.data = data  
        self.next = None   
                        
class LinkedList: 
    def __init__(self):  
        self.head = None
        self.tail = None
    
    def add(self, node):
        if (self.head != None):
            self.tail.next = node
            self.tail = node
            node.next = None
        else:
            self.head = node
            self.tail = node
            node.next = None

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
        h = self.head
        previous = None

        while (h != None):
            if (h.data == value):
                break
            previous = h
            h = h.next
        
        if (h != None):
            if (previous == None):
                if (self.head == self.tail):
                    self.head = None
                    self.tail = None
                else:
                    self.head = self.head.next
            else:
                previous.next = h.next
                if (previous.next == None):
                    self.tail = previous
                return h
        else:
            return None

if __name__ == '__main__':
    linkedList = LinkedList()

    node1 = Node("Merhaba")
    node2 = Node("Nasılsın")
    
    linkedList.add(node1)
    linkedList.add(node2)

    linkedList.list_nodes()

    value = linkedList.search("Nasılsın").data
    print("Found: {0}".format(value))

    linkedList.delete("Nasılsın")
    print("Datas after delete operation:")
    linkedList.list_nodes()
