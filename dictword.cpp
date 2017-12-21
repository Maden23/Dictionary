#include "dictword.h"

DictWord::DictWord()
{
    left = right = NULL;
}

DictWord::DictWord(std::string val, QList<std::string> list)
{
    if (val != "")
        value = val;
    else
        value = "Default";
    strings = list;
}

DictWord::DictWord(const DictWord &source)
{
    value = source.getValue();
    QList<std::string> sourceStrings = source.getStrings();
    QList<std::string>::iterator str;
    for (str = sourceStrings.begin(); str < sourceStrings.end(); str++);
        strings.append(*str);
}

DictWord::~DictWord()
{
    if (right)
        delete right;
    if (left)
        delete left;
}

QList<std::string> DictWord::getStrings()const
{
    return strings;
}

std::string DictWord::getValue() const
{
    return value;
}

bool DictWord::operator <(DictWord &otherWord)
{
    return std::lexicographical_compare(value.begin(), value.back(),
                                        otherWord.getValue().begin(), otherWord.getValue().end());
}

bool DictWord::operator >(DictWord &otherWord)
{
    return !std::lexicographical_compare(value.begin(), value.back(),
                                         otherWord.getValue().begin(), otherWord.getValue().end());
}

bool DictWord::operator !=(DictWord &otherWord)
{

}

