//      CODSOFT INTERNSHIP
//      TASK 05 : LIBRARY MANAGEMENT SYSTEM  using DSA ( Linked Lists )
//      Submitted By : Areeba Hanif


#include <iostream>
#include <string>
#include <fstream>
#include "signup.h"
using namespace std;
 


class Book {

public:
  Book *next;
  string title;
  string author;
  string ISBN;
  bool isAvailable;
  
};

class Library {

private:
  Book *head;

public:
  Library() { 

    head = NULL; 
    }


  bool Repeat(string name, string auth, string isbn) {
  	
    Book *current = head;
    
	while (current != NULL) {
      if (current->title == name || current->author == auth && current->ISBN == isbn) {
        return true;
      }
      current = current->next;
    }
    return false;
  }



  // function to add books
  void addBook(string name, string auth, string isbn) {

    Book *newBook = new Book;

    newBook->title = name;
    newBook->author = auth;
    newBook->ISBN = isbn;
    newBook->isAvailable = true;

    newBook->next = NULL;
    if (head == NULL) {

      head = newBook;
    } else {

      Book *current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = newBook;
    }
    
  }



  // function to search book by Title
  void searchByTitle(const char filename[100], string searchName) {

    ifstream file(filename);
    if (!file) {
      cout << "Database not Found." << endl;
      return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {

      size_t pos = line.find(',');
      size_t pos2 = line.find(':');

      if (pos != string::npos) {
        string name = line.substr(0, pos);
        string auth = line.substr(pos + 1, pos2 - pos - 1);
        string isbn = line.substr(pos2 + 1);

        if (name == searchName) {
          cout << "Book found  -> Title : " << name << ",  Author : " << auth<< "  ,  ISBN : " << isbn << endl;
          found = true;
          break;
        }
      }
    }

    if (!found) {
      cout << "Book not found." << endl;
    }

    file.close();
  }



  // function to search book by Author name
  void searchByAuthor(const char filename[100], string searchauth) {

    ifstream file(filename);
    if (!file) {
      cout << "Database not found." << endl;
      return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {

      size_t pos = line.find(',');
      size_t pos2 = line.find(':');

      if (pos != string::npos) {

        string name = line.substr(0, pos);
        string auth = line.substr(pos + 1, pos2 - pos - 1);
        string isbn = line.substr(pos2 + 1);

        if (auth == searchauth) {
          cout << "Book found  -> Title : " << name << ",  Author :  " << auth<< "  ISBN : " << isbn << endl;
          found = true;
          break;
        }
      }
    }

    if (!found) {
      cout << "Book not found in database." << endl;
    }

    file.close();
  }



  // function to search book by ISBN
  void searchByISBN(const char filename[100], string searchisbn) {

    ifstream file(filename);
    if (!file) {
      cout << "Database not found." << endl;
      return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {

      size_t pos = line.find(',');
      size_t pos2 = line.find(':');

      if (pos != string::npos) {
        string name = line.substr(0, pos);
        string auth = line.substr(pos + 1, pos2 - pos - 1);
        string isbn = line.substr(pos2 + 1);

        if (isbn == searchisbn) {

          cout << "Book found  -> Title : " << name << " ,  Author  :   " << auth << " , " << "    ISBN   :    " << isbn << endl;
          found = true;
          break;
        }
      }
    }

    if (!found) {
      cout << "Book not found in database." << endl;
    }

    file.close();
  }




  // function to Display Books from database
  void displayBooks() {

    Book *current = head;
    if (head == NULL) {
      cout << "Database  is empty." << endl;

    } else {
      cout << "\t\t-------------------------------------" << endl;
      cout << "\t\tTitle\t    Author\t    ISBN\n" << endl;
      cout << "\t\t-------------------------------------" << endl;
      while (current != NULL) {

      cout << "\t\t" << current->title << "\t" << current->author << "\t" << current->ISBN << endl;
      cout << "\t\t-------------------------------------" << endl;

        current = current->next;
      }
    }
  }



  // function to checkout Books
  void bookCheckout(string name, string auth, string isbn) {
  	
    Book *current = head;
    
	while (current != NULL) {

      if (current->title == name && current->author == auth && current->ISBN == isbn) {

        if (current->isAvailable) {

          current->isAvailable = false;
          cout << "Book " << current->title << " is checked out." << endl;
          return;
          
        } else {
        	
          cout << "Book is already checked out." << endl;
          return;
        }
      }
      current = current->next;
    }
    cout << "Book not found." << endl;
  }



  // function to Return a book
  void bookReturn(string name, string auth, string isbn, int days) {

    Book *current = head;
    while (current != NULL) {

      if (current->title == name && current->author == auth && current->ISBN == isbn) {
      	
          cout << "Book " << current->title << " is already returned." << endl;
         
          return;
        
        }
      
      current = current->next;
    }
    
            cout<<"Book " << name << " is returned successfully "<<endl;
        	addBook(name,auth,isbn);
        	storeBooksToFile("database.txt");
        	calculateFine(name, auth, isbn, days);
        	return;
  }




  // function to Calculate fine if Number of days Overdue  (greater than 15)

  void calculateFine(string name, string auth, string isbn, int daysOverdue) {
  	if( daysOverdue> 15){
  		const float fineRate = 0.25; // Fine rate per day
   
        float fineAmount = fineRate * daysOverdue;
        cout << "Fine for " << name << " is Rs  " << fineAmount << "." << endl;
	  }
	  else{
	  	cout << "No  Fine "  <<endl;
	  }
        
       
    
  }




  // function to store all the Books Information in the File "database.txt"

  void storeBooksToFile(const char filename[100]) {

    ofstream file(filename);

    if (!file) {
      cout << "Database not found." << endl;
      return;
    }

    Book *current = head;
    while (current != NULL) {
      file << current->title << "," << current->author << ":" << current->ISBN << endl;
      current = current->next;
    }

    file.close();
    cout << "Book stored in the database." << endl;
  }




  // Function to display all Books from  file "database.txt"

  void loadFromFile(const char filename[100]) {

    ifstream infile(filename);
    if (!infile.is_open()) {

      cout << "Failed to open file." << endl;
      return;
    }

    string line;
    while (getline(infile, line)) {

      size_t pos = line.find(",");
      size_t pos2 = line.find(":");
      
      if (pos == string::npos) {
        continue;
      }
      
      string title = line.substr(0, pos);
      string author = line.substr(pos + 1, pos2 - pos - 1);
      string isbn = line.substr(pos2 + 1);
      
      addBook(title, author, isbn);
    
    }
    
    infile.close();
  
  }




  void sortBooks() // Function to Sort  all the Books in Alphabetical order  but only on console
  {
    bool swapped = true;
    while (swapped) {
      swapped = false;
      Book *curr = this->head;
      Book *prev = NULL;

      while (curr != NULL && curr->next != NULL) {
        Book *next = curr->next;

        if (curr->title > next->title) {
          swapped = true;

          curr->next = next->next;
          next->next = curr;

          if (prev == NULL) {
            this->head = next;
          } else {
            prev->next = next;
          }
          prev = next;
        } else {
          prev = curr;
          curr = next;
        }
      }
    }
  }



  // Banner Function to reuse again
  void Banner() {

    cout << "\n\n========================================================================================================================";
    cout << "\n\n================================================ LIBRARY MANAGEMENT SYSTEM =============================================";
    cout << "\n\n========================================================================================================================\n";
    cout << "\n";
  }


  // function for Admin Menu

  void AdminMenu() {

    Banner();
    cout << "\n\t\t 0 . EXIT" << endl;
    cout << "\n\t\t 1 . Add Book " << endl;
    cout << "\n\t\t 2 . Search Book by title " << endl;
    cout << "\n\t\t 3 . Search Book by auhtor" << endl;
    cout << "\n\t\t 4 . Search Book by ISBN" << endl;
    cout << "\n\t\t 5 . Checkout Book" << endl;
    cout << "\n\t\t 6 . Display Books" << endl;
  }
  
  

  // function for Borrower Menu

  void borrowerMenu() {

    Banner();
    cout << "\n\t\t 0 . EXIT " << endl;
    cout << "\n\t\t 1 . Search Book by title " << endl;
    cout << "\n\t\t 2 . Search Book by auhtor" << endl;
    cout << "\n\t\t 3 . Search Book by ISBN" << endl;
    cout << "\n\t\t 4 . Return Book" << endl;
    cout << "\n\t\t 5 . Display Available Books" << endl;
  }


     ~Library()
		{
	        Book* current = head;
	        while(current != NULL)
			{
	            Book* next = current->next;
	            delete current;
	            current = next;
	        }
	    }
  
};   // Library class ends



int main() {

  system("color E1");
  
  Registration r1;
  Library book;

  book.Banner();

  book.loadFromFile("database.txt");        // load all Books from file

  string t, a, i;
  
  int choice = 1, d;

  do {
    
    cout << "\n\t\t| 1 . Librarian   |" << endl;
    cout << "\n\t\t| 2 . Student     |" << endl;
    cout << "\n\t\t| 3 . EXIT        |" << endl;
    cout << "\n\t\tEnter your choice : " << endl;
    cin >> choice;

    if (choice == 1) {
    	system("cls");
      int ch = 1;
     book.Banner();
     r1.display_menu();
      do {
      	
      	
        
        book.AdminMenu();
        cout << "\n\t\tEnter your choice : " << endl;
        cin >> ch;
        switch (ch) {


        case 0:

          cout << "\n\t\tEXIT" << endl;
          cout << "\n\n\n\t\tThank you !!" << endl;
          exit(0);
          break;


        case 1:

          cout << "\n\t\t'Add Book'" << endl;
          cout << "\nEnter Book Title :" << endl;
          cin.ignore();
          getline(cin,t);

          cout << "Enter Book Author name :" << endl;
          
          getline(cin,a);

          cout << "Enter Book ISBN :" << endl;
          cin >> i;

          if (book.Repeat(t, a, i)) {
            cout << "This Book is already Stored in the File  \n";
            cout << "No Duplication is Allowed" << endl;

          } else {
            book.addBook(t, a, i);
            book.storeBooksToFile("database.txt");
          }

          break;

        case 2:

          cout << "\n\t\t'Search Book by title'" << endl;
          cout << "\nEnter Book Title : " << endl;
          cin.ignore();
          getline(cin,t);
          book.searchByTitle("database.txt", t);

          break;


        case 3:
          cout << "\n\t\t'Search Book by author'" << endl;
          cout << "\nEnter Book Author name : " << endl;
          cin.ignore();
          getline(cin,a);
          book.searchByAuthor("database.txt", a);
          break;


        case 4:
          cout << "\n\t\t'Search Book by ISBN'" << endl;
          cout << "\nEnter Book ISBN : " << endl;
          cin >> i;
          book.searchByISBN("database.txt", i);
          break;


        case 5:
        	
          cout << "\n\t\t'Book Checkout'" << endl;
          cout << "\nEnter Book Title :" << endl;
          cin>>t;
          cout << "Enter Book Author name :" << endl;
          cin.ignore();
          getline(cin,a);
         
          cout << "Enter Book ISBN :" << endl;
          cin >> i;
          book.bookCheckout(t, a, i);
          break;


        case 6:

          book.sortBooks();
          book.displayBooks();
          break;

        default:
          cout << "\t\tINVALID INPUT !!\n" << endl;

          break;
        }

      } while (ch != 0);

    } else if (choice == 2) {


      int ch = 1;
      
      system("cls");
      book.Banner();
      r1.display_menu();
      do {
        
        book.borrowerMenu();
        cout << "\n\tEnter your choice : " << endl;
        cin >> ch;
        system("cls");
        switch (ch) {

        case 1:
          cout << "\n\t\t'Search Book by title'" << endl;
          cout << "\nEnter Book Title : " << endl;
          cin>>t;
          book.searchByTitle("database.txt", t);

          break;


        case 2:
          cout << "\n\t\t'Search Book by author'" << endl;
          cout << "\nEnter Book Author name : " << endl;
          cin.ignore();
          getline(cin,a);
          book.searchByAuthor("database.txt", a);
          break;


        case 3:
          cout << "\n\t\t'Search Book by ISBN'" << endl;
          cout << "\nEnter Book ISBN : " << endl;
          cin >> i;
          book.searchByISBN("database.txt", i);
          break;
          
          
        case 4:

          cout << "\n\t\t'Book Return'" << endl;
          cout << "Enter Book Name :" << endl;
          cin>>t;
          cout << "Enter Book Author :" << endl;
          cin.ignore();
          getline(cin,a);
          cout << "Enter Book ISBN :" << endl;
          cin >> i;
          cout << "Enter Days of OverDue:  ";
          cin >> d;
          book.bookReturn(t, a, i, d);
          

          break;


        case 5:
          book.sortBooks();
          book.displayBooks();
          break;

        default:
          cout << "\n\t\tINVALID INPUT !!" << endl;
          break;


        case 0:
          cout << "\n\n\n\t\tEXIT";
          cout << "\n\n\n\t\tThank you !!" << endl;
          exit(0);
        }

      } while (ch != 0);


    } else if (choice == 3) {

      cout << "\n\n\n\t\tEXIT !!" << endl;
      cout << "\n\n\t\tThank you !!" << endl;
      exit(0);


    } else {
      cout << "\n\t\tInvalid !!" << endl;
    }


  } while (choice != 3);



  return 0;


}
