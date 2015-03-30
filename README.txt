/* Homework 2, 600.120 Spring 2015
README.txt
Name: Joon Hyuck Choi
Date: Feb 16, 2015
Assignment 2
Phone: 667-239-0288
BB login: jchoi100
email: jchoi100@jhu.edu

 */


----------------------------------------------------------------------------------------------------
How to compile (using Makefile)

   To test:
	-> make test_wordsearch.o
	-> make test_wordsearch
	-> make test

   To compile hw2 and all relevant files:
	-> make wordsearch.o
	-> make hw2.o
	-> make hw2

----------------------------------------------------------------------------------------------------

How to compile (not with Makefile, on command line)

	gcc -std=c99 -Wall -Wextra -pedantic -o hw2 -O wordsearch.h wordsearch.c hw2.c

----------------------------------------------------------------------------------------------------
How to run (not with Makefile, on command line)

   (assuming there is an executable "hw2")

	-> ./hw2 <textfileName>.txt

	(When the .txt file is running)

	-> enter the words you want to find, separating each word by a space.
	   After the program is done finding the words for the first set of inputs, 
	   press enter once and then input the words you want to find again, in the same format.
	   (The user is directed to press enter after one series of input results s
	    so that it is easier to see where one stream of input ends and another starts.)
----------------------------------------------------------------------------------------------------

How to end running
    ctrl + d
----------------------------------------------------------------------------------------------------