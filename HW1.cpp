/*Name: Yen Pham	yenpham@my.unt.edu
Instructor: David Keithly
Class: CSCE1040
Assignment: Homework 1
Description: The purpose of this homework is to read the file, sort the students
in the file based on their grades, and display on screen the students's name and
grades in ascending order 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bubble.cpp"

typedef struct 
{
	float mean; 
	float min;
	float max;
	float median;
	char *name;
} classStates;

int main()
{
	int size = 19;
	float sumOfMean = 0;
	classStates class1;
	student *studentData[size]; //array of 19 student pointers
	char *classID;

	//Allocate memory for each pointer
	for (int i = 0; i < 19; i++)
	{
		studentData[i] = (student*) malloc(sizeof(student));
	}

	FILE *fptr;
	fptr=fopen("grades","r"); //open the read-only file
	if (fptr==NULL)
	{
		printf("File does not exist"); //display on screen if file does not exist
		exit(0);
	}
	
	classID = (char*) malloc(sizeof(char)); //allocate memory for char pointer classID
	fscanf(fptr, "%s", classID); //read in the classID

	for (int i = 0; i < size; i++)
	{
		(*studentData[i]).first = (char*) malloc(sizeof(char)); //allocate memory for the char pointer variable firstname 
		(*studentData[i]).last = (char*) malloc(sizeof(char)); //allocate memory for the char pointer variable lastname

		//read the first, last name & exams' scores for each student
		fscanf(fptr, "%s %s %d %d %d", (*studentData[i]).first, (*studentData[i]).last, &((*studentData[i]).exam1), &((*studentData[i]).exam2), &((*studentData[i]).exam3)); 

		//calculate the mean of each student's scores
		(*studentData[i]).mean = (float) ((*studentData[i]).exam1 + (*studentData[i]).exam2 + (*studentData[i]).exam3)/3.00;
		sumOfMean = sumOfMean + (*studentData[i]).mean; //get the sum of all grades' average
	}
	class1.mean = (float) ((sumOfMean) / size); //calculate the average of student's grades in class

	bubble(studentData, size); //call the function bubble to sort the students based on their grades' average

	class1.min = (*studentData[0]).mean; //assign the lowest student's average to the class's lowest grades
	class1.max = (*studentData[size-1]).mean; //assign the highest student's average the class's highest grades
	class1.median = (*studentData[(int) (floor(size/2.0))]).mean; //assign the median student's average to the class's median average
	
	printf("123456789012345678901234567890123456789012345678901234567890\n"); //print the digits

	//print the class's mean, mininum, maximum and meidan grades
	printf("%s  MEAN: %.2f  MIN:%.2f  MAX: %.2f  MEDIAN: %.2f\n", classID, class1.mean, class1.min, class1.max, class1.median);
	
	// display students data, including their names and their averages
	for (int i = 0; i < size; i++)
	{
		printf("%10s\t%10s\t%.2f\n", (*studentData[i]).first, (*studentData[i]).last, (*studentData[i]).mean);
	}
  	
	fclose(fptr); // close the file
  return 0;
}
