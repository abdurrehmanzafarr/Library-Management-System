#include<iostream>
#include<fstream>
using namespace std;
void readfile(int&lines)
{
	ifstream fin;
	fin.open("books_data.txt");
	int waste[4]={};
	int i=0;
	while(fin>>waste[i])
	{
		i++;
		if(i==4)
		{
			i=0;
			lines++;
		}
	}
}
int main()
{
	int lines=0;
	readfile(lines);
	cout<<lines;
}
