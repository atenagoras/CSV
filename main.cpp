/* This program is free software. It comes without any warranty, to
     * the extent permitted by applicable law. You can redistribute it
     * and/or modify it under the terms of the Do What The Fuck You Want
     * To Public License, Version 2, as published by Sam Hocevar. See
     * http://www.wtfpl.net/ for more details. */

// Atenágoras, Jan 2021

// This main function is just a test CSV class methods

#include "csv.hpp"

int main(){
  CSV csv("Microfilmes.csv");
  csv.printData(10); // prints line 10
  return 0;
}
