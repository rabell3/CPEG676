#include <stdio.h>
#include <iostream>
#include <string>
#include "db.h"
#include "user.h"

using namespace std;

void printMenu(const std::string inName){
//  unsigned short lline = loginname.size();
  cout << std::string(60,'-') << endl;  // top bar
  cout << "| Logged in as: " << inName << std::string(60-(17+inName.size()),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << "| 1.  Login to system " << std::string((60-23),' ') << "|" << endl;
  cout << "| 2.  List email " << std::string((60-18),' ') << "|" << endl;
  cout << "| 3.  Read email " << std::string((60-18),' ') << "|" << endl;
  cout << "| 4.  Write email " << std::string((60-19),' ') << "|" << endl;
  cout << "| 5.  Exit from system " << std::string((60-24),' ') << "|" << endl;
  cout << "|" << std::string(58,' ') << "|" << endl;
  cout << std::string(60,'-') << endl;  // bottom bar
}

int main(){
  sqlite3 *db;  // database handle
  string loginname="";
  if (openDB(db) != 0) {
    fprintf(stderr, "Error initilizing database...\n");
    return 1;
  }

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
        {
          unsigned short rc=0, tryCount=0;
          do {
            tryCount++;
            rc=getUser(loginname);
          } while ((tryCount <3) && rc==0);
          if (rc==1) {
            cout << "hello, " << loginname << endl;
          } 
          else { cout << "Please enter a valid login name.\n";}
        }
        break;
      case 2:  // list email
        getMessages(db, loginname);
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