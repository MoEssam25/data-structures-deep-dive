#include <bits/stdc++.h>
#include "iostream"
#include "istream"

using namespace std;

/* TODO (idea): implement per the lesson description. */

bool Bits[64];

int sum(string input, int n, bool Is_it_h1)
{
    int res = 0;
    if(Is_it_h1)
    {
        for (int i = 0; i < n; i++)
            res += (int)input[i];
    }
    else{
        for (int i = 0; i < n; i++)
            res += (int)input[i] * (i+1);
    }

    return res;
}

int h1(string input, int n)
{
    return sum(input, n, true) % 64;
}

int h2(string input, int n)
{
    return sum(input, n, false) % 64;
}

void CHECK(string input, int n)
{
    int h1_c = h1(input, n);
    int h2_c = h2(input, n);

    if(Bits[h1_c] == 1 && Bits[h2_c] == 1)
    {
        printf("MAYBE\n");
        return;
    }
    printf("NO\n");
}

void ADD(string input, int n)
{
    if(n < 0)
    {
        printf("Error, no input\n");
        return;
    }
    int h1_c = h1(input, n);
    int h2_c = h2(input, n);
    Bits[h1_c] = 1;
    Bits[h2_c] = 1;

    printf("OK\n");
}

int main(void) {

    for (int i = 0; i < 64; i++)
        Bits[i] = 0;

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        
        string cmd;
        
        iss >> cmd;

        if(cmd.empty()) continue;

        string rest;
        iss >> std::ws;
        getline(iss, rest);
        
        if(rest.empty())
        {
            for (int i = 0; i < 64; i++)
                cout << Bits[i];
            break;
        }

        if(cmd == "ADD"){
            ADD(rest, rest.length());
        }
        else if(cmd == "CHECK"){
            CHECK(rest, rest.length());
        }
    }

    return 0;
}