/**
 * Driver program to test the sorting algorithms
 * @author : Hawon Oh
 * @version: 1.0
 */
#include <iostream>
#include "DoublyLinked.h"
#include <vector>

using namespace std;

int main()
{
	DoublyLinked<int> dLinked = DoublyLinked<int>();
	
	dLinked.push_front(10);
	dLinked.push_front(11);
	dLinked.push_front(30);
	dLinked.push_front(25);
	dLinked.push_front(25);
	dLinked.push_front(7);
	dLinked.push_front(10);
	dLinked.push_front(7);
	
	dLinked.displayNode();
	
	dLinked.insertionSort();
	dLinked.displayNode();
}