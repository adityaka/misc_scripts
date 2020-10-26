from os import path
from os import walk
from os import access
from os import R_OK, W_OK, X_OK
from os import sep

def find_max_depth(root):
    if not access(root, R_OK):
        raise IOError("Read not allowed to {}".format(root))
    
    max_path_len = 0
    longest_abs_path = ""
    walker = walk(root)
    for root, files, dirs in walker:
        for item in files:
            abs_path = path.join(root,item)
            abs_path_len = len(abs_path.split(sep))
            if max_path_len < abs_path_len:
                max_path_len = abs_path_len
                longest_abs_path = abs_path
    
    return (max_path_len, longest_abs_path)