#include <utility>
#include <cmath>
#include <iostream>
#include <vector>

struct Convertor{
    int Number_dec;

    std::vector<int> Vl_dec;
    int Num_div = 0;

    Convertor NumBin_converted(std::string Num_hex){
        Convertor res;

        for (char caractere : Num_hex) {
            char letra_maiuscula = toupper(caractere);

            if (letra_maiuscula >= '0' && letra_maiuscula <= '9'){
                Vl_dec.push_back(letra_maiuscula - '0');

            }
            if (letra_maiuscula >= 'A' && letra_maiuscula <= 'F'){
                Vl_dec.push_back((letra_maiuscula - 'A') + 10);

            }
        };

        int resultado = 0;

        for (size_t i = 0; i < Vl_dec.size(); i++) {

            resultado = resultado * 16;
        
            resultado = resultado + Vl_dec[i];
        }

        res.Number_dec = resultado;

        return res;
    }
};

int main(){ 
    std::string Num_hex;

    std::cout << "Number in Hexadecimal:" << std::endl;
    std::cin >> Num_hex;

    Convertor Binary_number;
    Binary_number = Binary_number.NumBin_converted(Num_hex);

    std::cout << "Hexadecimal number converted to decimal:" <<std::endl;
    std::cout << "Hexadecimal: " << Num_hex << std::endl;
    std::cout << "Decimal: " << Binary_number.Number_dec;

    return 0;
}