#ifndef PROGRAMMEKEY_H
#include "Class_Key.h"
#include<iostream>
#include<fstream>

class ProgramKey :
	public Key {
private:
	char program[Program_length];
public:
	ProgramKey();
	bool Get_Program();
	bool Programcmp(const char s[]) const;
	friend std::ostream& operator<<(std::ostream& os, ProgramKey& p);
	friend std::ifstream& operator>>(std::ifstream& fs, ProgramKey& p);
	friend std::ofstream& operator<<(std::ofstream& fs, ProgramKey& p);
};

#endif // !PROGRAMMEKEY_H


