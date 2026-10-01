#include <bits/stdc++.h>
#include "iostream"
#include "istream"

using namespace std;

// Split the sentence into words 
vector<string> split_sentence(string sen)
{
    stringstream ss(sen);
    
    string word;
    
    vector<string> words;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;

}


// First Task 


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

// Second Task 


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
double BPI(double p)
{
    double ln2 = pow(log(2),2);
    return -(log(p) / (ln2));
}


// Third Task 

int h_a(string input)
{
    int sum_output = 0;
    for (int i = 0; i < input.size(); i++) sum_output += (int)input[i] * (i+1);
    
    return sum_output & 0xFFFFFFFFu;
}

int h_b(string input)
{
    int sum_output = 0;
    for (int i = 0; i < input.size(); i++) sum_output += (int)input[i] xor (i+1);
    
    return sum_output & 0xFFFFFFFFu;
}


int h_i(string input)
{

}


int main(void) {

    for (int i = 0; i < 64; i++)
        Bits[i] = 0;

    string line;

    while (getline(cin, line)) {
        vector<string> words;
        words = split_sentence(line);

        if(words[0] == "OPTIMAL")
        {
            double target_fp = stod(words[1]);
            int expected_n = stoi(words[2]);

            int m = M_opt(expected_n, target_fp);
            int k = K_opt(expected_n, m);

            cout << "m=" << m << " k=" << k << '\n';

        }
        else if(words[0] == "FP")
        {
            int m = stoi(words[1]);
            int n = stoi(words[2]);
            int k = stoi(words[3]);

            cout << fixed << setprecision(6) << Fp_rate(n, m, k) << '\n';
        }   
        else if(words[0] == "BPI"){
            double target_fp = stod(words[1]);
            
            cout << fixed << setprecision(4) << BPI(target_fp) << '\n';
        }
    }

    return 0;
}