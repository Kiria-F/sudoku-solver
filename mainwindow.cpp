#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_Debug->setVisible(false);
    ui->line->setVisible(false);
    ui->pushButton_Load->setVisible(false);
    this->setFixedSize(this->minimumSize());
    root = nullptr;
    allocateGridMemory(memoryGrid);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            QLineEdit* field = getField({x, y});
            field->setAlignment(Qt::AlignCenter);
            field->setMaxLength(1);
            memoryGrid[x][y] = 0;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    freeGridMemory(memoryGrid);
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Up:
        moveSelectionUp();
        break;
    case Qt::Key_Down:
        moveSelectionDown();
        break;
    case Qt::Key_Left:
        moveSelectionLeft();
        break;
    case Qt::Key_Right:
        moveSelectionRight();
        break;
    }
}

/*bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
        switch (ke->key()) {
        case Qt::Key_Up:
            moveSelectionUp();
            break;
        case Qt::Key_Down:
            moveSelectionDown();
            break;
        case Qt::Key_Left:
            moveSelectionLeft();
            break;
        case Qt::Key_Right:
            moveSelectionRight();
            break;
        }
    }
    else
    {
        qDebug() << event->type();
    }

    return QWidget::event(event);
}*/

QLineEdit* MainWindow::getField(CoordsOfField cof)
{
    switch (cof.x)
    {
    case 0:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_0_0;
        }
        case 1:
        {
            return ui->lineEdit_0_1;
        }
        case 2:
        {
            return ui->lineEdit_0_2;
        }
        case 3:
        {
            return ui->lineEdit_0_3;
        }
        case 4:
        {
            return ui->lineEdit_0_4;
        }
        case 5:
        {
            return ui->lineEdit_0_5;
        }
        case 6:
        {
            return ui->lineEdit_0_6;
        }
        case 7:
        {
            return ui->lineEdit_0_7;
        }
        case 8:
        {
            return ui->lineEdit_0_8;
        }
        }
        break;

    }
    case 1:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_1_0;
        }
        case 1:
        {
            return ui->lineEdit_1_1;
        }
        case 2:
        {
            return ui->lineEdit_1_2;
        }
        case 3:
        {
            return ui->lineEdit_1_3;
        }
        case 4:
        {
            return ui->lineEdit_1_4;
        }
        case 5:
        {
            return ui->lineEdit_1_5;
        }
        case 6:
        {
            return ui->lineEdit_1_6;
        }
        case 7:
        {
            return ui->lineEdit_1_7;
        }
        case 8:
        {
            return ui->lineEdit_1_8;
        }
        }
        break;

    }
    case 2:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_2_0;
        }
        case 1:
        {
            return ui->lineEdit_2_1;
        }
        case 2:
        {
            return ui->lineEdit_2_2;
        }
        case 3:
        {
            return ui->lineEdit_2_3;
        }
        case 4:
        {
            return ui->lineEdit_2_4;
        }
        case 5:
        {
            return ui->lineEdit_2_5;
        }
        case 6:
        {
            return ui->lineEdit_2_6;
        }
        case 7:
        {
            return ui->lineEdit_2_7;
        }
        case 8:
        {
            return ui->lineEdit_2_8;
        }
        }
        break;

    }
    case 3:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_3_0;
        }
        case 1:
        {
            return ui->lineEdit_3_1;
        }
        case 2:
        {
            return ui->lineEdit_3_2;
        }
        case 3:
        {
            return ui->lineEdit_3_3;
        }
        case 4:
        {
            return ui->lineEdit_3_4;
        }
        case 5:
        {
            return ui->lineEdit_3_5;
        }
        case 6:
        {
            return ui->lineEdit_3_6;
        }
        case 7:
        {
            return ui->lineEdit_3_7;
        }
        case 8:
        {
            return ui->lineEdit_3_8;
        }
        }
        break;

    }
    case 4:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_4_0;
        }
        case 1:
        {
            return ui->lineEdit_4_1;
        }
        case 2:
        {
            return ui->lineEdit_4_2;
        }
        case 3:
        {
            return ui->lineEdit_4_3;
        }
        case 4:
        {
            return ui->lineEdit_4_4;
        }
        case 5:
        {
            return ui->lineEdit_4_5;
        }
        case 6:
        {
            return ui->lineEdit_4_6;
        }
        case 7:
        {
            return ui->lineEdit_4_7;
        }
        case 8:
        {
            return ui->lineEdit_4_8;
        }
        }
        break;

    }
    case 5:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_5_0;
        }
        case 1:
        {
            return ui->lineEdit_5_1;
        }
        case 2:
        {
            return ui->lineEdit_5_2;
        }
        case 3:
        {
            return ui->lineEdit_5_3;
        }
        case 4:
        {
            return ui->lineEdit_5_4;
        }
        case 5:
        {
            return ui->lineEdit_5_5;
        }
        case 6:
        {
            return ui->lineEdit_5_6;
        }
        case 7:
        {
            return ui->lineEdit_5_7;
        }
        case 8:
        {
            return ui->lineEdit_5_8;
        }
        }
        break;

    }
    case 6:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_6_0;
        }
        case 1:
        {
            return ui->lineEdit_6_1;
        }
        case 2:
        {
            return ui->lineEdit_6_2;
        }
        case 3:
        {
            return ui->lineEdit_6_3;
        }
        case 4:
        {
            return ui->lineEdit_6_4;
        }
        case 5:
        {
            return ui->lineEdit_6_5;
        }
        case 6:
        {
            return ui->lineEdit_6_6;
        }
        case 7:
        {
            return ui->lineEdit_6_7;
        }
        case 8:
        {
            return ui->lineEdit_6_8;
        }
        }
        break;

    }
    case 7:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_7_0;
        }
        case 1:
        {
            return ui->lineEdit_7_1;
        }
        case 2:
        {
            return ui->lineEdit_7_2;
        }
        case 3:
        {
            return ui->lineEdit_7_3;
        }
        case 4:
        {
            return ui->lineEdit_7_4;
        }
        case 5:
        {
            return ui->lineEdit_7_5;
        }
        case 6:
        {
            return ui->lineEdit_7_6;
        }
        case 7:
        {
            return ui->lineEdit_7_7;
        }
        case 8:
        {
            return ui->lineEdit_7_8;
        }
        }
        break;

    }
    case 8:
    {
        switch (cof.y)
        {
        case 0:
        {
            return ui->lineEdit_8_0;
        }
        case 1:
        {
            return ui->lineEdit_8_1;
        }
        case 2:
        {
            return ui->lineEdit_8_2;
        }
        case 3:
        {
            return ui->lineEdit_8_3;
        }
        case 4:
        {
            return ui->lineEdit_8_4;
        }
        case 5:
        {
            return ui->lineEdit_8_5;
        }
        case 6:
        {
            return ui->lineEdit_8_6;
        }
        case 7:
        {
            return ui->lineEdit_8_7;
        }
        case 8:
        {
            return ui->lineEdit_8_8;
        }
        }
        break;

    }
    }
    return nullptr;
}

