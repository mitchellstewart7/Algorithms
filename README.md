# Algorithms
This repository contains work done in my analysis of algorithms class.

# Insertion Sort and Insertion Sort Time
These programs handle an insertion sort algorithm. Insertsort.cpp tests the algorithm out, while insertTime.cpp measures how fast it is sorting very large arrays (giving a better picture of how it compares to merge sort).

# Merge Sort and Merge Sort Time
Similar to insertion sort, these programs handle a merge sort algorithm. Mergesort.cpp tests the algorithm, while mergeTime.cpp measures how fast it is when used at a larger scale. Merge sort is much faster than insertion sort when thousands of items are in the sorted array.

# 0-1 Knapsack
This program provides two solutions to the 0-1 knapsack problem. One is done recursively, while the other is done using dynamic programming. Both calculate the same value, but the dynamic programming alternative runs much more quickly.

# Activity Scheduling
This program uses Greedy algorithm principles to maximize the number of activities that can be scheduled. It runs on the idea that by picking the latest start times at every interval that do not conflict with already selected activities, we can optimize out selections.

# Minimum Spanning Trees
This program takes an input tree and finds its minimum spanning tree (subset of the tree that spans all vertices and has minimum weight). The MST is found using a Greedy algorithm that minimzes total distance traveled along edges at each step.

# Traveling Salesperson Problem
This program is designed to be an approximation algorithm. It is not meant to find an exact optimal distance, but rather a distance that is reasonably close. This is done using a greedy method that functions similarly to the minimum spanning tree function, but also includes traversing back to the source vertex (as to complete the Hamiltonian path).
