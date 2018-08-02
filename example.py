#!/usr/bin/env python2

"""
example.py
Author: Cameron Fraser
Date: 8/7/2018

A simple example demonstating how to link to binary_tree.so from another language
"""

import ctypes
import os

dll_path = '{0}/binary_tree.so'.format(os.getcwd())

assert os.path.exists(dll_path) # Check that path to dynamic library is valid

binary_tree = ctypes.CDLL(dll_path) # Link to library using ctypes python

# Explicitly declare return types from interface functions
binary_tree.create_binary_tree.restype = ctypes.c_void_p 
binary_tree.insert.restype = ctypes.c_bool
binary_tree.search.restype = ctypes.c_bool
binary_tree.min_depth.restype = ctypes.c_int
binary_tree.max_depth.restype = ctypes.c_int

# Create binary tree object. Returns a void pointer that is used to reference the specific binary tree object.
node_limit = 10000
b1 = binary_tree.create_binary_tree(ctypes.c_int(node_limit)) 

vals = [3, 8, 5, 1, 9, 7, 4] # Values to insert into tree

"""
Diagram of expected BST from above values
        3
       / \
      1   8
         / \
        5   9
       / \
      4   7

"""

for val in vals:
    binary_tree.insert(ctypes.c_void_p(b1), ctypes.c_int(val)) # Insert values into tree

print 'Min depth: ', binary_tree.min_depth(ctypes.c_void_p(b1))
print 'Max depth: ', binary_tree.max_depth(ctypes.c_void_p(b1))

# Loop through values in range, printing 'True' if they are found in tree 
for k in range(10):
    print k, binary_tree.search(ctypes.c_void_p(b1), ctypes.c_int(k))


binary_tree.delete_binary_tree(ctypes.c_void_p(b1)) # Delete binary_tree object