void MainWindow::setFieldValue(CoordsOfField cof, const int value)
{
    if (value)
    {
        getField(cof)->setText(QString::number(value));
    }
    else
    {
        getField(cof)->setText("");
    }
}

int MainWindow::getFieldValue(CoordsOfField cof)
{
    return getField(cof)->text().toInt();
}

bool MainWindow::fieldValidation(int** grid, CoordsOfField cof) {
    if(grid[cof.x][cof.y] == 0) return false;
    int ys = cof.y/3; ys *= 3;
    int xs = cof.x/3; xs *= 3;

    for(int x = 0; x <= 2; x++) {
        for(int y = 0; y <= 2; y++) {
            if (ys+y != cof.y || xs+x != cof.x) {
                if (grid[cof.x][cof.y] == grid[xs+x][ys+y]) {
                    return false;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != cof.y) {
            if (grid[cof.x][i] == grid[cof.x][cof.y]) {
                return false;
            }
        }
        if (i != cof.x) {
            if (grid[i][cof.y] == grid[cof.x][cof.y]) {
                return false;
            }
        }
    }
    return true;
}

bool MainWindow::gridValidation(int** grid)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0 ; y < 9; y++)
        {
            if (!fieldValidation(grid, {x, y}))
            {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::loadToMemoryGridFromUI()
{
    if (!memoryGrid)
    {
        allocateGridMemory(memoryGrid);
    }
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            CoordsOfField cf{x, y};
            memoryGrid[x][y] = getFieldValue(cf);
        }
    }
}

int** MainWindow::getGrigFromUI()
{
    int** grid;
    allocateGridMemory(grid);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            grid[x][y] = getFieldValue({x, y});
        }
    }
    return grid;
}

