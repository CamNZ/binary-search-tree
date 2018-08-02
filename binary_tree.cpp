/*
binary_tree.cpp
author: cameron fraser
date: 8/7/2018

Dynamic library that implements a binary search tree
*/

#include "binary_tree.hpp"
#include <random>
#include <assert.h>

binary_tree::binary_tree(int node_limit){
    root = nullptr;
    num_nodes = 0;
    binary_tree::node_limit = node_limit;
}

binary_tree::~binary_tree(){
    del_all(root);
}

bool binary_tree::search(node *n, int value){
/* returns true if value exists in tree, flase if not */

    if (n == nullptr){
        return false;
    }
    else if (value == n->data) {
        return true;
    }
    else if (value < n->data){
        return search(n->left, value);
    }
    else if (value > n->data){
        return search(n->right, value);
    }
}

bool binary_tree::insert(node *n, int value){
/* returns true for successful insertion, false if unsuccessful */

    if (root == nullptr){  // if tree empty
        root = create_node(value);
        return root != nullptr ? true : false;
    }

    else if (value == n->data){  // if value already in tree
        return false;
    }

    else if(value < n->data){  // recurse left
        if (n-> left == nullptr){
            n->left = create_node(value);
            return n->left != nullptr ? true : false;
        }
        else{
            insert(n->left, value);
        }
    }

    else if(value > n->data){  // recurse right
        if (n->right == nullptr){
            n->right = create_node(value);
            return n->right != nullptr ? true : false;
        }
        else{
            insert(n->right, value);
        }
    }
}

node* binary_tree::del_node(node *n, int value){
/* deletes node containing value if such a node exists in tree */

    if (n == nullptr){
        return nullptr;
    }

    else if (value < n->data){
        n->left = del_node(n->left, value);
        return n;
    }

    else if (value > n->data){
        n->right = del_node(n->right, value);
        return n;
    }

    else if (value == n->data){
        
        // case: no children
        if ((n->left == nullptr) && (n->right == nullptr)){
            delete n;
            n = nullptr;
            num_nodes--;

            return n;
        }

        // case: one child
        else if (n->left == nullptr){
 
            delete n;
            n = n->right;
            num_nodes--;

            return n;
        }

        else if (n->right == nullptr){
            delete n;
            n = n->left;
            num_nodes--;

            return n;
        }

        // case: two children
        else{
            // tree more balanced if you find inorder sucessor on either left or right
            int ran = rand() % 2;
            if (ran == 0){ // inorder sucessor min node to right
                node *tmp = min_node(n->right);
                n->data = tmp->data;
                n->right = del_node(n->right, tmp->data);
        
                return n;

            }
            else{ // inorder sucessor max node to left
                node *tmp = max_node(n->left);
                n->data = tmp->data;
                n->left = del_node(n->left, tmp->data);

                return n;
            }
        }
    }
}

void binary_tree::del_all(node *n){
/* deletes all nodes from tree */

    if (n == nullptr){
        return;
    }
    else{
        del_all(n->left);
        del_all(n->right);
        delete n;
        num_nodes--;
    }
    root = nullptr;
}

int binary_tree::min_value(node *n){
/* returns lowest value in tree*/
    return min_node(root)->data;
}

int binary_tree::max_value(node *n){
/* returns highest value in tree */
    return max_node(root)->data;
}

int binary_tree::min_depth(node *n){
/* returns the smallest distance from root to a leaf */

    if (n == nullptr){
        return 0;
    }
    else{
        int left = min_depth(n->left);
        int right = min_depth(n->right);
        return left < right ? left + 1 : right + 1;
    }
}

int binary_tree::max_depth(node *n){
/* returns the largest distance from root to a leaf */

    if (n == nullptr){
        return 0;
    }
    else{
        int left = max_depth(n->left);
        int right = max_depth(n->right);
        return left > right ? left + 1 : right + 1;
    }
}

int binary_tree::count_nodes(node *n){
/* counts the number of nodes by traversing entire tree */

    if (n == nullptr){
        return 0;
    }
    else{
        return count_nodes(n->left) + count_nodes(n->right) + 1;
    }
}

void binary_tree::set_node_limit(int n){
    node_limit = n;
}

void binary_tree::set_root(node *n){
    root = n;
}

node* binary_tree::get_root(){
    return root;
}

int binary_tree::get_node_limit(){
    return node_limit;
}

int binary_tree::get_num_nodes(){
    return num_nodes;
}

node* binary_tree::min_node(node *n){
/* returns pointer to node containing lowest value in tree */

    if(n == nullptr){
        return n;
    }
    else{
        return n->left != nullptr ? min_node(n->left) : n;
    } 
}

node* binary_tree::max_node(node *n){
/* returns pointer to node containing highest value in tree */

    if(n == nullptr){
        return n;
    }
    else{
        return n->right != nullptr ? max_node(n->right) : n;
    }
}

node* binary_tree::create_node(int value){
/* returns pointer to node on successful creation, nullptr on unsuccessful creation */

    if (num_nodes < node_limit){
        try{
            node *tmp = new node;
            tmp->data = value;
            tmp->left = nullptr;
            tmp->right = nullptr;
            num_nodes ++;
            return tmp;
        }
        catch(std::bad_alloc e){
            return nullptr;
        }
    }
    else{
        return nullptr;
    }
}












