#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>

const int getUser(std::string &userName);
//std::string authenticateUser();
const int authenticateUser(sqlite3 *db, std::string &authUser);
