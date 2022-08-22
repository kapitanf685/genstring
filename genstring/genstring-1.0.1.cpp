// yasm_license_creator.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

//!! Preprocesor >> Preprocessor Definitions >> _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

/*char* replaceWord(const char* source, const char* oldWord, const char* newWord)
{
    char* result;
    int i, count = 0;
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    for (i = 0; source[i] != '\0'; i++)
    {
        count++;
        i += oldWordLen - 1;
    }

    result = (char*)malloc(i + count * (newWordLen - oldWordLen) + 1);

    i = 0;
    while (*source) {
        if (strstr(source, oldWord) == source) {

            strcpy(&result[i], newWord);

            i += newWordLen;
            source += oldWordLen;
        }
        else
            result[i++] = *source++;
    }

    result[i] = '\0';
    return result;
}*/

/*string replaceWords(string source, const char* oldWord, const char* newWord)
{
    int pos = 0;
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    while (pos <= source.length())
    {
        string::size_type found = source.find(oldWord, oldWordLen, pos + newWordLen - oldWordLen);
        if (found != string::npos)
        {
            source.replace(source.at(found), source.at(found+oldWordLen), newWord);
            //source.delete()
            //source.insert()
        }
        pos = pos + found + newWordLen - oldWordLen;
    }
    return source;
}*/

void file_to_string(fstream* fout, const char* str_name, const char* fin_name) {
    string c_content;
    c_content.append("/* This file auto-generated from ").append(fin_name).append(" by genstring.py - don't edit it */\n\n");
    c_content.append("static const char* ").append(str_name).append("[] = {\n");

    ifstream infile; infile.open(fin_name, ios_base::in);
    std::string line, all;
    while (getline(infile, line))
    {
        //c_content = c_content + "\"" + line1;                
        //string data = replaceWords(line.c_str(), "\\", "\\\\");
        //data = replaceWords(data, "\"", "\\\"");
        //content = content + data;
        c_content.append("    \"").append(line).append("\",\n");
    }

    c_content.append("};");

    fout->write(c_content.c_str(), c_content.length());
    fout->close();

}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: genstring.py <string> <outfile> <file>");
        exit(0);
    }
    fstream outfile; outfile.open(argv[2], ios_base::out);
    file_to_string(&outfile, argv[1], argv[3]);
    outfile.close();
    exit(0);
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
