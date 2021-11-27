#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool Include(const char* s, const char* cs)
{
    bool b, r = true;
    for (int i=0; cs[i] != '\0'; i++)
    {
        b = false;
        for (int j=0; s[j] != '\0'; j++)
            if (cs[i] == s[j])
            {
                b = true;
                break;
            }
        r = r && b;
    }
    return r;
}
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;
    char* tmp = new char[len * 2 / 3 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;
    while (i < len && str[i + 2] != 0)
    {
        if ((str[i] == 'A' &&
        str[i + 1] == 'G' &&
        str[i + 2] == 'A') ||
        (str[i] == 'O' &&
        str[i + 1] == 'G' &&
        str[i + 2] == 'O'))
        {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t++ = str[i++];
    *t++ = str[i++];
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    char cs1[]  = "AGA";
    char cs2[]  = "OGO";
    if ( Include(str, cs1) || Include(str, cs2) )
            cout << "yes" << endl;
    else
            cout << "no" << endl;
    char* dest = new char[151]; dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
