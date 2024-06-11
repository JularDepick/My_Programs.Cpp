/*
【代码版权声明】
    本程序代码由帅帅的李文芳撰写。
    禁止复制、抄袭本程序代码！
    如果你需要本程序代码为你服务，你得联系李文芳获取授权，邮箱为1724834368@qq.com.
    防伪标识码："SnVkZUJsYWNrRGVkaVBlbnNvbk1pbnBlbkp1bGFyRGVwaWNrQ2luaGFuQmFuamFuc0xpV2VuZmFuZD".
*/

//Written by liwenfang(Very Handsome)

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Note {
public:
    void Write_down(string time,string text) {
        Time=time;
        Text=text;
    }
    string get_time() {
        return Time;
    }
    string get_text() {
        return Text;
    }
protected:
    string Time;
    string Text;
}note;

string Head="————————Note————————\n\n";
string Please="\n>>请输入指令：\n";

int main() {
    ifstream fin;
    fin.open("Notes.txt",ios::in);
    Sleep(1000);
    vector<Note> Notes;
    string time,text;
    while(fin>>time>>text) {
        note.Write_down(time,text);
        Notes.push_back(note);
    }
    fin.close();
    system("color 33");
    Begin:
    system("cls");
    cout<<Head
        <<"0.保存并退出"<<endl
        <<"1.查看全部笔记"<<endl
        <<"2.新增笔记"<<endl
        <<"3.删除笔记"<<endl
        <<Please;
    int Model1;
    while(1) {
        Model1=getch();
        if(Model1>=48&&Model1<=51) break;
    }
    switch(Model1) {
        case 48: {
            system("cls");
            ofstream fout;
            fout.open("Notes.txt",ios::out);
            for(int i=0;i<int(Notes.size());i++) {
                fout<<Notes[i].get_time()<<endl;
                fout<<Notes[i].get_text()<<endl<<endl;
            }
            fout.close();
            getch();
            return 0;
            break;
        }
        case 49: {
            system("cls");
            cout<<Head<<endl;
            for(int i=0;i<int(Notes.size());i++) {
                cout<<i<<endl<<Notes[i].get_time()<<endl<<Notes[i].get_text()<<endl<<endl;
            }
            while(1) {
                char a=getch();
                if(a=='\n'||a=='\r') break;
            }
            break;
        }
        case 50: {
            system("cls");
            string name,time;
            cout<<Head
                <<"New's Time:"<<endl;
            cin>>name;
            cout<<endl<<endl<<"New's Text:" <<endl;
            cin>>text;
            note.Write_down(name,text);
            Notes.push_back(note);
            cout<<endl<<endl<<"Ok!";
            Sleep(1000);
            break;
        }
        case 51: {
            system("cls");
            int pos;
            cout<<Head
                <<"请输入索引(0起始):"<<endl;
            cin>>pos;
            if(pos>=int(Notes.size())) {
                cout<<"Error!";
                goto over223;
			}
            for(int i=pos;i<int(Notes.size())-1;i++) {
                Notes[i]=Notes[i+1];
            }
            Notes.pop_back();
            cout<<endl<<"Ok!";
            over223:
            Sleep(1000);
            break;
        }
    }
    while(1) {
        char a=getch();
        if(a=='\n'||a=='\r') break;
    }
    goto Begin;
    
    return 0;
}

