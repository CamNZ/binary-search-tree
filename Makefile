###
# Makefile for binary_tree.so
# author: cameron fraser
# date: 8/7/2018
###

all: binary_tree.so

binary_tree.so: binary_tree.o interface.o
	g++ binary_tree.o interface.o -shared -o binary_tree.so

binary_tree.o: binary_tree.cpp
	g++ -c -fPIC binary_tree.cpp -o binary_tree.o -std=c++11

interface.o: interface.cpp
	g++ -c -fPIC interface.cpp -o interface.o -std=c++11

clean:
	rm -rf binary_tree.so binary_tree.o interface.o
	clear

test:
	python -m pytest binary_tree_tests.py
