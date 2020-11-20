
class Stack(object):

    def __init__(self):
        self._impl = list()

    def push(self, data):
        self._impl.append(data)

    def pop(self):
        data = self._impl.pop()
        return data

    def top(self):
        return len(self._impl) -1

    def is_empty(self):
        return not self._impl

    def peek(self):
        return self._impl[len(self._impl)-1]

    def __str__(self):
        if len(self._impl) > 0:
            return ",".join([str(x) for x in self._impl])
        return "Empty Stack"


def main():
    stack = Stack()
    print("State of stack :", stack)
    print("Pushing elements on stack")
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.push(40)
    print("State Of Stack ", stack)
    while not stack.is_empty():
        print("popping from the stack {}".format(stack.pop()))


if __name__ == "__main__":
    main()