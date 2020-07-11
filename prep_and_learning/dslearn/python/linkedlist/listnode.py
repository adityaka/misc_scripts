
class ListNode(object):
    def __init__(self, number_of_nodes=2):
        self._links = [None for x in range(number_of_nodes)]
        
    @property
    def next(self):
        return self._links[0]

    @property
    def prev(self):
        return self._links[1]

    @next.setter
    def next(self, nextNode ):
        if nextNode and type(nextNode) is not ListNode :
            raise ValueError("Invalid type " +  type(nextNode))
        self._links[0] = nextNode

    @prev.setter
    def prev(self, prevNode):
        if prevNode and type(prevNode) is not ListNode:
            raise ValueError("invalid type " + type(prevNode))
        self._links[1] = prevNode

if "__main__" == __name__ :

    print ("manual double list construction")
    o = ListNode()

    o.next = ListNode()
    o.next.prev = o
    o.next.next = ListNode()
    o.next.next.prev = o.next
    o.next.next.next = ListNode()
    o.next.next.next.prev = o.next.next

    it = o
    end = o.next.next.next
    print ("forward iteration")
    while it.next != None :
        print(it)
        it = it.next

    print("backward iteration")
    while it.prev != None:
        print(it)
        it = it.prev

