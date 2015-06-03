#include <bits/stdc++.h>

using namespace std;

int i, j;

class functor
{

public:

    vector<vector int> &m; //ќ„≈Ќ№! важно что ссылка

    void operator() (const char& c)
    {
        if (c != '\n')
        {
            a[i][j] =
        }
    }

    functor (int** a):m(a){};
};

int main()
{
    vector<vector int> a;

    a.resize(100);
    assert(freopen("dfs.in", "r", stdin));
    assert(freopen("dfs.out", "w", stdout));
    ios::sync_with_stdio(0);

    istream_iterator<string> begin1((cin));
    istream_iterator<string> end1;
    functor f(a);
    for_each(begin1, end1, f);

    for_each(a.begin(), a.end(), l);

}
