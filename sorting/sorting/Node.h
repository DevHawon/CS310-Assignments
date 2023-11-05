#pragma once

/**
 * Node class
 * @author : Hawon Oh
 * @version: 1.0
 */
template<typename T>
class Node
{
	public:
    Node<T> *prev;
    T data;
    Node<T> *next;
};