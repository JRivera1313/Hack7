/**
  * binomialDemo.h
  * Author(s): Jesus Rivea III, Kylee Hauxwell
  * Date: 04/8/2019
  *
  * Finds the possable amount of unsorted combonations by n choose k
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

  choice = chooseWithMemoization(n,k);                                          //JR, Does the mem calls
  printf("choose(%d, %d) = %ld\n", n, k, choice);                               //JR, Output
  printf("number of calls: %ld\n", getNumCalls());                              //JR, Output

  return 0;
}
