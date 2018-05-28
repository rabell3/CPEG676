#include <stdio.h>
#include <iostream>
#include <string>
#include "db.h"
#include "user.h"

using namespace std;

void printMenu(const std::string inName){
  cout << std::string(60,'-') << endl;  // top bar
  cout << "| Logged in as: " << inName << std::string(60-(17+inName.size()),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << "| 1.  Account Settings " << std::string((60-24),' ') << "|" << endl;
  cout << "| 2.  List email " << std::string((60-18),' ') << "|" << endl;
  cout << "| 3.  Read email " << std::string((60-18),' ') << "|" << endl;
  cout << "| 4.  Write email " << std::string((60-19),' ') << "|" << endl;
  cout << "| 5.  Exit from system " << std::string((60-24),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << std::string(60,'-') << endl;  // bottom bar
}

void printLoginMenu(const std::string inName){
  cout << std::string(60,'-') << endl;  // top bar
  cout << "| Logged in as: " << inName << std::string(60-(17+inName.size()),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << "| 1.  Login to system " << std::string((60-23),' ') << "|" << endl;
  cout << "| 2.  Add account " << std::string((60-19),' ') << "|" << endl;
  cout << "| 3.  Remove account " << std::string((60-22),' ') << "|" << endl;
  cout << "| 4.  Back to main  " << std::string((60-21),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << std::string(60,'-') << endl;  // bottom bar
}

void runLogin(sqlite3 *db, std::string &loginname){
  int choice = 0;
  bool running = true;
  while (running) {
    printLoginMenu(loginname);
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
          //loginname = authenticateUser();
          unsigned short rc=0, tryCount=0;
          do {
            tryCount++;
            //rc=getUser(loginname);
            rc=authenticateUser(db, loginname);
          } while ((tryCount <3) && rc==0);
          if (rc==1) {
            cout << "hello, " << loginname << endl;
          } 
          else { cout << "Please enter a valid login name.\n";}
        }
        break;
      case 2:  // Add account
        getUser(loginname);
        setPass(db, loginname);
        break;
      case 3:  // Remove account
        std::cout << "Remove account code would be here.\n";
        break;
      case 4:  // Back to main
        running = false;
        break;
      default: // didn't match anything else
        break;
    }
  };
}
// --------------------------------------------------------------------------------------------------------------------------------

int main(){
  sqlite3 *db;  // database handle
  std::string dbname="geemail.db";
  string loginname="";
  int rc=openDB(db, dbname);
  if (rc != 0) {
//    cout << "rc: " << rc << endl;   // Debug code
    fprintf(stderr, "Error initializing database...\n");
    return 1;
  }
  cout << "rc: " << rc << endl;
//  if (db != NULL) {cout << "Wow lucky\n";} else { cout << "you're fucked\n";};
  int choice = 0;
  bool running = true;

  while (running) {
    printMenu(loginname);
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
        { /*
          //loginname = authenticateUser();
          unsigned short rc=0, tryCount=0;
          do {
            tryCount++;
            //rc=getUser(loginname);
            rc=authenticateUser(db, loginname);
          } while ((tryCount <3) && rc==0);
          if (rc==1) {
            cout << "hello, " << loginname << endl;
          } 
          else { cout << "Please enter a valid login name.\n";}*/
          runLogin(db, loginname);
        }
        break;
      case 2:  // list email
        getMessages(db, loginname);
        break;
      case 3:  // read email
        setPass(db, loginname);
        break;
      case 4:  // write email
        break;
      case 5:  // exit
        running = false;
        break;
/*      case 6:  // dbperfs, hidden option, segfaults, disabled for now.
        getDBperfs(db);
        break;*/
      default: // didn't match anything else
        break;
    }
  };

  sqlite3_close(db);
  return 0;
}