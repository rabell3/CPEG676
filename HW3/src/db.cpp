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

int sql_stmt(sqlite3 *db, const std::string stmt)
{
  char *errmsg=0;
  int ret = sqlite3_exec(db, stmt.c_str(), 0, 0, &errmsg);
  if (ret != SQLITE_OK) {
    std::cerr << "Error in statement " << stmt << "[" << errmsg << "]\n";
    return 0;
  }
  return 1;
}

int initDB(sqlite3 *db){
  int rc;
  std::cout << "Initializing database...\n";

  std::array<std::string, 4> inits { 
    "create table user (id integer primary key not null, name text, pwhash text);", \
    "create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);", \
    "insert into user (name, pwhash) values ('administrator', 's00p3rS3CR37');", \
    "insert into user (name, pwhash) values ('robert', 'robert');"
  };

  for (auto& init : inits){
    rc=sql_stmt(db, init.c_str());
  }

  if (rc=0) {return 0;} else return 1;

/*
  std::string db_query1="create table user (id integer primary key not null, name text, pwhash text);"; // include a guid field later when we get basic functionality working.
  std::string db_query2="create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);";
  std::string db_query3="insert into user (name, pwhash) values ('administrator', 's00p3rS3CR37');";
  std::string db_query4="insert into user (name, pwhash) values ('robert', 'robert');";

  char *zErrMsg = 0;


  //rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
  rc = sqlite3_exec(db, db_query1.c_str(), callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  rc = sqlite3_exec(db, db_query2.c_str(), callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  rc = sqlite3_exec(db, db_query3.c_str(), callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  rc = sqlite3_exec(db, db_query4.c_str(), callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  if (zErrMsg == 0) {return 0;}
    else return 1;
    */
}

int openDB(sqlite3 *db){
  std::string db_check="SELECT name FROM sqlite_master WHERE type='table' AND name='user';";
  std::string dbname="geemail.db";
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open(dbname.c_str(), &db);
  if( rc ){
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