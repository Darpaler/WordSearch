// WordSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Constant Variables
const int MAX_WORDS = 1024;	//Amount of words we're going to search for

int main()
{
	//Variables
	string words[MAX_WORDS];				//The list of words to search for
	string paragraph[MAX_WORDS];			//The paraghraph we're searching in
	ifstream infile1("inputfile1.txt");		//The file we're reading the words from
	ifstream infile2("inputfile2.txt");		//The file we're searching for the words

	for (int i = 0; i < MAX_WORDS; i++) {
		if (!infile1.eof()) 
		{
			infile1 >> words[i];
		}
	}
	infile1.close();

	for (int i = 0; i < MAX_WORDS; i++) 
	{
		int count = 0;
		for (int x = 0; x < MAX_WORDS; x++)
		{
			if (!infile2.eof())
			{
				infile2 >> paragraph[x];
				if (paragraph[x] == words[i]) count++;
			}
		}
		cout << words[i] << " count = " << count;
	}
}