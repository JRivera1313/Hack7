/**
  * binomialDemo.h
  * Author(s): Jesus Rivea III
  * Date: 04/8/2019
  *
  *
*/

#include<stdio.h>
#include<stdlib.h>

#include "binomial.c"                                                           //JR- changed to .c so it will compile

int main(int argc, char **argv) {

  int n;
  int k;

  //TODO - scan n and k
  scanf("%d",&n);
  scanf("%d",&k );

  long choice = -1;

  // //eventually modify to call memoized choice function
  // choice = choose(n, k);
  //
  // printf("choose(%d, %d) = %ld\n", n, k, choice);
  // printf("number of calls: %ld\n\n\n", getNumCalls());              // REMOVE TWO OF THE NEWLINES BEFORE ZYBOOKS

  //TEMP CODE FOR TESTING
  numCalls = 0;                                                     //JR, Resets counter
  choice = chooseWithMemoization(n,k);                      //JR, Does the mem calls
  printf("choose(%d, %d) = %ld\n", n, k, choice);         //JR, Duh
  printf("number of calls: %ld\n", getNumCalls());                  //JR, Duh

  return 0;
}
