/* Homework 2, 600.120 Spring 2015
hw2.c
Name: Joon Hyuck Choi
Date: Feb 16, 2015
Assignment 2
Phone: 667-239-0288
BB login: jchoi100
email: jchoi100@jhu.edu

*/

//Last Edited: 16:58 02/16/2015

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "wordsearch.h"

int main(int argc, char* argv[]) {

  //Usage error
  if(argc == 1) {
    printf("Usage: enter a file name as an argument.\n");
    return 1;
  } //end if

  //open one file for reading and another for writing
  FILE* infile = fopen(argv[1], "r");
  FILE* outfile = fopen("testoutput.txt", "w");

  //if the file that the user input cannot be read
  if(infile == NULL) {
    printf("Error in opening given file!\n");
    exit(1);
  } //end if

  //if the file to be written in cannot be read
  if(outfile == NULL) {
    printf("Error in opening output file!\n");
    exit(1);
  } //end if

  //Initialize a 2D grid array with '\0'
  char ourArray[10][MAXSZ];
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < MAXSZ; j++) {
      ourArray[i][j] = '\0';
    } //end inner for
  } //end outer for

  //load the result of load_grid in an int
  int result = load_grid(infile, ourArray);

  //End the program if there was an error in reading the file.
  if(result == 0) {
    printf("Error with the input grid!\n");
    exit(1);
  } //end for

  //get input from the user
  char entry[100]; //save user's input here
  printf("Enter words you want to find: "); //prompt just once

  //Keep searching for words until end of input
  do {
    fgets(entry, 500, stdin);

    //parse the user's inputs into tokens
    const char s[4] = " \n ";
    char* pch;
    pch = strtok(entry, s);

    //search for word tokens in the grid
    while(pch != NULL) {
      write_all_matches(outfile, ourArray, result, pch);
      pch = strtok(NULL, s);
    } //end while

  } while(fgets(entry, 500, stdin) != NULL); //condition to jump out

  //close both files
  fclose(infile);
  fclose(outfile);

  return 0;
} //end main
