#include <stdio.h>
#include <string>
#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName){
  int i;
  for(i=0; i<argc; i++){
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int initDB(sqlite3 *db){
  std::string db_query1="create table user (id integer primary key not null, name text, pwhash text);"; // include a guid field later when we get basic functionality working.
  std::string db_query2="create table messages (id integer primary key not null, subject text, sender text, recipient text, body text);";
  std::string db_query3="insert into user (name, pwhash) values ('administrator', 's00p3rS3CR37');";
  std::string db_query4="insert into user (name, pwhash) values ('robert', 'robert');";

  std::string dbname="geemail.db";
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open(dbname.c_str(), &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }
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