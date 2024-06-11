/*
【程序代码版权声明】
    本程序代码由帅帅的李文芳撰写。
    禁止复制、抄袭本程序代码！
    如果你需要本程序代码为你服务，你得联系李文芳获取授权，邮箱为1724834368@qq.com.
    防伪标识码："SnVkZUJsYWNrRGVkaVBlbnNvbk1pbnBlbkp1bGFyRGVwaWNrQ2luaGFuQmFuamFuc0xpV2VuZmFuZD".
*/

//Written by liwenfang(Very Handsome)

#include <bits/stdc++.h>
using namespace std;
std::string numcode_simple[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};

std::string numcode_mucher[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};

std::string numweight_simple[] = {"一", "十", "百", "千", "万", "十万", "百万", "千万", "亿", "十亿"};

std::string numweight_mucher[] = {"壹", "拾", "佰", "仟", "万", "拾万", "佰万", "仟万", "億", "拾億"};


int num;
int qian, wan, yi;

vector<string> readfour_sp(int four) {
	vector<string> respond = {};
	int g, s, b, q;
	g = four % 10 / 1;
	s = four % 100 / 10;
	b = four % 1000 / 100;
	q = four % 10000 / 1000;
	if (q) {
		respond.push_back(numcode_simple[q]);
		respond.push_back("千");
	}
	if (b) {
		respond.push_back(numcode_simple[b]);
		respond.push_back("百");
	}
	if (s) {
		if (q && (!b)) {
			respond.push_back("零");
		}
		respond.push_back(numcode_simple[s]);
		respond.push_back("十");
	}
	if (g) {
		if ((q && (!b) && (!s)) || (b && (!s))) {
			respond.push_back("零");
		}
		respond.push_back(numcode_simple[g]);
	}
	if ((!int(respond.size()))) {
		respond.push_back("零");
	}
	return respond;
}

vector<string> readfour_mr(int four) {
	vector<string> respond = {};
	int g, s, b, q;
	g = four % 10 / 1;
	s = four % 100 / 10;
	b = four % 1000 / 100;
	q = four % 10000 / 1000;
	if (q) {
		respond.push_back(numcode_mucher[q]);
		respond.push_back("仟");
	}
	if (b) {
		respond.push_back(numcode_mucher[b]);
		respond.push_back("佰");
	}
	if (s) {
		if (q && (!b)) {
			respond.push_back("零");
		}
		respond.push_back(numcode_mucher[s]);
		respond.push_back("拾");
	}
	if (g) {
		if ((q && (!b) && (!s)) || (b && (!s))) {
			respond.push_back("零");
		}
		respond.push_back(numcode_mucher[g]);
	}
	if ((!int(respond.size()))) {
		respond.push_back("零");
	}
	return respond;
}

vector<string> read_all_sp(int a, int b, int c) {
	vector<string> respond = {};
	if (a) {
		vector<string> vea = readfour_sp(a);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
		respond.push_back("亿");
	}
	if (b) {
		if ((a) && b < 1000) {
			respond.push_back("零");
		}

		vector<string> vea = readfour_sp(b);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}

		respond.push_back("万");
	}
	if (c) {
		if ((b && c < 1000) || (a && (!b))) {
			respond.push_back("零");
		}
		vector<string> vea = readfour_sp(c);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
	}
	if (!int(respond.size())) {
		respond.push_back("零");
	}
	return respond;
}

vector<string> read_all_mr(int a, int b, int c) {
	vector<string> respond = {};
	if (a) {
		vector<string> vea = readfour_mr(a);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
		respond.push_back("億");
	}
	if (b) {
		if ((a) && b < 1000) {
			respond.push_back("零");
		}

		vector<string> vea = readfour_mr(b);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}

		respond.push_back("万");
	}
	if (c) {
		if ((b && c < 1000) || (a && (!b))) {
			respond.push_back("零");
		}
		vector<string> vea = readfour_mr(c);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
	}
	if (!int(respond.size())) {
		respond.push_back("零");
	}
	return respond;
}

ostream &operator<<(ostream &fout, vector<string> sv) {
	for (string s : sv) {
		cout << s;
	}
	return fout;
}

int main() {
	int num;
	cin >> num;
	if (num >= INT_MAX) {
		cout << "UP TO MAX!!!" << endl;
		return 0;
	}
	qian = num % 10000;
	wan = num % 100000000 / 10000;
	yi = num % 1000000000000 / 100000000;
	freopen("reader_output.txt","w",stdout);
	cout << num << endl;
	cout << read_all_sp(yi, wan, qian) << endl;
	cout << read_all_mr(yi, wan, qian) << endl;

	return 0;
}