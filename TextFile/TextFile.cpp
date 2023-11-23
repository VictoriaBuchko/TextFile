#include <iostream>
#include <cstdio>
#include <cctype>
#include <Windows.h>
using namespace std;

#define Task 2

#if Task == 1 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* path = "myFile.txt";
    const int maxLineLength = 1000;
    char line[maxLineLength];

    FILE* myFile;

    fopen_s(&myFile, path, "r");
    if (myFile == NULL)
    {
        cout << "The file cannot be opened";
        return 1;
    }

    int longestLength = 0;

    while (fgets(line, maxLineLength, myFile) != NULL)
    {
        //проверка что строка завершается символом новой строки
        int lineLength = strlen(line);
        for (int i = 0; i < lineLength; i++) {

            if (line[i] == '\n') {

                line[i] = '\0';
                break;
            }
        }

        int currentLength = strlen(line);
        if (currentLength > longestLength)
        {
            longestLength = currentLength;
        }
    }

    cout << "The length of the longest line is: " << longestLength << endl;

    fclose(myFile);

    return 0;
}

#endif

#if Task == 2
#include <cstdio>

int main() {
    const char* path = "textFile.txt";

    FILE* textFile;

    const int wordLength = 100;
    char searchWord[wordLength];

    cout << "Enter the word to search: ";
    cin >> searchWord;

    //приводим слово к нижнему регистру
    for (int i = 0; i < strlen(searchWord); i++) {

        searchWord[i] = tolower(searchWord[i]);
    }

    fopen_s(&textFile, path, "r");
    if (textFile == NULL)
    {
        cout << "The file cannot be opened";
        return 1;
    }

    char word[wordLength];
    int count = 0;
    int ch;
    bool isWord = true;

    while ((ch = fgetc(textFile)) != EOF) {

        if (isalpha(ch)) {//проверяем является ли символ буквой

            int index = 0;
            while (isalpha(ch) || (ch == '.' || ch == ',' || ch == '!' || ch == '?')) {

                // если символ знак пунктуации, то заменяем его на конец строки '\0'
                word[index] = (ch == '.' || ch == ',' || ch == '!' || ch == '?') ? '\0' : ch;
                index ++;
                ch = fgetc(textFile);//считіваем следующий символ из файла
            }
            word[index] = '\0';// последний символ

            //сравниваем слово из файла с поискомым словом
            if (strlen(word) > 0 && strcmp(word, searchWord) == 0) {

                count++;
            }
        }
    }
    fclose(textFile);
    cout << "The word '" << searchWord << "' appears " << count << " times in the file" << endl;
    return 0;
}
#endif