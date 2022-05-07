#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;


int
main ()
{
  string s1;
  getline (cin, s1);

  int n, p, r = 0;
  string c;
  n = s1.length ();
  c = s1[n - 2];

  string v[5] = { "a", "e", "i", "o,", "u" };

  for (int i = 0; i <= 5; i++)
    {

      p = c.compare (v[i]);
      if (p == 0)
	{
	  r = r + 1;
	  break;
	}
    }
  if (r == 1)
    {
      cout << "YES";
    }
  else
    {
      cout << "NO";
    }


}