#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string word) {
    int b = 0;
    int e = word.size() - 1;

    while(b < e) {
        if(word[b] != word[e])
            return false;
        ++b;
        --e;
    }

    return true;
}

int main() {
    string word;
    cin >> word;

    string r = word;
    string l = word;

    int b = 0;
    int e = word.size();

    if(e == 1) {
        cout << word << word << endl;
        return 0;
    } 

    while(b < e) {
        if(word[b] == word[e-1]) {
            if(b == e-1) {
                string b1(1, word[b]);
                word.insert(e, b1);
                cout << word << endl;
                return 0;
            }

            ++b;
            --e;
        } else {
            string b1(1, word[b]);
            r.insert(e, b1);
            if(isPalindrome(r)) {
                cout << r << endl;
                return 0;
            }

            string e1(1, word[e-1]);
            l.insert(b, e1);
            if(isPalindrome(l)) {
                cout << l << endl;
                return 0;
            }

            break;
        }
    }

    if(b == e) {
        word.insert(e, "a");
        cout << word << endl;
        return 0;
    }

    cout << "NA" << endl;
}