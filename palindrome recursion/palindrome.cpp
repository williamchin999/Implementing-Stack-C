//Copyright 2021 William Chin
//Email: wchin1@sfsu.edu
//This file is apart of CSC340 -Assignment 3

//Checks for input to remove non alphabet chars,then checks for palindrome

//TODO: find better way to remove non alphabet chars

#include <iostream>
#include <string>

using namespace std;
int check(string s, int start, int end)
{
    if (end - start == 1 || start == end){
        return 1;
    }
    else{
        if (s[start] == s[end])
            return check(s, start + 1, end - 1);
        else
            return 0;
    }
}

void remove(string &str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z'){
            str.erase(i, 1);
            i--;
        }
    }
    //cout << s;
}

int main()
{
    string s;
    cout << "Input string " << endl;
    getline(cin, s);
    remove(s);
    int a = s.length();
    if (check(s, 0, a - 1))
        cout << s << " is a palindrome" << endl;
    else
        cout << s << " is not a palindrome" << endl;
    return 0;
}