#include <iostream>
using namespace std;
int compareTo(string s1, string s2)
{
    if (s1.length() > s2.length())
        return 1;
    else if (s1.length() < s2.length())
        return -1;
    else
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] - s2[i] > 0)
                return 1;
            else if (s1[i] - s2[i] < 0)
                return -1;
        }
        return 0;
    }
}

int main()
{
    string s = "hello";
    for (int i = 0; i < s.length(); i++)
    {   
    }
    return 0;
}