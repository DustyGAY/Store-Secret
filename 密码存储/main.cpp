#include"Class_Run.h"
#include<iomanip>

int main() {
	Run *r = new Run;
	std::cout << std::setiosflags(std::ios_base::left);
	while (1) {
		r->Menu();
		char number;
		std::cin >> number;
		std::cin.ignore(1024, '\n');
		if (number == '6')
			break;
		switch (number) {
		case '1':
			r->Read_data();
			break;
		case '2':
			r->Write_data();
			break;
		case '3':
			r->Change_data();
			break;
		case '4':
			r->Delete_data();
			break;
		case '5':
			r->Find_data();
			break;
		default:
			std::cout << "请在1~6之间选择（输入任意字符重新输入）\n";
			std::cin.get();
		}
	}
	r->Save();
	delete r;
}