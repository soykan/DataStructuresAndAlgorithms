class Stack:
    def __init__(self):
        self.stackData = []
        self.stackPointer = 0

    def push(self, data):
        self.stackData.append(data)
        self.stackPointer += 1

    def pop(self):
        if (len(self.stackData) == 0):
            print("Stack is full.")
            return -1
        else:
            self.stackPointer -= 1
            return self.stackData[self.stackPointer]

    def clear(self):
        self.stackPointer = 0

if __name__ == '__main__':
    stack = Stack()
    stack.push(10)
    stack.push(20)
    stack.push(30)
    print('Items after push')
    for i in range(0, stack.stackPointer):
        print('Item: {0}: {1}'.format(i, stack.stackData[i]))
    print()

    stack.pop()
    print('Items after pop')
    for i in range(0, stack.stackPointer):
        print('Item: {0}: {1}'.format(i, stack.stackData[i]))
    print()

    stack.clear()
    print('Items after clear')
    for i in range(0, stack.stackPointer):
        print('Item: {0}: {1}'.format(i, stack.stackData[i]))
    print()