// CS310_HW2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// This program will test DoublyLinked list class

#include <iostream>
#include <string>
#include "Node.h"
#include "DoublyLinked.h"

using namespace std;

int main()
{
    // deliverable 1: possible to declare any type of data
    cout << "Deliverable 1 (any name): " << endl;
    DoublyLinked<string> city_names;
    DoublyLinked<int> student_id;
    cout << "two different names doubly linked lists are declared. " << endl << endl;


    // deliverable 2: copy constructor
    cout << "Deliverable 2 (copy constructor): " << endl;
    student_id.push_back(1);
    student_id.push_back(2);
    student_id.push_back(3);
    student_id.push_back(3);

    DoublyLinked<int> id(student_id);

    cout << "student_id"; student_id.display(); // 1 2 3 3
    cout << "id:";  id.display(); // 1 2 3 3
    cout << "They have exactly same items. " << endl << endl;


    // deliverable 3: deleteItem (all items would be removed)
    cout << "Deliverable 3: " << endl;

    DoublyLinked<int> another_id;
    another_id.push_back(1);
    another_id.push_back(2);
    another_id.push_back(2);
    another_id.push_back(3);
    cout << "another_id: "; another_id.display(); // 1 2 2 3

    another_id.deleteItem(2);

    cout << "display: "; another_id.display(); // 1 3

    // deliverable 4: delete(index)
    cout << "Deliverable 4 (delete): " << endl;
    cout << "id: "; id.display(); // 1 2 3 3
    id.deleteNode(2);
    cout << "Deleted 3rd number. It must be 1 2 3" << endl;
    id.display(); cout << endl; // 1 2 3

    // deliverable 5: reverse
    cout << "Deliverable 5 (reverse): " << endl;
    DoublyLinked<int> account_nums;
    account_nums.push_back(1);
    account_nums.push_back(2);
    account_nums.push_back(3);
    account_nums.push_back(4);
    account_nums.push_back(5);
    // account_nums.push_back(6);

    cout << "account_nums: ";  account_nums.display(); // 1 2 3 4 5
    account_nums.reverse();
    cout << "reversed: ";  account_nums.display(); cout << endl; // 5 4 3 2 1

    // deliverable 6: search
    cout << "Deliverable 6 (search): " << endl;
    account_nums.push_back(3);
    cout << "account_nums: "; account_nums.display();
    cout << "3 are found from index (first index = 0): ";

    vector<int> vector1 = account_nums.search(3);

    for (const int& i : vector1)
    {
        cout << i << " "; // 3 5
    }
    cout << endl << endl;

    // deliverable 7: student class and overloaded operators
    cout << "Deliverable 7 (student class): " << endl;
    cout << endl;

    // deliverable 8: student class and test
    cout << "Deliverable 8 (test student class): " << endl;

    return 0;
}
