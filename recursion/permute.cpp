#include <iostream>
#include <string>
using namespace std;
void permute(string &s, int start);
int main()
{
    string myString = "abcde";
    permute(myString, 0);
}
void permute(string &s, int start)
{
    if (start == s.size())
        cout << s << " ";
    else
    {
        for (int i = start; i < s.size(); i++)
        {
            swap(s[start], s[i]);
            permute(s, start + 1);
            swap(s[i], s[start]);
        }
    }
}