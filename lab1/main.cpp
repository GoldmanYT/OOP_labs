#include <iostream>
#include <typeinfo>
 
using namespace std;
 
int int1 = 8;  // 4 bytes
char char1 = 'b';  // 1 byte
wchar_t wchar_t1 = 'A';  // 2 bytes
bool bool1 = false;  // 1 bytes
float float1 = 3.14f;  // 4 bytes
double double1 = 6.28;  // 8 bytes
 
typedef unsigned int UINT;
typedef long long LL;
 
enum colors { red, green, blue };
enum gender { male = 5, female };
 
struct Room {
    int a;
    int b;
    int c;
    bool light_on;
} struct1;
 
int main()
{
    cout << "sizeof(int) = " << sizeof(int1) << endl;
    cout << "sizeof(char) = " << sizeof(char1) << endl;
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t1) << endl;
    cout << "sizeof(bool) = " << sizeof(bool1) << endl;
    cout << "sizeof(float) = " << sizeof(float1) << endl;
    cout << "sizeof(double) = " << sizeof(double1) << endl << endl;
    
    cout << "sizeof(colors) = " << sizeof(colors) << endl;
    cout << "sizeof(gender) = " << sizeof(gender) << endl << endl;
    
    cout << "sizeof(Room.a) = " << sizeof(struct1.a) << endl;
    cout << "sizeof(Room.b) = " << sizeof(struct1.b) << endl;
    cout << "sizeof(Room.c) = " << sizeof(struct1.c) << endl;
    cout << "sizeof(Room.light_on) = " << sizeof(struct1.light_on) << endl;
    cout << "sizeof(Room) = " << sizeof(struct1) << endl << endl;

    cout << "char(98) = " << char(98) << endl;
    cout << "char('A') = " << char('A') << endl;
    cout << "int(3.14) = " << int(3.14) << endl << endl;

    cout << "typeid(8).name() = " << typeid(8).name() << endl;
    cout << "typeid(3.14).name() = " << typeid(3.14).name() << endl;
    cout << "typeid('b').name() = " << typeid('b').name() << endl;
    cout << "typeid(false).name() = " << typeid(false).name() << endl;
    cout << "typeid('b' + 3.14).name() = " << typeid('b' + 3.14).name() << endl;
 
    return 0;
}
