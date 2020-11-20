from typing import List
class ArrayOps(object):

    def __init__(self, input_array:List[int] ):
        self._input = input_array

    def _validate_index(self, index):
        assert (index > len(self._input), "Index can't be greater than length")

    def remove_at(self, index):
        self._validate_index(index)
        i = index
        length = len(self._input)
        while i+1 < length:
            self._input[i] = self._input[i+1]
            i+=1
        self._input.pop(len(self._input)-1)

    def insert_at(self, index, data):
        self._validate_index(index)
        self._input[index] = data

    def remove_duplicates(self):
        dup_map = dict()
        for i in range(len(self._input)):
            if self._input[i] in dup_map.keys():
                del self._input[i]
            else:
                dup_map[self._input[i]] = i

    def find_duplicates(self):
        dup_map = dict()
        for i in range(len(self._input)):
            if self._input[i] in dup_map:
                dup_map[self._input[i]] += 1
            else:
                dup_map[self._input[i]] = 1
        return dup_map.keys()
