
//C.J.K.学员管理系统(CSMS)
//CSMS: C.J.K._Scholars_Management_System
//Ownship:Confraternity of Jankers of Keyboard (C.J.K.)
//Written by 1724834368@qq.com

//////////预处理//////////
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h> 
using namespace std;
////////////////////////

//////////常量定义//////////
string Head_Str="=====C.J.K.学员管理系统(CSMS)=====\n\n";
string Please_Input_Number="\n>>请输入对应数字执行操作：\n";
string Unknown_Error=">>未知错误！\n";
string Found_Yes="\n查找成功！\n";
string Found_Not="\n查找失败！\n"; 
//////////////////////////

//////////学员信息结构体//////////
class SDs {
    //SD:Scholars_Data
public:
	void printall() {
		cout<<"姓名："<<Name<<endl
		    <<"性别："<<Sex<<endl
			<<"编号："<<Number<<endl 
			<<"头衔："<<Titles<<endl 
			<<"语言："<<Languages<<endl 
			<<"积分："<<Exp<<endl 
			<<"备注："<<Note<<endl
			<<endl; 
	}
	
    string Name;      //姓名
    string Sex;       //性别
    string Number;    //编号
    string Titles;    //头衔
    string Languages; //语言
    string Exp;       //积分
    string Note;      //备注
};

vector<SDs> SDV;  //学员数据容器
SDs SDM;          //学员数据组员
///////////////////////////////

//////////头部函数声明//////////
void SLP();  //系统加载页面
int SLR();  //系统密码锁 
void LSD();  //载入学员数据
int MMP();   //主菜单页面
void GSD();  //查询学员信息 
void CSD();  //更改学员信息
void ADSD(); //增删学员信息 
void SSD();  //保存学员数据
void Over(); //结束程序 
void OKEND();//回车或换行结束 
void OKCONTINUE();//回车或换行继续 
//////////////////////////////

//////////主函数//////////
int main() {
	
	if(!SLR()) return 0;
	LSD();
    SLP();
    Main_MMP_Begin:
    int Model=MMP();
    switch(Model) {
        case 48:
        	system("cls");
            SSD();
            Over();
            return 0;
            break;
        case 49:
        	system("cls");
        	GSD();
        	goto Main_MMP_Begin;
        	break;
        case 50:
		    system("cls");
        	CSD();
        	goto Main_MMP_Begin;
        	break;
        case 51:
        	system("cls");
        	ADSD();
        	goto Main_MMP_Begin;
        	break;
        default:
        	cout<<Unknown_Error;
        	Sleep(2000);
        	break;
    }

    return 0;
}
/////////////////////////

//////////尾部函数定义//////////
void SLP() {
    //SLP:System_Loading_Page
    system("color F9");
    cout<<Head_Str
        <<"系统加载中";
    for(int i=0;i<10;i++) {
        Sleep(300);
        cout<<'.';
    }
    cout<<"加载成功！"<<endl;
    Sleep(1000);
    system("cls");
}

int SLR() {
	cout<<Head_Str
	    <<"请输入密码:"<<endl;
	string Value;
	cin>>Value;
    const string Right_Key="eWtpnZONm5+bmA";
    const string Base64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char a;
    vector<int> k;
    for(int jsq=0;jsq<int(Value.size());jsq++) {
        a=Value[jsq];
        int s[8]={};
        for(int i=a,pos=7;i>0;i/=2,pos--) {
            s[pos]=i%2;
        }
        for(int i=0;i<8;i++) {
            k.push_back(s[i]);
        }
    }
    for(int i=0;i<int(k.size());i++) {
        k[i]=!k[i];
    }
    for(int i=0;i<int(k.size())-1;i++) {
        k[i]=k[i+1];
    }
    k[int(k.size())-1]=0;
    string Key="";
    for(int i=0,posb=0;i<int(k.size())/6;i++) {
        int l[6]={};
        for(int posa=0;posa<6;posa++,posb++) {
            l[posa]=k[posb];
        }
        int ans=l[0]*32+l[1]*16+l[2]*8+l[3]*4+l[4]*2+l[5];
        Key.push_back(Base64[ans]);
    }
    if(int(k.size())/6*6!=int(k.size())) {
        int ls[6]={};
        for(int i=int(k.size())-1,j=5;i>=int(k.size())/6*6;j--,i--) {
            ls[j]=k[i];
        }
        int ans=ls[0]*32+ls[1]*16+ls[2]*8+ls[3]*4+ls[4]*2+ls[5];
        Key.push_back(Base64[ans]);
    }
    bool yes=Key==Right_Key; 
}

void LSD() {
    //LSD:Load_Scholars_Data
    ifstream fin;
    fin.open("CJK_Scholars_Data.txt",ios::in);
    while(fin>>SDM.Name>>SDM.Sex>>SDM.Number>>SDM.Titles>>SDM.Languages>>SDM.Exp>>SDM.Note) {
        SDV.push_back(SDM);
    }
    fin.close();
}

