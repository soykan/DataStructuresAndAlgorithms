class Queue: 
    def __init__(self, capacity): 
        self.front = self.size = 0
        self.rear = capacity -1
        self.Q = [None]*capacity 
        self.capacity = capacity 
      
    def is_full(self): 
        return self.size == self.capacity 
      
    def is_empty(self): 
        return self.size == 0
  
    def enqueue(self, item): 
        if self.is_full(): 
            print('Kuyruk dolu.') 
            return
        self.rear = (self.rear + 1) % (self.capacity) 
        self.Q[self.rear] = item 
        self.size = self.size + 1
        print('{0} kuyruğa eklendi.'.format(str(item))) 
  
    def dequeue(self): 
        if self.is_empty(): 
            print('Kuyruk boş.') 
            return
        print('{0} kuyruktan çıkarıldı.'.format(str(self.Q[self.front]))) 
        self.front = (self.front + 1) % (self.capacity) 
        self.size = self.size -1
          
    def que_front(self): 
        if self.is_empty(): 
            print('Kuyruk boş.') 
        print('İlk eleman: ', self.Q[self.front]) 
          
    def que_rear(self): 
        if self.is_empty(): 
            print('Kuyruk boş.') 
        print('Son eleman: ',  self.Q[self.rear]) 
  

if __name__ == '__main__': 
    queue = Queue(30) 
    queue.enqueue(10) 
    queue.enqueue(20) 
    queue.enqueue(30) 
    queue.enqueue(40) 
    print()
    queue.dequeue()
    print() 
    queue.que_front() 
    queue.que_rear() 