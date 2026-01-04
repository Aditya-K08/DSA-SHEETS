#include <bits/stdc++.h>

using namespace std;

int calculateCombinations(char arr[], int n);

int main() 
{
    string inputAshok, inputAnand;
    getline(cin, inputAshok);
    getline(cin, inputAnand);
    

    char ashokArray[inputAshok.length()];
    char anandArray[inputAnand.length()];

    strcpy(ashokArray, inputAshok.c_str());
    strcpy(anandArray, inputAnand.c_str());

    int cntAshok = calculateCombinations(ashokArray, inputAshok.length());
    int cntAnand = calculateCombinations(anandArray, inputAnand.length());

    if (cntAshok == 0 && cntAnand == 0)
        cout << "Invalid input";
    if (cntAshok > cntAnand)
        cout << "Ashok";
    else if (cntAnand > cntAshok)
        cout << "Anand";
    else 
        cout << "Draw";

    return 0;
}

int calculateCombinations(char arr[], int n)
{
    int cnt = 0;
    string currentCombination = "";

    for (int i = 0; i < n; i++)
    {
        currentCombination = "";
        currentCombination += arr[i];

        for (int j = i + 1; j < n; j++)
        {
            currentCombination += arr[j];

            if (currentCombination[0] != arr[j])
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (currentCombination[1] != arr[k])
                        cnt++;
                }
            }
            currentCombination = arr[i];
        }
    }
    return cnt;
}
