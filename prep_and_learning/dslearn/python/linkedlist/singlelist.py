from linkedlist.listnode import ListNode
from linkedlist.listinterface import List

class SingleList(List):
    def __init__(self):
        super(List,self).__init__()

    def __len__(self):
        return self._len

    def __next__(self):
        if self._currentNode:
            self._currentNode = self._currentNode.next
            return self._currentNode.data
        else:
            if self._head:
                self._currentNode = self._head
            return self._currentNode.data

    def __getitem__(self, key):
        if key < self._len:
            iter = self._head
            for i in range (key):
                if i == key:
                    return iter
                if iter:
                    iter = iter.next
                else:
                    return None

    def __setitem__(self, key):
        pass

    def __iter__(self):
        pass

if "__main__" == __name__ :
    l = SingleList()