from stacks.stack import  Stack

class String(object):

    def __init__(self, value:str = None):
        self._val = value

    def reverse(self):
        if not self._val or len(self._val) == 1:
            return self._val
        stack = Stack()
        for x in self._val:
            stack.push(x)
        result_list = []
        while not stack.is_empty():
            result_list.append(stack.pop())
        return "".join(result_list)

    def __str__(self):
        return self._val

if __name__ == "__main__" :

    common_string = String("Some string which we will reverse")
    reversed_string = common_string.reverse()
    print ("Initial value {}".format(common_string))
    print ("After reversal {}".format(reversed_string))


