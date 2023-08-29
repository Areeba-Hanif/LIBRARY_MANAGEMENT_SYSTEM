#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;


 
class Registration{
	
	public:

        void login()
{
	    
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\nPlease enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"\nPASSWORD :";
        cin>>pass;
        
        ifstream input("users.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello  "<<user<<"\nLOGIN SUCCESS\nWe're glad that you're here.\nThanks for logging in\n";
                cin.get();
                cin.get();
               
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                exit(0);
              
        }
}

void registr()
{
        system("cls");
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("users.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
       
        
        
}

void forgot(){
	
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("users.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                               
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("users.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                               
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                              
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                      
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}


void display_menu(){
	

	int choice;
         
        cout << "\n\t\t------- REGISTRATION CHOICES --------\n";
        cout << "\n\t\t-------------------------------------"<<endl; 
        cout << "\n\t\t| 1 . LOGIN                          |" << endl;
	cout << "\n\t\t| 2 . REGISTER                       |" << endl;
	cout << "\n\t\t| 3 . FORGOT PASSWORD (or) USERNAME  |" << endl;
        cout << "\n\t\t| 4 . EXIT                           |" << endl;
        
        cout<<"\n\t\tEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this program\nThis program is created by Ayesha & Areeba ";
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                      
        }
	}
};


