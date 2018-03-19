#include "Serial.h"
#include <iostream>

using namespace std;

int main() {
    Serial serial(9600);

    string val;

    while (val!="fine") {
        getline(cin, val);

        serial.write(val);

        cout << serial.read() << endl;
    }
    return 0;
}