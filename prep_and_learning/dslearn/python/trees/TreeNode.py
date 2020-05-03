

class TreeNode(object):

    def __init__(self, data, max_children=2):
        self._children = [None for x in range(max_children)]
        self._data = data
        self._max_children = max_children
    
    def _is_valid_index(self, index ):
        if  index < self._max_children:
            return True
    
        return False
        
    def add_child(self, data, index):

        if not self._is_valid_index(index):
            raise ValueError("Invalid Child Index")
        
        self._children[index] = TreeNode(data, self._max_children)

    def get_child(self, index):
        if not self._is_valid_index(index):
            return None
        return self._children[index]
    
        
        
