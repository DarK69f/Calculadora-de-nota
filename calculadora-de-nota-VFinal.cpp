#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <cctype>
#include <algorithm>


using namespace std;

struct Aluno {
    string nome;
    string rgm;
    string curso;
    float A1;
    float A2;
    float AF = 0.0;

    float calcularNotaFinal() const {
        float n1 = A1, n2 = A2;
        if ((n1 + n2) < 6) {
            if (n1 < n2 && AF > n1) n1 = AF;
            else if (n2 <= n1 && AF > n2) n2 = AF;
        }
        return n1 + n2;
    }

    string status() const {
        return (calcularNotaFinal() >= 6) ? "Aprovado" : "Reprovado";
    }
};

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void cadastrarAluno(vector<Aluno>& alunos) {
    Aluno novo;
    cout << "\n--- Cadastro de Aluno ---\n";
    cout << "Nome completo: ";
    limparBuffer();
    getline(cin, novo.nome);

    cout << "RGM: ";
    getline(cin, novo.rgm);

    cout << "Curso: ";
    getline(cin, novo.curso);

    do {
        cout << "Nota A1 (0 a 5): ";
        cin >> novo.A1;
    } while (novo.A1 < 0 || novo.A1 > 5);

    do {
        cout << "Nota A2 (0 a 5): ";
        cin >> novo.A2;
    } while (novo.A2 < 0 || novo.A2 > 5);

    if ((novo.A1 + novo.A2) < 6) {
        char resposta;
        cout << "Fez atividade extra? (s/n): ";
        cin >> resposta;

        if (resposta == 's' || resposta == 'S') {
            do {
                cout << "Nota AF (0 a 5): ";
                cin >> novo.AF;
            } while (novo.AF < 0 || novo.AF > 5);
        }
    }

    alunos.push_back(novo);
    cout << "Aluno cadastrado com sucesso!\n";
}

void listarAlunos(const vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    cout << "\n--- Lista de Alunos ---\n";
    for (size_t i = 0; i < alunos.size(); ++i) {
        const Aluno& a = alunos[i];
        float final = a.calcularNotaFinal();

        cout << "\n" << i + 1 << ") " << a.nome
             << "\nRGM: " << a.rgm
             << "\nCurso: " << a.curso
             << fixed << setprecision(2)
             << "\nNotas: A1=" << a.A1 << ", A2=" << a.A2 << ", AF=" << a.AF
             << "\nNota Final: " << final
             << "\nStatus: " << a.status() << "\n";
    }
}

void editarNotas(vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado para editar.\n";
        return;
    }

    listarAlunos(alunos);

    int index;
    cout << "\nDigite o número do aluno que deseja editar: ";
    cin >> index;

    if (index < 1 || index > (int)alunos.size()) {
        cout << "Índice inválido.\n";
        return;
    }

    Aluno& a = alunos[index - 1];

    cout << "Editando notas de: " << a.nome << "\n";

    do {
        cout << "Nova nota A1 (0 a 5): ";
        cin >> a.A1;
    } while (a.A1 < 0 || a.A1 > 5);

    do {
        cout << "Nova nota A2 (0 a 5): ";
        cin >> a.A2;
    } while (a.A2 < 0 || a.A2 > 5);

    if ((a.A1 + a.A2) < 6) {
        char resposta;
        cout << "Fez atividade extra? (s/n): ";
        cin >> resposta;

        if (resposta == 's' || resposta == 'S') {
            do {
                cout << "Nota AF (0 a 5): ";
                cin >> a.AF;
            } while (a.AF < 0 || a.AF > 5);
        }
    } else {
        a.AF = 0.0;
    }

    cout << "Notas atualizadas com sucesso!\n";
}

void calcularMediaTurma(const vector<Aluno>& alunos) {
    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        return;
    }

    float soma = 0.0;
    for (size_t i = 0; i < alunos.size(); ++i) {
        soma += alunos[i].calcularNotaFinal();
    }

    float media = soma / alunos.size();
    cout << "\nMédia da turma: " << fixed << setprecision(2) << media << "\n";
}

int main() {
	
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	
    vector<Aluno> alunos;
    int opcao;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Cadastrar Aluno\n";
        cout << "2. Listar Alunos\n";
        cout << "3. Editar Notas\n";
        cout << "4. Calcular Média da Turma\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos);
                break;
            case 2:
                listarAlunos(alunos);
                break;
            case 3:
                editarNotas(alunos);
                break;
            case 4:
                calcularMediaTurma(alunos);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
