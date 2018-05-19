#include "user.h"

const std::string getUser(){
  std::string userName;
  std::string illegalChars = "\\/:?\"<>|";
  
  printf("Enter username: ");
  std::cin >> userName;

  return userName;
}