void MainWindow::debugGrid(int **grid, bool solveCounts)
{
    for (int x = 0; x < 9; x++)
    {
        QString debugString = " ";
        for (int y = 0; y < 9; y++)
        {
            if (solveCounts)
            {
                debugString.append(QString::number(findFieldSolvesCount(grid, {x, y})).append(' '));
            }
            else
            {
                debugString.append(QString::number(grid[x][y])).append(' ');
            }
        }
        qDebug() << debugString;
    }
    qDebug() << "\n\n";
}

void MainWindow::loadToRootFromMemoryGrid()
{
    if (root)
    {
        delete root;
    }
    root = new Tree(cloneGrid(memoryGrid));
}

//void MainWindow::updateField(int** grid, CoordsOfField cof)
//{
//    setFieldValue(cof, grid[cof.x][cof.y]);
//}

void MainWindow::updateGrid(int** grid)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            setFieldValue({x, y}, grid[x][y]);
        }
    }
}

void MainWindow::setFieldsEnabled(bool enable)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            getField({x, y})->setEnabled(enable);
        }
    }
}

CoordsOfField MainWindow::getFocusCoords()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (getField({x, y})->hasFocus())
            {
                return {x, y};
            }
        }
    }
    return {-1, -1};
}

void MainWindow::moveSelectionRight()
{
    CoordsOfField focus = getFocusCoords();
    if (focus.y < 8)
    {
        focus.y++;
        getField(focus)->setFocus();
    }
}

void MainWindow::moveSelectionDown()
{
    CoordsOfField focus = getFocusCoords();
    if (focus.x < 8)
    {
        focus.x++;
        getField(focus)->setFocus();
    }
}

void MainWindow::moveSelectionLeft()
{
    CoordsOfField focus = getFocusCoords();
    if (focus.y > 0)
    {
        focus.y--;
        getField(focus)->setFocus();
    }
}

void MainWindow::moveSelectionUp()
{
    CoordsOfField focus = getFocusCoords();
    if (focus.x > 0)
    {
        focus.x--;
        getField(focus)->setFocus();
    }
}

void MainWindow::on_pushButton_Load_clicked()
{
    int easyExample[9][9] = {
        {6, 3, 0,  7, 8, 0,  0, 5, 0},
        {8, 5, 0,  0, 1, 4,  0, 0, 0},
        {0, 7, 1,  0, 9, 6,  0, 4, 8},

        {9, 0, 0,  1, 7, 0,  2, 0, 5},
        {7, 8, 2,  4, 6, 0,  0, 0, 0},
        {0, 0, 5,  0, 0, 0,  6, 7, 4},

        {0, 0, 3,  2, 0, 8,  5, 6, 0},
        {5, 0, 0,  9, 0, 7,  4, 0, 2},
        {4, 2, 7,  0, 5, 1,  0, 3, 0}

    };

    int hardExample[9][9] = {
        {6, 3, 0,  7, 8, 0,  0, 5, 0},
        {8, 5, 0,  0, 0, 4,  0, 0, 0},
        {0, 7, 0,  0, 0, 6,  0, 4, 8},

        {9, 0, 0,  0, 7, 0,  2, 0, 5},
        {7, 8, 2,  4, 6, 0,  0, 0, 0},
        {0, 0, 5,  0, 0, 0,  0, 7, 4},

        {0, 0, 3,  2, 0, 8,  5, 6, 0},
        {5, 0, 0,  9, 0, 7,  4, 0, 2},
        {0, 2, 7,  0, 5, 0,  0, 0, 0}
    };

    int edgeExample[9][9] = {
        {0, 3, 0,  7, 8, 0,  0, 0, 0},
        {0, 5, 0,  0, 0, 4,  0, 0, 0},
        {0, 7, 0,  0, 0, 6,  0, 0, 0},

        {9, 0, 0,  0, 7, 0,  2, 0, 5},
        {7, 8, 2,  4, 6, 0,  0, 0, 0},
        {0, 0, 5,  0, 0, 0,  0, 7, 0},

        {0, 0, 0,  2, 0, 0,  5, 6, 0},
        {0, 0, 0,  0, 0, 7,  4, 0, 2},
        {0, 0, 0,  0, 5, 0,  0, 0, 0}
    };

    int** buffer = nullptr;
    allocateGridMemory(buffer);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            buffer[x][y] = edgeExample[x][y];
        }
    }
    updateGrid(buffer);
    freeGridMemory(buffer);
}

