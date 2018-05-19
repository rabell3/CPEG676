#include <sqlite3.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName);
int initDB(sqlite3 *db);
