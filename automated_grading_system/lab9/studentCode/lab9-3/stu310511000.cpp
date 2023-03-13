#include <iostream>
#include <fstream>

using namespace std;
string alphabet[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...",
    "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
string numbers[10] = {
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

int main(int argc, char *argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    if (!infile)
    {
        cout << "Cannot open file" << endl;
        exit(1);
    }

    ofstream outfile;
    outfile.open(argv[2]);
    if (!outfile)
    {
        cout << "Cannot open output file" << endl;
        exit(1);
    }

    string str;
    if (string(argv[3]) == "e")
    {
        while (getline(infile, str))
        {
            for (int i = 0; i < str.length(); i++)
            {

                if (isalpha(str[i]))
                {
                    outfile << alphabet[str[i] - 'A'];
                    if (i != str.length() - 1)
                    {
                        outfile << "   ";
                    }
                }
                else if (isdigit(str[i]))
                {
                    outfile << numbers[(str[i] - '0' + 9) % 10];
                    if (i != str.length() - 1)
                    {
                        outfile << "   ";
                    }
                }
                else if (str[i] == ' ')
                {
                    outfile << "    ";
                }
            }
            outfile << endl;
        }
    }
    else if (string(argv[3]) == "d")
    {
        while (getline(infile, str))
        {
            for (int i = 0; i < str.length(); i++)
            {

                if (str[i] != ' ')
                {
                    // cout << "word" << endl;
                    string tmp = "";
                    while (i < str.length() && str[i] != ' ')
                    {
                        tmp = tmp + str[i];
                        i++;
                    }
                    bool found = false;
                    for (int i = 0; i < 26 && !found; i++)
                    {
                        if (tmp == alphabet[i])
                        {
                            outfile << char('A' + i);
                            found = true;
                        }
                    }
                    for (int i = 0; i < 10 && !found; i++)
                    {
                        if (tmp == numbers[i])
                        {
                            outfile << (i + 1) % 10;
                            found = true;
                        }
                    }
                }
                else if (str[i] == ' ')
                {
                    int count = 0;
                    while (str[i] == ' ')
                    {
                        count++;
                        i++;
                    }
                    // cout << "c: " << count << endl;
                    if (count > 6)
                    {
                        outfile << " ";
                    }
                }
                i--;
            }
            outfile << endl;
        }
    }
    infile.close();
    return 0;
}
