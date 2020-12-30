#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->minimumSize());
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            QLineEdit* field = getField({x, y});
            field->setAlignment(Qt::AlignCenter);
            field->setMaxLength(1);
            memoryGrid[x][y] = 0;
            actualGrid[x][y] = 0;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

bool MainWindow::fieldValidation(CoordsOfField cof) {
    if(actualGrid[cof.x][cof.y] == 0) return false;
    int ys = cof.y/3; ys *= 3;
    int xs = cof.x/3; xs *= 3;

    for(int x = 0; x <= 2; x++) {
        for(int y = 0; y <= 2; y++) {
            if (ys+y != cof.y || xs+x != cof.x) {
                if (actualGrid[cof.x][cof.y] == actualGrid[xs+x][ys+y]) {
                    return false;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != cof.y) {
            if (actualGrid[cof.x][i] == actualGrid[cof.x][cof.y]) {
                return false;
            }
        }
        if (i != cof.x) {
            if (actualGrid[i][cof.y] == actualGrid[cof.x][cof.y]) {
                return false;
            }
        }
    }
    return true;
}

bool MainWindow::gridValidation()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0 ; y < 9; y++)
        {
            if (!fieldValidation({x, y}))
            {
                return false;
            }
        }
    }
    return true;
}

void MainWindow::loadToMemoryGridFromUI()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            CoordsOfField cf{x, y};
            memoryGrid[x][y] = getFieldValue(cf);
        }
    }
}

void MainWindow::loadToActualGridFromMemoryGrid()
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            actualGrid[x][y] = memoryGrid[x][y];
        }
    }
}

void MainWindow::updateField(CoordsOfField cof)
{
    setFieldValue(cof, actualGrid[cof.x][cof.y]);
}

