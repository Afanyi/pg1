#!/bin/bash

g++ -c main5.cpp -o main5.o
g++ -c func1.cpp -o func1.o
g++ -c func2.cpp -o func2.o 
g++ main5.o func1.o func2.o -o main5_merged
