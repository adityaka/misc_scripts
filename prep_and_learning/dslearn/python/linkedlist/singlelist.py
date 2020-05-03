from linkedlist.listnode import ListNode
from linkedlist.listinterface import List

class SingleList(List):
    def __init__(self):
        super().__init__()
    
    def __len__(self):
        pass

    def __next__(self):
        pass
        
    def __getitem__(self, key):
        pass

    def __setitem__(self, key):
        pass
    
    def __iter__(self):
        pass
    
if "__main__" == __name__ : 
    l = SingleList()