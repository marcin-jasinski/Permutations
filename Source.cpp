#include <iostream>
#include <vector>
#include <algorithm> // std::swap()
#include <ctime>
#include <fstream>	 // files 

void swap_elements(int&, int&);
void display_vector(std::vector<int>&, std::fstream & file);
void permutate(std::vector<int>&, unsigned int, std::fstream & file);

int main()
{
	unsigned int N;

	std::cout << "Generate all permutations from 1 to: ";
	std::cin >> N;

	std::vector<int> Numbers_array;								//
																// creating and filling number vector 
	for (int i = 1; i <= N; i++) Numbers_array.push_back(i);	//

	std::fstream file;
	file.open("results.txt", std::ios::out);					// creating output file
	if (file.good() == true)
	{
		std::cout << "\nFile acces granted." << std::endl;
		std::cout << "\nGenerating numbers in progress..." << std::endl;

		std::time_t start, end;
		std::time(&start);

		permutate(Numbers_array, 0, file);						// function call

		std::time(&end);
		double dif = std::difftime(end, start);

		std::cout << "\nElapsed time: " << dif << " seconds." << std::endl;
		std::cout << "Generaterd numbers written to the output file. " << std::endl;

		file.close();
	}
	else std::cout << "File acces denied!" << std::endl;

	std::cout << "\nPress ENTER to terminate program...";
	std::cin.ignore(2);
	return 0;
}

void swap_elements(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}

void display_vector(std::vector<int>& numbers, std::fstream& output_file)
{
	for (int i = 0; i < numbers.size(); i++) output_file << numbers[i];
	output_file << std::endl;
}

void permutate(std::vector<int>& numbers, unsigned int index, std::fstream & file)
{
	if (index == numbers.size()) // display vector if you have reached last element 
	{
		display_vector(numbers, file);
		return;
	}

	for (int i = index; i<numbers.size(); i++)
	{
		std::swap(numbers[i], numbers[index]);		//
		permutate(numbers, index + 1, file);		//	swap elements -> go deeper into the array until you swap last 2 elemets -> rollback 
		std::swap(numbers[i], numbers[index]);		//
	}
}