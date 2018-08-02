/*
interface.h
Author: Cameron Fraser
Date: 8/7/2018

C public interface for binary search tree library
*/

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

    void* create_binary_tree(int node_limit); // Returns pointer to a new tree object. Returns nullptr if unsucessful.  
    void delete_binary_tree(void *ptr); // Safely cleans up all allocated memory

    bool insert(void *ptr, int value); // Returns true on sucessful insert, false otherwise
    bool search(void *ptr, int value); // Returns true is value is found in tree, false otherwise
    void del_node(void *ptr, int value); // Removes node containing value, if it exists
    void del_all(void *ptr); // Removes all nodes
    int min_value(void *ptr); // Returns the lowest value stored in the tree
    int max_value(void *ptr); // Returns the highest value stored in the tree
    int min_depth(void *ptr); // Returns the shortast distance from root to a leaf
    int max_depth(void *ptr); // Returns the greatest distance from root to a leaf
    int count_num_nodes(void *ptr); // Returns the number of nodes, calculated by iterating through the entire tree. For debugging.

    int get_num_nodes(void* ptr);  // Returns the number of nodes
    int get_node_limit(void* ptr); // Returns the current node limit
    void set_node_limit(void* ptr, int value); // Use to set a new node limit. static const int MAX_NODE_LIMIT restricts the maximum value that can be set.

#ifdef __cplusplus
}
#endif

#endif // INTERFACE_HPP_
