#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int **books_data=new int*[3];
	for(int i=0;i<3;i++)
	books_data[i]=new int[4];
	ifstream fin;
	fin.open("books_data.txt");
	for(int i=0;i<3;i++)
	{
		for(int c=0;c<4;c++)
		fin>>books_data[i][c];
	}
		for(int i=0;i<3;i++)
	{
		for(int c=0;c<4;c++)
		cout<<books_data[i][c]<<" ";
		cout<<endl;
	}
}