void MainWindow::updateGrid(int grid[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            CoordsOfField cf{x,y};
            setFieldValue(cf, grid[cf.x][cf.y]);
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

void MainWindow::on_pushButton_Load_clicked()
{
    int eyample[9][9] = {
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
    updateGrid(eyample);
}

void MainWindow::on_pushButton_Solve_clicked()
{
    loadToMemoryGridFromUI();
    loadToActualGridFromMemoryGrid();
    solve();
}

void MainWindow::on_pushButton_Restore_clicked()
{
    updateGrid(memoryGrid);
}

void MainWindow::on_pushButton_Step_clicked()
{
    stepSolve();
}

void MainWindow::on_pushButton_Set_clicked()
{
    loadToMemoryGridFromUI();
    loadToActualGridFromMemoryGrid();
}

void MainWindow::on_pushButton_Debug_clicked()
{
    for (int x = 0; x < 9; x++)
    {
        QString debugString = " ";
        for (int y = 0; y < 9; y++)
        {
            //debugString.append(QString::number(actualGrid[x][y])).append(' ');
            debugString.append(QString::number(findSolvesCount({x, y}))).append(' ');
        }
        qDebug() << debugString;
    }
    qDebug() << "\n\n";
}

bool MainWindow::next()
{
    if (iterator.y == 8 && iterator.x == 8) return false;
    if(iterator.y < 8) {
        iterator.y++;
        return true;
    }
    if(iterator.y == 8) {
        iterator.x++; iterator.y = 0;
        return true;
    }
    return false;
}

bool MainWindow::back()
{
    if (iterator.y == 0 && iterator.x == 0) return false;
    if(iterator.y > 0) {
        iterator.y--;
        return true;
    }
    if(iterator.y == 0) {
        iterator.x--; iterator.y = 8;
        return true;
    }
    return false;
}

Step MainWindow::getNextStep()
{
    if (stepSolve_prevNeedToChange)
    {
        if (getFieldValue(iterator) != 9)
        {
            return Step::CHANGE;
        }
        return Step::BACK;
    }
    //stepSolve_prevNeedToChange = false;
    if (!fieldValidation(iterator))
    {
        if (getFieldValue(iterator) != 9)
        {
            return Step::CHANGE;
        }
        return Step::BACK;
    }
    return Step::NEXT;
}

bool MainWindow::doStep()
{
    Step step = getNextStep();
    switch (step)
    {
    case Step::CHANGE:
    {
        if (actualGrid[iterator.x][iterator.y] < 9)
        {
            stepSolve_prevNeedToChange = false;
            actualGrid[iterator.x][iterator.y]++;
            return true;
        }
        return false;
    }
    case Step::NEXT:
    {
        if (next())
        {
            return true;
        }
        return false;
    }
    case Step::BACK:
    {
        actualGrid[iterator.x][iterator.y] = 0;
        updateField({iterator.x, iterator.y});
        if (back())
        {
            stepSolve_prevNeedToChange = true;
            return true;
        }
        return false;
    }
    }
    return false;
}

void MainWindow::solve_OLD()
{
    bool solved = false;
    bool error = false;
    setFieldsEnabled(false);
    while (!solved && !error)
    {
        error = !doStep();
        //updateGrid(actualGrid);
        ui->lineEdit_Y->setText(QString::number(iterator.y));
        ui->lineEdit_X->setText(QString::number(iterator.x));
        updateField(iterator);
        QCoreApplication::processEvents();
        if (iterator.y == 8 && iterator.x == 8)
        {
            solved = gridValidation();
        }
    }
    setFieldsEnabled(true);
}

void MainWindow::solve()
{

}

void MainWindow::stepSolve_OLD()
{
    stepSolve_error = !doStep();
    ui->lineEdit_Y->setText(QString::number(iterator.y));
    ui->lineEdit_X->setText(QString::number(iterator.x));
    updateField(iterator);
    if (iterator.y == 8 && iterator.x == 8)
    {
        stepSolve_solved = gridValidation();
    }
}

void MainWindow::stepSolve()
{
    fillSimpleFields();
    updateGrid(actualGrid);
}

QStaticArrayData<bool, 9>* MainWindow::findFieldSolves(CoordsOfField cof)
{
    QStaticArrayData<bool, 9>* solves = new QStaticArrayData<bool, 9>;
    bool clear = !actualGrid[cof.x][cof.y];
    for (int i = 0; i < 9; i++)
    {
        solves->data[i] = clear;
    }
    if (!clear)
    {
        return solves;
    }
    int xs = cof.x/3; xs *= 3;
    int ys = cof.y/3; ys *= 3;
    for(int x = xs; x <= xs + 2; x++) {
        for(int y = ys; y <= ys + 2; y++) {
            int value = actualGrid[x][y];
            if (value != 0 && (y != cof.y || x != cof.x)) {
                if (solves->data[value - 1]) {
                    solves->data[value - 1] = false;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int value = actualGrid[cof.x][i];
        if (value != 0)
        {
            if (solves->data[value - 1])
            {
                solves->data[value - 1] = false;
            }
        }
        value = actualGrid[i][cof.y];
        if (value != 0)
        {
            if (solves->data[value - 1])
            {
                solves->data[value - 1] = false;
            }
        }
    }
    return solves;
}

int MainWindow::findSolvesCount(CoordsOfField cof)
{
    QStaticArrayData<bool, 9>* solves = findFieldSolves(cof);
    int count = findSolvesCount(solves);
    delete solves;
    return count;
}

int MainWindow::findSolvesCount(QStaticArrayData<bool, 9> *solves)
{
    int count = 0;
    for (bool solve : solves->data)
    {
        if (solve)
        {
            count++;
        }
    }
    return count;
}

QList<CoordsOfField> MainWindow::findSimpleFields()
{
    QList<CoordsOfField> result;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (findSolvesCount({x, y}) == 1)
            {
                result.append({x, y});
            }
        }
    }
    return result;
}

void MainWindow::fillSimpleField(CoordsOfField cof)
{
    QStaticArrayData<bool, 9>* solves = findFieldSolves(cof);
    for (int i = 0; i < 9; i++)
    {
        if (solves->data[i])
        {
            actualGrid[cof.x][cof.y] = i + 1;
        }
    }
    delete solves;
}

void MainWindow::fillSimpleFields()
{
    QList<CoordsOfField> simpleFields = findSimpleFields();
    for (CoordsOfField simpleField : simpleFields)
    {
        fillSimpleField(simpleField);
    }
}
