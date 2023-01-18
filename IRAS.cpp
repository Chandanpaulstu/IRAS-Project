#include <iostream>
using namespace std;
struct  Teacher 
{
      int  teacherId;
      string name, gender, email;
 
      int getTeacherID()
      {
          return teacherId;
      }
 
      string getEmail()
      {
          return email;
      }
 
      void setTeacher()
      {
          cout<<"Enter teacher Id :";
          cin>>teacherId;
          cout<<"Enter name : ";
          cin>>name;
          cout<<"Enter Gender : ";
          cin>>gender;
          cout<<"Enter Email : ";
          cin>>email;
 
      }
      void showTeacher()
      {
 
          cout<<"Teacher Name : "<<name<<" Gender : "<<gender<<" Email : "<<email<<endl;
      }
};
/*
user defined data type Teacher .which takes info of a teacher and show it and other function when they called they will return the data
*/
 
struct University
{
    string uniName, address, phoneNo;
 
    int noOfFaculty;
 
    Teacher *t; //university has teachers
 
    void setUniInfo()
    {
        cout<<"Enter university Name : ";
        cin>>uniName;
        cout<<"Enter university address : ";
        cin>>address;
        cout<<"Enter university phoneNo : ";
        cin>>phoneNo;
 
        cout<<"Enter no of teacher :  ";
        cin>>noOfFaculty;
 
        t = new Teacher[noOfFaculty];
        
        for(int i=0;i<noOfFaculty;i++)
        {
            t[i].setTeacher();
        }
    }
 
     void showUniInfo()
    {
        cout<<"University Name : "<<uniName<<" Address : "<<address<<"Phone No : "<<phoneNo<<endl;
 
        for(int i=0;i<noOfFaculty;i++)
        {
            t[i].showTeacher();
        }
 
    }
 
     void findAParticularTeacherEmail(int facultyId)
    {
        for(int i=0;i<noOfFaculty;i++)
        {
            if(t[i].getTeacherID()==facultyId)
            {
                cout<<"\nTeacher Email is : "<<t[i].getEmail()<<endl;
                return;
            }
        }
    }
};
/*
university will take the info & university has a relation with teacher .it will create a dynamic array in university(heap) which will contain the info of teachers
and to find a faculty's email id if the faculty id matched then it will show to eMail id
*/
struct Course
{
    string courseId, courseName;
    int noOfCredits;
 
    int noOfPrequisite;
 
    string  *prequisites; //applicable for offered  course
    int capacity; //applicable for offered course
 
 
   void setofferedCourseInfo()
   {
       cout<<"Enter Course ID : ";
       cin>>courseId;
       cout<<"Enter Course Name ; ";
       cin>>courseName;
       cout<<"Enter No of credits : ";
       cin>>noOfCredits;
       cout<<"Enter Course capacity : ";
       cin>>capacity;
       cout<<"Enter no of prequisite ";
       cin>>noOfPrequisite;
       prequisites  = new string[noOfPrequisite];
 
       cout<<"Now input this course prequisite ID";
 
       for(int i=0;i<noOfPrequisite;i++)
       {
           cin>>prequisites[i];
       }
   }
   
    int getNoOfCredits()
    {
        return noOfCredits;
    }
 
    void setCourseInfo(string cId)
    {
 
        courseId = cId;
        cout<<"Enter course  Name : ";
        cin>>courseName;
        cout<<"Enter no of credits ";
        cin>>noOfCredits;
    }
 
    void showCourseInfo()
    {
        cout<<"Course ID : "<<courseId<<" Name : "<<courseName<<" No of credits : "<<noOfCredits<<endl;
    }
    
   Course *next;
};
/*
linked list starts from here.it will take course info & shows it and linked course named another node
*/
 
struct Student
{
    int id;
    string name,gender,email;
    float cgpa;
    int scholarshipPercent;
 
    int noOfCourse;
    Course *course; //student registered course list
 
    string  **grades;
    int  **credits;
    
