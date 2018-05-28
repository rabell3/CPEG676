#include <stdio.h>
#include <string>
#include <iostream>
#include <array>
#include <sqlite3.h>

//using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int sql_stmt(sqlite3 *db, const std::string stmt){
  char *zErrMsg = 0;
  int rc;
  sqlite3_stmt *checkStmt;
//  std::cout << "Q: " << stmt << std::endl;   // Debug code
  if (db == NULL) { sqlite3_open("geemail.db", &db);};

//  sqlite3_prepare_v2(db, stmt.c_str(), stmt.size(), &checkStmt, NULL);
  if (sqlite3_prepare_v2(db, stmt.c_str(), stmt.size(), &checkStmt, NULL) != SQLITE_OK) {
           std::cout << "Prepare failure: " << sqlite3_errmsg(db) << std::endl;
       }
  if ( sqlite3_step(checkStmt) != SQLITE_ROW ){
      std::cout << "More...\n";
  }
  if (checkStmt == NULL) { std::cout << "shit\n";};
  sqlite3_finalize(checkStmt);
//  std::cout << "ret: " << rc << std::endl;   // Debug code

  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  if (zErrMsg == 0) {return 0;}
    else return 1;

/*

  std::cout << "st: " << stmt << std::endl;
  char *errmsg=0;
  int ret = sqlite3_exec(db, stmt.c_str(), 0, 0, &errmsg);
  if (ret != SQLITE_OK) {
    std::cerr << "Error in statement " << stmt << "[" << errmsg << "]\n";
    return 0;
  }
  return 1;*/
}

int initDB(sqlite3 *db){
  int rc;
  std::cout << "Initializing database...\n";

  std::array<std::string, 5> inits {     // <------- Make sure to change this value when adding/deleting from this init list
    "create table user (id integer primary key not null, name text, pwhash text, pwsalt text);", \
    "create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);", \
    "create index i1 on user (id, name)", \
    "create index i2 on messages (id, sender, recipient)", \
    "insert into user (name, pwhash, pwsalt) values ('administrator', 'B95C7787CBD4B9FA4F83A9D2554F57B5E389F06365F4772EE1CB516A5EA23433','CpEG676-482539739');"
  };

  for (auto& init : inits){
    rc=sql_stmt(db, init.c_str());
  }

  if (rc=0) {return 0;} else return 1;
}

int openDB(sqlite3 *db, const std::string dbname){
  std::string db_check="SELECT name FROM sqlite_master WHERE type='table' AND name='user';";
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open(dbname.c_str(), &db);
  if( rc != SQLITE_OK ){
    std::cout << "rc: " << rc << std::endl;
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }

  sqlite3_stmt *checkStmt;   // Check the database to see if the user table exist, if not, it's a brand new file and needs to be init'd
  sqlite3_prepare_v2(db, db_check.c_str(), db_check.size(), &checkStmt, NULL);
  if ( sqlite3_step(checkStmt) != SQLITE_ROW ) {    // sqlite3_step either returns a row of data (or not) depending on table existence
      initDB(db);
  }

    sqlite3_finalize(checkStmt);

  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  if (zErrMsg == 0) {return 0;}
    else return 1;
}

int getMessages(sqlite3 *db, const std::string userIn){
  std::string db_query1="select * from messages where recipient = '" + userIn + "';";

  char *zErrMsg = 0;
  int rc;

  //rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
  rc = sqlite3_exec(db, db_query1.c_str(), callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  if (zErrMsg == 0) {return 0;}
    else return 1;
}

int userExists(sqlite3 *db, const std::string recipent){
  // Not Ready. Code to check if user exists...
  /*
  if (zErrMsg == 0) {return 0;}
    else return 1;
  */
}

void getDBperfs(sqlite3 *db){
    int *pCur, *pHiwtr, resetFlg;
    if (db != NULL) {std::cout << "Wow lucky\n";} else { sqlite3_open("geemail.db", &db);};
    int rc =sqlite3_db_status(db, 3, pCur, pHiwtr, resetFlg);
    if (rc == SQLITE_OK) {
      std::cout <<"STMT Used: " << pCur << std::endl;
      std::cout <<"STMT Hiwtr: " << pHiwtr << std::endl;
    } else {std::cout <<"Err: " << std::endl;};
}