void MainWindow::on_pushButton_Solve_clicked()
{
    loadToMemoryGridFromUI();
    solve();
}

void MainWindow::on_pushButton_Restore_clicked()
{
    updateGrid(memoryGrid);
}

void MainWindow::on_pushButton_Debug_clicked()
{
    int** buffer = getGrigFromUI();
    for (int x = 0; x < 9; x++)
    {
        QString debugString = " ";
        for (int y = 0; y < 9; y++)
        {
            //debugString.append(QString::number(grid[x][y])).append(' ');
            debugString.append(QString::number(findFieldSolvesCount(buffer, {x, y}))).append(' ');
        }
        qDebug() << debugString;
    }
    qDebug() << "\n\n";
    freeGridMemory(buffer);
}

void MainWindow::on_pushButton_SolveNEW_clicked()
{
    loadToMemoryGridFromUI();
    solve_NEW();
}

bool* MainWindow::findFieldSolves(int** grid, CoordsOfField cof)
{
    bool* solves = new bool[9];
    bool clear = !grid[cof.x][cof.y];
    for (int i = 0; i < 9; i++)
    {
        solves[i] = clear;
    }
    if (!clear)
    {
        return solves;
    }
    int xs = cof.x/3; xs *= 3;
    int ys = cof.y/3; ys *= 3;
    for(int x = xs; x <= xs + 2; x++) {
        for(int y = ys; y <= ys + 2; y++) {
            int value = grid[x][y];
            if (value != 0 && (y != cof.y || x != cof.x)) {
                if (solves[value - 1]) {
                    solves[value - 1] = false;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int value = grid[cof.x][i];
        if (value != 0)
        {
            if (solves[value - 1])
            {
                solves[value - 1] = false;
            }
        }
        value = grid[i][cof.y];
        if (value != 0)
        {
            if (solves[value - 1])
            {
                solves[value - 1] = false;
            }
        }
    }
    return solves;
}

int MainWindow::findFieldSolvesCount(int** grid, CoordsOfField cof)
{
    bool* solves = findFieldSolves(grid, cof);
    int count = findFieldSolvesCount(solves);
    delete solves;
    return count;
}

int MainWindow::findFieldSolvesCount(bool* solves)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (solves[i])
        {
            count++;
        }
    }
    return count;
}

void MainWindow::freeGridMemory(int**& grid)
{
    for (int i = 0; i < 9; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
    grid = nullptr;
}

void MainWindow::allocateGridMemory(int**& grid)
{
    grid = new int*[9];
    for (int i = 0; i < 9; i++)
    {
        grid[i] = new int[9];
    }
}

int** MainWindow::cloneGrid(int** from)
{
    int** clone = nullptr;
    allocateGridMemory(clone);
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            clone[x][y] = from[x][y];
        }
    }
    return clone;
}

void MainWindow::cloneGrid(int** from, int** to)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            to[x][y] = from[x][y];
        }
    }
}

QList<CoordsOfField> MainWindow::findSimpleFields(int** grid)
{
    QList<CoordsOfField> result;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (findFieldSolvesCount(grid, {x, y}) == 1)
            {
                result.append({x, y});
            }
        }
    }
    return result;
}

int MainWindow::findMinimalSolvesCountFieldSolvesCount(int** grid)
{
    int minimalSolvesCount = 10;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            int solvesCount = findFieldSolvesCount(grid, {x, y});
            if (solvesCount)
            {
                if (solvesCount == 1)
                {
                    return solvesCount;
                }
                if (solvesCount < minimalSolvesCount)
                {
                    minimalSolvesCount = solvesCount;
                }
            }
        }
    }
    return minimalSolvesCount;
}

CoordsOfField MainWindow::findFieldForSolvesCount(int** grid, int solvesCount)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (findFieldSolvesCount(grid, {x, y}) == solvesCount)
            {
                return {x, y};
            }
        }
    }
    return {10, 10};
}

