#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("INPUT.TXT");
	
	if (!fin.is_open())												//�������� �������� �����
	{
		cout << "Warning open \"INPUT.TXT\" file!" << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "File \"INPUT.TXT\" is open!" << endl;
	}
	
	char num[100];
	int len[55];
	int a = 0;
	int s = 0;
	int k = 0;
	while (fin.get(num[a]))											//���������� �� �����
	{
		cout << num[a];
		a++;
	}
	cout << endl;
	
	for (int i = 0; i < a; i++)										//������� ������� ��������
	{
		if (num[i] == '1')
		{
			s++;
		}
		if ((num[i] == '1') && (num[i + 1] != '1'))					//����� ����� ������������������ ��������
		{
			len[k] = s;
			k++;
			s = 0;
		}
	}

	int maxlength = len[0];
	for (int i = 0; i < k; i++)										//����������� ������������� ���������� ����������� ��������
	{
		if (maxlength < len[i])
		{
			maxlength = len[i];
		}
	}
	
	int *seq = new int[maxlength];
	
	cout << "Desired Sequence: ";
	for (int i = 0; i < maxlength; i++)								//��������� �� ����� ������������������ ��������
	{
		seq[i] = 1;
		cout << seq[i];
	}
	cout << endl << "Sequence Length: " << maxlength << endl;
	
	fin.close();

	ofstream fout;
	fout.open("OUTPUT.TXT");						
	
	if (!fout.is_open())											//�������� �������� �����
	{
		cout << "Warning open \"OUTPUT.TXT\" file!" << endl;
		system("pause");
		return 1;
	}
	else
	{
		cout << "File \"OUTPUT.TXT\" is open!" << endl;
	}

	fout << "Desired Sequence: ";
	for (int i = 0; i < maxlength; i++)								//������ ������������������ �������� � ����
	{
		fout << seq[i];
	}
	fout << endl << "Sequence Length: " << maxlength << endl;

	fout.close();

	delete[]seq;
	system("pause");
	return 0;
}