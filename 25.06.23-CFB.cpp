#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1005;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) 
	{
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
		{
            cin >> a[i];
        }

        bool found0 = false;
        for (int i = 0; i < n - 1; i++) 
		{
            if (abs(a[i] - a[i + 1]) <= 1) 
			{
                found0 = true;
                break;
            }
        }
        if (found0) 
		{
            cout << 0 << '\n';
            continue;
        }

        if (n == 2) 
		{
            cout << -1 << '\n';
            continue;
        }

        int min_val[MAXN], max_val[MAXN];
        for (int i = 0; i < n; i++) 
		{
            min_val[i] = a[i];
            max_val[i] = a[i];
        }

        int ans = -1;
        for (int L = 2; L <= n; L++) 
		{
            bool found_ans = false;
            for (int i = 0; i <= n - L; i++) 
			{
                int new_val = a[i + L - 1];
                min_val[i] = min(min_val[i], new_val);
                max_val[i] = max(max_val[i], new_val);

                bool flag = false;
                if (i > 0) 
				{
                    int left_val = a[i - 1];
                    if (max_val[i] >= left_val - 1 && min_val[i] <= left_val + 1) 
					{
                        flag = true;
                    }
                }
                if (!flag && i + L < n) 
				{
                    int right_val = a[i + L];
                    if (max_val[i] >= right_val - 1 && min_val[i] <= right_val + 1) 
					{
                        flag = true;
                    }
                }
                if (flag) 
				{
                    ans = L - 1;
                    found_ans = true;
                    break;
                }
            }
            if (found_ans) 
			{
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
