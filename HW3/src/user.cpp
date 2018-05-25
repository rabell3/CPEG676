#include "user.h"
#include <cstring>

using namespace std;

const int getUser(string &userName){
  string userIn, illegalChars = ".\\/:;{}[]`~,?\"<>|";
  
  printf("Enter username: ");
  cin >> userIn;
  if (std::cin.fail()) {
      std::cerr << "Please make a valid choice." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  size_t valid_len = strcspn(userIn.c_str(), illegalChars.c_str());
    if(valid_len != userIn.size()) {
      std::cout << "You entered invalid chars starting at position "
        << valid_len << '\n';
      std::cin.clear();
      return 0;
    } else {
      userName = userIn;
      return 1;
    }
}