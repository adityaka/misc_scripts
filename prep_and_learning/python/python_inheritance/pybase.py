

class PyBase:
    def __init__(self):
        self._fa = 10
        self._fb = 20
    
    @property
    def a(self):
        return self._fa
    
    @property
    def b(self):
        return self._fb
    
    @a.setter
    def a(self, val):
        self._fa = val

    @b.setter
    def b(self, val):
        self._fb = val
    