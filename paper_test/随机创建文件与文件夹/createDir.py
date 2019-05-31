#!/usr/bin/env python

import random   # Random number generator
import os       # Crossplatform OS rutines
import sys      # interpreter tools
import argparse # parse command-line arguments

legal_chars = "abcdefghijklmnopqrstuvwxyz"+\
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"+"0123456789_"

def random_string(length=6, prefix="", legal_chars=legal_chars):
    """
Create a random string of text.
Parameters
----------
length : int
    Length of the string (minus the prefix part).
prefix : string
    Prefix the string with some text.
legal_chars : string
    A string of charracter that are allowed to be used in the
    output.
Returns
-------
res : str
Example
-------
>>> random.seed(5)
>>> print(random_string(30, "ef2x_", legal_chars))
ef2x_NUY7U6bD7O4hDpIKanr5WkYiMha2nn
    """
    chars = []
    for i in range(length):
        chars += random.choice(legal_chars)
    res = prefix+''.join(chars)
    return res


def generate_tree(target, dirs, rec_depth, verbose):
    """
Genereate a random folder structure with random names.
Parameters
----------
target : str
    Path to the root where folders are to be created.
dirs : int
    Maximum number of directories to be created per directory.
rec_depth : int
    Maximum directory depth.
verbose : bool
    Be loud about what to do.
    """
    if rec_depth > 0:
        for i in range(random.randint(0, dirs)):
            new_dir = target + random_string(6) + "/"
            if not os.path.exists(new_dir):
                os.makedirs(new_dir)
                if verbose:
                    print("Creating directory: " + new_dir)
            generate_tree(new_dir, dirs, rec_depth-1, verbose)
    
# If-test to ensure code only executed if ran as stand-alone app
if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Create a random file tree")
    parser.add_argument("target", help="target folder")
    parser.add_argument("folders", help="max. # of folders created at each level")
    parser.add_argument("files", help="max. # of files created at each level")
    parser.add_argument("-s", "--size", help="file size")
    parser.add_argument("-d", "--depth", help="recursion depth")
    parser.add_argument("-S", "--start", help="mtime/atime start")
    parser.add_argument("-e", "--end", help="mtime/atime end")
    parser.add_argument("--seed", help="seed for the RNG")
    parser.add_argument("-v", "--verbose", action="store_true", help="print info")
    args = parser.parse_args()

    # Fix the random seed (if not None):
    random.seed(args.seed)
    
    args.folders = int(args.folders or 3)
    args.files = int(args.files or 3)
    args.depth = int(args.depth or 5)
    args.start = int(args.start or 1388534400)
    args.end = int(args.end or 1406851201000)
    args.size = int(args.size or 800)
    
    generate_tree(args.target, args.folders, args.depth, args.verbose)
