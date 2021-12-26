#include <bits/stdc++.h>

using namespace std;

long long bintodec(int *arr, int n)
{
    long long val = 0;
    for(int i = 0; i < n; i++)
        val += arr[i] * pow(2, n - i - 1);
    return val;
}
long long gcd(long long a, long long b)
{
    while(a % b != 0 && b % a != 0)
        if(a > b)
            a %= b;
        else b %= a;
    return min(a, b);
}
int highestPower(long long a)
{
    int i = 0;
    while(a != 0)
    {
        a /= 2;
        i++;
    }
    return i;
}
long long countChanges(long long a)
{
    int i = 1;
    long long sum = 0;
    while(a != 0)
    {
        sum += (a / 2 + a % 2)  * i;
        a /= 2;
        i++;
    }
    return sum;
}

int main()
{
    long long k = 0, n = 0;
    cin >> k;
    int *arr = new int[k];
    for(int i = 0; i < k; i++)
        cin >> arr[i];
    cin >> n;
    long long start = bintodec(arr, k);
    long long counter = 0;
    counter = countChanges(start + n) - countChanges(start);
    cout << highestPower(start ^ (start + n)) << endl;
    cout << counter / gcd(counter, n) << "/" << n / gcd(counter, n) << endl;
    return 0;
}
