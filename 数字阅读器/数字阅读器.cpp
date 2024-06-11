/*
����������Ȩ������
    �����������˧˧�����ķ�׫д��
    ��ֹ���ơ���Ϯ��������룡
    �������Ҫ���������Ϊ����������ϵ���ķ���ȡ��Ȩ������Ϊ1724834368@qq.com.
    ��α��ʶ�룺"SnVkZUJsYWNrRGVkaVBlbnNvbk1pbnBlbkp1bGFyRGVwaWNrQ2luaGFuQmFuamFuc0xpV2VuZmFuZD".
*/

//Written by liwenfang(Very Handsome)

#include <bits/stdc++.h>
using namespace std;
std::string numcode_simple[] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��"};

std::string numcode_mucher[] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};

std::string numweight_simple[] = {"һ", "ʮ", "��", "ǧ", "��", "ʮ��", "����", "ǧ��", "��", "ʮ��"};

std::string numweight_mucher[] = {"Ҽ", "ʰ", "��", "Ǫ", "��", "ʰ��", "����", "Ǫ��", "�|", "ʰ�|"};


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
		respond.push_back("ǧ");
	}
	if (b) {
		respond.push_back(numcode_simple[b]);
		respond.push_back("��");
	}
	if (s) {
		if (q && (!b)) {
			respond.push_back("��");
		}
		respond.push_back(numcode_simple[s]);
		respond.push_back("ʮ");
	}
	if (g) {
		if ((q && (!b) && (!s)) || (b && (!s))) {
			respond.push_back("��");
		}
		respond.push_back(numcode_simple[g]);
	}
	if ((!int(respond.size()))) {
		respond.push_back("��");
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
		respond.push_back("Ǫ");
	}
	if (b) {
		respond.push_back(numcode_mucher[b]);
		respond.push_back("��");
	}
	if (s) {
		if (q && (!b)) {
			respond.push_back("��");
		}
		respond.push_back(numcode_mucher[s]);
		respond.push_back("ʰ");
	}
	if (g) {
		if ((q && (!b) && (!s)) || (b && (!s))) {
			respond.push_back("��");
		}
		respond.push_back(numcode_mucher[g]);
	}
	if ((!int(respond.size()))) {
		respond.push_back("��");
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
		respond.push_back("��");
	}
	if (b) {
		if ((a) && b < 1000) {
			respond.push_back("��");
		}

		vector<string> vea = readfour_sp(b);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}

		respond.push_back("��");
	}
	if (c) {
		if ((b && c < 1000) || (a && (!b))) {
			respond.push_back("��");
		}
		vector<string> vea = readfour_sp(c);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
	}
	if (!int(respond.size())) {
		respond.push_back("��");
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
		respond.push_back("�|");
	}
	if (b) {
		if ((a) && b < 1000) {
			respond.push_back("��");
		}

		vector<string> vea = readfour_mr(b);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}

		respond.push_back("��");
	}
	if (c) {
		if ((b && c < 1000) || (a && (!b))) {
			respond.push_back("��");
		}
		vector<string> vea = readfour_mr(c);
		for (int i = 0; i < int(vea.size()); i++) {
			respond.push_back(vea[i]);
		}
	}
	if (!int(respond.size())) {
		respond.push_back("��");
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