#include <iostream>
#include <vector>
#include <algorithm>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

    // 1. Seus métodos de ir para Decimal (os inversos)
int bin_to_dec(std::vector<int> leftOver_number) {
    int number = 0;

    for (size_t i = 0; i < leftOver_number.size(); i++) {
        number = number * 2;
        number = number + leftOver_number[i];
    }
return number; }
int oct_to_dec(std::vector<int> leftOver_number) { 
    int number = 0;

    for (size_t i = 0; i < leftOver_number.size(); i++) {
        number = number * 8;
        number = number + leftOver_number[i];
}
return number; }
int hex_to_dec(std::vector<int> leftOver_number) {
    int number = 0;

    for (size_t i = 0; i < leftOver_number.size(); i++) {
        number = number * 16;
        number = number + leftOver_number[i];
}
return number; }

// 2. Seus métodos de voltar do Decimal
std::vector<int> dec_to_bin(int number) { 
std::vector<int> Vl_bin;
    
int rest;
while (number != 0){ 
    rest = number % 2;
    number = number / 2;
    Vl_bin.push_back(rest);
}
std::reverse(Vl_bin.begin(), Vl_bin.end());
    
return Vl_bin; }
std::vector<int> dec_to_oct(int number) {
    std::vector<int> Vl_oct;
    
    int rest;
    while (number != 0){ 
        rest = number % 8;
        number = number / 8; 
        Vl_oct.push_back(rest);
    }
    std::reverse(Vl_oct.begin(), Vl_oct.end());

    return Vl_oct; }
std::vector<int> dec_to_hex(int number) { 
    std::vector<int> Vl_hex;
    
    int rest;
    while (number != 0){ 
        rest = number % 16;
        number = number / 16;
        Vl_hex.push_back(rest);
    }
    std::reverse(Vl_hex.begin(), Vl_hex.end());

    return Vl_hex; }


// O bloco mágico do pybind11 que empacota TUDO para o Python de uma vez só
PYBIND11_MODULE(Computational_bases, m) {
    m.doc() = "Computational bases conversion module";

    // Bindings for functions converting TO decimal
    m.def("bin_to_dec", &bin_to_dec, "Convert a binary vector to a decimal integer");
    m.def("oct_to_dec", &oct_to_dec, "Convert an octal vector to a decimal integer");
    m.def("hex_to_dec", &hex_to_dec, "Convert a hexadecimal vector to a decimal integer");
    
    // Bindings for functions converting FROM decimal
    m.def("dec_to_bin", &dec_to_bin, "Convert a decimal integer to a binary vector");
    m.def("dec_to_oct", &dec_to_oct, "Convert a decimal integer to a octal vector");
    m.def("dec_to_hex", &dec_to_hex, "Convert a decimal integer to a hexadecimal vector");
}