#include <cstring>
#include "user.h"
#include <crypto++/sha.h>
#include <crypto++/filters.h>
#include <crypto++/hex.h>


using namespace std;
using namespace CryptoPP;

const int getUser(string &userName){
  string userIn, illegalChars = ".\\/:;{}[]`~,?\"<>|";
  
  cout << "Enter username: ";
  cin >> userIn;
  if (std::cin.fail()) {
      std::cerr << "Please make a valid choice." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  if (userIn.size() >= 40) { 
      cout << "Please try again.\n";
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

int authenticateUser(){
  string authUser="";
  int rcU=getUser(authUser);
  SHA256 userHash;
  string authPassHash="";
  string authPass="";
  cout << "Enter password: ";
  cin >> authPass;
  string authDigest;
StringSource ss( authPass, true /* PumpAll */,
                 new HashFilter( userHash, 
                   new HexEncoder( 
                     new StringSink( authDigest )
                   ) // HexEncoder
                 ) // HashFilter
              ); // StringSource

  cout << "authPass " << authPass << endl;
  cout << "authPassHash " << authDigest << endl;
  
  return 1;
}