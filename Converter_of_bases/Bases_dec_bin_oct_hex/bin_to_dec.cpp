#include <utility>
#include <cmath>
#include <iostream>
#include <vector>

struct Convertor{

    int Number_dec;

    std::vector<int> Vl_bin;
    int Num_div = 0;

    Convertor NumBin_converted(std::string Num_bin){
        Convertor res;

        for (char caractere : Num_bin) {
            Vl_bin.push_back(caractere - '0'); // Converte o texto '0' ou '1' para número 0 ou 1
        }

        int resultado = 0;

        for (size_t i = 0; i < Vl_bin.size(); i++) {

            resultado = resultado * 2;
         
            resultado = resultado + Vl_bin[i];
        }

        res.Number_dec = resultado;

        return res;
    }
};

int main(){ 
    std::string Num_bin;

    std::cout << "Number in Binary:" << std::endl;
    std::cin >> Num_bin;

    Convertor Binary_number;
    Binary_number = Binary_number.NumBin_converted(Num_bin);

    std::cout << "Binary number converted to decimal:" <<std::endl;
    std::cout << "Binary: " << Num_bin << std::endl;
    std::cout << "Decimal: " << Binary_number.Number_dec;

    return 0;
}