    void calcCgpa()//Cgpa calculator which takes the semister info,course grade & credit and auto calculated it
    {
        int n;
        cout<<"How many semesters you have completed?"<<endl;
        cin>>n;
        grades  = new string*[n];
        credits = new int*[n];
 
        int creditSum=0;
        int gradeSum =0;
 
 
        for(int i=0;i<n;i++)
        {
            cout<<"How many course completed in "<<i+1<<" th semester"<<endl;
            int m;
            cin>>m;
 
            grades[i] = new string[m];
            credits[i] = new int[m];
 
            for(int j=0;j<m;j++)
            {
                cout<<"Enter Grades for "<<i+1<<" st course"<<endl;
                cin>>grades[i][j];
                cout<<"Enter Credits for "<<j+1<<" st course"<<endl;
                cin>>credits[i][j];
 
                if(grades[i][j]=="A")
                {
                    if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (4*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (4*3);
                    }
                }
                else   if(grades[i][j]=="A-")
                {
                        if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (3.7*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (3.7 * 3);
                    }
 
                }
                else  if(grades[i][j]=="B+")
                {
                     if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (3.3*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (3.3 * 3);
                    }
                }
                else   if(grades[i][j]=="B")
                {
                     if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (3.0*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (3.0 * 3);
                    }
                }
                else   if(grades[i][j]=="B-")
                {
                     if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (2.7*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (2.7 * 3);
                    }
                }
                else   if(grades[i][j]=="C+")
                {
                    if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (2.3*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (2.3 * 3);
                    }
 
                }
                else   if(grades[i][j]=="C")
                {
                      if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (2.0*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (2.0 * 3);
                    }
 
                }
                else   if(grades[i][j]=="C-")
                {
                    if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (1.7*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (1.7 * 3);
                    }
                }
                else   if(grades[i][j]=="D")
                {
                           if(credits[i][j]==4)
                    {
                        gradeSum = gradeSum + (1.0*4);
                    }
                    else if(credits[i][j]==3)
                    {
                         gradeSum = gradeSum + (1.0 * 3);
                    }
 
                }
                else   if(grades[i][j]=="F")
                {
                    gradeSum = gradeSum + (0*4);
                }
                creditSum = creditSum + credits[i][j];
            }
        }
        
        cgpa = (float)gradeSum/creditSum;
 
    }
 
     void setStudInfo(int ID)
    {
 
        id = ID;
        cout<<"Enter student name  : ";
        cin>>name;
        cout<<"Enter Gender  : ";
        cin>>gender;
        cout<<"Enter email : ";
        cin>>email;
        cout<<"Enter Scholarship Percent : ";;
        cin>>scholarshipPercent;
 
        calcCgpa();
    }
 
    int  getTotalCredits()//says how many credits s/he takes
    {
       int sum = 0;
       Course *tNode = course;
       while(tNode!=NULL)
       {
           sum+= tNode->getNoOfCredits();
           tNode = tNode->next;
       }
       return sum;
    }
    //constructor which sets the default value
    Student()
    {
        id = 0;
        name=gender=email = "TBA";
        cgpa = 0.0f;
        noOfCourse=0;
      course = NULL;
    }
 
    void appendCourse(string cId)//append the course in student list(basis on id)
    {
        Course *newNode = new Course; 
        newNode->setCourseInfo(cId);  
        newNode->next  = NULL;
 
        if(course==NULL)
        {
            course = newNode; 
        }
        else
        {
            
            Course *tNode = course;
            while(tNode->next!=NULL)
            {
                tNode = tNode->next;
            }
            tNode->next = newNode;
 
        }
 
    }
 
    bool prequisiteCheck(string cId, Course *offeredCourse, Course *registeredCourse)//check the prequisite T/F
    {
 
        Course *tNode = offeredCourse;
        while(tNode!=NULL &&  cId!=tNode->courseId)
        {
 
            tNode = tNode->next;
        }
 
        for(int i=0;i<tNode->noOfPrequisite;i++)
        {
             Course *tRegCourse = registeredCourse;
             bool b = false;
             while(tRegCourse!=NULL)
             {
                   if(tRegCourse->courseId==tNode->prequisites[i])
                   {
                       b = true;
                       break;
                   }
                tRegCourse = tRegCourse->next;
 
             }
             if(b==false ) return false;
 
        }
        return true;
    }
 
