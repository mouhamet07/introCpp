#include <iostream>

int main(){
    for(int i = 1; i <=10 ; i++){
        std::cout << i << std::endl;
        if(i!=5){
            std::cout << "different de 5" << std::endl;
            continue;
        }else{
            std::cout << "On a atteint 5" << std::endl;
            break;
        }
    }
    return 1;
}