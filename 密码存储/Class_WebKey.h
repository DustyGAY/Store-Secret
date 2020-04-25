#ifndef WEBKEY_H
#define WEBKEY_H
#include"Class_Key.h"
#include<iostream>
#include<fstream>

class WebKey :
	public Key {
private:
	char web[Web_length];
public:
	WebKey();
	bool Get_web();
	bool Webcmp(const char s[]) const;
	friend std::ostream& operator<<(std::ostream& os, WebKey& w);
	friend std::ifstream& operator>>(std::ifstream& fs, WebKey& w);
	friend std::ofstream& operator<<(std::ofstream& fs, WebKey& w);
};

#endif // !WEBKEY_H

