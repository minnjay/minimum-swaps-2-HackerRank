#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr)
{
    
    // int swap=0;
    //     for(int i=0;i<a.size();i++){
    //         if(i+1!=a[i]){
    //             int t=i;
    //             while(a[t]!=i+1){
    //                 t++;  
    //             }
    //             int temp=a[t];
    //             a[t]=a[i];
    //             a[i]=temp;
    //             swap++;
    //         }
    //     }
    //     return swap;
    
    int total = 0;
    for(int i= 0; i<arr.size(); i++)
    {
        if(arr[i] != i+1)
        {   
            for(int a = i+1;a<arr.size();a++)
            {
                if(arr[a] == i+1)
                {
                    int temp = arr[a];
                    arr[a] = arr[i];
                    arr[i]= temp;
                    total ++;
                    break;
                }
                
            }
        }
        
    }
    
    return total;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
