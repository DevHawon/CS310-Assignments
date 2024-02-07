// simulDoubleLinearSearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//



#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int NOT_FOUND = -1;
unsigned long compCount = 0; // global counter

// generate random values between min and max
int random_value(int min, int max);

// takes a vector and an int value and returns the index if found
vector<int> linearSearch(vector<int> array, int searchValue);


int main() {

    // Use current time as seed for random generator 
    srand(time(0));

    const long SIMUL_SIZE = 1000;
    const long VECTOR_SIZE = 100000; // N
    const int MIN = 0, MAX = 15000;

    vector<int> array;
    int hits = 0;
    int misses = 0;
    int min_steps = INT_MAX;
    double average_steps = 0;
    long total_steps = 0;

    // main simulation loop;
    for (long simul_index = 0; simul_index < SIMUL_SIZE; simul_index++)
    {
        compCount = 0; // global variable to count number of steps to complete search

        array.clear(); // remove all elements from the vector
        // filling the vector with VECTOR_SIZE random values
        for (long array_index = 0; array_index < VECTOR_SIZE; array_index++)
        {
            int ranValue = random_value(MIN, MAX);
            array.push_back(ranValue);

        }

        // sort the array elements in ascending order
        sort(array.begin(), array.end());

        // generate a random search value
        int search_value = random_value(MIN, MAX);

        // call the search function
        vector<int> search_index = linearSearch(array, search_value);

        if (search_index[0] == -1)
            misses++;
        else
            hits++;

        // store min steps
        if (min_steps > compCount)
            min_steps = compCount;

        // increment the total steps
        total_steps = total_steps + compCount;

    }

    // determining the average steps
    average_steps = total_steps / static_cast<double> (SIMUL_SIZE);

    cout << "\nHits is: " << hits << endl;
    cout << "\nMisses is: " << misses << endl;
    cout << "\nMin steps is: " << min_steps << endl;
    cout << "\nAverage steps is: " << average_steps << endl;
    

    return 0;
}



// generate random values between min and max (inclusive)
int random_value(int min, int max)
{
    return min + rand() % (max - min) + 1;
}



// takes a vector and an int value and returns the index if found
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
            compCount++;

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