int MMP() {
    //MMP:Main_Meun_Page
    system("cls");
    cout<<Head_Str
        <<"【主菜单】"<<endl
        <<"0.保存并退出"<<endl
        <<"1.查询学员信息"<<endl
		<<"2.更改学员信息"<<endl
		<<"3.增删学员信息"<<endl;
    cout<<Please_Input_Number;
    Cin_Model_MMP:
    int Model;
    fflush(stdin);
    Model=getch();
    if(Model<48||Model>51) {    	
        goto Cin_Model_MMP;
    }
    return Model;
}

void GSD() {
	//GSD:Get_Scholars_Date
	cout<<Head_Str
        <<"【查询学员信息】"<<endl
        <<"0.返回主菜单"<<endl
        <<"1.查询全部学员信息"<<endl
		<<"2.查询指定姓名学员信息"<<endl
		<<"3.查询指定编号学员信息"<<endl;
    cout<<Please_Input_Number;
    Cin_Model_GSD:
    int Model;
    fflush(stdin);
    Model=getch();
    if(Model<48||Model>51) {
        goto Cin_Model_GSD;
    }
    switch(Model) {
    	case 48:break;
    	case 49: {
    		system("cls");
    		cout<<Head_Str
                <<"【查询全部学员信息】"<<endl<<endl;
			for(int i=0;i<int(SDV.size());i++) {
				SDV[i].printall();
				Sleep(100);
			}
			OKEND();
			break;
		}
		case 50: {
			system("cls");
    		cout<<Head_Str
                <<"【查询指定姓名学员信息】"<<endl<<endl;
            cout<<"请输入学员姓名:"<<endl;
            string name;
            cin>>name;
            for(int i=0;i<int(SDV.size());i++) {
            	if(SDV[i].Name==name) {
            		cout<<Found_Yes<<endl;
            		Sleep(300);
            		SDV[i].printall();
            		goto Find_End1;
                }
			}
			cout<<Found_Not<<endl;
			Find_End1:
            OKEND();
			break;
		}
		case 51: {
			system("cls");
    		cout<<Head_Str
                <<"【查询指定编号学员信息】"<<endl<<endl;
            cout<<"请输入学员编号:"<<endl;
            string number;
            cin>>number;
            for(int i=0;i<int(SDV.size());i++) {
            	if(SDV[i].Number==number) {
            		cout<<Found_Yes<<endl;
            		Sleep(300);
            		SDV[i].printall();
            		goto Find_End2;
                }
			}
			cout<<Found_Not<<endl;
			Find_End2:
            OKEND();
			break;
		}
	}
}

void CSD() {
	//CSD:Change_Scholars_Data
	cout<<Head_Str
        <<"【更改学员信息】"<<endl
        <<"0.返回主菜单"<<endl
        <<"1.继续更改学员信息"<<endl;
    cout<<Please_Input_Number;
    Cin_Model_CSD:
    int Model;
    fflush(stdin);
    Model=getch();
    if(Model<48||Model>49) {
        goto Cin_Model_CSD;
    }
    switch(Model) {
    	case 48: break;
    	case 49: {
    		Begin_CSD_49:
    		system("cls");
    		cout<<Head_Str
       		    <<"【更改学员信息】"<<endl<<endl;
       		cout<<">>请输入学员姓名或编号:"<<endl;
       		string nameornumber;
       		cin>>nameornumber;
       		int pos;
       		for(int i=0;i<int(SDV.size());i++) {
            	if(SDV[i].Number==nameornumber||SDV[i].Name==nameornumber) {
            		cout<<Found_Yes<<endl;
            		pos=i;
            		Sleep(1000);
					system("cls");
					cout<<Head_Str
       		    		<<"【更改学员信息】"<<endl<<endl;
            		Sleep(300);
            		SDV[i].printall();
            		goto Find_End3;
                }
			}
			cout<<Found_Not<<endl;
			cout<<"按回车或换行返回主菜单，其他键重新查找:\n";
			while(1) {
				char a=getch();
				if(a=='\n'||a=='\r') break;
				else goto Begin_CSD_49;
			}
			Find_End3:
			cout<<endl
				<<"请输入需要更改的信息项:\n";
			string need_change;
			cin>>need_change;
			//此处存在运行bug/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
			if(need_change=="姓名"||need_change=="性别"||need_change=="编号"||need_change=="头衔"||need_change=="语言"||need_change=="积分"||need_change=="备注") {
			} else {
				cout<<"\n该信息项不存在！"<<endl
						<<"按1重新输入，其他键返回主菜单"<<endl; 
				if(getch()=='1') {
					goto Find_End3;
				} else {
					break;
				}
			}
			cout<<endl
			    <<"请输入新的信息内容(请勿包含空格):\n";
			string new_content;
			cin>>new_content;
			if(need_change=="姓名") {
				SDV[pos].Name=new_content;
			} else if(need_change=="性别") {
				SDV[pos].Sex=new_content;
			} else if(need_change=="编号") {
				SDV[pos].Number=new_content;
			} else if(need_change=="头衔") {
				SDV[pos].Titles=new_content;
			} else if(need_change=="语言") {
				SDV[pos].Languages=new_content;
			} else if(need_change=="积分") {
				SDV[pos].Exp=new_content;
			} else if(need_change=="备注") {
				SDV[pos].Note=new_content;
			}
			cout<<"\n修改成功！\n"; 
			OKEND();
			break;
		} 
	}
}

