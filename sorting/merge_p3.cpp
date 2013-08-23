#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> Vector;
typedef vector< Vector > VVector;


Vector read_vector() {
    int n;
    Vector v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    return v;
}

VVector read_vector_vector() {
    int m;
    VVector vectors;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        Vector v;
        v = read_vector();
        vectors.push_back(v);
    }
    return vectors;
}

void print_vector(Vector v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}

void print_vector_vector(VVector v) {
    for (int i = 0; i < v.size(); ++i) {
        print_vector(v[i]);
    }
}

void merge(Vector &v, int i, int mid, int j, unsigned long long &swaps) {
    int x = i;
    int y = mid + 1;
    Vector aux;
    while (x <= mid && y <= j) {
        if (v[x] <= v[y]) {
            aux.push_back(v[x]);
            ++x;
        } else {
            aux.push_back(v[y]);
            ++y;
            swaps += mid - x + 1;
        }
    }
    if (x <= mid) {
        for (x; x <= mid; ++x) {
            aux.push_back(v[x]);
        }
    }
    if (y <= j) {
        for (y; y <= j; ++y) {
            aux.push_back(v[y]);
        }
    }
    for (int k = i; k <= j; ++k) {
        v[k] = aux[k - i];
    }
}

void merge_sort(Vector &v, int i, int j, unsigned long long &swaps) {
    if (i < j) {
        int mid = floor((i + j) / 2);
        merge_sort(v, i, mid, swaps);
        merge_sort(v, mid + 1, j, swaps);
        merge(v, i, mid, j, swaps);
    }
}

int main() {
    vector <int> res;
    VVector v;
    v = read_vector_vector();
    for (int i = 0; i < v.size(); ++i) {
        unsigned long long swaps = 0;
        merge_sort(v[i], 0, v[i].size() - 1, swaps);
        res.push_back(swaps);
    }
    print_vector(res);
    return 0;
}
