get_student_details(student);


char**student=new char*[row];
for(int i=0;i<row;i++)
{
	student[i]=new char [20];
}
void get_student_details(char**student)
{
	cout<<"Enter Student name : ";
	cin.getline(student[0],19);
	cout<<"Gender : ";
	cin.ignore();
	cin>>student[1];
	cout<< "Book Name : ";
	cin>>student[2];
	cout<<"Class Section : ";
	cin>>student[3];
	cout<<"Batch No. : ";
	cin>>student[4];
}
