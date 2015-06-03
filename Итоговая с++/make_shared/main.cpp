#include <bits/stdc++.h>

using namespace std;

void l(std::pair<string,int> it)
{
    cout << it.first << " => " << it.second << '\n';
}

class functor
{

public:

    map<string, int> &m; //ќ„≈Ќ№! важно что ссылка

    void operator() (const string& c)
    {
        ++m[c];
    }

    functor (map<string, int>& m2):m(m2){};
};

int main()
{
    assert(freopen("map.in", "r", stdin));
    assert(freopen("map.out", "w", stdout));
    ios::sync_with_stdio(0);

    map<string, int> a;
    istream_iterator<string> begin1((cin));
    istream_iterator<string> end1;
    functor f(a);
    for_each(begin1, end1, f);

    for_each(a.begin(), a.end(), l);

}
