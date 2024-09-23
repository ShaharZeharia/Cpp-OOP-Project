#include "GeneralFunctions.h"

//General Functions
int getIntWithPrompt(const string& message)
{
    int num;
    cleanBuffer();
    cout << message << endl;
    cin >> num;
    return num;
}

float getFloatWithPrompt(const string& message)
{
    float num;
    cleanBuffer();
    cout << message << endl;
    cin >> num;
    return num;
}

int getEnumSelection(const string& message, const string types[], const int numOfTypes) {
    int enumChoice;
    do {
        cleanBuffer();
        cout << message << endl;
        for (int i = 0; i < numOfTypes; ++i) {
            cout << i + 1 << ") " << types[i] << endl;
        }
        cin >> enumChoice;
    } while (enumChoice < 1 || enumChoice > numOfTypes);

    return enumChoice - 1;  // Adjust to zero-based index
}

string getStrExactName(const string& msg) {
    string str;
    cleanBuffer();
    cout << msg << "\n";
    getline(cin, str);
    return str;
}

void cleanBuffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}