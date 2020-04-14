#include<iostream>
#include<vector>

using namespace std;

void bubble(vector<int> vec){    
    for (int i = 0; i < vec.size(); i++)
    {
        int sum = 0;
        int left = vec[i];
        do
        {
            if (left == 2)
            {
                sum++; 
                break;
            }
            sum += left/3;
            left = left/3 + left%3;
            
        } while (left != 0 && left != 1);
        cout << sum << endl;
    }
}

int main(){
    int n;
    vector<int> vec;
    while ((cin >> n) && n)
    {
        vec.push_back(n);
    }
    bubble(vec);
    return 0;
}
