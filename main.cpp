#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

  string qJson;
  ifstream f("questions.json");
  
  if (f.is_open())
  {
    string line;
    while(getline(f, line))
    {
      qJson += line;
    }
    f.close();
  }

  cout << qJson;

  return 0;
}