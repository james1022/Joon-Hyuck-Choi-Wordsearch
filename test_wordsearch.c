/* Homework 2, 600.120 Spring 2015
test_wordsearch.c
Name: Joon Hyuck Choi
Date: Feb 16, 2015
Assignment 2
Phone: 667-239-0288
BB login: jchoi100
email: jchoi100@jhu.edu

 */

//Last Edited: 17:15 02/16/2015

#include "wordsearch.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match.
 */
bool fileeq(char lhsName[], char rhsName[]) {
    FILE* lhs = fopen(lhsName, "r");
    FILE* rhs = fopen(rhsName, "r");

    // don't compare if we can't open the files
    if (!lhs || !rhs) return false;

    bool match = true;
    // read until both of the files are done or there is a mismatch
    while (!feof(lhs) || !feof(rhs)) {
        if (feof(lhs) ||                  // lhs done first
            feof(rhs) ||                  // rhs done first
            (fgetc(lhs) != fgetc(rhs))) { // chars don't match
            match = false;
            break;
        }
    }
    fclose(lhs);
    fclose(rhs);
    return match;
} //end fileeq()

/*
 * Test fileeq on same file, files with same contents, files with
 * different contents and a file that doesn't exist
 */
void test_fileeq() {
    FILE* fptr = fopen("test1.txt", "w");
    fprintf(fptr, "this\nis\na test\n");
    fclose(fptr);

    fptr = fopen("test2.txt", "w");
    fprintf(fptr, "this\nis\na different test\n");
    fclose(fptr);

    fptr = fopen("test3.txt", "w");
    fprintf(fptr, "this\nis\na test\n");
    fclose(fptr);

    assert(fileeq("test1.txt", "test1.txt"));
    assert(fileeq("test2.txt", "test2.txt"));
    assert(!fileeq("test2.txt", "test1.txt"));
    assert(!fileeq("test1.txt", "test2.txt"));
    assert(fileeq("test3.txt", "test3.txt"));
    assert(fileeq("test1.txt", "test3.txt"));
    assert(fileeq("test3.txt", "test1.txt"));
    assert(!fileeq("test2.txt", "test3.txt"));
    assert(!fileeq("test3.txt", "test2.txt"));
    assert(!fileeq("", ""));  // can't open file
} //end test_fileeq()

/*
 * A direct copy from the wordsearch.c to match fuction names.
 */
void read_grid(FILE* infile, char outgrid[][MAXSZ]) {

  int count = 0;

  while(!feof(infile)) {
    fscanf(infile, "%s\n", outgrid[count]);
    int length = strlen(outgrid[count]);
    outgrid[count][length] = '\0';
    count++;
  } //end while

} //end load_grid

/*
 * writes out a hard-coded grid to a file;
 * uses read_grid to read in the grid;
 * test that the loaded grid is correct
 */
void test_read_grid() {

  //First test
	//Open a file to write in
	FILE* outfile1_1 = fopen("readGridTest1_1.txt", "w");

	//hard coded grid1
	char grid1[10][MAXSZ] = {"1111111111",
				 "dronesabcd",
				 "thrownabcd",
				 "micronabcd",
				 "electrabcd",
				 "formalabcd",
				 "abcdefabcd", 
				 "dronesabcd",
				 "thrownabcd",
				 "micronabcd"};
	
	//fprint grid1 in outfile1_1.txt
	for(int i = 0; i < 10; i++) {
	  fprintf(outfile1_1, "%s\n", grid1[i]);
	} //end for
	//close outfile1_1
	fclose(outfile1_1);

        //read test1 file and put the same data in test2 file
        FILE* outfile1_2 = fopen("readGridTest1_2.txt", "w"); 
	FILE* infile1 = fopen("readGridTest1_1.txt", "r");
	char testGrid1[10][MAXSZ];
        read_grid(infile1, testGrid1);
	for(int i = 0; i < 10; i++) {
	  fprintf(outfile1_2, "%s\n", testGrid1[i]);
	} //end for

	//close both files
	fclose(infile1);	
        fclose(outfile1_2);
	
        //assert the two files contain the same contents.
        assert(fileeq("readGridTest1_1.txt", "readGridTest1_2.txt"));

       	
  //Second test
	FILE* outfile2_1 = fopen("readGridTest2_1.txt", "w");
	FILE* outfile2_2 = fopen("readGridTest2_2.txt", "w");
	
	//hard coded grid2
        char grid2[10][MAXSZ] = {"2222222222",
				 "dronesabcd",
				 "thrownabcd",
				 "micronabcd",
				 "electrabcd",
				 "formalabcd",
				 "aaaaaaaaaa",
				 "aaaaaaaaaa",
				 "bbbbbbbbbb",
				 "bbbbbbbbbb"};

        //hard coded grid3
        char grid3[10][MAXSZ] = {"3333333333",
				 "dronesabcd",
				 "thrownabcd",
				 "micronabcd",
				 "electrabcd",
				 "formalabcd",
				 "abcdefabcd",
				 "dronesabcd",
				 "thrownabcd",
				 "micronabcd"};

	//fprint grid2 in readGridtest2_1.txt
	for(int i = 0; i < 10; i++) {
	  fprintf(outfile2_1, "%s\n", grid2[i]);
	}
	fclose(outfile2_1);

	//fprint grid3 in readGridtest 2_2.txt
        for(int i = 0; i < 10; i++) {
          fprintf(outfile2_2, "%s\n", grid3[i]);
        }
        fclose(outfile2_2);

	//compare readGridtest2_1.txt and readGridtest 2_2.txt
	//Use read_grid to read each .txt file and save
	//in separate files: 2_3 and 2_4
	FILE* infile2 = fopen("readGridTest2_1.txt", "r");
	FILE* outfile2_3 = fopen("readGridTest2_3.txt", "w");
	char testGrid2[10][MAXSZ];
	read_grid(infile2, testGrid2);
	for(int i = 0; i < 10; i++) {
	  fprintf(outfile2_3, "%s\n", testGrid2[i]);
	}
	fclose(infile2);
	fclose(outfile2_3);

        FILE* infile3 = fopen("readGridTest2_2.txt", "r");
        FILE* outfile2_4 = fopen("readGridTest2_4.txt", "w");
        char testGrid3[10][MAXSZ];
        read_grid(infile3, testGrid3);
        for(int i = 0; i < 10; i++) {
          fprintf(outfile2_4, "%s\n", testGrid3[i]);
        }
        fclose(infile3);
        fclose(outfile2_4);
		
	//assert the two files contain different contents.
	assert(!fileeq("readGridTest2_3.txt", "readGridTest2_4.txt"));
	
	//Some extra assert statements
        assert(!fileeq("readGridTest1_1.txt", "readGridTest2_3.txt"));
        assert(!fileeq("readGridTest1_1.txt", "readGridTest2_4.txt"));
        assert(!fileeq("readGridTest1_2.txt", "readGridTest2_3.txt"));
        assert(!fileeq("readGridTest1_2.txt", "readGridTest2_4.txt"));

} //end test_read_grid()

