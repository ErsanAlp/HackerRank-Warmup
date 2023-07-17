/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,2));
    int sec = stoi(s.substr(6,2));
    string ns;
    if (s.substr(8,1) == "P" && hour != 12) {
        hour += 12;
        string h = to_string(hour);
        ns = h + ":" + s.substr(3,2) + ":" + s.substr(6,2);
        return ns;   
    }
    else if (s.substr(8,1) == "A" && hour != 12) {
        ns = s.substr(0,2) + ":" + s.substr(3,2) + ":" + s.substr(6,2);
        return ns; 
    }
    else if (s.substr(8,1) == "P" && hour == 12) {
        ns = s.substr(0,2) + ":" + s.substr(3,2) + ":" + s.substr(6,2);
        return ns; 
    }
    else {
        ns = "00:" + s.substr(3,2) + ":" + s.substr(6,2);
        return ns; 
    }     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
