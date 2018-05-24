#include "user.h"
using namespace std;

const int getUser(string &userName){
  string userIn;
  string illegalChars = "\\/:?\"<>|";
  
  printf("Enter username: ");
  cin >> userIn;

/*
  if (std::cin.fail()) {
    std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
*/
/*
  bool found = (userIn.find(illegalChars));
  if (found==string::npos) {
      return "INVALID";
  } else {
    userName = userIn;
    return userName;
  }
*/
  cout << "name length: " << userIn.size() << endl;
  for (unsigned int i=0; i <= illegalChars.size(); i++) {
      cout << illegalChars[i] << endl;
/*      if (userIn.find(illegalChars[i])) {
      cout << "junkchars\n";
      return 0;
        } else {
            userName = userIn;
            return 1;
        }*/
  }
}