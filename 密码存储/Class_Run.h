#ifndef RUN_H
#define RUN_H

#include"Class_ProgramKey.h"
#include"Class_WebKey.h"

class Run {
private:
    ProgramKey programkey[Max_Storage];
    WebKey webkey[Max_Storage];
    int p_count;
    int w_count;
    bool C_to_n(const char s[], int &num);
public:
    Run();
    void Write_data();
    void Read_data();
    void Find_data();
    void Delete_data();
    void Change_data();
    void Menu();
    void Save();
    ~Run();
};

#endif // !RUN_H

