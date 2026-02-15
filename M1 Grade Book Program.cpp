// M1 Grade Book Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>
using namespace std;

const int maximum = 50;
const int testScores = 5;

void readStudentData(string name[], int grade[][testScores], int &number);

int main()
{
	int grade[maximum][testScores], number = 0;
	string name[maximum];
	double average;

	readStudentData(name, grade, number);

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
