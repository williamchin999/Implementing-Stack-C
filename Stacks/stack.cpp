//Copyright 2021 William Chin
//Email: wchin1@sfsu.edu
//This file is apart of CSC340 -Assignment 3

//Use stack to double size of stack,rev chars, check for palindrome

//TODO: Remove non alphabet chars on inputs

#include "stack.h"
#include <iostream>
#include <string>

void reg_asgn();
void pal();
void rev();

int main()
{
    reg_asgn();
    pal();
    rev();
    return 0;
}

void reg_asgn() {
    stack<string> pt(3);

    pt.push("1");
    pt.push("2");
    pt.push("3");
    pt.push("4");
    cout << "The top element is " << pt.peek() << endl;
    pt.push("5");
    pt.push("6");
    pt.push("7");

    cout << "The stack size is " << pt.size() << endl;
    //cout << pt.size() << endl;
    while (!pt.isEmpty()) {
        pt.pop();
    }

    cout << "The top element is ";
    if (pt.peek() == " ") {}
    else
        cout << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl << endl;
}

void rev() {
    stack<char>pt;
    string str;
    cout << "Input string to check reverse" << endl;
    getline(cin, str);
    int len = str.length();

    string temp = "";
    //push 
    for (int i = 0; i < len; i++) {
        pt.push(str[i]);
    }
    //peek top
    for (int i = 0; i < len; i++) {
        temp += pt.peek();
        pt.pop();
    }
    cout << "reverse: " << temp << endl <<endl;
}

void pal() {
    stack<char>pt;
    string str;
    cout << "Input string to check Palindrome " << endl;
    getline(cin, str);
    int len = str.length();

    //push 
    for (int i = 0; i < len; i++) {
        pt.push(str[i]);
    }
    //pop & pal check
    int count = 0;
    for (int i = 0; i < len; i++) {
        //cout << "String " << pt.peek() << endl;
        if (str[i] != pt.peek()) {
            count++;
        }
        pt.pop();
        //cout << "Count " << count << endl;
    }
    if (count > 0)
        cout << "Not a Palindrome" << endl <<endl;
    else
        cout << "A Palindrome" << endl <<endl;
}