#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

string Locker(string value) {
	const static char Base64[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&%"; //加密字典(基于Base64)
	string encode;
	vector<int> k;
	
	//字节展开求值,加入其他操作后对应加密字典 
    for(int i=0;i<int(value.size());i++) {
    	byte bt=value[i];    //byte类型包含在Windows头文件中(为了处理中文) 
        int a=abs(int(bt));
        int s[8]={};
        for(int i=a,pos=7;i>0;i/=2,pos--) {
		    //展开为二进制数 
            s[pos]=i%2;
        }
        for(int i=0;i<8;i++) {
            k.push_back(s[i]);
        }
    }
    
    for(int i=0;i<int(k.size());i++) {
    	//按位取反 
    	k[i]=(!k[i]);
	}
    
    for(int i=0,posb=0;i<int(k.size())/6;i++) {
    	//按六位匹配解析 
        int l[6]={};
        for(int posa=0;posa<6;posa++,posb++) {
            l[posa]=k[posb];
        }
        int ans=l[0]*32+l[1]*16+l[2]*8+l[3]*4+l[4]*2+l[5];
        encode.push_back(Base64[ans]);
    }
    if(int(k.size())/6*6!=int(k.size())) {
    	//处理可能的剩余位 
        int ls[6]={};
        for(int i=int(k.size())-1,j=5;i>=int(k.size())/6*6;j--,i--) {
            ls[j]=k[i];
        }
        int ans=ls[0]*32+ls[1]*16+ls[2]*8+ls[3]*4+ls[4]*2+ls[5];
        encode.push_back(Base64[ans]);
    }
    
    //拉锁式打乱 
    string sa,sb;
    if(encode.size()%2) {
        for(int i=0;i<int(encode.size());i++) {
            if(i<=int(encode.size())/2) {
                sa.push_back(encode[i]);
            } else {
                sb.push_back(encode[i]);
            }
        }
    } else {
        for(int i=0;i<int(encode.size());i++) {
            if(i<int(encode.size())/2) {
                sa.push_back(encode[i]);
            } else {
                sb.push_back(encode[i]);
            }
        }
    }
    encode.clear();
    for(int i=0;i<int(sb.size());i++) {
        encode.push_back(sa[i]);
        encode.push_back(sb[i]);
    }
    if(sa.size()>sb.size()) {
        encode.push_back(*(sa.end()-1));
    }
    
    return encode;
}

int main() {
	string s;
	cin>>s;
	string k=Locker(s);
	cout<<endl<<k<<endl;
	ofstream fout("Encoded.txt",ios::app);
	fout<<s<<endl<<k<<endl<<endl;
	getch();
	
	return 0;
}
