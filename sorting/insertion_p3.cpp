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

int insertion_sort(vector< vector<int> >::iterator list) {
    int swaps = 0;
    if ((*list).size() <= 1) { return swaps; }
    for (int i=1; i<=(*list).size()-1; i++) {
        int elem = (*list)[i];
        int k = i - 1;
        while (k >= 0 && (*list)[k] > elem) {
            (*list)[k+1] = (*list)[k];
            k -= 1;
            swaps += 1;
        }
        (*list)[k+1] = elem;
    }
    return swaps;
}

int main() {
    vector <int> res;
    vector< vector<int> > lists;
    lists = read_lists();
    for (vector< vector<int> >::iterator it = lists.begin(); it != lists.end(); ++it) {
        res.push_back(insertion_sort(it));
    }
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
