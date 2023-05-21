#include <iostream>
#include <fstream>

using namespace std;

void log(string message) {
  ofstream logfile("log.txt");
  logfile << message << endl;
  logfile.close();
}
