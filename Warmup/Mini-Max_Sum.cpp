/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void miniMaxSum(vector<int> arr) {
    int length = arr.size();
    int smallest, biggest;
    biggest = 0;
    for (int i = 0; i < length; i++){
        if(arr[i] > biggest){
            biggest = arr[i];
        }
    }
    smallest = biggest;
    for (int i = 0; i < length; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    long sum1 = 0;
    long sum2 = 0;
    long sum3 = 0;
    for(int a = 0; a < length; a++){
        sum1 += arr[a];
    }
    sum3 = sum1-smallest;
    sum2 = sum1-biggest;
    
    cout << sum2 << " " << sum3;
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
