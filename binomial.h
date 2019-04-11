/**
  * binomial.h
  * Author(s): Jesus Rivea III, Kylee Hauxwell
  * Date: 04/8/2019
  *
  *
*/


static long numCalls = 0;

//returns the number of function calls that were necessary to execute Pascal's Rule in choosing
long getNumCalls();

//Returns N choose K by the recursive formula (n, k) = (n-1, k) + (n-1, k -1)
long choose(int n, int k);

//Allocates memory for its subsequent recusive call of chooseWithMemoizationRecursive and sets base cases
long chooseWithMemoization(int n, int k);

//Optomised version of the choose function. Preforms the same recusion. However, it stores all values per iteration in a table
// that it then checks aginst. If the value is in the table, it ceses recurion and returns the areadly solved value in the table
// instead.
long chooseWithMemoizationRecursive(int n, int k, long **tableau);
