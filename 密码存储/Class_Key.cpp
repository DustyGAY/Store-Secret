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
		std::cout << "�������������(����~ȡ������):\n";
		std::cin.get(key, Key_length);
		if (key[0] == '~' && key[1] == '\0')
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "���볤�ȹ��������������롣";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}

bool Key::Get_account() {
	while (1) {
		std::cout << "����������˺�(����~ȡ������):\n";
		std::cin.get(account, Account_length);
		if (account[0] == '~' && account[1] == '\0')
			return 0;
		if (std::cin.get() != '\n') {
			std::cout << "�˺ų��ȹ��������������롣";
			std::cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	return 1;
}


