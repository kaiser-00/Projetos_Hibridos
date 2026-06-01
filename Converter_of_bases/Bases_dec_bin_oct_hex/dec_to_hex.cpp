#include <utility>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

struct Convertor{
    
    std::vector<int> Vl_bin;
    int Num_div = 0;

    Convertor NumBin_converted(int Num_dec){
        Convertor res;

        int rest;

        for (Num_dec; Num_dec != 0;){
            rest = Num_dec % 16;
            Num_dec = Num_dec / 16;

            Num_div = Num_div + 1;
            
            res.Vl_bin.push_back(rest);
        }

        res.Num_div = Num_div;

        return res;
    }
};

int main(){ 
    int Num_dec;
    // O alfabeto só precisa ir até o F (índice 15)
    std::vector<std::string> alfabeto{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                                      "A", "B", "C", "D", "E", "F"};

    std::cout << "Number in Decimal:" << std::endl;
    std::cin >> Num_dec;

    Convertor Binary_number; // Aqui armazena o cálculo hexadecimal
    Binary_number = Binary_number.NumBin_converted(Num_dec);

    std::cout << "Number converted to Hexadecimal:" << std::endl;
    std::cout << "Decimal: " << Num_dec << std::endl;
    std::cout << "Hexadecimal: ";

    int Tm_bin = Binary_number.Num_div;
    int list = Tm_bin - 1;

    // Começamos o contador em 0 para cobrir todo o tamanho do vetor de forma padrão
    for (int i = 0; i < Tm_bin; ++i){
        // A MÁGICA ESTÁ AQUI: Passamos todos os números de dentro do vetor 
        // pelo filtro do alfabeto antes de exibir!
        int resto_atual = Binary_number.Vl_bin[list];
        std::cout << alfabeto[resto_atual];

        list = list - 1;
    }
    
    std::cout << std::endl;

    return 0;
}