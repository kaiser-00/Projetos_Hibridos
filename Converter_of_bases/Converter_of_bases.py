import os
# Isso avisa o Python onde o seu compilador e as DLLs dele estão guardados
os.add_dll_directory(r"C:\msys64\ucrt64\bin")

import sys
from PySide6.QtWidgets import QApplication, QWidget, QLineEdit, QFormLayout
import Computational_bases 

class WindowSchool(QWidget):
    def __init__(self):
        super().__init__()
        
        # 1. Configuração da Janela
        self.setWindowTitle("Bases converter")
        self.resize(350, 250)
        
        # 2. Criando as entradas de texto
        self.dec_imput = QLineEdit()
        self.bin_imput = QLineEdit()
        self.oct_imput = QLineEdit()
        self.hex_imput = QLineEdit()

        # 3. Organizando com o QFormLayout
        layout = QFormLayout()
        layout.addRow("Type a number in decimal below:", self.dec_imput)
        layout.addRow("Type a number in binary below:", self.bin_imput)
        layout.addRow("Type a number in octal below:", self.oct_imput)
        layout.addRow("Type a number in hexadecimal below:", self.hex_imput)

        layout.setRowWrapPolicy(QFormLayout.WrapAllRows)
        self.setLayout(layout)

        # Sempre que o texto do Decimal mudar, o loop avisa e roda a função abaixo.
        self.dec_imput.textChanged.connect(self.convert_of_dec)
        self.bin_imput.textChanged.connect(self.convert_of_bin)
        self.oct_imput.textChanged.connect(self.convert_of_oct)
        self.hex_imput.textChanged.connect(self.convert_of_hex)
      
    def convert_of_dec(self):
        text_dec = self.dec_imput.text()
        
        # Se o usuário apagar o decimal, limpa TODOS os campos automáticos
        if not text_dec:
            self.bin_imput.setText("")
            self.oct_imput.setText("")
            self.hex_imput.setText("")
            return

        try:
            # Pegamos APENAS o número decimal, que é o que precisamos para calcular o resto
            number_dec = int(text_dec)
            
            # --- 1. CÁLCULO DO BINÁRIO ---
            value_list_bin = Computational_bases.dec_to_bin(number_dec)
            value_bin_joing = "".join(str(x) for x in value_list_bin)
            
            self.bin_imput.blockSignals(True)
            self.bin_imput.setText(value_bin_joing)
            self.bin_imput.blockSignals(False)      

            # --- 2. CÁLCULO DO OCTAL ---
            value_list_oct = Computational_bases.dec_to_oct(number_dec)
            value_oct_joing = "".join(str(x) for x in value_list_oct)
            
            self.oct_imput.blockSignals(True)
            self.oct_imput.setText(value_oct_joing)
            self.oct_imput.blockSignals(False)
            
            # --- 3. CÁLCULO DO HEXADECIMAL ---
            value_list_hex = Computational_bases.dec_to_hex(number_dec)
            
            # Uma lista simples para mapear os restos maiores que 9 para letras (A-F)
            hex_table = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"]
            
            # Mapeia cada resto retornado pelo C++ direto na tabela hexadecimal
            value_hex_joing = "".join(hex_table[int(x)] for x in value_list_hex)
            
            self.hex_imput.blockSignals(True)
            self.hex_imput.setText(value_hex_joing)
            self.hex_imput.blockSignals(False)

        except ValueError:
            pass
        
    def convert_of_bin(self):
        text_bin = self.bin_imput.text()

        if not text_bin:
            self.dec_imput.setText("")
            self.oct_imput.setText("")
            self.hex_imput.setText("")
            return

        try:
            bin_table = [int(x) for x in text_bin]

            value_dec_str = Computational_bases.bin_to_dec(bin_table)
            value_dec = str(value_dec_str)

            self.dec_imput.blockSignals(True)
            self.dec_imput.setText(value_dec)
            self.dec_imput.blockSignals(False)

            value_list_oct = Computational_bases.dec_to_oct(int(value_dec))
            value_oct = "".join(str(x) for x in value_list_oct)

            self.oct_imput.blockSignals(True)
            self.oct_imput.setText(value_oct)
            self.oct_imput.blockSignals(False)

            value_hex_list = Computational_bases.dec_to_hex(int(value_dec))
            hex_table = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"]
            
            value_hex = "".join(hex_table[int(x)] for x in value_hex_list)

            self.hex_imput.blockSignals(True)
            self.hex_imput.setText(value_hex)
            self.hex_imput.blockSignals(False)

        except ValueError:
            pass

    def convert_of_oct(self):
        text_oct = self.oct_imput.text()

        if not text_oct:
            self.dec_imput.setText("")
            self.bin_imput.setText("")
            self.hex_imput.setText("")
            return

        try:
            oct_table = [int(x) for x in text_oct]

            value_dec_str = Computational_bases.oct_to_dec(oct_table)
            value_dec = str(value_dec_str)

            self.dec_imput.blockSignals(True)
            self.dec_imput.setText(value_dec)
            self.dec_imput.blockSignals(False)

            value_list_bin = Computational_bases.dec_to_bin(int(value_dec))
            value_bin = "".join(str(x) for x in value_list_bin)

            self.bin_imput.blockSignals(True)
            self.bin_imput.setText(value_bin)
            self.bin_imput.blockSignals(False)

            value_hex_list = Computational_bases.dec_to_hex(int(value_dec))
            hex_table = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"]
            
            value_hex = "".join(hex_table[int(x)] for x in value_hex_list)

            self.hex_imput.blockSignals(True)
            self.hex_imput.setText(value_hex)
            self.hex_imput.blockSignals(False)

        except ValueError:
            pass

    def convert_of_hex(self):
        text_hex = self.hex_imput.text()

        if not text_hex:
            self.dec_imput.setText("")   
            self.bin_imput.setText("")
            self.oct_imput.setText("")
            return

        try:
            table_of_symbol = {"0" : 0, "1" : 1, "2" : 2, "3" : 3, "4" : 4, "5" : 5, "6" : 6, "7" : 7,
            "8" : 8, "9" : 9, "A" : 10, "B" : 11, "C" : 12, "D" : 13, "E" : 14, "F" : 15}
            
            hex_list = [table_of_symbol[x] for x in text_hex.upper()]

            value_dec_str = Computational_bases.hex_to_dec(hex_list)
            value_dec = str(value_dec_str)

            self.dec_imput.blockSignals(True)
            self.dec_imput.setText(value_dec)
            self.dec_imput.blockSignals(False)

            value_list_bin = Computational_bases.dec_to_bin(int(value_dec))
            value_bin = "".join(str(x) for x in value_list_bin)

            self.bin_imput.blockSignals(True)
            self.bin_imput.setText(value_bin)
            self.bin_imput.blockSignals(False)

            value_list_oct = Computational_bases.dec_to_oct(int(value_dec))
            value_oct = "".join(str(x) for x in value_list_oct)

            self.oct_imput.blockSignals(True)
            self.oct_imput.setText(value_oct)
            self.oct_imput.blockSignals(False)

        except (ValueError, KeyError):
            pass



# Inicialização padrão do sistema de janelas
if __name__ == "__main__":
    app = QApplication(sys.argv)
    janela = WindowSchool()
    janela.show()
    sys.exit(app.exec())