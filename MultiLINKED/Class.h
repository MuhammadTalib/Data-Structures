#include<stdlib.h>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;
class Class
{
public:

    void insert_Class( Class **start);
    void display_classes(Class *start);

private:
    string Name="            ";
    int Total_Students;
    Class *next;
};
