/**
  * binomial.h
  * Author(s): Jesus Rivea III
  * Date: 04/8/2019
  *
  *
*/


static long numCalls = 0;

//returns the number of function calls that were necessary to execute Pascal's Rule in choosing
long getNumCalls();

//TO DOCUMENT
long choose(int n, int k);

//Allocates memory for its subsequent recusive call of chooseWithMemoizationRecursive
long chooseWithMemoization(int n, int k);

//TO DOCUMENT
long chooseWithMemoizationRecursive(int n, int k, long **tableau);
