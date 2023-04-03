#include <bits/stdc++.h>

using namespace std;
void func3()
{
    cout << "func3 before" << endl;
}
void func2()
{
    cout << "func2 before" << endl;
    func3();
    cout << "func2 after" << endl;
    func3();
    cout << "func2 after2" << endl;
}

void func1()
{
    cout << "func1 before" << endl;
    func2();
    cout << "func1 after" << endl;
    func2();
    cout << "func1 after2" << endl;
}

void func(int n)
{
    if (n == 0)
        return;
    
    func(n - 1);
    cout << n << endl;
}

int main()
{
    func(5);

    return 0;
}