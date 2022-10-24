#include <iostream>
#include <fstream>
#include <ctime>

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define RESET	"\033[0m"

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));

	string extension;
	float size;
	string path;
	string filename;

	int persentage = 0;
	int persentage_remaining = 100;
	
	while (true)
	{
		cout << "Welcome to file-destructor\nChoose file extension (ex.: .mp4)\n";
		cin >> extension;
		cout << "Enter file size: (mb)\n";
		cin >> size;
		size *= 1048576;
		cout << "Enter file path: (ex.: C:\\Folder\\)\n";
		cin >> path;
		cout << "Enter file name:\n";
		cin >> filename;
		system("CLS");

		cout << "Extension:	" << extension << endl
			<< "Size:		" << size / 1048576 << "mb" << endl
			<< "Path:		" << path << endl
			<< "Filename:	" << filename << endl;
		cout << endl << "is everything correct? [" << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "]" << endl;
		string accept;
		cin >> accept;
		if (accept == "y")
		{
			ofstream out(path + filename + extension);

			if (out.is_open())
			{
				cout << "Writing new file...\n";

				for (int i = 0; i < size; i++)
				{
					out << char('A' + rand() % 26);

					if (i == (int)size / persentage_remaining && persentage_remaining >= 0)
					{
						persentage++;
						cout << persentage << "%\n";
						persentage_remaining--;
					}
				}
				cout << GREEN << "Done!" << RESET << endl;
				break;
			}
			else system("CLS"), cout << RED << "Something went wrong..." << RESET << endl;
		}
		else system("CLS");
	}
	return 0;
}
