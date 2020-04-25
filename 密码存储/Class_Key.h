#ifndef KEY_H
#define KEY_H
#include"Setting.h"

class Key {
public:
	Key();
	bool Get_key();
	bool Get_account();
protected:
	char key[Key_length];
	char account[Account_length];
};

#endif


