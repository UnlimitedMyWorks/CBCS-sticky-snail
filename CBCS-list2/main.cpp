#include <iostream>
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <wininet.h>
#include <cstring>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <locale>
#include <cstdlib>
#include <time.h>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5


int whileloop(int num)
{
    int tid;
    tid = num;
    cout << tid << "\n";

    char bs[7];
    int bstuid = tid, l = tid + 1000;

    int flag = 0;   // flag to check the strings "program" and "section"

    //Naming files with respect to the "stuid"
    string file;
    char index[6];
    itoa(bstuid, index, 10);
    stringstream ss1;
    ss1 << index;
    ss1 >> file;
    file = file + ".txt";


    ofstream fout(file.c_str(), ios::app);

    do
    {
        flag = 0;
        // Uncomment this line if you want the stuid to be displayed
        //cout << bstuid << "\n";

        // Opening Internet connections?
        HINTERNET connect = InternetOpen("MyBrowser",INTERNET_OPEN_TYPE_PRECONFIG,NULL, NULL, 0);

        //Converting bsutid(Beginning of stuid) from integer to char[]
        itoa(bstuid, bs, 10);
        stringstream ss;
        string s;
        ss << bs;
        ss >> s;
        // Checking the connections (one is enough)
        if(!connect)
        {
            //system("cls");
            fout << "Connection Failed: Check your Internet connection!\n";
            cout << "Connection Failed: Check your Internet connection!\n";
            system("pause");
            return 0;
        }

        // link of the site
        string apilink = "http://webstream.sastra.edu/DecCBCS2017/academy/StudentCourseRegistrationView.jsp?session=hjllww22343adfadsfasdf76523231234adfadfafdafdadfadfadf&rand=6789854435&stuid="+s+"&pid=3&sid=3";

        HINTERNET OpenAddress = InternetOpenUrl(connect, apilink.c_str(), NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE|INTERNET_FLAG_KEEP_CONNECTION, 0);
        Sleep(500);

        // Checking internet connection
        if ( !OpenAddress )
        {
            //DWORD ErrorNum = GetLastError();
            //system("cls");
            cout << "Failed to open URL \nTry again later\n";//Error No: " << ErrorNum << "\n";
            InternetCloseHandle(connect);
            system("pause");
            return 0;
        }

// This Buffer will store the contents of the HTML code
        char DataReceived[4096];
        DWORD NumberOfBytesRead = 0;

        // Storing the API data to the buffers
        stringstream buffer;
        while(InternetReadFile(OpenAddress, DataReceived, 4096, &NumberOfBytesRead) && NumberOfBytesRead )
        {
            buffer << DataReceived;
        }

        string data = buffer.str();

        // Searching for the strings in the HTML code
        for(int i=0; data[i] != '\0'; ++i)
        {
            if(data.substr(i, 7) == "Program")
                flag += 1;
            if(data.substr(i, 7) == "Section")
                flag += 1;
        }

        // Extracting Data from the HTML code
        for(int i=0; data[i] != '\0' && flag == 2; ++i)
        {
            if(data.substr(i,9) == "content\">")
                {
                    i += 9;
                    stringstream name;
                    //i += 12;
                    for(; data[i] != '<'; i++)
                        name << data[i];
                    if(name.str() != "4")
                    {
                        fout << setw(50) << left << name.str() << "\t\t";
                        cout << setw(50) << left << name.str() << "\t\t";
                    }
                    //cout << "\t\t";
                }
            //}



            if(data.substr(i,6) == "middle")
            {
                stringstream mid1;
                i += 7;
                for(; data[i] != '<'; i++)
                    mid1 << data[i];
                fout << mid1.str() ;  // Seven spaces, it sucks >_<
                cout << mid1.str() ;  // Seven spaces, it sucks >_<
                fout << "\n";
                cout << "\n";
                break;

            }
        }

        // Closing all the connections/handles
        InternetCloseHandle(OpenAddress);
        InternetCloseHandle(connect);
        //Sleep(10000);
        bstuid++;
    }while(bstuid < l);
    cout << "yay";
}

int main(int argc, char *argv[])
{
    int i = atoi(argv[1]);
    //cout << i;
    whileloop(i);
    //whileloop();
    return 0;
}
