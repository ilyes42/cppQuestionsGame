#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace rapidjson;
using namespace std;

int main()
{
  ifstream ifs("questions.json");
  IStreamWrapper isw(ifs);

  Document questions;
  questions.ParseStream(isw);

  vector<int> seenBefore;
  int n = questions.Size();
  int q;
  string input;

  cout << "we have " << n << " questions in questions.json !!" << endl;
  cout << "Are you ready to play this game ??\n(if ready press 'y')\n";
  cin >> input;

  if (input != "y")
    return 0;
  else
  {
    while (true)
    {
      if (seenBefore.size() == n)
      {
        cout << "No more !!" << endl;
        break;
      }
      do
      {
        q = rand() % n;
      } while (find(seenBefore.begin(), seenBefore.end(), q) != seenBefore.end());
      seenBefore.push_back(q);
      cout << questions[q]["q"].GetString() << endl;
      for (int i = 0; i < 3; i++)
      {
        cout << "(" << i + 1 << ") " << questions[q]["a"][i].GetString() << endl;
      }
      cin >> input;
      if (input == questions[q]["c"].GetString())
      {
        cout << "That's correct !! Awesome !!!" << endl;
      }
      else
      {
        cout << "Not correct !! Not Awesome !!!" << endl;
      }
    }
  }

  return 0;
}