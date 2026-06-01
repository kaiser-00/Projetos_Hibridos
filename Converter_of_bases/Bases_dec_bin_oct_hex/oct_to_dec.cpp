#include <utility>
#include <cmath>
#include <iostream>
#include <vector>

struct Convertor{
    int Number_dec;

    std::vector<int> Vl_bin;
    int Num_div = 0;

    Convertor NumBin_converted(std::string Num_oct){
        Convertor res;

        int rest;

        for (char caractere : Num_oct) {
            Vl_bin.push_back(caractere - '0'); // Converte o texto '0' ou '1' para número 0 ou 1
        }

        int resultado = 0;

        for (size_t i = 0; i < Vl_bin.size(); i++) {

            resultado = resultado * 8;
        
    
            resultado = resultado + Vl_bin[i];
        }

        res.Number_dec = resultado;

        return res;
    }
};

int main(){ 
    std::string Num_oct;

    std::cout << "Number in Octal:" << std::endl;
    std::cin >> Num_oct;

    Convertor Binary_number;
    Binary_number = Binary_number.NumBin_converted(Num_oct);

    std::cout << "Binary number converted to decimal:" <<std::endl;
    std::cout << "Octal: " << Num_oct << std::endl;
    std::cout << "Decimal: " << Binary_number.Number_dec;

    return 0;
}