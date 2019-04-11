/**
  * binomial.c
  * Author(s): Jesus Rivea III, Kylee Hauxwell
  * Date: 04/8/2019
  *
  * Refer to binomial.h for information on the purpous of each function
  *
  *
*/

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
    tableau[i] = (long*)malloc(sizeof(long) * (k + 1));                         //JR, Allocates the second part of the array                                                                       //JR, sets base case for recursion
    for(j=0; j<=k; j++) {
      if (j == 0 || j == i) {
        tableau[i][j] = 1;                                                      //JR Sets base case
      }
      else{
        tableau[i][j] = -1;
      }
    }
  }

  return chooseWithMemoizationRecursive(n, k, tableau);

}

long chooseWithMemoizationRecursive(int n, int k, long **tableau) {

  numCalls++;
  long value = -1;

  //implement error checking on invalid n and k                                 //JR
  if(k < 0 || n < 0) {                                                          //JR
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);       //JR
    exit(1);                                                                    //JR
  }                                                                             //JR

  //if the value has already been computed, return it...                        //JR
  if (tableau[n][k] != -1) {                                                    //JR, Checks if the value has been computed yet, and returns it
    value = tableau[n][k];                                                      //JR
    return value;                                                               //JR
  }                                                                             //JR

    tableau[n][k] = chooseWithMemoizationRecursive(n - 1, k,tableau) + chooseWithMemoizationRecursive(n - 1, k - 1,tableau); //JR, Stores the value in Tablue.

  value = tableau[n][k];                                                        //JR, Value was was part of the starter code so, I used it.
  //free(tableau);                                                              //Zybooks doesn't like this free, but it should probbboly be here.
  return value;
}


long choose(int n, int k) {

  numCalls++;

  //implement error checking on invalid n and k
  if(k < 0 || n < 0) {                                                          //JR
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);       //JR
    exit(1);                                                                    //JR
  }

  //implement Pascal's Rule to choose
  //TEMP CODE TO HELLP FIGURE THE DAMN THING OUT//
  printf("Choose %d %d \t %ld\n",n,k,numCalls);

  //Base case
  if (k == 0 || k == n) {                                                       //JR
    return 1;                                                                   //JR
  }

  return choose(n - 1, k) + choose(n - 1, k - 1);                               //JR
}
