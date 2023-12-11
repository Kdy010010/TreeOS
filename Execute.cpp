#include <iostream>
#include <cstdlib>

int main() {
    std::string app_name;
    std::cout << "Enter the application name to execute: ";
    std::getline(std::cin, app_name);

    std::string app_path = std::string(get_current_dir_name()) + "/" + app_name;
    try {
        system(app_path.c_str());
    } catch (const std::exception& e) {
        std::cerr << "Error executing the application: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