    bool capacityCheck(string courseId, Course *offeredCourse)//check the capacity of a offered course  
    {
        while(offeredCourse!=NULL)
        {
            if(offeredCourse->courseId == courseId)
            {
                if(offeredCourse->capacity>0) return true;
                else return false;
 
            }
 
            offeredCourse = offeredCourse->next;
        }
    }
 
 
    void decrementOfferedCourse(string cId, Course *&offeredCourse)//minus the seats which has been taken
    {
        Course *tNode = offeredCourse;
        while(tNode!=NULL && tNode->courseId!=cId)
        {
            tNode = tNode->next;
        }
        tNode->capacity = tNode->capacity -1;
 
    }
 
    void courseRegistration(Course *&offeredCourse)
    {
        int n;
        cout<<"How many courses : ";
        cin>>n;
 
        if(n>6)
        {
            cout<<"You can't take more than 5 courses!"<<endl;
            return;
        }
 
        noOfCourse = n;
 
        for(int i=0;i<n;i++)
        {
            cout<<"Enter course ID : ";
            string cId;
            cin>>cId;
 
           if(prequisiteCheck(cId, offeredCourse, course)) //going to register course id, offeredCourseList, registeredCourseList
           {
                 if(capacityCheck(cId,offeredCourse)) // it takes,  going to register course id, offered CourseList
                 {
                         appendCourse(cId);
 
                         //now, decrement (capacity-1) from offeredCourseList
 
                         decrementOfferedCourse(cId, offeredCourse);
                 }
                 else
                 {
                     cout<<"Sorry! Capacity is Full! Try to register another course! If you can't take any courses then contract Mahady Sir ASAP! "<<endl;
                 }
           }
           else
           {
              cout<<"Sorry! Prequisite not done yet!"<<endl;
 
           }
        }
    }
 
    int getStudentID()
    {
        return id;
    }
 
    float getCgpa()
    {
        return cgpa;
    }
 
    void showStudInfo()
    {
        cout<<"Student name : "<<name<<" Gender : "<<gender<<" Cgpa : "<<cgpa<<endl;
    }
    Student *next;
 
};/*
student has relation with course(structure with in structure) and the other student course related function.structure student ends here and
 connect the linked with another student
*/
 
float getAmountToBePaid(Student *tNode, int id)
{
   while(tNode!=NULL && tNode->id!=id)
   {
       tNode=tNode->next;
   }
 
    int totalCredits =   tNode->getTotalCredits();
 
    if(tNode->scholarshipPercent==0)
    {
        return totalCredits *6000;
    }
    else
    {
        int percent  = tNode->scholarshipPercent;
 
        int tk  = totalCredits *6000;
 
        float amount =  ((100-percent)/100 ) * tk;
 
        return amount;
    }
}/*
global function which calculates the registration course's bill of student
*/
void getStudentCgpa(Student *tNode,int id)
{
    while(tNode!=NULL)
    {
        if(tNode->getStudentID()==id)
        {
            cout<<"Student cgpa is  : "<<tNode->getCgpa()<<endl;
            return;
        }
        tNode = tNode->next;
    }
    cout<<"Student ID : "<<id<<" is not present in our database :( !"<<endl;
 
}/*
id student id is matched then it shows the particular student cgpa
*/
 
bool isUniqueID(Student *tNode, int id)
{
    while(tNode!=NULL)
    {
        if(tNode->id== id)
        {
            return false;
        }
 
        tNode = tNode->next;
    }
    return true;
}
/*
check the student id is unique or not
*/
 
