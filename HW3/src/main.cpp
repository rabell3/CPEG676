#include <stdio.h>
#include <iostream>
#include <string>
#include "db.h"
#include "user.h"


int main(){
  sqlite3 *db;  // database handle
  if (initDB(db) != 0) {
    printf("Error initilizing database...\n");
    return 1;
  }

  std::string loginname=getUser();
  printf("hello, %s\n", loginname.c_str());

  sqlite3_close(db);
  return 0;
}