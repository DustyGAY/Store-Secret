#include "Class_Run.h"
#include<fstream>
void Run::Menu() {
	system("cls");
	std::cout << "===============\n";
	std::cout << "|这是一个密码本|\n";
	std::cout << "|==1.显示全部==|\n";
	std::cout << "|==2.添加密码==|\n";
	std::cout << "|==3.修改密码==|\n";
	std::cout << "|==4.删除密码==|\n";
	std::cout << "|==5.查找密码==|\n";
	std::cout << "|==6.退出程序==|\n";
	std::cout << "===============\n";
	std::cout << "已有" << p_count + w_count << "条数据。\n";
	std::cout << "请选择要执行的功能，并输入该功能的编号。\n";
} 

Run::Run() {
	std::ifstream outfile1("P_data.txt");
	if (!(outfile1 >> p_count))
		p_count = 0;
	outfile1.get();
	for (int i = 0; i < p_count; i++)
		outfile1 >> programkey[i];
	outfile1.close();
	std::ifstream outfile2("W_data.txt");
	if (!(outfile2 >> w_count))
		w_count = 0;
	outfile2.get();
	for (int i = 0; i < w_count; i++)
		outfile2 >> webkey[i];
	outfile2.close();
}

void Run::Read_data() {
	system("cls");
	std::cout << "程序：\n";
	for (int i = 0; i < p_count; i++)
		std::cout << i + 1 << '.' << programkey[i];
	std::cout << "网站：\n";
	for (int i = 0; i < w_count; i++)
		std::cout << i + 1 << '.' << webkey[i];
	std::cout << "输入任意键返回:\n";
	std::cin.get();
}

void Run::Write_data() {
	system("cls");
	std::cout << "请输入密码类型(网站密码输入1，程序密码输入2):\n";
	while (1) {
		char type;
		std::cin >> type;
		std::cin.ignore(1024, '\n');
		system("cls");
		if (type == '1') {
			if (webkey[w_count].Get_web())
				if (webkey[w_count].Get_account())
					if (webkey[w_count].Get_key())
						w_count++;
			break;
		}
		else
			if (type == '2') {
				if (programkey[p_count].Get_Program())
					if (programkey[p_count].Get_account())
						if (programkey[p_count].Get_key())
							p_count++;
				break;
			}
			else
				std::cout << "请输入1或2(网站密码输入1，程序密码输入2):\n";
	}
}

void Run::Save() {
	std::ofstream infile1("P_data.txt");
	infile1 << p_count << '\n';
	for (int i = 0; i < p_count; i++)
		infile1 << programkey[i] << '\n';
	infile1.close();
	std::ofstream infile2("W_data.txt");
	infile2 << w_count << '\n';
	for (int i = 0; i < w_count; i++)
		infile2 << webkey[i] << '\n';
	infile2.close();
}

Run::~Run() {
	std::cout << "已成功储存。";
}

void Run::Delete_data() {
	system("cls");
	std::cout << "请输入想要删除的密码类型(网站密码输入1，程序密码输入2，输入~取消):\n";
	char type;
	while (1) {
		std::cin >> type;
		std::cin.ignore(1024, '\n');
		system("cls");
		if (type == '~')
			break;
		else
			if (type == '1') {
				for (int i = 0; i < w_count; i++)
					std::cout << i + 1 << '.' << webkey[i];
				std::cout << "请输入数据编号(输入~取消)：\n";
				char number[Max_Storage * 2];
				while (1) {
					std::cin.get(number, Max_Storage * 2);
					std::cin.ignore(1024, '\n');
					if (number[0] == '~' || number[1] == '\0')
						break;
					int num;
					bool flag = C_to_n(number, num);
					num--;
					if (num >= w_count || !flag)
						std::cout << "请输入正确数据:";
					else {
						for (int i = num; i < w_count; i++)
							webkey[i] = webkey[i + 1];
						w_count--;
						break;
					}
				}
			}
			else
				if (type == '2') {
					for (int i = 0; i < p_count; i++)
						std::cout << i + 1 << '.' << programkey[i];
					std::cout << "请输入数据编号(输入~取消)：\n";
					char number[Max_Storage * 2];
					while (1) {
						std::cin.get(number, Max_Storage * 2);
						std::cin.ignore(1024, '\n');
						if (number[0] == '~' || number[1] == '\0')
							break;
						int num;
						bool flag = C_to_n(number, num);
						num--;
						if (num >= p_count || !flag)
							std::cout << "请输入正确数据:";
						else {
							for (int i = num; i < p_count; i++)
								programkey[i] = programkey[i + 1];
							p_count--;
							break;
						}
					}
				}
				else {
					std::cout << "请输入正确的数据:";
					continue;
				}
		break;
	}
}

