#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName);
int sql_stmt(sqlite3 *db, const std::string stmt);
int initDB(sqlite3 *db);
int openDB(sqlite3 *db, std::string dbname);
int getMessages(sqlite3 *db, const std::string userIn);
int userExists(sqlite3 *db, const std::string recipent);
void getDBperfs(sqlite3 *db);
