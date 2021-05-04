    #include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<unistd.h>
#include<iomanip>
#include<unistd.h>
using namespace std;

class employee
{
    private:
        // Variables for employee details
        char name[30];
        char id[5];
        char designation[10];
        int age;
        int ctc;
        int experience;


        void listEmployees(void){ //To list total employees with Name, Id and Designation
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of Employees\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
        }

        void showDetails(void){ //Displays all details according to Employee's id

            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nExperience: "<<experience;
                    cout<<"\n---------------------";
                }
            fclose(file);
        }

        void editExisting(void){ //edits Designation and CTC of an employee
            char checkId[5];
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
        }

        void addNewEmployee(void){ //adding records
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();

        }

        void deleteEmployeeDetails(void){ //removing records
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";

            }
            else
                deleteEmployeeDetails();
        }


    public:
        // Function to serve as end point
        void options(void){ //menu

                // Options to choose an action
                go:
                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   6:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice)
                {
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Sorry! I don't understand that! \n";
                        break;
                }
                goto go;

            }


};
void printProgBar( int percent )
{
    string bar;
    for(int i = 0; i < 50; i++)
    {
        if( i < (percent/2))
        {
            bar.replace(i,1,"=");
        }
        else if( i == (percent/2))
        {
            bar.replace(i,1,">");
        }else
        {
            bar.replace(i,1," ");
        }
  }
  cout<< "\r" "[" << bar << "] ";
  cout.width( 3 );
  cout<< percent << "%     " << std::flush;
}

int main()
{
    int password = 1234;
	cout << setw(50)<<"Enter password:";
	cin >> password;
    	if (password == 1234)
        {
            cout <<setw(52) <<"Access Granted...\n";
            cout<<"\n---------------LOADING-----------------------";
            int N = 100;

            for(int i = 0; i < N; i++)
            {
                float p = (i / (float) N) * (float) 100;
                printProgBar(p);
                usleep(19990);
            }
            printProgBar(100);
            cout << endl;

            goto step1;
        }

    	if (password != 1234)
        {
            cout << "Access Denied.....Invalid Username/Password:";
            exit(0);
        }
    step1:
    char ans;
    cout<<"\t\t"<<"\n|************************************************|";
    cout<<"\t\t"<<"\n|                                                |";
    cout<<"\t\t"<<"\n|              HELLO                             |";
    cout<<"\t\t"<<"\n|                                                |";
    cout<<"\t\t"<<"\n|   WELCOME TO OUR PROJECT FOR ........          |";
    cout<<"\t\t"<<"\n|                                                |";
    cout<<"\t\t"<<"\n|      EMPLOYEE  MANAGEMENT                      |";
    cout<<"\t\t"<<"\n|                                                |";
    cout<<"\t\t"<<"\n|************************************************|\n";



    employee e;
    e.options();
    return 0;
}

