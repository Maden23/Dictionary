#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <dictword.h>

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();
    std::string lookFor(const std::string &word); // возвращает соответствующие строки
    DictWord *findMatch(const std::string &word); // проверяет наличие слова в словаре
    void addWord(const std::string &newWord);
    void deleteWord(DictWord *delWord);
    int count();
private:
    DictWord *root;
    int wordsCount; // количество слов с словаре
    void addWordTo(DictWord &word, DictWord* node);
    DictWord *findParent(DictWord *child); //ищет звено-родителя
};

#endif // DICTIONARY_H