void appendNode(Student  *&head,int id)
{
    if(!isUniqueID(head,id))
    {
        cout<<"Id is not unique!"<<endl;
        return;
    }
 
    Student *newNode = new Student();
    newNode->setStudInfo(id);
    newNode->next = NULL;
 
    if(head==NULL)
    {
        head = newNode;
    }
    else
    {
        Student *tNode = head;
        while(tNode->next!=NULL)
        {
 
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
 
}
/*
if the student id is unique then it will create a student named linked list 
*/
 
void displayStudent(Student *tNode)
{
    while(tNode!=NULL)
    {
        tNode->showStudInfo();
        tNode = tNode->next;
    }
}
void findAParticularStudent(Student *tNode,int  id)//this will check if the student data is present or not
{
    while(tNode!=NULL)
    {
        if(tNode->id== id)
        {
            cout<<"Student  "<<id<<" Id is present"<<endl;
            return;
        }
 
        tNode = tNode->next;
    }
 
    cout<<"Student "<<id<<" is not present in our database..."<<endl;
 
}
 
float getAverageCgpa(Student *tNode)
{
    float sum =0;
    int count=0;
 
    while(tNode!=NULL)
    {
        sum+= tNode->getCgpa();
        count++;
        tNode = tNode->next;
    }
    return sum/count;
}
/*
to calculate the average student cgpa
*/
 
void offerACourse(Course *&offerACourse) //pass by reference
{
    Course *newNode = new Course;
    newNode->setofferedCourseInfo();
    newNode->next = NULL;
 
    if(offerACourse==NULL)
    {
        offerACourse  = newNode;
    }
    else
    {
        Course *tNode  = offerACourse;
        while(tNode->next!=NULL)
        {
            tNode = tNode->next;
        }
        tNode->next  = newNode;
    }
}
/*
offered course list which is offered by the university
*/
 
void courseRegistration(Student *tNode, Course *&offeredCourse, int studId)
{
    while(tNode!=NULL && tNode->id!=studId)
    {
        tNode = tNode->next;
    }
 
    tNode->courseRegistration(offeredCourse);
}
/*
student course registration part
*/
 
int main()
{
   int choice;
 
   University iub;
 
   Student *head=NULL;
 
   Course *offeredCourse = NULL;
 
   do
   {
        cout<<"\nPress 1 to set University Info : "<<endl;
        cout<<"Press 2  to add a Student : (CGPA should be auto calculated and Student ID should be unique)"<<endl;
        cout<<"Press 3 to view all Student'"<<endl;
        cout<<"Press 4 to find a Particular Student : "<<endl;
        cout<<"Press 5 to find a Particular Facult's email "<<endl;
        cout<<"Press 6 to find particular student's cgpa "<<endl;
        cout<<"Press 7 to offer a course..."<<endl;
        cout<<"Press 8 to print Bill....(Student will get discount if he/she has discount)"<<endl;
        cout<<"Press 9 to get Average CGPA of All Student "<<endl;
        cout<<"Press 10 for course registration... (you can't take more than 5 courses  & check if prequisite is done or not! & also check if capacity if full or not!)"<<endl;
        cout<<"Press 11 to exit ..."<<endl;
 
        cin>>choice;
 
          if(choice==1)
          {
                iub.setUniInfo();
          }
          else if(choice==2)
          {
            int id;
            cout<<"Enter Student ID :";
            cin>>id;
 
            appendNode(head,id);
          }
           else if(choice==3)
          {
            displayStudent(head);
 
          }
          else if(choice==4)
          {
             int id;
             cout<<"Enter student id : ";
             cin>>id;
 
             findAParticularStudent(head,id);
 
          }
          else if(choice==5)
          {
              int id;
              cout<<"Enter faculty ID : ";
              cin>>id;
              
             iub.findAParticularTeacherEmail(id);
 
          }
          else if(choice==6)
          {
              int id;
              cout<<"Enter Student ID : ";
              cin>>id;
 
              getStudentCgpa(head,id);
 
          }
          else if(choice==7)
          {
            offerACourse(offeredCourse);
 
 
          }
          else if(choice==8)
          {
              int id;
              cout<<"Enter Student Id first,.."<<endl;
              cin>>id;
 
             cout<<"Amount to be paid is : "<< getAmountToBePaid(head,id)<<endl;
 
          }
          else if(choice==9)
          {
              float avg = getAverageCgpa(head);
              cout<<"Average CGPA of All Student is : "<<avg<<endl;
         }
        else if(choice==10)
        {
            int id;
             cout<<"Enter Student id for course registration : ";
             cin>>id;
 
             courseRegistration(head,offeredCourse,id);
        }
   }
   while(choice!=11);
 
    return 0;
}
