
//C.J.K.ѧԱ����ϵͳ(CSMS)
//CSMS: C.J.K._Scholars_Management_System
//Ownship:Confraternity of Jankers of Keyboard (C.J.K.)
//Written by 1724834368@qq.com

//////////Ԥ����//////////
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h> 
using namespace std;
////////////////////////

//////////��������//////////
string Head_Str="=====C.J.K.ѧԱ����ϵͳ(CSMS)=====\n\n";
string Please_Input_Number="\n>>�������Ӧ����ִ�в�����\n";
string Unknown_Error=">>δ֪����\n";
string Found_Yes="\n���ҳɹ���\n";
string Found_Not="\n����ʧ�ܣ�\n"; 
//////////////////////////

//////////ѧԱ��Ϣ�ṹ��//////////
class SDs {
    //SD:Scholars_Data
public:
	void printall() {
		cout<<"������"<<Name<<endl
		    <<"�Ա�"<<Sex<<endl
			<<"��ţ�"<<Number<<endl 
			<<"ͷ�Σ�"<<Titles<<endl 
			<<"���ԣ�"<<Languages<<endl 
			<<"���֣�"<<Exp<<endl 
			<<"��ע��"<<Note<<endl
			<<endl; 
	}
	
    string Name;      //����
    string Sex;       //�Ա�
    string Number;    //���
    string Titles;    //ͷ��
    string Languages; //����
    string Exp;       //����
    string Note;      //��ע
};

vector<SDs> SDV;  //ѧԱ��������
SDs SDM;          //ѧԱ������Ա
///////////////////////////////

//////////ͷ����������//////////
void SLP();  //ϵͳ����ҳ��
int SLR();  //ϵͳ������ 
void LSD();  //����ѧԱ����
int MMP();   //���˵�ҳ��
void GSD();  //��ѯѧԱ��Ϣ 
void CSD();  //����ѧԱ��Ϣ
void ADSD(); //��ɾѧԱ��Ϣ 
void SSD();  //����ѧԱ����
void Over(); //�������� 
void OKEND();//�س����н��� 
void OKCONTINUE();//�س����м��� 
//////////////////////////////

//////////������//////////
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

//////////β����������//////////
void SLP() {
    //SLP:System_Loading_Page
    system("color F9");
    cout<<Head_Str
        <<"ϵͳ������";
    for(int i=0;i<10;i++) {
        Sleep(300);
        cout<<'.';
    }
    cout<<"���سɹ���"<<endl;
    Sleep(1000);
    system("cls");
}

int SLR() {
	cout<<Head_Str
	    <<"����������:"<<endl;
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
        <<"�����˵���"<<endl
        <<"0.���沢�˳�"<<endl
        <<"1.��ѯѧԱ��Ϣ"<<endl
		<<"2.����ѧԱ��Ϣ"<<endl
		<<"3.��ɾѧԱ��Ϣ"<<endl;
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
        <<"����ѯѧԱ��Ϣ��"<<endl
        <<"0.�������˵�"<<endl
        <<"1.��ѯȫ��ѧԱ��Ϣ"<<endl
		<<"2.��ѯָ������ѧԱ��Ϣ"<<endl
		<<"3.��ѯָ�����ѧԱ��Ϣ"<<endl;
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
                <<"����ѯȫ��ѧԱ��Ϣ��"<<endl<<endl;
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
                <<"����ѯָ������ѧԱ��Ϣ��"<<endl<<endl;
            cout<<"������ѧԱ����:"<<endl;
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
                <<"����ѯָ�����ѧԱ��Ϣ��"<<endl<<endl;
            cout<<"������ѧԱ���:"<<endl;
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
        <<"������ѧԱ��Ϣ��"<<endl
        <<"0.�������˵�"<<endl
        <<"1.��������ѧԱ��Ϣ"<<endl;
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
       		    <<"������ѧԱ��Ϣ��"<<endl<<endl;
       		cout<<">>������ѧԱ��������:"<<endl;
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
       		    		<<"������ѧԱ��Ϣ��"<<endl<<endl;
            		Sleep(300);
            		SDV[i].printall();
            		goto Find_End3;
                }
			}
			cout<<Found_Not<<endl;
			cout<<"���س����з������˵������������²���:\n";
			while(1) {
				char a=getch();
				if(a=='\n'||a=='\r') break;
				else goto Begin_CSD_49;
			}
			Find_End3:
			cout<<endl
				<<"��������Ҫ���ĵ���Ϣ��:\n";
			string need_change;
			cin>>need_change;
			//�˴���������bug/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
			if(need_change=="����"||need_change=="�Ա�"||need_change=="���"||need_change=="ͷ��"||need_change=="����"||need_change=="����"||need_change=="��ע") {
			} else {
				cout<<"\n����Ϣ����ڣ�"<<endl
						<<"��1�������룬�������������˵�"<<endl; 
				if(getch()=='1') {
					goto Find_End3;
				} else {
					break;
				}
			}
			cout<<endl
			    <<"�������µ���Ϣ����(��������ո�):\n";
			string new_content;
			cin>>new_content;
			if(need_change=="����") {
				SDV[pos].Name=new_content;
			} else if(need_change=="�Ա�") {
				SDV[pos].Sex=new_content;
			} else if(need_change=="���") {
				SDV[pos].Number=new_content;
			} else if(need_change=="ͷ��") {
				SDV[pos].Titles=new_content;
			} else if(need_change=="����") {
				SDV[pos].Languages=new_content;
			} else if(need_change=="����") {
				SDV[pos].Exp=new_content;
			} else if(need_change=="��ע") {
				SDV[pos].Note=new_content;
			}
			cout<<"\n�޸ĳɹ���\n"; 
			OKEND();
			break;
		} 
	}
}

