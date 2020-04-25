#include "Class_Run.h"
#include<fstream>
void Run::Menu() {
	system("cls");
	std::cout << "===============\n";
	std::cout << "|����һ�����뱾|\n";
	std::cout << "|==1.��ʾȫ��==|\n";
	std::cout << "|==2.�������==|\n";
	std::cout << "|==3.�޸�����==|\n";
	std::cout << "|==4.ɾ������==|\n";
	std::cout << "|==5.��������==|\n";
	std::cout << "|==6.�˳�����==|\n";
	std::cout << "===============\n";
	std::cout << "����" << p_count + w_count << "�����ݡ�\n";
	std::cout << "��ѡ��Ҫִ�еĹ��ܣ�������ù��ܵı�š�\n";
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
	std::cout << "����\n";
	for (int i = 0; i < p_count; i++)
		std::cout << i + 1 << '.' << programkey[i];
	std::cout << "��վ��\n";
	for (int i = 0; i < w_count; i++)
		std::cout << i + 1 << '.' << webkey[i];
	std::cout << "�������������:\n";
	std::cin.get();
}

void Run::Write_data() {
	system("cls");
	std::cout << "��������������(��վ��������1��������������2):\n";
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
				std::cout << "������1��2(��վ��������1��������������2):\n";
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
	std::cout << "�ѳɹ����档";
}

void Run::Delete_data() {
	system("cls");
	std::cout << "��������Ҫɾ������������(��վ��������1��������������2������~ȡ��):\n";
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
				std::cout << "���������ݱ��(����~ȡ��)��\n";
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
						std::cout << "��������ȷ����:";
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
					std::cout << "���������ݱ��(����~ȡ��)��\n";
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
							std::cout << "��������ȷ����:";
						else {
							for (int i = num; i < p_count; i++)
								programkey[i] = programkey[i + 1];
							p_count--;
							break;
						}
					}
				}
				else {
					std::cout << "��������ȷ������:";
					continue;
				}
		break;
	}
}

void Run::Find_data(){
	system("cls");
	std::cout << "�������������ͣ���վ��������1��������������2������~ȡ�����룩��\n";
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
				std::cout << "��������ַ(����~ȡ��)��\n";
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
				std::cout << "��������ȷ����ַ,";
			}
		else
			if (type == '2')
				while (1) {
					char program[Program_length];
					std::cout << "�����������(����~ȡ��)��\n";
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
					std::cout << "��������ȷ�ĳ�����,";
				}
			else {
				std::cout << "��������ȷ��ѡ��:";
				continue;
			}
		break;
	}
	std::cout << "�������������:\n";
	std::cin.ignore(1024, '\n');
}

void Run::Change_data() {
	system("cls");
	std::cout << "�������������ͣ���վ��������1��������������2������~ȡ�����룩��\n";
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
				std::cout << "��ѡ����(����~ȡ������):\n";
				char num[Max_Storage];
				int n_num;
				while (1) {
					std::cin.get(num, Max_Storage);
					std::cin.ignore(1024, '\n');
					bool flag = C_to_n(num, n_num);
					n_num--;
					if (!flag || n_num >= w_count) {
						std::cout << "��������ȷ�ı��:\n";
						continue;
					}
					break;
				}
				system("cls");
				char type0;
				while (1) {
					std::cout << "������ݣ�" << webkey[n_num];
					std::cout << "�޸���ַ����1���޸��˺�����2���޸���������3������~ȡ�����룺\n";
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
					std::cout << "��������ȷ�����ݡ�\n";
				}
				break;
			}
		if (type == '2') {
			while (1) {
				for (int i = 0; i < p_count; i++)
					std::cout << i + 1 << '.' << programkey[i];
				std::cout << "��ѡ����(����~ȡ������):\n";
				char num[Max_Storage];
				int n_num;
				while (1) {
					std::cin.get(num, Max_Storage);
					std::cin.ignore(1024, '\n');
					bool flag = C_to_n(num, n_num);
					n_num--;
					if (!flag || n_num >= p_count) {
						std::cout << "��������ȷ�ı��:\n";
						continue;
					}
					break;
				}
				system("cls");
				char type0;
				while (1) {
					std::cout << "������ݣ�" << programkey[n_num];
					std::cout << "�޸ĳ���������1���޸��˺�����2���޸���������3������~ȡ�����룺\n";
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
					std::cout << "��������ȷ�����ݡ�\n";
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
