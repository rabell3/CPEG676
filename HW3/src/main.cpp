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
  if (initDB(db) != 0) {
    printf("Error initilizing database...\n");
    return 1;
  }

  int choice = 0;
  bool running = true;

  while (running) {
    printMenu();
    cin >> choice;
    switch (choice)
    {
      case 1:  // login
        {
          string loginname;
          int tryCount=1;
          while ((loginname != "INVALID") && (tryCount <3)) {
            loginname=getUser();
            printf("try: %d\t", tryCount);
            tryCount++;
          };
          printf("hello, %s\n", loginname.c_str());
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