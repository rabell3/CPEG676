#include <iostream>

//const int CAP = 10;
const unsigned long CAP = 4000000;

int main(){
  std::cout << "Euhler problem 2\nSum of even-number Fibonacci terms < 4mil" << std::endl;
  unsigned long first=1, second=1, next, sum=0, count=0;
  while (first < CAP){
      count++;
  //for (int count=0; count<CAP ; count++){
      next = first + second;
      first = second;
      second = next;
//      std::cout << "count " << count << " fib: " << first << "\n";
      if (first%2 == 0) {
        sum = sum+first;
        std::cout << "count " << count << " fib: " << first << "\n";
      }
  }
  std::cout << "Last fib " << first << " sum: " << sum << "\n";
  return 0;
}