void ADSD() {
	//ADSD:Add_or_Delete_Scholars_Data
	cout<<Head_Str
        <<"【增删学员信息】"<<endl
        <<"0.返回主菜单"<<endl
        <<"1.新增学员信息"<<endl
		<<"2.删除学员信息"<<endl;
    cout<<Please_Input_Number;
    Cin_Model_ADSD:
    int Model;
    fflush(stdin);
    Model=getch();
    if(Model<48||Model>50) {
        goto Cin_Model_ADSD;
    }
    switch(Model) {
    	case 48:break;
    	case 49: {
    		Begin_ADSD_49:
    		system("cls");
    		cout<<Head_Str
       		    <<"【新增学员信息】"<<endl<<endl;
       		string Cin_Data="无";
       		cout<<"\n>>请根据提示逐步输入新学员信息\n";
       		cout<<"\n姓名:";
			cin>>Cin_Data;
			SDM.Name=Cin_Data;
			cout<<"性别:";
			cin>>Cin_Data;
			SDM.Sex=Cin_Data;
			cout<<"编号:";
			cin>>Cin_Data;
			SDM.Number=Cin_Data;
			cout<<"头衔:";
			cin>>Cin_Data;
			SDM.Titles=Cin_Data;
			cout<<"语言:";
			cin>>Cin_Data;
			SDM.Languages=Cin_Data;
			cout<<"积分:";
			cin>>Cin_Data;
			SDM.Exp=Cin_Data;
			cout<<"备注:";
			cin>>Cin_Data;
			SDM.Note=Cin_Data;
			cout<<"\n>>请仔细检查确认输入信息无误，按1键重新输入，按其他键保存:\n"; 
       		if(getch()=='1') {
       			goto Begin_ADSD_49;
			}
			SDV.push_back(SDM);
			system("cls");
			cout<<Head_Str
       		    <<"【新增学员信息】"<<endl<<endl;
       		cout<<">>新增成功！\n\n";
       		Sleep(500);
			SDM.printall();
			Sleep(500);
			OKEND(); 
			break;
		}
		case 50: {
			Begin_ADSD_50:
			system("cls");
    		cout<<Head_Str
       		    <<"【删除学员信息】"<<endl<<endl;
       		    cout<<">>请输入学员姓名或编号:"<<endl;
       		string nameornumber;
       		cin>>nameornumber;
       		for(int i=0;i<int(SDV.size());i++) {
            	if(SDV[i].Number==nameornumber||SDV[i].Name==nameornumber) {
            		cout<<Found_Yes<<endl;
            		Sleep(1000);
					system("cls");
					cout<<Head_Str
       		    		<<"【删除学员信息】"<<endl<<endl;
            		Sleep(500);
            		SDV[i].printall();
            		cout<<"按1确认删除，按其他键取消删除并返回主菜单:\n";
					if(getch()=='1') {
						for(int j=i;j<int(SDV.size())-1;i++) {
							SDV[j]=SDV[i+1];
						}
						SDV.pop_back();
						cout<<"\n删除成功！\n";
						Sleep(1000);
						OKEND();
					}
					goto END666;
                }
			}
			cout<<Found_Not<<endl; 
			Sleep(500);
			cout<<">>按1重新查找，按其他键返回主菜单:\n";
			if(getch()=='1') goto Begin_ADSD_50;
			END666:
			break;
		}
    	default:break;
	}
}

void Over() {
    system("cls");
    cout<<Head_Str;
    cout<<">>保存并退出！"<<endl;
    Sleep(2000);
}

void SSD() {
    //Save_Scholars_Data
    ofstream fout;
    fout.open("CJK_Scholars_Data.txt",ios::out);
    for(int i=0;i<int(SDV.size());i++) {
    	fout<<SDV[i].Name<<endl; 
    	fout<<"    "<<SDV[i].Sex<<endl; 
    	fout<<"    "<<SDV[i].Number<<endl; 
    	fout<<"    "<<SDV[i].Titles<<endl; 
    	fout<<"    "<<SDV[i].Languages<<endl; 
    	fout<<"    "<<SDV[i].Exp<<endl; 
    	fout<<"    "<<SDV[i].Note<<endl; 
    	fout<<endl;
	}
	fout.close();
}

void OKEND() {
	cout<<"\n>>回车或换行返回主菜单..."<<endl;
			while(getch()!='\n'&&getch()!='\r') {}
}

void OKCONTINUE() {
	cout<<">>回车或换行继续..."<<endl;
			while(getch()!='\n'&&getch()!='\r') {}
}
//////////////////////////////
