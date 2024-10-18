#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    // Reading the input array
    for (int i = 0; i < n; i++)
	{
        cin >> v[i];
    }

    // Total number of subsets = 2^n
    int tot_sub = 1 << n;  // This is equivalent to pow(2, n)

    // Iterate over all subsets
    for (int i = 1; i < tot_sub; i++)
		{
        // For each bit in the bitmask, check if it is set
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {  // Fixed the missing parenthesis here
                cout << v[j] << " ";
            }
        }
        cout << endl;  // Move to the next line after printing one subset
    }

    return 0;
}
