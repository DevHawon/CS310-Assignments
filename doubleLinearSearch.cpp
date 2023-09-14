// 2023-09-14 by Hawon Oh
// this program finds the first two indices where their values are equal to a search value.
// if not found, print -1.

#include <iostream>
#include <vector>

using namespace std;

vector<int> linear_search(vector<int>, int);

int main()
{
    vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 5};
    int search_value = 10;
    
    vector<int> search_result = linear_search(array, search_value);
    
    // print array and search value
    for (unsigned i = 0; i < array.size(); i++)
    {
        cout << array.at(i) << " ";
    }
    cout << endl << "Search value: " << search_value << endl;
    cout << "Result: ";
    
    // print results
    for (unsigned i = 0; i < search_result.size(); i++)
    {
        cout << search_result.at(i) << " ";
    }
}

/** @brief  find first two indices at which their values are equal to the search value param
 *  @data   2023-09-14
 *  @return int vector array(0 < size < 3) : one or two indices that have equal value
 *  @param  int vector array(0 =< size)    : array to be searched
 *          int                            : value to search
 */
vector<int> linear_search(vector<int> array, int search_value)
{
    vector<int> result;
    int i;
    
    // find first index
    for (i = 0; i < array.size(); i++)
    {
        if (array.at(i) == search_value)
        {
            result.push_back(i);
            
            i++;
            break;
        }
    }
    
    // find second index
    for (; i < array.size(); i++)
    {
        if (array.at(i) == search_value)
        {
            result.push_back(i);

            break;
        }
    }
    
    // if search value not found, return -1
    if (result.empty())
    {
        result.push_back(-1);
    }

    return result;
}
