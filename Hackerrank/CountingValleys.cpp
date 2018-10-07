#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int level = 0;
    int result = 0;
    int temp = 0;
    for(int i=0;i<n;i++){
        temp = level;
        if(s[i]=='U')
            level++;
        else
            level--;
        if(level==0 && temp<0)
            result++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
