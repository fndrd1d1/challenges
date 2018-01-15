#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long int n;
    long int m;
    long int max = 0;
    cin >> n >> m;
    vector<long int> v(n + 1,0);

    long int a, b ,k;
        
    // idea:
    // 1. save the starting point of k as + value
    //    save the ending point + 1 as - value
    // 2. iterate over all n and add up these values
    //    save the max 

    // O(n + m)
    
    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> k;
        v[a] += k;
        if (b+1 <= n)
        {
            v[b+1] -= k;
        }
    }

    long int temp = 0;
    for(long int i = 1; i <= n; ++i)
    {
        temp = temp + v[i];
        if (max < temp)
        {
            max = temp;
        }
    }

    cout << max;
    
    return 0;
}
