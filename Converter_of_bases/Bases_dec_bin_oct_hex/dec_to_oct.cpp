#include <utility>
#include <cmath>
#include <iostream>
#include <vector>

struct Convertor{

    std::vector<int> Vl_bin;
    int Num_div = 0;

    Convertor NumBin_converted(int Num_dec){
        Convertor res;

        int rest;

        for (Num_dec; Num_dec != 0;){
            rest = Num_dec % 8;
            Num_dec = Num_dec / 8;

            Num_div = Num_div + 1;
            
            res.Vl_bin.push_back(rest);
        }

        res.Num_div = Num_div;

        return res;
    }
};

int main(){ 
    int Num_dec, Num_oct, Num_hex, Num_bin;

    std::cout << "Number in Decimal:" << std::endl;
    std::cin >> Num_dec;

    Convertor Binary_number;
    Binary_number = Binary_number.NumBin_converted(Num_dec);

    std::cout << "Octal number converted to decimal:" <<std::endl;
    std::cout << "Decimal: " << Num_dec << std::endl;
    std::cout << "Octal: ";

    int Tm_bin = Binary_number.Num_div;
    int list = Tm_bin - 1;

    for (int i = 0; i < Tm_bin; ++i){
        std::cout << Binary_number.Vl_bin[list];

        list = list - 1;
    }
    return 0;
}