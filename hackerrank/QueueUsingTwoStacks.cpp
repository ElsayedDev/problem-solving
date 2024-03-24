#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue
{
private:
    stack<T> s1, s2;

public:
    void enqueue(T x) { s1.push(x); }

    void dequeue()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    T front()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};
