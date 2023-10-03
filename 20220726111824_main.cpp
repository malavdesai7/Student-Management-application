#include <iostream>
#include <vector>
#include <string>
#include<limits>
using namespace std;

struct Person
{
    string firstName,lastName;
};

struct Address
{
    int streetNumber;
    string streetName,city;
    string postalCode;
    string provi_state;
};


struct Student
{
    int studentNumber;
    long long studentPhoneNumber;
    string email;
    Person p1;
    Address a1;
};

vector<Student> student(0);

Student stud;

bool flag=false;

void createStudent();
void findStudent();
void modifyInformation();
void deletStudentInformation();
void displayStudentData();
long long getNumber();

int main()
{
    int opt;
    do
    {
        cout<<"Student Management Application\n";
        cout<<"\t 1.\tCreate and add a student\n";
        cout<<"\t 2.\tSearch for a student sudent number \n";
        cout<<"\t 3.\tModify the information of the student by stvudent number\n";
        cout<<"\t 4.\tDelete the information of the student by info :\n";
        cout<<"\t 5.\tDisplay the list of student in ascending order(use student Number) \n";
        cout<<"\t 6.\tExit the application \n";
        cout<<"Enter Your choice : ";
        cin>>opt;

        switch(opt)
        {
            case 1:
                {
                    createStudent();
                    break;
                }
            case 2:
                {
                    findStudent();
                    break;
                }
            case 3:
                {
                    modifyInformation();
                    break;
                }
            case 4:
                {
                    deletStudentInformation();
                    break;
                }
            case 5:
                {
                    displayStudentData();
                    break;
                }
            case 6:
                {
                    exit(0);
                }
            default:
                cout<<"\nERROR : Invalid choice......\n";
        }
    }while(opt!=6);
    return 0;
}
void createStudent()
{
    int num;
    lable1:
    cout<<"Enter student Number  :";
    num=getNumber();
    stud.studentNumber=num;
    for(int i=0;i<student.size();i++)
    {
        if(student[i].studentNumber==num)
        {
             cout<<"\nERROR : The student  is already  in list  "<<endl;
             goto lable1;
        }
    }
    cout<<"Enter student First Name :";
    cin>>stud.p1.firstName;
    cout<<"Enter student Last name :";
    cin>>stud.p1.lastName;
    cout<<"Enter Student email :";
    cin>>stud.email;
    cout<<"Enter Student Phone Number :";
    stud.studentPhoneNumber=getNumber();
    cout<<"Enter student street number :";
    stud.a1.streetNumber=getNumber();
    cout<<"Enter student street name :";
    cin>>stud.a1.streetName;
    cout<<"Enter the city :";
    cin>>stud.a1.city;
    cout<<"Enter Postal code :";
    cin>>stud.a1.postalCode;
    cout<<"Enter the province :";
    cin>>stud.a1.provi_state;
    cout<<endl;
    flag=true;
    student.push_back(stud);

}
void findStudent()
{
    if(flag==true)
    {
        int num;
        cout<<"Please Enter Student Number : ";
        cin>>num;

        for(int i=student.size()-1;i>=0;i--)
        {
            if(num==student[i].studentNumber)
            {
                cout<<"\nStudent : "<<i+1<<"\n";
                cout<<"Student Number is :"<<student[i].studentNumber<<endl;
                cout<<"Student first name is :"<<student[i].p1.firstName<<endl;
                cout<<"Student last name is :"<<student[i].p1.lastName<<endl;
                cout<<"Student email is :"<<student[i].email<<endl;
                cout<<"Student phone number is :"<<student[i].studentPhoneNumber<<endl;
                cout<<"Student street number is :"<<student[i].a1.streetNumber<<endl;
                cout<<"Student street name is :"<<student[i].a1.streetName<<endl;
                cout<<"Student city is :"<<student[i].a1.city<<endl;
                cout<<"Student province is :"<<student[i].a1.provi_state<<endl;
                cout<<"Student postal code is :"<<student[i].a1.postalCode<<endl;
                cout<<"***********************************************************\n";
            }
        }
    }
    else
        cout<<"\nINVALID : There is no data to on this student ......\n";
}
void modifyInformation()
{
    if(flag==true)
    {
        string fname,lname,email,streetName,city,postalCode,state;
        long long phoneNumber;
        int num,streetNumber;

                cout<<"Please Enter Student Number To modify the data : ";
                cin>>num;
                for(int i=student.size()-1;i>=0;i--)
                {
                    if(num==student[i].studentNumber)
                    {
                        cout<<"Modifying The Student Data for this Student Number : "<<student[i].studentNumber<<endl;

                        cout<<"Enter student First Name :";
                        cin>>fname;
                        student[i].p1.firstName=fname;
                        cout<<"Enter student Last name :";
                        cin>>lname;
                        student[i].p1.lastName=lname;
                        cout<<"Enter Student email :";
                        cin>>email;
                        student[i].email=email;
                        cout<<"Enter Student Phone Number :";
                        cin>>phoneNumber;
                        student[i].studentPhoneNumber=phoneNumber;
                        cout<<"Enter student street number :";
                        cin>>streetNumber;
                        student[i].a1.streetNumber=streetNumber;
                        cout<<"Enter student street name :";
                        cin>>streetName;
                        student[i].a1.streetName=streetName;
                        cout<<"Enter the city :";
                        cin>>city;
                        student[i].a1.city=city;
                        cout<<"Enter Postal code :";
                        cin>>postalCode;
                        student[i].a1.postalCode=postalCode;
                        cout<<"Enter the province :";
                        cin>>state;
                        student[i].a1.provi_state=state;
                        cout<<endl;
                        cout<<"****Data Modified ******\n";
                    }
                    else
                        cout<<"\nERROR : no data on this student  ..." ;
                }
        }
        else
        cout<<"\nINVALID : There is no data to modify.....\n";
}
void deletStudentInformation()
{
    if(flag==true)
    {
        int num;
        cout<<"\nPlease Enter Student Number in order to delete : ";
        cin>>num;
        for(int i=0;i<student.size();i--)
        {
            if(num==student[i].studentNumber)
            {
                student.erase(student.begin(),student.begin()+(i+1));
                cout<<"\nStudent Data Deleted from list.........\n";
            }
            else
                cout<<"\n ERROR : No Data on the STUDENT NUMBER....\n";
        }
    }
    else
        cout<<"\nINVALID : There is no data to delete.....\n";


}
