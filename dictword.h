#ifndef DICTWORD_H
#define DICTWORD_H
#include <string>
#include <QList>


class DictWord
{
public:
    DictWord();
    DictWord(std::string val, QList<std::string> list);
    DictWord(const DictWord &source);
    ~DictWord();

    DictWord *left, *right;

    void addString(const std::string &newString);
    QList<std::string> getStrings() const;
    std::string getValue() const;

    bool operator <(DictWord &otherWord);
    bool operator >(DictWord &otherWord);
    bool operator !=(DictWord &otherWord);
    bool operator ==(DictWord &otherWord);
private:
    QList<std::string> strings; //строки с грамматической информацией
    std::string value;
};

#endif // DICTWORD_H
