#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string en_flag = "\x77\x4d\x49\x44\x4b\x44\x4c\x4b\x34\x85\x88\x38\x3c\x8b\x8b\x3d\x27\x22\x29\x59\x5c\x2b\x26\x2f\x17\x19\x67\x66\x1b\x1f\x17\x6f";
string buf = "mssctf{This_is_a_fake_flag_hhhh}";
//string flag="mssctf{e93418672ab02ce5523ab38355ab179c}";

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