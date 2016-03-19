#include <iostream>
#include "wx/wx.h"

using namespace std;

int main() {
    wxApp app;
    app.CheckSignal();
    cout << "fagit" << endl;
    return 0;
}