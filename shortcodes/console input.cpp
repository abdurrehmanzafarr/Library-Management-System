#include<iostream>
#include<fstream>
using namespace std;
void length(char arr[], int& L)
{
	L = 0;
	while (arr[L] != '\0')
		L++;
}
void copy_arr(char newarr[], char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
}
void shrink(char*& arr)
{
	int l1 = 0;
	length(arr, l1);
	char* newarr = new char[l1 + 1];
	copy_arr(newarr, arr, l1);
	newarr[l1] = '\0';
	delete[]arr;
	arr=NULL;
	arr = newarr;
}

int main()
{
	ofstream fout;
	fout.open("students.txt",ios::app);
	int count=0;
	ifstream y;
	y.open("countfile.txt");
	y>>count;
	for(int i=0;i<5;i++)
	{
		if(i==0&&count>0)
		fout<<endl;
			if(i<4)
			fout<<students[i]<<",";
			else if(i==4)
			fout<<students[i]<<".";
	}
	count++;
	ofstream x;
	x.open("countfile.txt");
	x<<count;
}
