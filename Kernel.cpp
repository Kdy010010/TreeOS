#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    while (true) {
        std::string user_input;
        std::cout << "명령어를 입력하세요: ";
        std::getline(std::cin, user_input);
        
        if (user_input == "help") {
            std::cout << "도움말: help - 도움말 표시, cmd - command.o 실행" << std::endl;
        } else if (user_input == "cmd") {
            system("./command.o");
        } else if (user_input.substr(user_input.length() - 2) == ".o") {
            std::string filename = user_input.substr(0, user_input.length() - 2);
            if (std::ifstream(filename)) {
                system(("./" + filename).c_str());
            } else {
                std::cout << "파일이 존재하지 않습니다: " << user_input << std::endl;
            }
        } else {
            std::cout << "알 수 없는 명령어입니다." << std::endl;
        }
    }
    return 0;
}
