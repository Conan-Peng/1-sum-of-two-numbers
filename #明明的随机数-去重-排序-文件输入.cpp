#include<iostream>
#include<set>
#include<vector>

using namespace std;

void modif(vector<int> vec){
    if (vec.empty()) return;
    set<int> st;
    for (int i = 0; i < vec.size(); i++)
    {
        st.insert(vec[i]);
    }
    for (auto iter = st.begin(); iter != st.end(); iter++)
    {
        cout << *iter << endl;
    }
}

int main(){
    int n;
    vector<int> vec;
    while ((cin >> n).eof() != true)
    { 
        vec.push_back(n);
    }

    while (!vec.empty())
    {
        vector<int> vec1(vec.begin()+1, vec.begin()+vec[0]+1);
        vec.erase(vec.begin(), vec.begin()+vec[0]+1);
        modif(vec1);
    }
    return 0;
}
