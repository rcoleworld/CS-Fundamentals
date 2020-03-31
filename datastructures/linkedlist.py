class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = self.curr = self.tail = None
    
    def is_empty(self):
        return self.size == 0

    # inserts after the current value
    def insert(self, val):
        if self.is_empty():
            self.head = self.curr = self.tail = Node(val)
        else:
            self.curr.next = Node(val)
            self.curr = self.curr.next
        self.size += 1

    # deletes the first occurance as the given key
    def delete(self, key):
        if self.size == 1:
            self.curr = self.head = self.tail = None
        elif not self.is_empty():
            deleter = self.head
            while deleter.next and deleter.next.val != key:
                deleter = deleter.next
            temp = deleter
            deleter.next = deleter.next.next
        self.size -= 1
        
    # overloaded string function for printing
    def __str__(self):
        printer = self.head
        print_string = []
        while printer:
            print_string.append(str(printer.val))
            printer = printer.next
        return " -> ".join(print_string)
