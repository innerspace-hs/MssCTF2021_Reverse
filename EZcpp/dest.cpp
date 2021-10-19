#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string en_flag = "\x43\x72\x42\x48\x51\x7e\x80\x50\x83\x32\x87\x40\x8c\x3a\x8f\x91\x25\x59\x22\x56\x22\x5a\x2c\x29\x1b\x16\x67\x64\x70\x1d\x21\x21";
string buf = "mssctf{This_is_a_fake_flag_hhhh}";

int main() {
    string input;
    
    cout << "[EZcpp] welcome to mssctf2021" << endl;
    cout << "please input your password and I will check it" <<endl;
    cout << "input : " ;
    cin >> input ;
    for (int i=0;i<32;i++){
        buf.at(i) = (input.at(i) ^ i + i) + 18;
    }
    if(buf == en_flag){
        cout << "Congratulations!!!" << endl;
        cout << "Here is your flag : mssctf{" << input << "}" << endl;
        Sleep(0xdeadbeef);
    }
    else{
        cout << "OHHH,you are wrong.Try again!" << endl;
        Sleep(0xdeadbeef);
    }
    return 0;
}