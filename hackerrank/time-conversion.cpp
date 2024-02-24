#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s)
{
    // convert 12-hours clock to 24-hours clock
    // 12:00:00AM -> 00:00:00
    // 12:00:00PM -> 12:00:00

    string hour = s.substr(0, 2);
    string minute = s.substr(3, 2);
    string second = s.substr(6, 2);
    string ampm = s.substr(8, 2);

    if (ampm == "AM")
    {
        if (hour == "12")
        {
            hour = "00";
        }
    }
    else
    {
        if (hour != "12")
        {
            hour = to_string(stoi(hour) + 12);
        }
    }

    return hour + ":" + minute + ":" + second;
}

int main()
{

    return 0;
}
