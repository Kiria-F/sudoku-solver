#include "tree.h"

Tree::Tree(int** data, QObject *parent) : QObject(parent)
{
    childsCount = 0;
    childs = nullptr;
    this->data = data;
    active = true;
}

Tree::~Tree()
{
    for (int x = 0; x < 9; x++)
    {
        delete[] data[x];
        data[x] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

void Tree::addChild(int** data)
{
    Tree* child = new Tree(data, this);
    Tree** buffer = new Tree*[childsCount];
    for (unsigned int i = 0; i < childsCount; i++)
    {
        buffer[i] = childs[i];
    }
    childsCount++;
    delete[] childs;
    childs = new Tree*[childsCount];
    for (unsigned int i = 0; i < childsCount - 1; i++)
    {
        childs[i] = buffer[i];
    }
    childs[childsCount - 1] = child;
}

unsigned int Tree::getChildsCount()
{
    return childsCount;
}

Tree* Tree::getChild(unsigned int index)
{
    if (index >= childsCount)
    {
        return nullptr;
    }
    return childs[index];
}

int** Tree::getData()
{
    return data;
}

bool Tree::isActive()
{
    return active;
}

void Tree::deactive()
{
    active = false;
}
