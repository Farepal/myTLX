#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Orang {
    public:
        string jenis;
        int iq;

        Orang (const char *jenis, int iq){
            Orang::jenis = jenis;
            Orang::iq = iq;
        }

        void tes(const int &iq){
            Orang::iq -= iq;
        }

        void show(){
            cout << jenis << endl;
            cout << iq << endl;
        }

        void showA(){
            cout << "jenis " << jenis << endl;
            cout << "iq " << &iq << endl;
        }
};

int main(int argc, char const *argv[])
{
    //_pid_t
    cout << __SIZEOF_LONG_DOUBLE__ << endl;
    return 0;
}