// A simulation to determine the efficiency of the lenear search algorithm

#include <iostream>
#include <vector>
#define NOT_FOUND 1
using namespace std; 

vector<int> double_linear_search(const vector<int>& array, int search_value, int&comp);
/**
* Returns a random number within the range low and high
*/
unsigned get_rand_in_range(unsigned low, unsigned high);

/**
* The main function
*/

int main()
{ 
  srand(time(0)); // in order to generate random numbers
  
  const int SIMUL_SIZE = 1000;
  const int RAND_SIZE = 15000;
  const int VECTOR_SIZE = 10000;
  vector<int> test_values;
  double sumOfComparison = 0;
  int hits= 0;
  int miss = 0;
  int min_comparison = INT_MAX;
  
  
  
  // this search process will run 1000 number of times.
  for(int i=0;i<SIMUL_SIZE; i++)
  { 
    // clearing the vector, so, we can start with an empty vector
    test_values.clear();
    
    // generating random values and storing them to the vector
    for(int k=0;k<VECTOR_SIZE;k++)
    {
      int value = get_rand_in_range(1, RAND_SIZE);
      test_values.push_back(value); 
    }
    
    sort(test_values.begin(), test_values.end());
    
    // generating a random value to search in the vector
    int searchValue = get_rand_in_range(1, RAND_SIZE);
    int comp = 0;
    
    // calling the function to search for the searchValue
    vector<int> results = double_linear_search(test_values, searchValue, comp);
    
    // determining whether we have found this element in the vector
    if(results.at(0) == -1) // Not found
    {
      miss ++;
    }
    else // Found
    {  
      hits ++;
    }
    
    if(comp < min_comparison)
        min_comparison = comp;
    
    // adding the number of comparisons to the sum
    sumOfComparison = sumOfComparison + comp;
  }
  
  // preparing the report to show the average comparison size
  cout <<"\nHits: " << hits << endl;
  cout<<"\nMiss: " << miss << endl;
  cout<<"\nAverage number of comparisons: " <<sumOfComparison/SIMUL_SIZE<<endl;
  cout << "\nMin comparisons: " << min_comparison << endl;

  
  return 0; // end of the main function
}



/*  search the element value inside the vector array
*   inside the comp variable we store the number of comparisons needed
*/



/** @brief  find first two indices at which their values are equal to the search value param
 *  @data   2023-09-14
 *  @return int vector array(0 < size < 3) : one or two indices that have equal value
 *  @param  int vector array(0 =< size)    : array to be searched
 *          int                            : value to search
 */
vector<int> double_linear_search(const vector<int>& array, int search_value, int&comp)
{
    vector<int> result;
    int i;
    
    // find first index
    for (i = 0; i < array.size(); i++)
    {
        comp++; // counting the number of comparisons for the search
        
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
        comp++; // counting the number of comparisons for the search
        
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

/**
* Returns a random number within the range low and high
*/
unsigned get_rand_in_range(unsigned low, unsigned high)
{
  int random_number=0;
  // generate the random number
  random_number = low + rand() % (high - low + 1);
  return random_number;
}




