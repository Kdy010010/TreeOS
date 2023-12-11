#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string user_input;
    while (true) {
        std::cout << "입력: ";
        std::getline(std::cin, user_input);
        if (user_input == "help") {
            std::cout << "도움말 출력" << std::endl;
        } else if (user_input == "cmd") {
            try {
                system("./command.o");
            } catch (const std::exception& e) {
                std::cout << "command.o 파일을 찾을 수 없습니다." << std::endl;
            }
        } else if (user_input == "execute") {
            std::string file_name;
            std::cout << "실행할 파일명 입력: ";
            std::getline(std::cin, file_name);
            if (file_name == "execute.o") {
                try {
                    system(file_name.c_str());
                } catch (const std::exception& e) {
                    std::cout << file_name << " 파일을 찾을 수 없습니다." << std::endl;
                }
            } else {
                std::cout << "execute 명령은 execute.o 파일에만 적용됩니다." << std::endl;
            }
        } else if (user_input == "editdir") {
            std::string new_directory;
            std::cout << "새로운 디렉토리 경로 입력: ";
            std::getline(std::cin, new_directory);
            try {
                if (chdir(new_directory.c_str()) == 0) {
                    std::cout << "디렉토리가 " << new_directory << "로 변경되었습니다." << std::endl;
                } else {
                    std::cout << "디렉토리를 찾을 수 없습니다." << std::endl;
                }
            } catch (const std::exception& e) {
                std::cout << "디렉토리를 찾을 수 없습니다." << std::endl;
            }
        } else if (user_input == "exit" || user_input == "quit") {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        } else {
            std::cout << "알 수 없는 명령입니다." << std::endl;
        }
    }
    return 0;
}

