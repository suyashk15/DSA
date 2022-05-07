
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;



int
main ()
{
  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  int n;
  n = s1.length ();

  reverse (s1.begin (), s1.end ());

  int x = s1.compare (s2);
  
  if (x == 0)
    {
      cout << "YES";
    }
  else
    {
      cout << "NO";
    }
}




