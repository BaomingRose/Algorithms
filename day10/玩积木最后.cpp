#include<iostream>
using namespace std;

long long a[60] = { 1, 2 };

long long int f(int n) {
    if(a[n])
        return a[n];
    return a[n] = f(n - 2) + f(n - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n) {
        cout << f(n - 1) << endl;
    }
    return 0;
}
