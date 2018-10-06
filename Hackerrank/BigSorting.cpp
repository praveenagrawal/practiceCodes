#include <bits/stdc++.h>

using namespace std;

struct bigInt{
    string s;
    int siz;
    int index;
};

bool comp(bigInt i, bigInt j){
    return i.siz<j.siz;
}

bool compStr(bigInt i, bigInt j){
    return i.s<j.s;
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    vector <bigInt> strings(unsorted.size());
    for(int i=0;i<unsorted.size();i++){
        strings[i].siz = unsorted[i].size();
        strings[i].index = i;
        strings[i].s = unsorted[i];
    }
    sort(strings.begin(), strings.end(), comp);
    int prev = 0;
    for(int i=1;i<unsorted.size();i++){
        if(strings[i-1].siz !=strings[i].siz){
            sort(strings.begin()+prev,strings.begin()+i, compStr);
            prev = i;
        }
    }
    sort(strings.begin()+prev,strings.end(), compStr);
    vector <string> sorted(unsorted.size());
    for(int i=0;i<unsorted.size();i++){
        sorted[i] = strings[i].s;
    }
    return sorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
