from pybase import PyBase

"""
# Note About Construction
If a child class defines a constructor
then the child class has to initialize
the base class explicitly.

If a child class chooses not to have a
constructor, then the base class constructor
is called implicitly.

## Implications:
 1. If the base class has parameterized constructor then base class constructor should be explicitly initialized
 2. As a best practice if there are too many parameters for contructor *args or **kwargs is a good way to handle them
 3. FactoryClass Instantiation or Using the Base to initialize apropriate children is a practice to explore 
"""

class PyChild(PyBase):

    def __init__(self):
        PyBase.__init__(self)
        self._fc = 10
    
    @property
    def c(self):
        return self._fc
    
    @c.setter
    def c(self, val):
        self._fc = val


class PyChild1(PyBase):
    
    @property
    def c(self):
        if hasattr(self, "_c") != True:
            self._fc = self.a + self.b
        return self._fc
    
    @c.setter
    def c(self, val):
        self._fc = val;