#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <unistd.h>

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int initDB(sqlite3 *db){
  string db_query1="create table user (id integer primary key not null, name text, pwhash text);"; // include a guid field later when we get basic functionality working.
  string db_query2="create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);";
  string db_query3="insert into user (name, pwhash) values ('administrator', 's00p3rS3CR37');";
  string db_query4="insert into user (name, pwhash) values ('robert', 'robert');";

  char *zErrMsg = 0;
  int rc;

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
}

int openDB(sqlite3 *db){
  string db_check="SELECT CASE WHEN tbl_name = 'user' THEN 1 ELSE 0 END FROM sqlite_master WHERE tbl_name = 'user' AND type = 'table'"; // https://stackoverflow.com/questions/1601151/how-do-i-check-in-sqlite-whether-a-table-exists
/*  string db_query1="create table user (id integer primary key not null, name text, pwhash text);"; // include a guid field later when we get basic functionality working.
  string db_query2="create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);";
  string db_query3="insert into user (name, pwhash) values ('administrator', 's00p3rS3CR37');";
  string db_query4="insert into user (name, pwhash) values ('robert', 'robert');";*/

  string dbname="geemail.db";
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open(dbname.c_str(), &db);
//    fprintf (stdout, "return: %d", rc);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }

  rc = sqlite3_exec(db, db_check.c_str(), NULL, 0, &zErrMsg);
  if (!rc) {
      initDB(db);
  }

//  fprintf (stdout, "return: %d", rc);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }

/*  
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
  }*/
  if (zErrMsg == 0) {return 0;}
    else return 1;
}

int getMessages(sqlite3 *db, const string userIn){
  string db_query1="select * from messages where ;";
}