#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int acidentes[10][30][4] = {0};
    ifstream arquivo("ACIDENTES.txt");

    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            int avenida = stoi(linha.substr(0, 2));
            int rua = stoi(linha.substr(2, 2));
            int ano = stoi(linha.substr(4, 4));
            int qtde = stoi(linha.substr(8, 2));

            acidentes[avenida - 1][rua - 11][ano - 2016] = qtde;
        }

        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo ACIDENTES.txt." << endl;
        return 1; 
    }

    while (true) {
        cout << "Menu de Opções:" << endl;
        cout << "a) Quantos acidentes ocorreram na avenida X no ano AAAA" << endl;
        cout << "b) Quantos acidentes ocorreram no cruzamento da avenida X com a rua Y durante o período pesquisado" << endl;
        cout << "c) Quais os cruzamentos com mais de 10 acidentes no período pesquisado" << endl;
        cout << "d) Qual o cruzamento mais perigoso de todos, e em que ano ocorreu" << endl;
        cout << "e) Exibir todos os dados de acidentes" << endl;
        cout << "0) Sair" << endl;

        char opcao;
        cin >> opcao;

        if (opcao == '0') {
            break;
        } else if (opcao == 'a' || opcao == 'A') {
            int avenida, ano;
            cout << "Digite o número da avenida (1 a 10): ";
            cin >> avenida;
            cout << "Digite o ano (2016 a 2019): ";
            cin >> ano;

            if (avenida >= 1 && avenida <= 10 && ano >= 2016 && ano <= 2019) {
                int totalAcidentes = acidentes[avenida - 1][0][ano - 2016];
                cout << "Total de acidentes na avenida " << avenida << " no ano " << ano << ": " << totalAcidentes << endl;
            } else {
                cout << "Avenida ou ano fora do intervalo válido." << endl;
            }
        } else if (opcao == 'b' || opcao == 'B') {
            int avenida, rua;
            cout << "Digite o número da avenida (001 a 010): ";
            string input;
            cin >> input;
            avenida = stoi(input);
        
            cout << "Digite o número da rua (011 a 029): ";
            cin >> input;
            rua = stoi(input);
        
            if (avenida >= 1 && avenida <= 10 && rua >= 11 && rua <= 29) {
                int totalAcidentes = 0;
                for (int ano = 2016; ano <= 2019; ano++) {
                    totalAcidentes += acidentes[avenida - 1][rua - 11][ano - 2016];
                }
                cout << "Total de acidentes no cruzamento da avenida " << avenida << " com a rua " << rua << " durante o período pesquisado: " << totalAcidentes << " acidentes." << endl;
            } else {
                cout << "Avenida ou rua fora do intervalo válido." << endl;
            }
        } else if (opcao == 'c' || opcao == 'C') {
            struct Cruzamento {
                int avenida;
                int rua;
                int totalAcidentes;
            };

            vector<Cruzamento> cruzamentos;

            for (int av = 0; av < 10; av++) {
                for (int r = 0; r < 30; r++) {
                    int totalAcidentes = 0;
                    for (int ano = 0; ano < 4; ano++) {
                        totalAcidentes += acidentes[av][r][ano];
                    }
                    if (totalAcidentes > 10) {
                        Cruzamento cruzamento;
                        cruzamento.avenida = av + 1;
                        cruzamento.rua = r + 11;
                        cruzamento.totalAcidentes = totalAcidentes;
                        cruzamentos.push_back(cruzamento);
                    }
                }
            }

            sort(cruzamentos.begin(), cruzamentos.end(), [](Cruzamento a, Cruzamento b) {
                return a.totalAcidentes > b.totalAcidentes;
            });

            cout << "Cruzamentos com mais de 10 acidentes são:" << endl;
            for (const Cruzamento &cruzamento : cruzamentos) {
                cout << "Avenida: " << cruzamento.avenida << ", Rua: " << cruzamento.rua << ", Total de Acidentes: " << cruzamento.totalAcidentes << endl;
            } 
        } else if (opcao == 'd' || opcao == 'D') {
            int maxAcidentes = 0;
            int anoMaisPerigoso = 2016;
            int avMaisPerigosa = 1;
            int ruaMaisPerigosa = 11;

            for (int av = 0; av < 10; av++) {
                for (int r = 0; r < 30; r++) {
                    for (int ano = 0; ano < 4; ano++) {
                        if (acidentes[av][r][ano] > maxAcidentes) {
                            maxAcidentes = acidentes[av][r][ano];
                            anoMaisPerigoso = ano + 2016;
                            avMaisPerigosa = av + 1;
                            ruaMaisPerigosa = r + 11;
                        }
                    }
                }
            }
            cout << "O cruzamento mais perigoso: avenida " << avMaisPerigosa << " com a rua " << ruaMaisPerigosa
                 << " no ano " << anoMaisPerigoso << " com um total de " << maxAcidentes << " acidentes." << endl;
        } else if (opcao == 'e' || opcao == 'E') {
            for (int av = 0; av < 10; av++) {
                for (int r = 0; r < 30; r++) {
                    for (int ano = 0; ano < 4; ano++) {
                        int qtde = acidentes[av][r][ano];
                        cout << "Avenida: " << (av + 1) << ", Rua: " << (r + 11) << ", Ano: " << (ano + 2016) << ", Acidentes: " << qtde << endl;
                    }
                }
            }
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    return 0;
}
