#include "Class_Key.h"
#include<iostream>

Key::Key() {
	account[0] = '?';
	account[1] = '\0';
	key[0] = '?';
	key[1] = '\0';
}

bool Key::Get_key() {
	while (1) {
		std::cout << "请输入你的密码(输入~取消输入):\n";
		std::cin.get(key, Key_length);
		if (key[0] == '~' && key[1] == '\0')
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "密码长度过长，请重新输入。";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}

bool Key::Get_account() {
	while (1) {
		std::cout << "请输入你的账号(输入~取消输入):\n";
		std::cin.get(account, Account_length);
		if (account[0] == '~' && account[1] == '\0')
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "账号长度过长，请重新输入。";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}


