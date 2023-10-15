#pragma once

/*
    Homework4

    1. Use heap data structure to implement below abstract data type PriorityQueue 

    Requirement:
    You are not allowed to use any C's/C++'s built in data structure class,
    including dynamic array, vector.
    All you can use are basic array and the classes built by yourselves.
*/

/// <summary>
/// prioriry queue
/// </summary>
/// <typeparam name="K"> the type of the key that the priority queue hold</typeparam>
/// <typeparam name="V"> the type of the value that the priority queue hold</typeparam>

template<typename K, typename V>
class PriorityQueue
{
public:
    /// <summary>
    ///     <para>Return the numbers of key-value pairs in the priority queue.</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// <returns> The numbers of key-value pairs in the priority queue. </returns>
    virtual int size() = 0;

    /// <summary>
    ///     <para>Check if the priority queue is empty</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// </returns> true if the priority queue is empty. </returns>
    virtual bool isEmpty()
    {
        return size() == 0;
    };

    /// <summary>
    ///     <para>Insert the key-value pair into the priority queue.</para>
    ///     <para>Note: the key can be duplicated with different value.</para>
    ///     <para>Required time complexity: O(logN), except for resizing</para>
    /// </summary>
    /// <param name="key"></param>
    /// <param name="value"></param>
    virtual void put(const K& key, const V& value) = 0;

    /// <summary>
    ///     <para>Remove the smallest element from the priority queue.</para>
    ///     <para>Required time complexity: O(logN), except for resizing</para>
    /// </summary>
    /// <returns> the associated value if removed successfully.</returns>
    virtual V removeSmallest() = 0;

    /// <summary>
    ///     <para>Get the samllest element from the priority queue.</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// <returns> the associated value if it exists in the priority queue.</returns>
    virtual V getSmallest() const = 0;
};