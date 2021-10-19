#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string en_flag = "mssctf{please_set_a_flag}";
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