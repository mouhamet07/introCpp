#include <iostream>
#include <string> 

int main(){
    std::string welcomeM = " Bonjour";
    std::string name;
    std::cout << welcomeM << ",saisir votre nom : "<< std::endl;
    std::getline(std::cin , name);
    std::cout << "Bienvenue " << name << std::endl;
    return 0;
}