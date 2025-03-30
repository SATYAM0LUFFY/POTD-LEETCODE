#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;

    int findPrime(int a)
    {
        set<int> primes;
        for (int i = 2; i <= sqrt(a); i++)
        {
            while (a % i == 0)
            {
                primes.insert(i);
                a /= i;
            }
        }
        if (a > 1)
            primes.insert(a);
        return primes.size();
    }

    vector<int> findRanges(vector<int> &primeScore)
    {
        int n = primeScore.size();
        vector<int> rightGreater(n, 0), leftGreater(n, 0);
        stack<int> st;

        st.push(n - 1);
        rightGreater[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && primeScore[st.top()] <= primeScore[i])
                st.pop();
            rightGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();
        st.push(0);
        leftGreater[0] = -1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && primeScore[st.top()] < primeScore[i])
                st.pop();
            leftGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        vector<int> range(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftGreater[i] == -1)
                range[i] = i;
            else
                range[i] = i - leftGreater[i] - 1;
            if (rightGreater[i] == -1)
                range[i] += max(0, (n - i - 1));
            else
                range[i] += (rightGreater[i] - i - 1);
            range[i]++;
        }
        return range;
    }

    long long int findPower(int a, int b)
    {
        if (b == 1)
            return a;
        if (b % 2 == 0)
        {
            long long int x = findPower(a, b / 2);
            return ((x % mod) * (x % mod)) % mod;
        }
        else
        {
            long long int x = findPower(a, (b - 1) / 2);
            return (a * (x % mod) * (x % mod)) % mod;
        }
    }

    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> primeScore(n, 0);
        for (int i = 0; i < n; i++)
            primeScore[i] = findPrime(nums[i]);
        cout << "prime Score";
        for (int i = 0; i < n; i++)
            cout << primeScore[i] << " ";
        cout << endl;
        vector<int> range = findRanges(primeScore);
        long long int ans = 1;

        vector<vector<int>> num;
        for (int i = 0; i < n; i++)
            num.push_back({nums[i], range[i]});
        sort(num.begin(), num.end());
        cout << "range" << endl;
        for (int i = 0; i < n; i++)
            cout << range[i] << " ";
        int i = n - 1;
        while (k > 0)
        {
            ans = ((ans % mod) * (findPower(num[i][0], min(k, num[i][1])) % mod)) % mod;
            if (k > num[i][1])
                k -= num[i][1];
            else
                k = 0;
            i--;
        }
        return ans % mod;
    }
};

int main()
{
}