#include<iostream>
#include<cstdlib>
using namespace std;

int max(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int lcs(string a, string b) {
    int m = a.size();
    int n = b.size();
    
    int* prev_row = new int[n+1];
    int* curr_row = new int[n+1];
    
    for (int i = 0; i <= n; i++)
        prev_row[i] = 0;
    
    for (int i = 1; i <= m; i++) {
        curr_row[0] = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                curr_row[j] = prev_row[j-1] + 1;
            } else {
                curr_row[j] = max(prev_row[j], curr_row[j-1]);
            }
        }
        
        for (int i = 0; i <= n; i++)
            cout << prev_row[i] << " ";
        cout << endl;
        
        for (int i = 0; i <= n; i++)
            prev_row[i] = curr_row[i];
    }
    
    int result = curr_row[n];
    delete[] prev_row;
    delete[] curr_row;
    
    return result;
}

int main() {
    string a = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string b = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    
    cout << lcs(a, b);
    return 0;
}
