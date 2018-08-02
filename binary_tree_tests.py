#!/usr/bin/env python2

"""
binary_tree_tests.py
author: cameron fraser
date: 8/7/2018

a simple test suite for binary_tree.so using the pytest module
to run: python -m pytest binary_tree_tests.py
"""

import pytest
import ctypes
import random
import os
import sys

dll_path = '{0}/binary_tree.so'.format(os.getcwd())

def test_dll_ctypes():
    """ Test linking to shared library with python ctypes"""
    binary_tree = ctypes.CDLL(dll_path)

def test_create_tree():
    """ Test instantiation of binary tree object """
    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))
    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_search_insert():
    """ Insert random values into tree, test that these values have been inserted and no others"""

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = random.sample(range(-500, 500), random.randint(100, 150))

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    for k in range(-500, 500):
        if k in vals:
            assert binary_tree.search(ctypes.c_void_p(b1), k)
        else:
            assert not binary_tree.search(ctypes.c_void_p(b1), k)

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_num_nodes():
    """ Insert a random number of nodes. Test that get_num_nodes and count_num_nodes both return this number"""

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    x = random.randint(50, 250)

    for k in range(x):
        binary_tree.insert(ctypes.c_void_p(b1), k)

    assert binary_tree.get_num_nodes(ctypes.c_void_p(b1)) == x
    assert binary_tree.count_num_nodes(ctypes.c_void_p(b1)) == x

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_del_node():
    """ Test del_node method by inserting random values, then attempt to delete all potential values in source range"""

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    insert_vals = random.sample(range(-500, 500), random.randint(100, 150))

    for val in insert_vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    test_vals = range(-500, 500)
    random.shuffle(test_vals)

    for val in test_vals:
        if val in insert_vals:

            assert binary_tree.search(ctypes.c_void_p(b1), val)
            nodes_before_del = binary_tree.get_num_nodes(ctypes.c_void_p(b1))

            binary_tree.del_node(ctypes.c_void_p(b1), val)

            assert not binary_tree.search(ctypes.c_void_p(b1), val)
            assert binary_tree.get_num_nodes(ctypes.c_void_p(b1)) == nodes_before_del -1

        else:

            assert not binary_tree.search(ctypes.c_void_p(b1), val)
            nodes_before_del = binary_tree.get_num_nodes(ctypes.c_void_p(b1))

            binary_tree.del_node(ctypes.c_void_p(b1), val)

            assert binary_tree.get_num_nodes(ctypes.c_void_p(b1)) == nodes_before_del

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_del_all():
    """ Test that after del_all method there are zero nodes"""

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = random.sample(range(-500, 500), random.randint(100, 150))

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    binary_tree.del_all(ctypes.c_void_p(b1))

    assert binary_tree.get_num_nodes(ctypes.c_void_p(b1)) == 0

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_min_value():
    """ Insert random values into tree, test that min_value returns expected result """

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = random.sample(range(-500, 500), random.randint(100, 150))

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    assert binary_tree.min_value(ctypes.c_void_p(b1)) == min(vals)

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_max_value():
    """ Insert random values into tree, test that max_value returns expected result """

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = random.sample(range(-500, 500), random.randint(100, 150))

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    assert binary_tree.max_value(ctypes.c_void_p(b1)) == max(vals)

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_set_node_limit():
    """ Test set_node_limit method """

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    x = random.randint(500, 5000)

    binary_tree.set_node_limit(ctypes.c_void_p(b1), x)

    assert binary_tree.get_node_limit(ctypes.c_void_p(b1)) == x

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_min_depth():
    """ Insert a predetermined set of nodes, test that min_depth is calculated correctly """


    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = [8, 17, 10, 3, 5, 1, 2, 13, 9]

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    assert binary_tree.min_depth(ctypes.c_void_p(b1)) == 2

    binary_tree.insert(ctypes.c_void_p(b1), 18)

    assert binary_tree.min_depth(ctypes.c_void_p(b1)) == 3

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_max_depth():
    """ Insert a predetermined set of nodes, test that max_depth is calculated correctly """

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    b1 = binary_tree.create_binary_tree(ctypes.c_int(10000))

    vals = [8, 17, 10, 3, 5, 1, 2, 13, 9]

    for val in vals:
        binary_tree.insert(ctypes.c_void_p(b1), val)

    assert binary_tree.max_depth(ctypes.c_void_p(b1)) == 4

    binary_tree.insert(ctypes.c_void_p(b1), 15)

    assert binary_tree.max_depth(ctypes.c_void_p(b1)) == 5

    binary_tree.delete_binary_tree(ctypes.c_void_p(b1))

def test_node_limit():
    """ Insert more nodes than limit. After limit is exceeded insertions should fail """

    binary_tree = ctypes.CDLL(dll_path)
    binary_tree.create_binary_tree.restype = ctypes.c_void_p
    binary_tree.insert.restype = ctypes.c_bool

    limit = random.randint(100, 150)

    b1 = binary_tree.create_binary_tree(ctypes.c_int(limit))

    for k in range(1, limit * 2, 1):
        if k <= limit:
            assert binary_tree.insert(ctypes.c_void_p(b1), k)
        else:
            assert not binary_tree.insert(ctypes.c_void_p(b1), k)



