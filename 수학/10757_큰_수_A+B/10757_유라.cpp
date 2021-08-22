#include <iostream>
#include <string>
using namespace std;

string calNum(string n, string m) {
    int diff = m.size() - n.size();
    bool flag = false;
    string res;
    
    for (int i=n.size()-1; i>=0; i--) {
        int tmp = (m[i+diff]-'0') + (n[i]-'0');
        if (flag == true) tmp += 1;

        if (tmp>=10) {
            res.insert(0, to_string(tmp%10));
            flag = true; 
        }
        else {
            res.insert(0, to_string(tmp));
            flag = false;
        }
    }

    for (int i=diff-1; i>=0; i--) {
        int tmp = (m[i] -'0');
        if (flag == true) tmp += 1;
       
        if (tmp>=10 && i!=0) {
            res.insert(0, to_string(tmp%10));
            flag = true; 
        }
        else {
            res.insert(0, to_string(tmp));
            flag = false;
        }
    }

    return res;
}

int main() {
    string a, b, c;
    cin >> a >> b;

    // string to char array
    bool flag = false;
    int tmp = 0;

    if (a.size() == b.size()) {
        for (int i=a.size()-1; i>=0; i--) {
            tmp =(a[i]-'0') + (b[i]-'0'); // char to int : char - '0'
            if (flag == true) tmp += 1;
            
            if (tmp>=10 && i!=0) {
                c.insert(0, to_string(tmp%10));
                flag = true; 
            }
            else {
                c.insert(0, to_string(tmp));
                flag = false;
            }
        }
    }
    else if (a.size() > b.size())
        c = calNum(b, a);
    else
        c = calNum(a, b);

    cout << c;
    return 0;
}