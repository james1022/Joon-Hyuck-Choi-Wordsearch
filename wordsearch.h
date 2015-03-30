/* Homework 2, 600.120 Spring 2015
wordsearch.h
Name: Joon Hyuck Choi
Date: Feb 15, 2015
Assignment 2
Phone: 667-239-0288
BB login: jchoi100
email: jchoi100@jhu.edu

 */

//Last Edited: 18:31 02/15/2015

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// maximum grid size
#define MAXSZ 11

int load_grid(FILE* infile, char outgrid[][MAXSZ]);

// reads square grid from infile until first empty line
// returns the number of rows in the grid or 0 for an error
int load_grid(FILE* infile, char outgrid[][MAXSZ]);

// return true if the word 'w' is in
// the n x n grid starting at the given i, j position
// and moving in the specified direction;
// n specifies the length and width of the grid (try
// to avoid code duplication in these; you may want
// other helper functions that they can all use)
bool find_word_up(char grid[][MAXSZ], int n, char w[], int i, int j);
bool find_word_down(char grid[][MAXSZ], int n, char w[], int i, int j);
bool find_word_left(char grid[][MAXSZ], int n, char w[], int i, int j);
bool find_word_right(char grid[][MAXSZ], int n, char w[], int i, int j);
    
// searches the n x n grid for the given word, w, and prints
// the matches to outfile; n specifies the length and width
// of the grid (which is square)
void write_all_matches(FILE* outfile, char grid[][MAXSZ], int n, char w[]);
