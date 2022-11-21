#include <iostream>
#include <string>

using namespace std;

class kain {
    public:
        int cerah;
        char nyaman;
        string jenis;

        kain (int c, char n, const char* s){
            cerah = c;
            nyaman = n;
            jenis = s;
        }

        void show(){
            cout << &cerah << endl;
            cout << &nyaman << endl;
            cout << &jenis << endl;
        }
};

int main(int argc, char const *argv[])
{
    kain batik (20, 'y', "tipis");
    batik.show();

    bool tr = 1;
    cout << &tr << endl;

    return 0;
}