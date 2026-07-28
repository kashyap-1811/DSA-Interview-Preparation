#include <bits/stdc++.h>
using namespace std;

int findDiff(char a, char b) {
    if (b >= a) return b - a;
    return 'z'-a+b-'a';
}

string decrypt(const string &cipher, const string &knownWord) {
    string c = cipher;
    string kWord = knownWord;

    stringstream ss(c);
    string word;

    int count = -1;
    for (char &c : kWord)
        tolower(c);
    
    while (ss >> word)
    {
        /* code */
        if (word.size() != kWord.size())
            continue;
        
        for (char &c : word)
            tolower(c);
        
        int diff = findDiff(kWord[0], word[0]);
        for (int i = 1; i < word.size(); i++) {
            if (findDiff(kWord[i], word[i]) != diff) {
                diff = -1;
                break;
            }
        }

        if (diff != -1) {
            count = diff;
            break;
        }
    }

    if (count == -1)
        return "Invalid";
    
    string ans = cipher;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= 'a' && ans[i] <= 'z') {
            ans[i] -= count;
            if (ans[i] < 'a')
                ans[i] += 26;
        } else {
            ans[i] -= count;
            if (ans[i] < 'A')
                ans[i] += 26;
        }
    }

    return ans;
}

int main()
{
    string cipher;
    cin >> cipher;

    string word;
    cin >> word;

    cout << decrypt(cipher, word);
    return 0;
}