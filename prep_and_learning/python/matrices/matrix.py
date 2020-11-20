from typing import Type


class Matrix(object):

    def __init__(self, rows: int, cols: int):
        self._rows = rows
        self._cols = cols
        self._store = list()
        for i in range(rows):
            current_row = list()
            for j in range(3):
                current_row.append(None)
            self._store.append(current_row)

    def __str__(self):
        return str(self._store)

    def __eq__(self, rhs):
        eq = True
        if type(rhs) != Matrix:
            eq = False
        if self.is_equal_size(rhs):
            for i in range(self._rows):
                if self.get_row(i) != rhs.get_row(i):
                    eq = False
                    break
        else:
            return False
        return eq

    def __add__(self, rhs: Type[matrix.Matrix]):
        sum_matrix = Matrix(self.cols, self.rows)
        if self.is_equal_size(rhs):
            for i in range(self.rows):
                for j in range(self.cols):
                    sum_matrix.insert(i, j, self.get(i, j) + rhs.get(i, j))
        return sum_matrix

    def _is_valid_row(self, row_index):
        return self.rows > row_index

    def _is_valid_col(self, col_index):
        return self.cols > col_index

    def _is_valid_index_location(self, row, col):
        return self._is_valid_col(row) and self._is_valid_col(col)

    def is_equal_size(self, rhs):
        return self.cols == rhs.cols and self.rows == rhs.rows

    @property
    def cols(self):
        return self._cols

    @property
    def rows(self):
        return self._rows

    def insert(self, row: int, col: int, data):
        try:
            self._store[row][col] = data
        except IndexError as ie:
            raise ie

    def remove(self, row, col):
        try:
            row_ref = self._store[row]
            row_ref.pop(col)
        except IndexError as ie:
            raise ie

    def get_row(self, row_index: int):
        assert (row_index < self._rows)
        return self._store[row_index]

    def set_row(self, row_index, row_data: list):
        if self._is_valid_row(row_index):
            self._store[row_index] = row_data

    def get_col(self, col_index):
        assert (col_index < self._cols)
        col_list = list()
        for r in self._store:
            col_list.append([col_index])
        return col_list

    def get(self, row, col):
        assert (self._is_valid_index_location(row, col), "Invalid Location")
        return self._store[row][col]

    def set(self, row, col):
        assert (self._is_valid_index_location(row, col), "Invalid Location")
        self._store[i][j]

    def transpose(self):
        new_matrix = Matrix(self._cols, self._rows)
        nr = 0
        nc = 0
        for row in self._store:
            for elem in row:
                new_matrix.insert(nr, nc, elem)
                nr += 1
            nc += 1
            nr = 0
        return new_matrix


if __name__ == "__main__":
    import random

    random.seed(10)

    m1 = Matrix(3, 3)
    print(m1)
    for i in range(3):
        for j in range(3):
            m1.insert(i, j, int(random.random() * 10))
    print("Initial matrix {}".format(m1))
    mt = m1.transpose()
    print("Matrix after transpose {}".format(mt))

    for i in range(3):
        assert (m1.get_col(i) != mt.get_row(i))
