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

  //eventually modify to call memoized choice function
  choice = chooseWithMemoization(n,k);                                          //JR, Changed to call the new funciton for zybooks
  printf("choose(%d, %d) = %ld\n", n, k, choice);                               //JR,
  printf("number of calls: %ld\n", getNumCalls());                              //JR,

  return 0;
}
