//
// Created by 黃威凱 on 2023/8/14.
//

#pragma once

/*
    Homework2

    Implement the below class Binary search tree

    Requirement:
    You are not allowed to use any C's/C++'s built in data structure class,
	including dynamic array, vector.
	All you can use are basic array and the classes built by yourselves.
*/

/// <summary>
/// Binary Search Tree
/// </summary>

template <typename T>
class BinarySearchTree {
public:
    /// <summary>
    /// Return the numbers of element in the binary search tree.
    /// </summary>
    /// <returns> The numbers of element in the binary search tree. </returns>
    virtual int size() const = 0;

    /// <summary>
    /// Check if the binary search tree is empty
    /// </summary>
    /// </returns> true if the binary search tree is empty. </returns>
    virtual bool empty()
    {
        return size() == 0;
    };

    /// <summary>
    /// Insert the element into binary search tree
    /// </summary>
    /// <param name="item"> item to put in binary search tree</param>
    virtual void insertion(const T& item) = 0;

    /// <summary>
    /// Remove the element from the binary search tree
    /// </summary>
    /// <param name="item">item to remove from binary search tree</param>
    virtual void deletion(const T& item) = 0;

    /// <summary>
    /// Check if the element in the binary search tree
    /// </summary>
    /// <returns> true if the element in the binary search tree.</returns>
    virtual bool search(const T& item) const = 0;

    /// <summary>
    /// Accesses the root element without removing it
    /// </summary>
    /// <returns> A reference to the root element. </returns>
    virtual const T& top() const = 0;

    /// <summary>
    /// Print the binary search tree.
    /// </summary>
    virtual void printTree() const = 0;
};
