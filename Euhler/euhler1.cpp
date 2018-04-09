#include <iostream>

bool checkthree(int innum){
    return !(innum % 3);
}

bool checkfive(int innum){
    return !(innum % 5);
}

int main(){
  int sum=0;
  std::cout << "Euhler problem 1\nSum of numbers less than 1000 which are multiples of 3 or 5" << std::endl;
  std::cout << "Num: " << "#" << "\t" << "mult 3" << "\t" << "mult 5" << "\n";
  std::cout << "----------------------------------------------------------\n";
  for (int n=0; n<1000; n++) {
//      std::cout << "sum\t" << sum << "\n";  // debug output
      if (checkthree(n) || checkfive(n))
        sum=sum+n;
//      else
//        std::cout << "nah\n";
      std::cout << "Num: " << n << "\t" << checkthree(n) << "\t" << checkfive(n) << "\n";
//      sum=sum+n;
  }
  std::cout << "Eulher 1 sum: " << sum << "\n";
  return 0;
}
