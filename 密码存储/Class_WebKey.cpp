#include "Class_WebKey.h"
#include<iomanip>
#include<cstring>

WebKey::WebKey() {
	web[0] = '?';
	web[1] = '\0';
}

std::ostream& operator<<(std::ostream& os, WebKey& w) {
	int w_len = strlen(w.web);
	int a_len = strlen(w.account);
	int k_len = strlen(w.key);
	os << "网址: ";
	for (int i = 0; i < w_len; i++)
		os << w.web[i];
	for (int i = w_len; i <= Web_length; i++)
		std::cout << ' ';
	os << " 账号: ";
	for (int i = 0; i < a_len; i++)
		os << w.account[i];
	for (int i = a_len; i <= Account_length; i++)
		std::cout << ' ';
	os << " 密码: ";
	for (int i = 0; i < k_len; i++)
		os << w.key[i];
	for (int i = k_len; i <= Key_length; i++)
		std::cout << ' ';
	os << '\n';
	return os;
}

std::ifstream& operator>>(std::ifstream& fs, WebKey& w) {
	fs.getline(w.web, Program_length, ' ');
	fs.getline(w.account, Account_length, ' ');
	fs.getline(w.key, Key_length, '\n');
	return fs;
}

std::ofstream& operator<<(std::ofstream& fs, WebKey& w) {
	fs << w.web << ' ' << w.account << ' ' << w.key << '\n';
	return fs;
}

bool WebKey::Get_web() {
	while (1) {
		std::cout << "请输入网址(输入~取消输入):\n";
		std::cin.get(web, Web_length);
		if (web[0] == '~' && web[1] == '\0')
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "网址长度过长，请重新输入。\n";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}

bool WebKey::Webcmp(const char s[]) const {
	if (!strcmp(s, web))
		return 1;
	else
		return 0;
}