void Run::Find_data(){
	system("cls");
	std::cout << "请输入密码类型（网站密码输入1，程序密码输入2，输入~取消输入）：\n";
	char type;
	while (1) {
		std::cin >> type;
		std::cin.ignore(1024, '\n');
		system("cls");
		if (type == '~')
			break;
		if(type == '1')
			while (1) {
				char web[Web_length];
				std::cout << "请输入网址(输入~取消)：\n";
				std::cin.get(web, Web_length);
				std::cin.ignore(1024, '\n');
				if (web[0] == '~' || web[1] == '\0')
					break;
				bool flag = 0;
				for (int i = 0; i < w_count; i++)
					if (webkey[i].Webcmp(web)) {
						std::cout << webkey[i];
						flag = 1;
					}
				if (flag)
					break;
				std::cout << "请输入正确的网址,";
			}
		else
			if (type == '2')
				while (1) {
					char program[Program_length];
					std::cout << "请输入程序名(输入~取消)：\n";
					std::cin.get(program, Program_length);
					std::cin.ignore(1024, '\n');
					if (program[0] == '~' || program[1] == '\0')
						break;
					bool flag = 0;
					for (int i = 0; i < w_count; i++)
						if (programkey[i].Programcmp(program)) {
							std::cout << i + 1 << '.' << programkey[i];
							flag = 1;
						}
					if (flag)
						break;
					std::cout << "请输入正确的程序名,";
				}
			else {
				std::cout << "请输入正确的选项:";
				continue;
			}
		break;
	}
	std::cout << "输入任意键返回:\n";
	std::cin.ignore(1024, '\n');
}

void Run::Change_data() {
	system("cls");
	std::cout << "请输入密码类型（网站密码输入1，程序密码输入2，输入~取消输入）：\n";
	char type;
	while (1) {
		std::cin >> type;
		std::cin.ignore(1024, '\n');
		if (type == '~')
			break;
		if(type == '1')
			while (1) {
				for(int i = 0; i < w_count; i++)
					std::cout << i + 1 << '.' << webkey[i];
				std::cout << "请选择编号(输入~取消输入):\n";
				char num[Max_Storage];
				int n_num;
				while (1) {
					std::cin.get(num, Max_Storage);
					std::cin.ignore(1024, '\n');
					bool flag = C_to_n(num, n_num);
					n_num--;
					if (!flag || n_num >= w_count) {
						std::cout << "请输入正确的编号:\n";
						continue;
					}
					break;
				}
				system("cls");
				char type0;
				while (1) {
					std::cout << "你的数据：" << webkey[n_num];
					std::cout << "修改网址输入1，修改账号输入2，修改密码输入3，输入~取消输入：\n";
					std::cin >> type0;
					std::cin.ignore(1024, '\n');
					if (type0 == '~')
						break;
					if (type0 == '1') {
						webkey[n_num].Get_web();
						break;
					}
					else
						if (type0 == '2') {
							webkey[n_num].Get_account();
							break;
						}
						else
							if (type0 == '3') {
								webkey[n_num].Get_key();
								break;
							}
					std::cout << "请输入正确的数据。\n";
				}
				break;
			}
		if (type == '2') {
			while (1) {
				for (int i = 0; i < p_count; i++)
					std::cout << i + 1 << '.' << programkey[i];
				std::cout << "请选择编号(输入~取消输入):\n";
				char num[Max_Storage];
				int n_num;
				while (1) {
					std::cin.get(num, Max_Storage);
					std::cin.ignore(1024, '\n');
					bool flag = C_to_n(num, n_num);
					n_num--;
					if (!flag || n_num >= p_count) {
						std::cout << "请输入正确的编号:\n";
						continue;
					}
					break;
				}
				system("cls");
				char type0;
				while (1) {
					std::cout << "你的数据：" << programkey[n_num];
					std::cout << "修改程序名输入1，修改账号输入2，修改密码输入3，输入~取消输入：\n";
					std::cin >> type0;
					std::cin.ignore(1024, '\n');
					if (type0 == '~')
						break;
					if (type0 == '1') {
						programkey[n_num].Get_Program();
						break;
					}
					else
						if (type0 == '2') {
							programkey[n_num].Get_account();
							break;
						}
						else
							if (type0 == '3') {
								programkey[n_num].Get_key();
								break;
							}
					std::cout << "请输入正确的数据。\n";
				}
				break;
			}
		}
		break;
	}
}

bool Run::C_to_n(const char s[],int &num) {
	int len = strlen(s);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum * 10 + s[i] - '0';
		if (s[i] > '9' || s[i] < 0)
			return 0;
	}
	num = sum;
	return 1;
}
