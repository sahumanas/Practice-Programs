#include<iostream>
#include<string.h>

using namespace std ;


int main()
{
char s[10] = "abcde";
char *pS = new char[strlen(s) + 1]; // allocate correct memory size based on string size

cout << "Size is " << sizeof(pS) << endl; // just for testing
int count = strlen(s); // for iteration

pS[count] = '\0'; // last symbol must be '\o' (thanks to Mr.Yellow)

for (int i = 0; i < 10; i++) // 10 because array of char still has 10 elements
{
    if (s[i] != '\0') // looks like "not garbage memory"
    {
        count--;
        pS[count] = s[i]; // set correct value
    }
}

cout << "Reversed = " << pS << endl;
}
