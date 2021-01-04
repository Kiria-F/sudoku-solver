#ifndef TREE_H
#define TREE_H

#include <QObject>

class Tree : public QObject
{
    Q_OBJECT
    unsigned int childsCount;
    Tree** childs;
    int** data;
    bool active;

public:
    explicit Tree(int** data, QObject *parent = nullptr);
    ~Tree();
    void addChild(int** data);
    unsigned int getChildsCount();
    Tree* getChild(unsigned int index);
    int** getData();
    bool isActive();
    void deactive();

signals:

};

#endif // TREE_H
