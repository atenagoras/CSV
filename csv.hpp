#ifndef _CSV
#define _CSV
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class CSV{
public:
  CSV(const char *fname, char delim = ',', bool has_head = true);
  CSV(string & fname, char delim = ',', bool has_head = true);
  CSV(ifstream & f, char delim = ',', bool has_head = true);
  vector<string> HEAD(); // Returns the headline
  vector<vector<string>> DATA(); // Returns the whole data
  void printData(); // prints the whole data
  void printData(int i); // prints data in the line i
  void printHead(); // prints the head
  vector<string> & operator[] (int i); // overloading operator []. Returns the data in line i
protected:
  vector<string> head; // Get the field names in the headline
  vector<vector<string>> data; // Get the data. For each Line, a vector<string> of data.
  /* Example:
     Suppose a csv file with 10 fields and 20 lines.
     data[0] = data from first line
     data[0][9] = data from first line and field 10
   */
private:
  vector<string> csvParser(string & str, char delim);
};

#endif
