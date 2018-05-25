#include <stdio.h>
#include <iostream>
#include <string>
#include "db.h"
#include "user.h"

using namespace std;

void printMenu(){
  cout << "----------------------------\n";
  cout << " 1.  Login to system        \n";
  cout << " 2.  List email             \n";
  cout << " 3.  Read email             \n";
  cout << " 4.  Write email            \n";
  cout << " 5.  Exit from system       \n";
  cout << "----------------------------\n";
}

int main(){
  sqlite3 *db;  // database handle
  if (openDB(db) != 0) {
    fprintf(stderr, "Error initilizing database...\n");
    return 1;
  }

  int choice = 0;
  bool running = true;

  while (running) {
    printMenu();
    cout << " -> ";
    cin >> choice;
    if (std::cin.fail()) {
      std::cerr << "Please make a valid choice." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (choice)
    {
      case 1:  // login
        {
          string loginname;
          unsigned short rc=0, tryCount=0;
          do {
            tryCount++;
            rc=getUser(loginname);
          } while ((tryCount <3) && rc==0);
          if (rc==1) {cout << "hello, " << loginname << endl;} 
          else { cout << "Please enter a valid login name.\n";}
        }
        break;
      case 2:  // list email
        break;
      case 3:  // read email
        break;
      case 4:  // write email
        break;
      case 5:  // exit
        running = false;
        break;
      default: // didn't match anything else
        break;
    }
  };



  sqlite3_close(db);
  return 0;
}