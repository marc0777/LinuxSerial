#include "Serial.h"
#include <iostream>

using namespace std;

int main() {
    Serial serial(115200);

    string val = "";

    while (val!="fine") {
        cin >> val;
        serial.write(val);

        cout << serial.read() << endl;
    }
    return 0;
}