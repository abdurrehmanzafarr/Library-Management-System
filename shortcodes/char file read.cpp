#include<iostream>
#include<fstream>
using namespace std;
void copy_arr(char newarr[], char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
}
char* regrow(char* arr, char temp, int& size)
{
	char* newarr = new char[size + 1];
	copy_arr(newarr, arr, size);
	if (size > 0)
		delete[]arr;
	newarr[size] = temp;
	size++;
	return newarr;
}
void readfile(ifstream& fin, char**& book, int row)
{
	char temp = 'a';
	int size = 0;
	for (int r = 0; r < row && temp != '.'; r++)
	{
		fin.get(temp);
		while (temp != ',' && temp != '.')
		{
			book[r] = regrow(book[r], temp, size);
			fin.get(temp);
		}
		if (temp == '.')
			fin.ignore();
		temp = '\0';
		book[r] = regrow(book[r], temp, size);
		size = 0;
	}
}
int main()
{
	int row = 5;
	char** book = new char* [row];
	ifstream fin;
	fin.open("students.txt");
	while(!fin.eof())
	{
		
		readfile(fin,book,row);
		for(int i=0;i<row;i++)
		cout<<book[i]<<endl;
	}
}