CoordsOfField MainWindow::findMinimalSolvesCountField(int** grid)
{
    return findFieldForSolvesCount(grid, findMinimalSolvesCountFieldSolvesCount(grid));
}

int MainWindow::findEmptyFieldsCount(int** grid)
{
    int emptyFieldsCount = 0;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (!grid[x][y])
            {
                emptyFieldsCount++;
            }
        }
    }
    return emptyFieldsCount;
}

QList<Tree*> MainWindow::getLastGen()
{
    QList<Tree*> lastGen;
    QList<Tree*> buffer;
    lastGen.append(root);
    for (int g = 0; g < lastGenIndex; g++)
    {
        buffer = lastGen;
        lastGen.clear();
        int branchesCount = buffer.size();
        for (int b = 0; b < branchesCount; b++)
        {
            Tree* branch = buffer[b];
            int childsCount = branch->getChildsCount();
            for (int c = 0; c < childsCount; c++)
            {
                Tree* child = branch->getChild(c);
                if (child->isActive())
                {
                    lastGen.append(child);
                }
            }
        }
    }
    return lastGen;
}

Tree* MainWindow::isGenHaveSolvedGrid(QList<Tree*> gen)
{
    int size = gen.size();
    for (int i = 0; i < size; i++)
    {
        if (!findEmptyFieldsCount(gen[i]->getData()))
        {
            return gen[i];
        }
    }
    return nullptr;
}

QList<int**> MainWindow::findGridSolves(int **grid)
{
    int nextGenChildsCount = findMinimalSolvesCountFieldSolvesCount(grid);
    QList<int**> gridSolves;
    if (nextGenChildsCount == 1)
    {
        int** nextGenChild = cloneGrid(grid);
        fillSimpleFields(nextGenChild);
        gridSolves.append(nextGenChild);
    }
    else
    {
        CoordsOfField cof = findFieldForSolvesCount(grid, nextGenChildsCount);
        bool* fieldSolves = findFieldSolves(grid, cof);
        for (int i = 0; i < 9; i++)
        {
            if (fieldSolves[i])
            {
                int** nextGenChild = cloneGrid(grid);
                nextGenChild[cof.x][cof.y] = i + 1;
                gridSolves.append(nextGenChild);
            }
        }
    }
    return gridSolves;
}

QList<int**> MainWindow::findGridSolves(int **grid, GridExploreResult gridExploreResult)
{
    QList<int**> gridSolves;
    if (gridExploreResult.minimalSolvesCountField.solvesCount == 1)
    {
        int** nextGenChild = cloneGrid(grid);
        fillSimpleFields(nextGenChild);
        gridSolves.append(nextGenChild);
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (gridExploreResult.minimalSolvesCountField.solves[i])
            {
                int** nextGenChild = cloneGrid(grid);
                nextGenChild[gridExploreResult.minimalSolvesCountFieldCoords.x][gridExploreResult.minimalSolvesCountFieldCoords.y] = i + 1;
                gridSolves.append(nextGenChild);
            }
        }
    }
    return gridSolves;
}

void MainWindow::addSolvesListToTree(QList<int **> solves, Tree *tree)
{
    int nextGenChildsCount = solves.size();
    for (int i = 0; i < nextGenChildsCount; i++)
    {
        tree->addChild(solves[i]);
    }
}

int** MainWindow::getSolvedChildFromGen(QList<Tree *> gen)
{
    int count = gen.size();
    for (int i = 0; i < count; i++)
    {
        if (!findEmptyFieldsCount(gen[i]->getData()))
        {
            return gen[i]->getData();
        }
    }
    return nullptr;
}

