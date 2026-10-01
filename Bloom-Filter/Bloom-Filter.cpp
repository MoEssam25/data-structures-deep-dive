#include <bits/stdc++.h>
#include "iostream"
#include "istream"

using namespace std;

/* TODO (idea): implement per the lesson description. */

bool Bits[64];

int sum(string input, bool Is_it_h1)
{
    int res = 0;
    if(Is_it_h1)
    {
        for (int i = 0; i < input.size(); i++)
            res += (int)input[i];
    }
    else{
        for (int i = 0; i < input.size(); i++)
            res += (int)input[i] * (i+1);
    }

    return res;
}

int h1(string input)
{
    return sum(input, true) % 64;
}

int h2(string input)
{
    return sum(input, false) % 64;
}

void CHECK(string input)
{
    int h1_c = h1(input);
    int h2_c = h2(input);

    if(Bits[h1_c] == 1 && Bits[h2_c] == 1)
    {
        printf("MAYBE\n");
        return;
    }
    printf("NO\n");
}

void ADD(string input)
{
    int h1_c = h1(input);
    int h2_c = h2(input);
    Bits[h1_c] = 1;
    Bits[h2_c] = 1;

    printf("OK\n");
}

// Optimizing m, k for a target false-positive rate p

// OPTIMAL Smallest number of bits m achieving a target false-positive
int M_opt(int n, double p)
{
    return (int)ceil((-n * std::log(p))/(pow(log(2.0),2)));
}

// OPTIMAL Number of hash functions at the chosen m:
int K_opt(int n, int m)
{
    return (int)round((m/(double)n) * (log(2.0)));
}

// Compute the Bloom filter false-positive rate math.    
double Fp_rate(int n, int m, int k)
{
    double x = (double)k * n / m;

    return pow(1.0 - exp(-x), k);
}

//(Bits Per Item) Number of bits per item needed to reach a target FP rate p:
double BPI(int p)
{
    double ln2 = log(2.0);
    return log(p) / (ln2 * ln2);
}

// Split the sentence into words 
vector<string> split_sentence(string sen)
{
    

}

int main(void) {

    for (int i = 0; i < 64; i++)
        Bits[i] = 0;

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        
        string cmd;
        
        iss >> cmd;

        string rest;
        iss >> std::ws;
        getline(iss, rest);
        
    }

    

    return 0;
}