#include <stdio.h>
#include <string>
#include "db.h"

int main(){
  char* dbname="geemail.db";
  sqlite3 *db;  // database handle
  char *zErrMsg = 0;
  int rc;

  char* db_query1="create table person (id integer primary key, name text, age int);";
  char* db_query2="insert into person (name, age) values ('Robert', '39');";
  char* db_query3="insert into person (name, age) values ('Mary', '40');";
/*
  if( argc!=2 ){
    //fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
    fprintf(stderr, "Usage: %s SQL-STATEMENT\n", argv[0]);
    return(1);
  }
*/
  rc = sqlite3_open(dbname, &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }
  //rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
  rc = sqlite3_exec(db, db_query1, callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  rc = sqlite3_exec(db, db_query2, callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  rc = sqlite3_exec(db, db_query3, callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

  sqlite3_close(db);
  return 0;
}