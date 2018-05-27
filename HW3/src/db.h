#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName);
int sql_stmt(sqlite3 *db, const std::string stmt);
int initDB(sqlite3 *db);
int openDB(sqlite3 *db);
int getMessages(sqlite3 *db, const std::string userIn);