/*
 * Test find_right()
 */
void test_find_right() {
  
 bool isItThere = false;
 int row = -1;
 int col = -1;
 int gridRow = 2;
 int gridCol = 0;

 char grid[][MAXSZ] = {"pitk",
		       "olpe",
		       "pkey",
		       "tope"};

 for(int i = 0; i < 4; i++) {
   for(int j = 0; j < 4; j++) {
     isItThere = find_word_right(grid, 4, "pke", i, j);
	if(isItThere == true) {
	  row = i;
	  col = j;
	} //end if
   } //end inner for
 } //end outer for

 assert(row == gridRow && col == gridCol);

} //end test_find_right()

/*
 * Test find_left()
 */
void test_find_left() { 

  bool isItThere = false;
  int row = -1;
  int col = -1;
  int gridRow = 0;
  int gridCol = 2;

  char grid[][MAXSZ] = {"pitk",
			"olpe",
			"pkey",
			"tope"};

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_left(grid, 4, "tip", i, j);
      if(isItThere == true) {
	row = i;
	col = j;
      } //end if
    } //end inner for
  }

  assert(row == gridRow && col == gridCol);

} //end test_find_left()

/*
 * Test find_up()
 */
void test_find_up() {  

 bool isItThere = false;

 int row = -1;
 int col = -1;
 int gridRow = 3;
 int gridCol = 3;

 char grid[][MAXSZ] = {"pitk",
		       "olpe",
		       "pkey",
		       "tope"};

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_up(grid, 4, "eyek", i, j);
      if(isItThere == true) {
	row = i;
	col = j;
      } //end if
    } //end inner for
  } //end outer for

  assert(row == gridRow && col == gridCol);

} //end test_find_up()

/*
 * Test find_downn()
 */
void test_find_down() {

  bool isItThere = false;
  int row = -1;
  int col = -1;
  int gridRow = 0;
  int gridCol = 2;

  char grid[][MAXSZ] = {"pitk",
			"olpe",
			"pkey",
			"tope"};

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_down(grid, 4, "tpe", i, j);
      if(isItThere == true) {
       	row = i;
	col = j;
      } //end if
    } //end inner for
  } //end outer for

  assert(row == gridRow && col == gridCol);

} //end test_find_down()

/*
 *Test write_all_matches()
 */
void test_write_all_matches() {

  FILE* outfile = fopen("writeTest1.txt", "w");
  char grid[][MAXSZ] = {"pitk",
			"olpe",
			"pkey",
			"tope"};
  bool isItThere = false;

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_right(grid, 4, "pit", i, j);
      if(isItThere == true) {
	fprintf(outfile, "%s %d %d R\n", "pit", i, j);	
      } //end if
    } //end inner for
  } //end outer for

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_left(grid, 4, "yek", i, j);
      if(isItThere == true) {
	fprintf(outfile, "%s %d %d L\n", "yek", i, j);
      } //end if
    } //end inner for
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_down(grid, 4, "tpe", i, j);
      if(isItThere == true) {
        fprintf(outfile, "%s %d %d D\n", "tpe", i, j);
      } //end if
    } //end inner for
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      isItThere = find_word_up(grid, 4, "okl", i, j);
      if(isItThere == true) {
        fprintf(outfile, "%s %d %d U\n", "okl", i, j);
      } //end if
    } //end inner for
  } //end outer for

  //hardcode expected output in a 2D array
  char expectedOutput[4][10] = {"pit 0 0 R",
				"yek 2 3 L",
				"tpe 0 2 D",
				"okl 3 1 U"};

  //store the expected output in a .txt file
  FILE* compareFile = fopen("compareOutput.txt", "w");
  for(int i = 0; i < 4; i++) {
    fprintf(compareFile, "%s\n", expectedOutput[i]);
  }

  //close both files
  fclose(compareFile);
  fclose(outfile);

  //assert the two files contain the same contents
  assert(fileeq("compareOutput.txt", "writeTest1.txt"));

} //test_write_all_matches()

//Driver main for this tester program
int main(void) {

    printf("Testing fileeq...\n");
    test_fileeq();
    printf("Passed fileeq tests.\n");

    printf("Running wordsearch tests...\n");
 
      test_read_grid();   
      test_find_right();
      test_find_left();
      test_find_up();
      test_find_down();
      test_write_all_matches();
 
   printf("Passed wordsearch tests.\n");

   return 0;
} //end main
