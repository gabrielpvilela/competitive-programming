#include <bits/stdc++.h>
using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};

const int MAXLEN = 200000 + 10;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;

    while(p != - 1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if(p == -1) {
        st[cur].link = 0;
    }
    else {
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            
            while(p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }

            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int minstr(string &T) {
    int ans = 1;
    int atual = 0;

    for(char c : T) {
        if(st[atual].next.count(c))
            atual = st[atual].next[c];
        else {
            ans++;
            atual = 0;
            if(st[0].next.count(c))
                atual = st[0].next[c];
            else
                return -1;
        }
    }
    return ans;
}

int main() {

    string S, T;
    cin >> S;

    sa_init();
    for(char c : S) {
        sa_extend(c);
    }

    int n;
    cin >> n;
    while(n--) {
        cin >> T;
        int min = minstr(T);
        cout << min << endl;
    }

    
    return 0;
}