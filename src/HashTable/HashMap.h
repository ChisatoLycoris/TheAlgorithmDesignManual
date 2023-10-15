#pragma once

/*
    Homework3

    1. Create a class inherit the below class Hash Table.

    Requirement:
    You are allowed to use the hash function built in c++ or the third party library .
    You are not allowed to use any C's/C++'s built in data structure class,
    including dynamic array, vector.
    All you can use are basic array and the classes built by yourselves.
*/

/// <summary>
/// hash table
/// </summary>
/// <typeparam name="K"> the type of the key that the hash table hold</typeparam>
/// <typeparam name="V"> the type of the value that the hash table hold</typeparam>

template<typename K, typename V>
class HashMap
{
public:
    /// <summary>
    ///     <para>Return the numbers of key-value pairs in the hash table.</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// <returns> The numbers of key-value pairs in the hash table. </returns>
    virtual int size() const = 0;

    /// <summary>
    ///     <para>Check if the hash table is empty</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// </returns> true if the hash table is empty. </returns>
    virtual bool isEmpty() const
    {
        return size() == 0;
    };

    /// <summary>
    ///     <para>Insert the key-value pair into the hash table.</para>
    ///     <para>If the key already existed in the hash table, update the value.</para>
    ///     <para>Required time complexity: O(1), except for resizing</para>
    /// </summary>
    /// <param name="key"></param>
    /// <param name="value"></param>
    virtual void insert(const K& key, const V& value) = 0;

    /// <summary>
    ///     <para>Remove the element from the hash table.</para>
    ///     <para>Required time complexity: O(1), except for resizing</para>
    /// </summary>
    /// <param name="key"></param>
    virtual void remove(const K& key) = 0;

    /// <summary>
    ///     <para>Search for a element from the hash table based on a key.</para>
    ///     <para>Required time complexity: O(1)</para>
    /// </summary>
    /// <param name="key"></param>
    /// <returns> the associated value if it exists in the hash table.</returns>
    virtual V get(const K& key) const = 0;
};