/*
interface.cpp
author: cameron fraser
date: 8/7/2018

C public interface for binary search tree library
*/

#include "interface.hpp"
#include "binary_tree.hpp"
#include <new>
#include <assert.h>

static const int MAX_NODE_LIMIT = 20000;

void* create_binary_tree(int node_limit){
    assert (node_limit > 0);
    assert (node_limit <= MAX_NODE_LIMIT);
    return new(std::nothrow) binary_tree(node_limit);
}

void delete_binary_tree(void *ptr){
    delete (binary_tree*)ptr;
}

bool insert(void *ptr, int value){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->insert(ref->get_root(), value);
}

bool search(void *ptr, int value){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->search(ref->get_root(), value);
}

void del_node(void *ptr, int value){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    ref->set_root( ref->del_node(ref->get_root(), value) );
}

void del_all(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    ref->del_all(ref->get_root());
}

int min_value(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->min_value(ref->get_root());
}

int max_value(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->max_value(ref->get_root());
}

int min_depth(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->min_depth(ref->get_root());
}

int max_depth(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->max_depth(ref->get_root());
}

int count_num_nodes(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->count_nodes(ref->get_root());
}

int get_num_nodes(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->get_num_nodes();
}

int get_node_limit(void *ptr){
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    return ref->get_node_limit();
}

void set_node_limit(void *ptr, int node_limit){
    assert (node_limit > 0);
    assert (node_limit <= MAX_NODE_LIMIT);
    binary_tree *ref = reinterpret_cast<binary_tree *>(ptr);
    ref->set_node_limit(node_limit);
}














