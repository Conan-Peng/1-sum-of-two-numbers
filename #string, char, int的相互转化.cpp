#include<iostream>
#include<string>

using namespace std;

int main(){
    // char, string, int之间的相互转换
    // char2string: s.push_back(ch)
    // char2int: ch - '0'
    // string2int: s[0] - '0' 
    // int2string: s.push_back(char(i + '0'))
    // int2char: char(i + '0')
    // string2char: s[0]
    int t = 9;
    char ch = '9';
    int k = ch - '0';
    string s = "1", str;
    str.push_back(ch); //可以理解为一个技术栈，新来的C++类型string向下兼容老旧的C类型char
    ch = s[0]; //char向上兼容string
    cout << " int " << t << " char " << char('0' + t) << " string " << to_string(t) << endl;
    cout << " char2int " << k << " string2char " << ch << " char2string " << str << endl;
    return 0;
}
