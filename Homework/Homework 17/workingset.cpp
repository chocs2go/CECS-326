#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
/*
 n is the array size, w is the window size and pages is the list
 of pages.
*/
using namespace std;
void workingset(int n, int w, int pages[])
{
  /* This is the header line as shown in the homework assignment */
  printf("Time \t Size \t Set\n");

  /* DUMMY SAMPLE CODE, REMOVE! */
  /* This print shows how to compute the loop bounds. */
 // printf("Do from %d to %d\n",w-1,n-1);

  /* This print confirms the parameter pass, it shows you how to line
    things up with the headers.*/
 // printf("%d \t %d \t ",n,w);
  for (int time=w-1; time<n; time++)
  {
        vector<int> v;
  for (int i = time-w+1; i <= time; i++){
  //Loop to see if page is in window
  if (find(v.begin(), v.end(), pages[i]) == v.end()){
        v.push_back(pages[i]);
        //Page is in window - do nothing
        }
