/**
  * binomial.c
  * Author(s): Jesus Rivea III
  * Date: 04/8/2019
  *
  *
*/


//DOCUMENTATION HERE

#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"

long getNumCalls() {
  return numCalls;
}

long chooseWithMemoization(int n, int k) {

//implement error checking on invalid n and k
  if(k < 0 || n < 0 ) {                                                         //JR
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);
    exit(1);
  }

  int i, j;

  /*
     dynamically allocate (malloc) a matrix of longs to hold values,
     containing flags to indicate if the values has been set or
     not
  */

  //malloc
  long** tableau = (long**)malloc(sizeof(long*) * (n + 1));                     //JR, Allocates enough memory for first part of array
  for(i=0; i<=n; i++) {
    //malloc
    tableau[i] = (long*)malloc(sizeof(long) * (k + 1));                         //JR, Allocates the second part of the array

    if (i == 0) {                                                               //JR, sets base case for recursion
      for (j = 0; j <= k; j++) {
        tableau[i][j] = 1;
      }
    }

    for(j=0; j<=k; j++) {
      tableau[i][j] = -1;
    }
  }

  return chooseWithMemoizationRecursive(n, k, tableau);

}

long chooseWithMemoizationRecursive(int n, int k, long **tableau) {

  numCalls++;
  long value;

  //if the value has already been computed, return it...
  if (tableau[n][k] != -1) {                                                    //JR, Checks if the value has been computed yet, and returns it
    return tableau[n][k];
  }
  //otherwise do recursive logic, determine when to call function again

  //Base case
  if (k == n) {                                                                 //JR
    return 1;                                                                   //JR
  }


  value = chooseWithMemoizationRecursive(n - 1, k,tableau) + chooseWithMemoizationRecursive(n - 1, k - 1,tableau); //JR, yay recursion :|....                                                          //JR, pretty much the same code from Choose

  return value;
}


long choose(int n, int k) {

  numCalls++;

  //implement error checking on invalid n and k
  if(k < 0 || n < 0) {                                                          //JR
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);
    exit(1);
  }

  //implement Pascal's Rule to choose

  //Base case
  if (k == 0 || k == n) {                                                       //JR
    return 1;                                                                   //JR
  }                                                                             //JR
  return choose(n - 1, k) + choose(n - 1, k - 1);                               //JR
}
