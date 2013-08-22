#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector< vector<int> > read_lists() {
    int t;
    vector< vector<int> > lists;

    cin >> t;
    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> list;
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            list.push_back(x);
        }
        lists.push_back(list);
    }
    return lists;
};

void print_lists(vector< vector<int> > lists) {
    for (vector< vector<int> >::iterator it=lists.begin(); it != lists.end(); ++it) {
        for (vector<int>::iterator it2=(*it).begin(); it2 != (*it).end(); ++it2) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
};

vector<int> insertion_sort(vector<int> list) {
    if (list.size() <= 1) { return list; }
    for (int i=1; i<=list.size()-1; i++) {
        int elem = list[i];
        int k = i - 1;
        while (k >= 0 && list[k] > elem) {
            list[k+1] = list[k];
            k -= 1;
        }
        list[k+1] = elem;
    }

    return list;
}

int main() {
    vector< vector<int> > lists;
    lists = read_lists();
    for (vector< vector<int> >::iterator it = lists.begin(); it != lists.end(); ++it) {
        *it = insertion_sort(*it);
    }

    print_lists(lists);
    return 0;
}
