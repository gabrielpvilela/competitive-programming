#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string l1 = " ", l2 = " ";
    int i = 0;
    while(i < 2 && getline(cin, l2)) {
        if(l1 == " ") l1 = l2;
        i++;
    }
    
    //cout << l1 << endl << endl;

    string cmd;
    int j = 0;
    while(l1[j] != ' ' && l1[j] != '(') {
        //cout << 1 << endl;
        cmd += l1[j];
        j++;
    }

    if(cmd == "print") {
        int k = cmd.size() + 1;
        string var;
        while(k < l1.size() - 1) {
            var += l1[k];
            k++;
        }
        cout << "APRESENTE " << var << endl;
        return 0;
    }
    else if(cmd == "if") {
        int aux1 = cmd.size() + 1;
        string cond;
        while(l1[aux1] != ':') {
            cond += l1[aux1];
            aux1++;
        }
        cout << "SE " << cond << " ENTAO ";
        aux1 = 0;
        while(l2[aux1] == ' ') aux1++;
        if(l2.substr(aux1, 6) == "print(") {
            aux1 += 6;
            string var2;
            while(aux1 < l2.size() - 1) {
                var2 += l2[aux1];
                aux1++;
            }
            cout << "APRESENTE " << var2 << endl;
            return 0;
        }
        else {
            for(int i = aux1; i < l2.size(); i++) {
                if(l2[i] == '=' && l2.substr(i + 2, 5) == "input") {
                    string resp;
                    int j = aux1;
                    while(l2[j] != ' ') {
                        resp += l2[j];
                        j++;
                    }
                    cout << "LEIA " << resp << endl;
                    return 0;
                }
            }
        }
    }
    else if(cmd == "while") {
        int aux1 = cmd.size() + 1;
        string cond;
        while(l1[aux1] != ':') {
            cond += l1[aux1];
            aux1++;
        }
        cout << "ENQUANTO " << cond << " ";
        aux1 = 0;
        while(l2[aux1] == ' ') aux1++;
        if(l2.substr(aux1, 6) == "print(") {
            aux1 += 6;
            string var2;
            while(aux1 < l2.size() - 1) {
                var2 += l2[aux1];
                aux1++;
            }
            cout << "APRESENTE " << var2 << endl;
            return 0;
        }
        else {
            for(int i = aux1; i < l2.size(); i++) {
                if(l2[i] == '=' && l2.substr(i + 2, 5) == "input") {
                    string resp;
                    int j = aux1;
                    while(l2[j] != ' ') {
                        resp += l2[j];
                        j++;
                    }
                    cout << "LEIA " << resp << endl;
                    return 0;
                }
            }
        }
    }
    else {
        //cout << 2 << endl;
        for(int i = 0; i < l1.size(); i++) {
            //cout << 3 << endl;
            
            if(l1[i] == '=' && l1.substr(i + 2, 5) == "input") {
                string resp;
                int j = 0;
                while(l1[j] != ' ') {
                    //cout << 4 << endl;
                    resp += l1[j];
                    j++;
                }
                cout << "LEIA " << resp << endl;
                return 0;
            }
        }
    }
    
    return 0;
}