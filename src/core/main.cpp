#include <iostream>
#include "wx/wx.h"

using namespace std;

int main() {
    wxApp app;
    app.CheckSignal();
    cout << "fagot" << endl;
    return 0;
}