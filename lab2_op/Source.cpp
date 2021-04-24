#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	int kilk = 20;
	int kilk_teams = 0, kilk_result = 0;
	string* mas_teams = new string[kilk];
	int* result = new int[kilk];
	string path_file1 = "C:\\Users\\Mike\\source\\repos\\lab2_op\\csv files\\premier_league1.csv";
	string path_file2 = "C:\\Users\\Mike\\source\\repos\\lab2_op\\csv files\\premier_league2.csv";
	string path_res = "result.csv";
	string mas_files[2] = {path_file1, path_file2 };
	for (int i = 0; i < 2; i++)
	{
		ifstream fIn(mas_files[i]);
		if (!fIn.is_open()) cout << "Cannot open";
		else cout << "open" << endl;
		string s, s_team;
		while (!fIn.eof())
		{
			getline(fIn, s);
			if (s.size() > 2)
			{
				cout << s << endl;
				for (int j = 0; j < s.size(); j++)
				{
					if (isalpha(s[j]) || isspace(s[j]))
					{
						s_team += s[j];
					}
				}
				if (s_team.size() != 0)
				{
					mas_teams[kilk_teams] = s_team;
					kilk_teams++;
					s_team = "";
				}
				char point = ',';
				int sum = 0;
				for (int j = 0; j < s.size(); j++)
				{
					if (!isalpha(s[j]) && !isspace(s[j]) && s[j] != point)
					{
						s_team += s[j];
						if (s_team.size() == 3)
						{
							if (s_team[0] > s_team[2])
							{
								sum += 3;
								s_team = "";
							}
							else if (s_team[0] == s_team[2])
							{
								sum += 1;
								s_team = "";
							}
							else s_team = "";;
						}
					}
				}
				result[kilk_result] = sum;
				kilk_result++;
			}
			else continue;
		}
		fIn.close();
	}
	for (int i = kilk - 1; i >= 0; i--)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			if (result[i] > result[k])
			{
				int temp1 = result[i];
				result[i] = result[k];
				result[k] = temp1;
				string temp2 = mas_teams[i];
				mas_teams[i] = mas_teams[k];
				mas_teams[k] = temp2;
			}
		}
	}
	//for (int i = 0; i < kilk; i++)
	//{
	//	cout << mas_teams[i] << "  ";
	//}
	//cout << endl;
	//for (int i = 0; i < kilk; i++)
	//{
	//	cout << result[i] << "  ";
	//}
	ofstream fOut(path_res);
	if (!fOut.is_open()) cout << "Cannot open";
	else
	{
		for (int i = 0; i < kilk; i++)
		{
			fOut << mas_teams[i] << ";" << result[i] << "\n";
		}
		fOut << /*"---------------------------------------" << "\n\t\t\t*/"Winner;" << mas_teams[0];
	}
	fOut.close();
}