bool MainWindow::isGridSolvable(int **grid)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (!findFieldSolvesCount(grid, {x, y}) && !grid[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::fillSimpleField(int** grid, CoordsOfField cof)
{
    bool* solves = findFieldSolves(grid, cof);
    for (int i = 0; i < 9; i++)
    {
        if (solves[i])
        {
            grid[cof.x][cof.y] = i + 1;
        }
    }
    delete solves;
}

void MainWindow::fillSimpleFields(int** grid)
{
    QList<CoordsOfField> simpleFields = findSimpleFields(grid);
    for (CoordsOfField simpleField : simpleFields)
    {
        fillSimpleField(grid, simpleField);
    }
}

FieldExploreResult MainWindow::exploreField(int **grid, CoordsOfField cof)
{
    FieldExploreResult result;
    result.value = grid[cof.x][cof.y];

    bool clear = !grid[cof.x][cof.y];
    for (int i = 0; i < 9; i++)
    {
        result.solves[i] = clear;
    }
    if (clear)
    {
        result.solvesCount = 9;
        int xs = cof.x/3; xs *= 3;
        int ys = cof.y/3; ys *= 3;
        for(int x = xs; x <= xs + 2; x++) {
            for(int y = ys; y <= ys + 2; y++)
            {
                int value = grid[x][y];
                if (y != cof.y || x != cof.x)
                {
                    if (result.solves[value - 1])
                    {
                        result.solves[value - 1] = false;
                        result.solvesCount--;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++)
        {
            int value = grid[cof.x][i];
            if (result.solves[value - 1])
            {
                result.solves[value - 1] = false;
                result.solvesCount--;
            }
            value = grid[i][cof.y];
            if (result.solves[value - 1])
            {
                result.solves[value - 1] = false;
                result.solvesCount--;
            }
        }
    }
    else
    {
        result.solvesCount = 0;
    }

    return result;
}

GridExploreResult MainWindow::exploreGrid(int **grid)
{
    GridExploreResult result;
    result.isSolvable = true;
    result.isSolved = true;
    result.minimalSolvesCountFieldCoords = {10, 10};
    result.emptyFieldsCount = 0;
    result.minimalSolvesCountField = {10, {false, false, false, false, false, false, false, false, false}, 10};
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            FieldExploreResult fieldExploreResult = exploreField(grid, {x, y});
            if (!fieldExploreResult.value)
            {
                result.emptyFieldsCount++;
                if (!fieldExploreResult.solvesCount)
                {
                    result.isSolvable = false;
                }
                else
                {
                    if (result.minimalSolvesCountField.solvesCount > fieldExploreResult.solvesCount)
                    {
                        result.minimalSolvesCountField = fieldExploreResult;
                        result.minimalSolvesCountFieldCoords = {x, y};
                    }
                }
            }
        }
    }
    if (result.emptyFieldsCount)
    {
        result.isSolved = false;
    }
    return result;
}

void MainWindow::solve()
{
    loadToRootFromMemoryGrid();
    lastGenIndex = 0;
    while (!isGenHaveSolvedGrid(getLastGen()))
    {
        QList<Tree*> lastGen = getLastGen();
        //qDebug() << "getting lastGen: " << timer. ;
        //lastTime = timer.interval();
        int childsCount = getLastGen().size();
        for (int i = 0; i < childsCount; i++)
        {
            if (isGridSolvable(lastGen[i]->getData()))
            {
                QList<int**> solves = findGridSolves(lastGen[i]->getData());
                addSolvesListToTree(solves, lastGen[i]);
            }
            else
            {
                lastGen[i]->deactive();
            }
        }
        lastGenIndex++;
        /*for (int i = 0; i < childsCount; i++)
        {
            qDebug() << "gen: " << lastGenIndex << endl
                     << "child num: " << i << endl;
            debugGrid(getLastGen()[i]->getData());
        }*/
    }

    updateGrid(getSolvedChildFromGen(getLastGen()));
    delete root;
    root = nullptr;
}

void MainWindow::solve_NEW()
{
    loadToRootFromMemoryGrid();
    lastGenIndex = 0;
    bool solved = false;
    //bool solvable = true;
    int** result = nullptr;
    while (!solved)
    {
        QList<Tree*> lastGen = getLastGen();
        int lastGenChildsCount = lastGen.size();
        for (int i = 0; i < lastGenChildsCount; i++)
        {
            GridExploreResult gridExploreResult = exploreGrid(lastGen[i]->getData());
            solved = gridExploreResult.isSolved;
            //solvable = gridExploreResult.isSolvable;
            if (!gridExploreResult.isSolvable)
            {
                lastGen[i]->deactive();
            }
            if (!solved)
            {
                QList<int**> solves = findGridSolves(lastGen[i]->getData(), gridExploreResult);
                addSolvesListToTree(solves, lastGen[i]);
            }
            else
            {
                result = cloneGrid(lastGen[i]->getData());
            }
        }
        if (!solved)
        {
            lastGenIndex++;
        }
    }
    updateGrid(result);
    freeGridMemory(result);
    delete root;
    root = nullptr;
}
