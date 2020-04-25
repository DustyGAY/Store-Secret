#include "Class_ProgramKey.h"
#include<iomanip>
#include<cstring>

ProgramKey::ProgramKey() {
	program[0] = '?';
	program[1] = '\0';
}

std::ostream& operator<<(std::ostream& os, ProgramKey& p) {
	int p_len = strlen(p.program);
	int a_len = strlen(p.account);
	int k_len = strlen(p.key);
	os << "程序:";
	for (int i = 0; i < p_len; i++)
		os << p.program[i];
	for (int i = p_len; i <= Program_length; i++)
		std::cout << ' ';
	os << " 账号:";
	for (int i = 0; i < a_len; i++)
		os << p.account[i];
	for (int i = a_len; i <= Account_length; i++)
		std::cout << ' ';
	os << " 密码:";
	for (int i = 0; i < k_len; i++)
		os << p.key[i];
	for (int i = k_len; i <= Key_length; i++)
		std::cout << ' ';
	os << '\n';
	return os;
}

std::ifstream& operator>>(std::ifstream& fs, ProgramKey& p) {
	fs.getline(p.program, Program_length, ' ');
	fs.getline(p.account, Account_length, ' ');
	fs.getline(p.key, Key_length, '\n');
	return fs;
}

std::ofstream& operator<<(std::ofstream& fs, ProgramKey& p) {
	fs << p.program << ' ' << p.account << ' ' << p.key << '\n';
	return fs;
}

bool ProgramKey::Get_Program() {
	while (1) {
		std::cout << "请输入程序名(输入~取消输入):\n";
		std::cin.get(program, Program_length);
		if (program[0] == '~' && program[1] == '\0') 
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "程序名长度过长，请重新输入。\n";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}

bool ProgramKey::Programcmp(const char s[]) const {
	if (!strcmp(s, program))
		return 1;
	else
		return 0;
}