#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>
#include <iostream>

using namespace rapidjson;
using namespace std;

int main()
{
  ifstream ifs("questions.json");
  IStreamWrapper isw(ifs);

  Document document;
  document.parseStream(isw);

  cout << document[0];

  return 0;
}