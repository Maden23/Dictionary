#include "dictionary.h"

Dictionary::Dictionary()
{

}

Dictionary::~Dictionary()
{
    delete root;
}

DictWord *Dictionary::findMatch(const std::string &word)
{
    QList<std::string> empty;
    DictWord dword(word, empty);
    DictWord *curr = root;
    while (curr)
    {
        if (dword < *curr)
            curr = curr->left;
        else if (dword > *curr)
            curr = curr->right;
        else break;
    }
    return curr;
}

void Dictionary::addWord(const std::string &newWord)
{
    // нельзя второй раз вставить то же слово
    if (findMatch(newWord)) return;

    QList<std::string> empty;
    DictWord dword(newWord, empty);

    if (root)
        addWordTo(dword, root);
    else
        root = new DictWord(dword);
}

void Dictionary::deleteWord(DictWord *delWord)
{
    DictWord *curr = findMatch(delWord->getValue());
    if (!curr) return;
    DictWord *parent = findParent(curr);

    wordsCount--;

    // у узла есть пустой правый потомок
    if (!curr->right)
    {
        if (!parent)
            root = curr->left;
        else
        {
            if (curr < parent)
                parent->left = curr->left;
            else if (parent < curr)
                parent->right = curr->left;
        }
    }

    // у правого потомка нет потомков слева
    else if (!curr->right->left)
    {
        curr->right->left = curr->left;
        if (!parent)
            root = curr->right;
        else if (curr < parent)
            parent->left = curr->right;
        else if (parent < curr)
            parent->right = curr->right;
    }

    // у правого потомка есть дети слева
    else if (curr->right->left)
    {
        // Поиск крайнего левого узла
        DictWord *lastLeft = curr->right->left;
        DictWord *lastLeftParent = curr->right;
        while (lastLeft->left)
        {
            lastLeftParent = lastLeft;
            lastLeft = lastLeft->left;
        }

        // левое поддерево родителя становится правым поддеревом крайнего левого узла
        lastLeftParent->left = lastLeft->right;
        // потомки текущего узла становятся потомками крайнего левого
        lastLeft->left = curr->left;
        lastLeft->right = curr->right;

        if(!parent)
            root = lastLeft;
        else if (curr < parent)
            parent->left = lastLeft;
        else if (parent < curr)
            parent->right = lastLeft;
    }
    delete curr;

}

int Dictionary::count()
{
    return wordsCount;
}

void Dictionary::addWordTo(DictWord &word, DictWord *node)
{
    // вставляемое слово стоит по алфавиту раньше
    if (word < *node)
    {
        if (node->left)
            addWordTo(word, node->left);
        else
            node->left = new DictWord(word);
    }
    // вставляемое слово стоит по алфавиту позже
    else
    {
        if (node->right)
            addWordTo(word, node->right);
        else
            node->right = new DictWord(word);
    }
}

DictWord *Dictionary::findParent(DictWord *child)
{
    DictWord *parent = NULL;
    DictWord *curr = root;
    while (curr)
    {
        if (child < curr)
        {
            parent = curr;
            curr = curr->left;
        }
        else if (child > curr)
        {
            parent = curr;
            curr = curr->right;
        }
        else break;
    }
    return parent;

}
