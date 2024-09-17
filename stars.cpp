#include <iostream>
using namespace std;

void stars(){
    int number;
    cout << "Введите число: ";
    cin >> number;
    string stars_output = "";
    for (int i = 0; i < number; ++i) {
        stars_output += '*';
        cout << stars_output << '\n';
    }
    int step = 1;
    for (int i = 0; i <= number; ++i) {
        stars_output = stars_output.substr(0, number-step);
        cout << stars_output << '\n';
        step = step + 1;

    }
}

int main(){
    stars();
}
