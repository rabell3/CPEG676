#include <string>
#include <crypto++/sha.h>
#include <crypto++/blowfish.h>
#include <crypto++/filters.h>
#include <crypto++/hex.h>
#include <sqlite3.h>
#include "user.h"
#include "db.h"

using namespace CryptoPP;

const int getUser(std::string &userName){
  std::string userIn, illegalChars = ".\\/:;{}[]`~,?\"<>|";
  
  std::cout << "Enter username: ";
  std::cin >> userIn;
  if (std::cin.fail()) {
      std::cerr << "Please make a valid choice." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  if (userIn.size() >= 40) { 
      std::cout << "Please try again.\n";
      return 0;
    }

  size_t valid_len = strcspn(userIn.c_str(), illegalChars.c_str());
    if(valid_len != userIn.size()) {
      std::cout << "Please do not include invalid characters\n";
//        << valid_len << '\n';
      std::cin.clear();
      return 0;
    } else {
      userName = userIn;
      return 1;
    }
}

const int pwHashGet(sqlite3 *db, const std::string authUser, const std::string authUserHash){
  return 1;
}

const int authenticateUser(sqlite3 *db, std::string &authUser){
  authUser="";
  int rcU=0, rcP=0;
  rcU=getUser(authUser); 

  if (rcU == 1){
  SHA256 userHash;
  std::string authPassHash="";
  std::string authPass="";
  std::cout << "Enter password: ";
  std::cin >> authPass;
  std::string authHash;
  StringSource ss( authPass, true /* PumpAll */,
                 new HashFilter( userHash, 
                   new HexEncoder( 
                     new StringSink( authHash )
                   ) // HexEncoder
                 ) // HashFilter
              ); // stringSource

  std::cout << "authPass " << authPass << std::endl;
  std::cout << "authPassHash " << authHash << std::endl;

//  std::string pwHashSQL="insert into user (name, pwhash) values ('robert', 'robert');";
  std::string pwHashSQL="insert into user (name, pwhash) values ('" + authUser + "', '" + authHash + "');";
  rcP=sql_stmt(db, pwHashSQL);

  return 1;
  } else return 0;
}

const int writeEmail(sqlite3 *db, std::string sender){
  std::string recipient;
  int rc=getUser(recipient);
  // The below section not really ready yet.

  if (userExists(db, recipient) != 1) {
    std::cout << "User does not exist. Please try again.\n";
  }


}

encryptMessage(){

}
decryptMessage(){
  
}