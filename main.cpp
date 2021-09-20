#include <iostream>
#include <fstream>
#define MAX_SIZE_STACK 100
/**
8. ��������� ����, ������ ��������� ������.
� ��������� ����� F �������� ��� ������ ������� ���������� ����:
<�������> ::= <�����> | �(<�������>, <�������>) | m(<�������>, <�������>)
<�����> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9,
��� � ���������� ������� max, � m - min. ��������� ��� ����� ����� �������� ������ �������.
��������, �(M(4,5),m(6,M(8,3))).
��� ���������� ��� ���� ������������ ������.
*/

int Stack[MAX_SIZE_STACK];
int t;
void init(); // ������������� �����
void Push(int); // �������� � ����
int Pop(); // ������� �� �����
int Top(); // �������� �������� �������� �������� �����
bool IsEmpty(); // ���������, �������� �� ���� ������
void M(std::ifstream& fin);
void m(std::ifstream& fin);

int main()
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
    std::ifstream fin("F.txt"); //������� ���� ��� ������
    if (!fin.is_open()) // ���� ������� ���� �� ������
        std::cout << "������� ���� �� ����� ���� ������!\n"; // �������� �� ����
    else
    {
        char k; init(); // ������������� �����
        fin >> k;
        switch (k)
        {
        case 'M': M(fin); break;
        case 'm': m(fin); break;
        }
        std::ofstream fout("outputDATA.txt"); //������� ���� ��� ������
        if (!fout.is_open()) // ���� �������� ���� �� ������
            std::cout << "�������� ���� �� ����� ���� ������!\n"; // �������� �� ����
        else { fout << Pop(); fout.close(); // ��������� �������� ����  }
        fin.close(); // ��������� ������� ����
    }
    return 0;
}


void init() { t = -1; }// ������������� �����
void Push(int a) // �������� � ����
{
    if (t == MAX_SIZE_STACK) // �������� �� ������� ��������� �������� � ������ ����
    {
        std::cout << "������� ��������� �������� � ������ ����";
        exit(EXIT_FAILURE);
    }
    else Stack[++t] = a;
}
int Pop() // ������� �� �����
{
    if (t == -1) // �������� �� ������� ������� ������� �� ������� �����
    {
        printf("������� ������ �� ������� �����");
        exit(EXIT_FAILURE);
    }
    else return(Stack[t--]);
}
int Top() { if (!IsEmpty()) return(Stack[t]); else return EOF; } // �������� �������� �������� �������� �����
bool IsEmpty() { return(t == -1); } // ���������, �������� �� ���� ������

void m(std::ifstream& fin)
{
    while (!fin.eof())
    {
        char k; int a, b;
        fin >> k;
        switch (k)
        {
        case 'M': M(fin); break;
        case 'm': m(fin); break;
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':  Push(k - '0'); break;
        case ')':  a = Pop(); b = Pop(); Push(a < b ? a : b); return;
        }
    }
}

void M(std::ifstream& fin)
{
    while (!fin.eof())
    {
        char k; int a, b;
        fin >> k;
        switch (k)
        {
        case 'M':  M(fin); break;
        case 'm':  m(fin); break;
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':  Push(k - '0'); break;
        case ')':  a = Pop(); b = Pop(); Push(a > b ? a : b); return;
        }
    }
}

