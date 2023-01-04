// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
    cout << "Hello " << endl;
  ofstream outfile ("example.txt");
  if (outfile.is_open())
  {
    outfile << "This is a line.\n";
    outfile << "This is another line.\n";
    outfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
