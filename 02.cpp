#include <iostream>

int main(){
    int jour;
    float pi{3.14};
    float PI = 3.145;
    std::cout << "Entrez un nombre de jour: " << std::endl ;
    std::cin >> jour;
    std::cout << "Vous avez entre: " << jour << " jours" << std::endl;
    if (jour > 0)
    {
        std::cout << "Vous avez entre un nombre valide" << std::endl;
    }else{
        std::cout << pi << std::endl;
        std::cout << PI << std::endl;
    }
    
}