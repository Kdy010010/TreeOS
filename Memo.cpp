#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(const string& fileName) {
    ofstream file(fileName);
    file.close();
}

void editFile(const string& fileName) {
    cout << "메모를 입력하세요. 종료하려면 Ctrl + Z를 누르세요." << endl;

    ofstream file(fileName, ios::app); // 파일 끝에 추가
    string line;

    while (getline(cin, line)) {
        file << line << endl;
    }

    file.close();
}

void loadFile(const string& fileName) {
    ifstream file(fileName);

    if (file.is_open()) {
        cout << "메모 내용:" << endl;

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    } else {
        cout << "파일을 열 수 없습니다." << endl;
    }
}

int main() {
    string fileName;
    string fileExtension = ".txt";

    cout << "메모 파일의 이름을 입력하세요: ";
    cin >> fileName;

    fileName += fileExtension;

    createFile(fileName);

    int choice;

    do {
        cout << "\n1. 메모 편집\n2. 메모 불러오기\n3. 종료\n";
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1:
                editFile(fileName);
                break;
            case 2:
                loadFile(fileName);
                break;
            case 3:
                cout << "프로그램을 종료합니다." << endl;
                break;
            default:
                cout << "올바른 선택이 아닙니다. 다시 시도하세요." << endl;
        }

    } while (choice != 3);

    return 0;
}
