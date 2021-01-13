#include "csv.hpp"
#include <iostream>

vector<string> CSV::csvParser(string & str, char delim){
  char aspas_delim[3];
  aspas_delim[0] = '\"';
  aspas_delim[1] = delim;
  aspas_delim[2] = '\0';
  string P;
  vector<string> result;
  int i_i = 0, i_f = 0;
  bool flag = true;
  do {
    if (str[i_i] == '\"'){
      i_f = str.find(aspas_delim, i_i);
      if (i_f == string::npos){
	i_f = str.size() - 1;
	flag = false;
      }
      P.insert(0, str, i_i, (i_f + 1) - i_i); // Insert in P str from i_i to i_f positions
      result.push_back(P);
      i_i = i_f + 2;
    }
    else {
      i_f = str.find(delim, i_i);
      if (i_f == string::npos){
	i_f = str.size();
	flag = false;
      }
      P.insert(0, str, i_i, i_f - i_i); // Insert in P str from i_i to i_f - 1 positions
      result.push_back(P);
      i_i = i_f + 1;
      P = "";
    }
  } while(flag);
  return result;
}

// CSV::CSV(const char *fname, char delim = ',', bool has_head = true)
CSV::CSV(const char *fname, char delim, bool has_head){
  ifstream f;
  f.open(fname);
  if (f.fail()){
    cerr << "File not found!" << endl;
    exit(1);
  }
  string line;
  if (has_head){
    getline(f, line);
    head = csvParser(line, delim);      
  }
  vector<string> P;
  while (!f.eof()){
    getline(f, line);
    P = csvParser(line, delim);
    data.push_back(P);
  }
}

// CSV::CSV(string & fname, char delim = ',', bool has_head = true)
CSV::CSV(string & fname, char delim, bool has_head){
  ifstream f;
  f.open(fname);
  if (f.fail()){
    cerr << "File not found!" << endl;
    exit(1);
  }
  string line;
  if (has_head){
    getline(f, line);
    head = csvParser(line, delim);      
  }
  vector<string> P;
  while (!f.eof()){
    getline(f, line);
    P = csvParser(line, delim);
    data.push_back(P);
  }
}

// CSV::CSV(ifstream & f, char delim = ',', bool has_head = true)
CSV::CSV(ifstream & f, char delim, bool has_head){
  if (f.fail()){
    cerr << "File not found!" << endl;
    exit(1);
  }
  string line;
  if (has_head){
    getline(f, line);
    head = csvParser(line, delim);      
  }
  vector<string> P;
  while (!f.eof()){
    getline(f, line);
    P = csvParser(line, delim);
    data.push_back(P);
  }
}

inline vector<string> CSV::HEAD(){return head;}
inline vector<vector<string>> CSV::DATA(){return data;}

void CSV::printHead(){
  for (int i; i < head.size(); i++){
    cout << head[i] << ",";
  }
  cout << endl;
}

void CSV::printData(){
  if (head.size() != 0)
    printHead();
  
  for (int i = 0; i < data.size(); i++){
    for (int j = 0; j < data[i].size(); j++){
      cout << data[i][j] << ",";  
    }
    cout << endl;
  }
}

void CSV::printData(int i){
  for (int j = 0; j < data[i].size(); j++){
    cout << data[i][j] << ",";
  }
  cout << endl;
}

inline vector<string> & CSV::operator[](int i){return data[i];}
