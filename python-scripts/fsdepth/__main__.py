from depthfinder import find_max_depth
from argparse import ArgumentParser

if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("root_path",  type=str)
    args = parser.parse_args()
    max_length, longest_path = find_max_depth(args.root_path)
    print("Max depth = {}\n longest path: {}".format(max_length, longest_path))
