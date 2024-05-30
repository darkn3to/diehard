#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(string pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    int len = 0;  // Length of the previous longest prefix suffix

    for (int i = 1; i < n; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();

    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;  // i for text index and j for pattern index
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "abaab";
    string pattern = "ab";
    KMP(text, pattern);
    return 0;
}
