#include "csv.hpp"

int main(){
  CSV csv("Microfilmes.csv");
  csv.printData(10); // prints line 10
  return 0;
}
