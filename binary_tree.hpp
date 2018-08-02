/*
binary_tree.hpp
author: cameron fraser
date: 8/7/2018

Dynamic library that implements a binary search tree
*/

#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_

struct node{
    int data;
    node *left;
    node *right;
};

class binary_tree{

public:
    binary_tree(int node_limit);
    ~binary_tree();   
    bool search(node *n, int value);
    bool insert(node *n, int value);
    node* del_node(node *n, int value);
    void del_all(node *n);
    int min_value(node *n);
    int max_value(node *n);
    int min_depth(node *n);
    int max_depth(node *n);
    int count_nodes(node *n);

    void set_node_limit(int n);
    void set_root(node *n);
    int get_node_limit();
    node* get_root();
    int get_num_nodes();

private:
    node* min_node(node *n);
    node* max_node(node *n);
    node* create_node(int value);

    node *root;
    int num_nodes;
    int node_limit;
};

#endif // BINARY_TREE_HPP_
