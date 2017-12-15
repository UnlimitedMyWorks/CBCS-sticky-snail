#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    long long num;
    int val = atoi(argv[2]);
    //char cbcs[500] = "";
    for(int i = 0; num < val; i++ )
    {
        char cbcs1[30] = "CBCS-list2.exe ";
        char no[5];
        char cmd [300] = "start cmd /k ";
        num = atoi(argv[1]) + (i * 1000);
        itoa(num, no, 10);
        strcat(cbcs1,no);
        strcat(cmd, cbcs1);
        system(cmd);
    }
    return 0;
}
