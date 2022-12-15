//Вариант 6
// В текстовом файле input.txt записан русский текст. Найти в тексте слова,
// содержащие последовательность из четырех алфавитно упорядоченных букв,
// записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
// Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
bool Diap(char x)
{
    bool flag = false;
    if (65 <= int(x) && int(x) <= 90)
        flag = true;
    return flag;
}
int main()
{
    std::ifstream in("input.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);
    std::string words;
    int size;
    std::string slovo;
    while (in>>slovo)//пока есть слова
    {
        words="";
        std::string slovocopy = slovo;
        //bool flag=false;
        for (int j = 0; j < slovo.length(); j++)
            if (Diap(slovo[j]) == true)
                slovocopy[j] = char(int(slovo[j])+32);//переделываем заглавные буквы в строчные
        //std::cout<<slovo<<": "<<slovocopy<<std::endl;

        if (slovo.length()>3)
        {
            for (int i = 0; i < slovo.length() - 3; i++)
            {
                if (int(slovocopy[i]) < int(slovocopy[i+1]) && int(slovocopy[i+1]) < int(slovocopy[i+2]) && int(slovocopy[i+2]) < int(slovocopy[i+3]))
                {
                    //std::cout << slovo << ": " << slovo[i]<< slovo[i + 1] << slovo[i + 2] << slovo[i + 3] << std::endl;
                    //flag = true;
                    for(int k=0; k< 4;k++)
                    {
                        words += slovocopy[i+k];//последовательность строчных букв
                        if (Diap(slovo[i+k])!= true)
                            slovo[i+k]=(char)((int)slovo[i+k] -32);//буквы дклаем заглавными
                    }
                    break;

                }

            }

        }
        out<<slovo;//выводим слово
        if (words.length() != 0)//если существует последовательность
            out<<"(" << words << ")";//выводим её в скобках
        out<< " ";

    }
    in.close();
    return 0;
}
