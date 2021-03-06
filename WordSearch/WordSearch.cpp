// WordSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Constant Variables
const int MAX_WORDS = 1024;										//Amount of words we're going to search for

int main()
{
	//Variables
	string words[MAX_WORDS];									//The list of words to search for
	string paragraph[MAX_WORDS];								//The paraghraph we're searching in
	ifstream infile1;											//The file we're reading the words from
	ifstream infile2;											//The file we're searching for the words
	ofstream outfile;											//The file to write output to
	int count;													//The amount of times the word we're searching for appears

	//Get Words
	infile1.open("inputfile1.txt");								//Open the file with words to search for
	cout << "Reading file 1...\n";
	for (int i = 0; i < MAX_WORDS; i++) {						//For every word in the file
		if (!infile1.eof())										//If we're not at the end of the file
		{
			infile1 >> words[i];								//Add it to the list
		}
		else													//If the file ends
		{
			break;												//Stop checking for words
		}
	}
	infile1.close();											//Close the file
	cout << "File 1 closed.\n\n";

	//Get Paragraph
	infile2.open("inputfile2.txt");								//Open the file with paragraphs to search in
	cout << "Reading file 2...\n";
	for (int i = 0; i < MAX_WORDS; i++)							//For every word in the file
	{
		if (!infile2.eof())										//If we're not at the end of the file
		{
			infile2 >> paragraph[i];							//Add it to the list
		}
		else													//If the file ends
		{
			break;												//Stop checking for words
		}
	}
	infile2.close();											//Close the file
	cout << "File 2 closed.\n\n";

	//Compare the two lists
	outfile.open("outputfile.txt");								//Open the Output file
	cout << "Writing words found in Output file...\n";
	outfile << "Words Found in File\n\nWord : Count\n";			//Add header to file
	for (int i = 0; i < MAX_WORDS; i++)							//For every word in the list of words
	{
		if (words[i] != "")										//If the word is not null
		{
			count = 0;											//Reset the count
			for (int n = 0; n < MAX_WORDS; n++)					//For every word in the paragraphs
			{
				if (paragraph[n] != "")							//If the word is not null
				{
					if (words[i] == paragraph[n])				//Check if it is the word we're searching for
					{
						count += 1;								//Add 1 to our count if it is
					}
				}
				else											//If the word from the paragraph is null
				{	
					break;										//Stop checking for words
				}
			}

			outfile << words[i] << " : " << count << endl;		//Add the word and count to the Output file
		}
		else													//If the word to search for is null
		{
			break;												//Stop searching for words
		}
	}
	outfile.close();											//Close the Output file
	cout << "Closed Output file.\n\n";
}