#include<iostream>
#include<fstream>
using namespace std;
void length(char arr[], int& L)
{
	L = 0;
	while (arr[L] != '\0')
		L++;
}
bool check(char arr[], char arr1[])
{
	int l1 = 0;
	int l2 = 0;
	length(arr, l1);
	length(arr1, l2);
	if (l1 == l2)
	{
		for (int i = 0; arr[i] != '\0'; i++)
		{
			if (arr[i] != arr1[i])
				return false;
			if (arr[i + 1] == '\0')
				return true;
		}
	}
	return false;
}
void console_input(char& input)
{
	cout << "						WELCOME TO BRAINS LIBRARY" << endl;
	cout << "1. Do you want issue a book? Press I to go to issue menu." << endl;
	cout << "2. Do you want to return a book? Press R to go to return menu." << endl;
	cout << "3. Do you want to see all the books in library? Press S to see." << endl;
	cout << "4. Do you want to Check All details of Students? Press C to check." << endl;
	cout << "5. Enter E to exit the LMS." << endl;
	cout << "*** Enter here: ";
	cin >> input;
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
	arr = newarr;
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
void update_file(int** arr, int row, int col)
{
	ofstream fout;
	fout.open("books_data.txt");
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
			fout << arr[r][c] << " ";
		fout << endl;
	}
	fout.close();
}
void calculate_lines(int& lines,int size)
{
	ifstream fin;
	fin.open("books_data.txt");
	if (!fin.is_open())
	{
		cout << "file not found";
	}
	else
	{
		int* waste = new int[size];
		int i = 0;
		while (fin >> *(waste+i))
		{
			i++;
			if (i == 4)
			{
				i = 0;
				lines++;
			}
		}
	}
	fin.close();
}
void read_data(int** arr, int row, int col)
{
	ifstream fin;
	fin.open("books_data.txt");
	if (!fin.is_open())
	{
		cout << "file not found" << endl;
	}
	else
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
			{
				fin >> arr[r][c];
			}
		}
	fin.close();
}
void console_output(char** arr, int row, int arr1[], int size)
{
	for (int r = 0; r < row; r++)
	{
		if (r == 0)
			cout << "IBAN No : ";
		else if (r == 1)
			cout << "Book Name : ";
		else if (r == 2)
			cout << "Author : ";
		else if (r == 3)
			cout << "Edition : ";
		else if (r == 4)
			cout << "Publisher : ";
		cout << arr[r] << endl;
	}
	for (int r = 0; r < size; r++)
	{
		if (r == 0)
			cout << "Year : ";
		else if (r == 2)
			cout << "Price : ";
		else if (r == 3)
			cout << "Quantity : ";
		if (r != 1)
			cout << arr1[r] << endl;
	}
}
void get_student_details(char** student,int*std_data,int size)
{
	cin.ignore();
	cout << "Enter Student name : ";
	cin.getline(student[0], 19);
	cout << "Gender : ";
	cin >> student[1];
	cin.ignore();
	cout << "Book Name : ";
	cin.getline(student[2],19);
	cout << "Class Section : ";
	cin >> student[3];
	cout << "Batch No. : ";
	cin >> student[4];
	cout << "AGE : ";
	cin >> std_data[0];
	cout << " Roll Number : ";
	cin >> std_data[1];
}
void process_students(char** student, int* std_data)
{
	ofstream fout;
	fout.open("Student.txt", ios::app);
	get_student_details(student, std_data, 2);
	int count = 0;
	ifstream y;
	y.open("countfile.txt");
	y >> count;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 && count > 0)
			fout << endl;
		if (i < 4)
			fout << student[i] << ",";
		else if (i == 4)
			fout << student[i] << ".";
	}
	count++;
	ofstream x;
	x.open("countfile.txt");
	x << count;
	fout.close();
	x.close();
	y.close();
	fout.open("student_data.txt",ios::app);
	for (int i = 0; i < 2; i++)
		fout << std_data[i] << " ";
	fout << endl;
	fout.close();
}
int main()
{
	int lines = 0, size = 4, row = 5;
	calculate_lines(lines, size);
	char** book = new char* [row];
	int** books_data = new int* [lines];
	char** student = new char* [row];
	for (int i = 0; i < row; i++)
	{
		student[i] = new char[20];
	}
	int* std_data = new int[2];
	char* find_iban = new char[10];
	for (int i = 0; i < lines; i++)
		books_data[i] = new int[size];
	read_data(books_data, lines, size);
	char input = 'z';
	ifstream fin;
	while (input != 'E')
	{
		console_input(input);
		if (input == 'I' || input == 'i')
		{
			int line_no = 0;
			int temp = 0;
			fin.open("books.txt");
			if (!fin.is_open())
				cout << "file not found";
			else
			{
				cout << "Enter the iban of the book you want to issue : ";
				cin >> find_iban;
				shrink(find_iban);
				while (!fin.eof())
				{
					readfile(fin, book, row);
					if (check(find_iban, book[0]))
					{
						console_output(book, row, books_data[line_no], size);
						if (books_data[line_no][size - 1] > 1)
						{
							process_students(student, std_data);
							cout << "Book has been Successfully issued to you till Feb-20-2021" << endl;
						}
						else
							cout << "All books of this IBAN number have been already issued to students.Wait for some days and try again :(" << endl;
						if (books_data[line_no][3] > 1)
						{
							books_data[line_no][3]--;
							update_file(books_data, lines, size);
							read_data(books_data, lines, size);
						}
						break;
					}
					line_no++;
				}
				if (fin.eof() && !check(find_iban, book[0]))
					cout << "No book found with this IBAN number. " << endl;
			}
			fin.close();
		}
		else if (input == 'R' || input == 'r')
		{
			int line_no = 0;
			int temp = 0;
			fin.open("books.txt");
			if (!fin.is_open())
				cout << "file not found";
			else
			{
				cout << "Enter the iban of the book you want to Return : ";
				cin >> find_iban;
				shrink(find_iban);
				while (!fin.eof())
				{
					readfile(fin, book, row);
					if (check(find_iban, book[0]))
					{
						console_output(book, row, books_data[line_no], size);
						cout << "Book has been successully returned. Record Updated." << endl;
						books_data[line_no][3]++;
						update_file(books_data, lines, size);
						read_data(books_data, lines, size);
						break;
					}
					line_no++;
				}
				if (fin.eof() && !check(find_iban, book[0]))
					cout << "No book found with this IBAN number. " << endl;
			}
			fin.close();
		}
		else if (input == 'S')
		{
			cout << "All books sorted on prices are :" << endl;
			for (int i = 0; i < lines; i++)
			{
				int line_no = 0, line = 0;
				int max = books_data[lines - lines][size - 2];
				for (int r = 0, c = size - 2; r < lines; r++)
				{
					if (max < books_data[r][c])
					{
						max = books_data[r][c];
						line_no = r;
					}
				}
				fin.open("books.txt");
				if (!fin.is_open())
					cout << "file not found";
				else
				{
					while (!fin.eof())
					{
						readfile(fin, book, row);
						if (line == line_no)
						{
							console_output(book, row, books_data[line_no], size);
							books_data[line_no][size - 2] = -1;
							break;
						}
						line++;
					}
					fin.close();
				}
				cout << endl;
			}
		}
		else if (input == 'C')
		{
			lines = 0;
			fin.open("student_data.txt");
			if (!fin.is_open())
			{
				cout << "file not found";
			}
			else
			{
				int* waste = new int[2];
				int i = 0;
				while (fin >> *(waste + i))
				{
					i++;
					if (i == 2)
					{
						i = 0;
						lines++;
					}
				}
			}
			fin.close();
			int** students_data = new int* [lines];
			for (int i = 0; i < lines; i++)
			{
				students_data[i] = new int[2];
			}
			fin.open("student_data.txt");
			if (!fin.is_open())
			{
				cout << "file not found" << endl;
			}
			else
				for (int r = 0; r < lines; r++)
				{
					for (int c = 0; c < 2; c++)
					{
						fin >> students_data[r][c];
					}
				}
			fin.close();
			cout << "All Students sorted on age are :" << endl;
			for (int i = 0; i < lines; i++)
			{
				int line_no = 0, line = 0;
				int max = students_data[lines - lines][0];
				for (int r = 0, c = 0; r < lines; r++)
				{
					if (max < students_data[r][c])
					{
						max = students_data[r][c];
						line_no = r;
					}
				}
				fin.open("Student.txt");
				if (!fin.is_open())
					cout << "file not found";
				else
				{
					while (!fin.eof())
					{
						readfile(fin, student, row);
						if (line == line_no)
						{
							cout << "Name :";
							cout << student[0] << endl;
							cout << " Age : " << students_data[line_no][0] << endl;
							students_data[line_no][0] = -1;
							break;
						}
						line++;
					}
					fin.close();
				}
				cout << endl;
			}
		}
	}
}