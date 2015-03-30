/* Homework 2, 600.120 Spring 2015
wordsearch.c
Name: Joon Hyuck Choi
Date: Feb 15, 2015
Assignment 2
Phone: 667-239-0288
BB login: jchoi100
email: jchoi100@jhu.edu
 */

//Last Edited: 18:46 02/15/2015

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "wordsearch.h"

int load_grid(FILE* infile, char outgrid[][MAXSZ]) {

  int count = 0;

  while(!feof(infile)) {
    fscanf(infile, "%s ", outgrid[count]);
    int length = strlen(outgrid[count]);
    outgrid[count][length] = '\0';
    count++;
  }

  //Check if two of the rows have differing number of characters.
  for(int i = 0; i < count - 2; i++) {
    if(strlen(outgrid[i]) != strlen(outgrid[i + 1])) {
      return 0;
    }
  }

  //Check if numRow == numCol
  if((unsigned int) count != strlen(outgrid[0])) {
    return 0;
  }

  //Check if numRow == 0 or numRow > 10
  if(count == 0 || count > 10) {
    return 0;
  }

  //Check if numCol == 0 or numCol > 10
  for(int i = 0; i < count; i++) {
    if(strlen(outgrid[i]) == 0 || strlen(outgrid[i]) > 10) {
      return 0;
    }
  }

  return count;
} //end load_grid

bool find_word_right(char grid[][MAXSZ], int n, char w[], int i, int j) {

  int wordLen = strlen(w);

  //If the word is longer than the grid dimension n
  if(wordLen > n) {
    return false;
  }

  //If the word would have gotten cut off at right edge
  if((j + wordLen - 1) > n) {
    return false;
  }

  int wordIndex = 0;

  for(int c = j; c <= j + wordLen - 1; c++) {
    if(tolower(grid[i][c]) != tolower(w[wordIndex++])) {
      return false;
    }
  }

  return true;

} //end find_word_right()

bool find_word_left(char grid[][MAXSZ], int n, char w[], int i, int j) {

  int wordLen = strlen(w);

  //If the word is longer than the grid dimension n
  if(wordLen > n) {
    return false;
  }

  //If the word would have gotten cut off at left edge
  if((j - wordLen + 1) < 0) {
    return false;
  }

  int wordIndex = 0;

  for(int c = j; c >= j - wordLen + 1; c--) {
    if(tolower(grid[i][c]) != tolower(w[wordIndex++])) {
      return false;
    }
  }

  return true;

} //end find_word_left()

bool find_word_down(char grid[][MAXSZ], int n, char w[], int i, int j) {

  int wordLen = strlen(w);

  //If the word is longer than the grid dimension n
  if(wordLen > n) {
    return false;
  }

  //If the word would have gotten cut off at bottom edge
  if((i + wordLen - 1) > n) {
    return false;
  }

  int wordIndex = 0;

  for(int r = i; r <= i + wordLen - 1; r++) {
    if(tolower(grid[r][j]) != tolower(w[wordIndex++])) {
      return false;
    }
  }
  return true;

} //end find_word_down()

bool find_word_up(char grid[][MAXSZ], int n, char w[], int i, int j) {

  int wordLen = strlen(w);

  //If the word is longer than the grid dimension n
  if(wordLen > n) {
    return false;
  }

  //If the word would have gotten cut off at bottom edge
  if((i - wordLen + 1) < 0) {
    return false;
  }

  int wordIndex = 0;

  for(int r = i; r >= i - wordLen + 1; r--) {
    if(tolower(grid[r][j]) != tolower(w[wordIndex++])) {
      return false;
    }
  }
  return true;

} //end find_word_up()



void write_all_matches(FILE* outfile, char grid[][MAXSZ], int n, char w[]) {

  bool isItThere = false;

  int countU = 0;
  int countD = 0;
  int countR = 0;
  int countL = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      isItThere = find_word_right(grid, n, w, i, j);
      if(isItThere == true) {
	printf("%s %d %d R\n", w, i, j);
	fprintf(outfile, "%s %d %d R\n", w, i, j);	
	countR++;
      } //end if
    } //end inner for

  } //end outer for

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      isItThere = find_word_left(grid, n, w, i, j);
      if(isItThere == true) {
	printf("%s %d %d L\n", w, i, j);
	fprintf(outfile, "%s %d %d L\n", w, i, j);
	countL++;
      } //end if
    } //end inner for
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      isItThere = find_word_down(grid, n, w, i, j);
      if(isItThere == true) {
        printf("%s %d %d D\n", w, i, j);
        fprintf(outfile, "%s %d %d D\n", w, i, j);
	countD++;
      } //end if
    } //end inner for
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      isItThere = find_word_up(grid, n, w, i, j);
      if(isItThere == true) {
        printf("%s %d %d U\n", w, i, j);
        fprintf(outfile, "%s %d %d U\n", w, i, j);
	countU++;
      } //end if
    } //end inner for
  } //end outer for

  
  //When no instance of the word has been found.
  if(countU == 0 && countD == 0 && countR == 0 && countL == 0) {
    printf("%s - Not Found\n", w);
  }
  
} //end write
