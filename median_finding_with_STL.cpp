#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

multiset <int> smaller, larger;

void balance() {
    if (smaller.size() > larger.size() + 1) {
        larger.insert(*smaller.rbegin());
        smaller.erase(smaller.find(*smaller.rbegin()));
    } else
    if (larger.size() > smaller.size() + 1) {
        smaller.insert(*larger.begin());
        larger.erase(larger.begin());
    }
}

void print() {
    cout << "smaller: ";
    for (auto x: smaller) {
        cout << x << " ";
    }
    cout << endl;
    cout << "larger: ";
    for (auto x: larger) {
        cout << x << " ";
    }
    cout << endl << endl;
}

void add(int x) {
    if (smaller.empty())
        smaller.insert(x);
    else {
        if (!larger.empty() && *larger.begin() < x)
            larger.insert(x);
        else
            smaller.insert(x);
    }
    balance();
    //print();
}

int median() {
    int l = *smaller.rbegin(), r = *larger.begin();
    if ((smaller.size() + larger.size()) % 2 == 1) {
        if (smaller.size() > larger.size())
            return l * 2;
        else
            return r * 2;
    } else
        return l + r;
}

void remove(int x) {
    if (smaller.find(x) != smaller.end())
        smaller.erase(smaller.find(x));
    else
        larger.erase(larger.find(x));
    balance();
}

int n, d, i, notifications, x[202000];

int main() {
    
    cin >> n >> d;
    for (i = 0; i < n; i++) {
        cin >> x[i];
        if (i >= d) {
            if (x[i] >= median())
                notifications++;
            remove(x[i - d]);
        }
        add(x[i]);
    }
    
    cout << notifications;
    return 0;
}