void ADSD() {
	//ADSD:Add_or_Delete_Scholars_Data
	cout<<Head_Str
        <<"����ɾѧԱ��Ϣ��"<<endl
        <<"0.�������˵�"<<endl
        <<"1.����ѧԱ��Ϣ"<<endl
		<<"2.ɾ��ѧԱ��Ϣ"<<endl;
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
       		    <<"������ѧԱ��Ϣ��"<<endl<<endl;
       		string Cin_Data="��";
       		cout<<"\n>>�������ʾ��������ѧԱ��Ϣ\n";
       		cout<<"\n����:";
			cin>>Cin_Data;
			SDM.Name=Cin_Data;
			cout<<"�Ա�:";
			cin>>Cin_Data;
			SDM.Sex=Cin_Data;
			cout<<"���:";
			cin>>Cin_Data;
			SDM.Number=Cin_Data;
			cout<<"ͷ��:";
			cin>>Cin_Data;
			SDM.Titles=Cin_Data;
			cout<<"����:";
			cin>>Cin_Data;
			SDM.Languages=Cin_Data;
			cout<<"����:";
			cin>>Cin_Data;
			SDM.Exp=Cin_Data;
			cout<<"��ע:";
			cin>>Cin_Data;
			SDM.Note=Cin_Data;
			cout<<"\n>>����ϸ���ȷ��������Ϣ���󣬰�1���������룬������������:\n"; 
       		if(getch()=='1') {
       			goto Begin_ADSD_49;
			}
			SDV.push_back(SDM);
			system("cls");
			cout<<Head_Str
       		    <<"������ѧԱ��Ϣ��"<<endl<<endl;
       		cout<<">>�����ɹ���\n\n";
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
       		    <<"��ɾ��ѧԱ��Ϣ��"<<endl<<endl;
       		    cout<<">>������ѧԱ��������:"<<endl;
       		string nameornumber;
       		cin>>nameornumber;
       		for(int i=0;i<int(SDV.size());i++) {
            	if(SDV[i].Number==nameornumber||SDV[i].Name==nameornumber) {
            		cout<<Found_Yes<<endl;
            		Sleep(1000);
					system("cls");
					cout<<Head_Str
       		    		<<"��ɾ��ѧԱ��Ϣ��"<<endl<<endl;
            		Sleep(500);
            		SDV[i].printall();
            		cout<<"��1ȷ��ɾ������������ȡ��ɾ�����������˵�:\n";
					if(getch()=='1') {
						for(int j=i;j<int(SDV.size())-1;i++) {
							SDV[j]=SDV[i+1];
						}
						SDV.pop_back();
						cout<<"\nɾ���ɹ���\n";
						Sleep(1000);
						OKEND();
					}
					goto END666;
                }
			}
			cout<<Found_Not<<endl; 
			Sleep(500);
			cout<<">>��1���²��ң����������������˵�:\n";
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
    cout<<">>���沢�˳���"<<endl;
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
	cout<<"\n>>�س����з������˵�..."<<endl;
			while(getch()!='\n'&&getch()!='\r') {}
}

void OKCONTINUE() {
	cout<<">>�س����м���..."<<endl;
			while(getch()!='\n'&&getch()!='\r') {}
}
//////////////////////////////
