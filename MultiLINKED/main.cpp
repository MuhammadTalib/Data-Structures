#include<stdlib.h>
#include<string>
#include<string.h>
#include <iostream>
using namespace std;

#include "Class.h"

int main()
{
    Class *start=NULL;
    start->insert_Class(&start);
    start->insert_Class(&start);
    start->display_classes(start);

}
