// M1 Grade Book Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>
using namespace std;

const int maximum = 50;
const int testScores = 5;

void readStudentData(string name[], int grade[][testScores], int &number);
void calculateAverage(int grade[][testScores], double average[], int& number);
void getLetterGrade(double average[], int &number, char letter[]);

int main()
{
	int grade[maximum][testScores], number = 0;
	string name[maximum];
	double average[maximum];
	char letter[maximum];

	readStudentData(name, grade, number);
	calculateAverage(grade, average, number);
	getLetterGrade(average, number, letter);

	return 0;
}

void readStudentData(string name[], int grade[][testScores], int &number)
{
	ifstream inputfile("StudentGrades.txt");
	if (!inputfile)
	{
		cout << "There was an error opening the file.\n";
	}
	
	while (number < maximum && inputfile >> name[number])
	{
		for (int a = 0; a < testScores; a++)
		{
			inputfile >> grade[number][a];
		}
		number++;
	}
}

void calculateAverage(int grade[][testScores], double average[], int& number)
{
	for (int a = 0; a < number; a++)
	{
		double total = 0;
		for (int b = 0; b < testScores; b++)
		{
			total += grade[a][b];
		}
		average[a] = total / testScores;
	}
}

void getLetterGrade(double average[], int & number, char letter[])
{
	for (int a = 0; a < number; a++)
	{
		if (average[a] >= 90 && average[a] <= 100)
		{
			letter[a] = 'A';
		}
		else if (average[a] >= 80)
		{
			letter[a] = 'B';
		}
		else if (average[a] >= 70)
		{
			letter[a] = 'C';
		}
		else if (average[a] >= 60)
		{
			letter[a] = 'D';
		}
		else 
		{
			letter[a] = 'F';
		}
	}
}
