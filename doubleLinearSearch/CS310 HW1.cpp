// CS310 HW1.cpp : 2024-02-07 by Hawon Oh
// this program uses linear search algorithm and prints the first two index positions
// if no search value is matched, print -1

#include <iostream>
#include <vector>

using namespace std;

vector<int> linearSearch(vector<int>, int);

int main()
{
    vector<int> array {10, 50, 16, 1, 9, 15, 16, 20, 16, 2, 5};
    int searchValue = 16;
    vector<int> searchResult = linearSearch(array, searchValue);

    // print search result
    for (int i : searchResult)
    {
        cout << i << " ";
    }

    return 0;
}




/** @brief  find first two index positions at which their values
            are equal to the search value param, if no search value found, return -1
 *  @date   2024-02-06
 *  @return int vector array(0 < size < 3) : one or two indices that have equal value
 *  @param  int vector array(0 =< size)    : array to be searched
 *          int                            : value to search
 */
vector<int> linearSearch(vector<int> arr, int search)
{
    vector<int> result;

    // return -1 when negative search value
    if (search < 0) result.push_back(-1);

    // the loop will find only up to 2 index positions
    else
    {
        int count = 2;  

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == search)
            {
                result.push_back(i + 1);

                count--;
                if (count == 0) break;
            }
        }

        // if no search value found, return -1
        if (result.empty()) result.push_back(-1);
    }

    return result;
}