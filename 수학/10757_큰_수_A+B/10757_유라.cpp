#include <iostream>
#include <string>
using namespace std;

void calNum(string n, string m) {
    int diff = m.size() - n.size();
    bool flag = false; // check carry or not
    string res;
    
    for (int i=n.size()-1; i>=0; i--) { // common parts
        int tmp = (m[i+diff]-'0') + (n[i]-'0'); // addition
        if (flag == true) tmp += 1; // carry

        if (tmp>=10) {
            res.insert(0, to_string(tmp%10)); // left after carry
            flag = true; 
        }
        else {
            res.insert(0, to_string(tmp));
            flag = false;
        }
    }

    if (diff != 0) { // if the lengths of two numbers are different
        for (int i=diff-1; i>=0; i--) {
            int tmp = (m[i] -'0');
            if (flag == true) tmp += 1;
       
            if (tmp>=10 && i!=0) { // at last digit, no need for carry.
                res.insert(0, to_string(tmp%10));
                flag = true; 
            }
            else {
                res.insert(0, to_string(tmp));
                flag = false;
            }
        }
    }
    
    if (flag == true) res.insert(0, "1"); // if the lengths of two numbers are same, carry here.

    cout << res;
    return;
}

int main(){
    string a, b;
    cin >> a >> b;

    int diff = a.size()-b.size(); // to simplify the code, fix 'a' as a larger number
    if (diff < 0)
        swap(a, b);

    calNum(b, a);

    return 0;
}
