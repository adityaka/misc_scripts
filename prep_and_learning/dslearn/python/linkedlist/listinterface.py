from abc import ABC, abstractmethod

class List(ABC):
    
    def __init__(self):
        self._head = None
        self._len = 0
    
    @abstractmethod
    def __len__(self):
        pass

    @abstractmethod
    def __next__(self):
        pass
    
    @abstractmethod
    def __getitem__(self, key):
        pass

    @abstractmethod
    def __setitem__(self, key):
        pass

    @abstractmethod
    def __iter__(self):
        pass
    