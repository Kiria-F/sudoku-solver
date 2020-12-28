#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->minimumSize());
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            CoordsOfField cf{y, x};
            QLineEdit* field = getField(cf);
            field->setAlignment(Qt::AlignCenter);
            field->setMaxLength(1);
            memoryGrid[y][x] = 0;
            actualGrid[y][x] = 0;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QLineEdit* MainWindow::getField(CoordsOfField cof)
{
    switch (cof.y)
    {
    case 0:
    {
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
        switch (cof.x)
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
    int xs = cof.x/3; xs *= 3;
    int ys = cof.x/3; ys *= 3;

    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 2; j++) {
            if (xs+j != cof.x && ys+i != cof.y) {
                if (actualGrid[cof.y][cof.x] == actualGrid[ys+i][xs+j]) return false;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != cof.x) {
            if (actualGrid[cof.y][i] == actualGrid[cof.x][cof.y]) return false;
        }
        if (i != cof.y) {
            if (actualGrid[i][cof.x] == actualGrid[cof.x][cof.y]) return false;
        }
    }
    return true;
}

void MainWindow::loadToMemoryGridFromUI()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            CoordsOfField cf{y, x};
            memoryGrid[y][x] = getFieldValue(cf);
        }
    }
}

void MainWindow::loadToActualGridFromMemoryGrid()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            actualGrid[y][x] = memoryGrid[y][x];
        }
    }
}

void MainWindow::updateField(CoordsOfField cof)
{
    setFieldValue(cof, actualGrid[cof.y][cof.x]);
}

void MainWindow::updateGrid(int grid[9][9])
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            CoordsOfField cf{y,x};
            setFieldValue(cf, grid[cf.y][cf.x]);
        }
    }
}

void MainWindow::on_pushButton_Load_clicked()
{
    int example[9][9] = {
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
    updateGrid(example);
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

bool MainWindow::next()
{
    if(iterator.x < 8) iterator.x +=1;
    if(iterator.x == 8) {
        iterator.y += 1; iterator.x = 0;
    }
    return true;
    if (iterator.x == 8 && iterator.y == 8) return false;
}

bool MainWindow::back()
{
    if(iterator.x > 0) iterator.x -=1;
    if(iterator.x == 0) {
        iterator.y -= 1; iterator.x = 8;
    }
    return true;
    if (iterator.x == 0 && iterator.y == 0) return false;
}

Step MainWindow::getNextStep()
{
    if (getFieldValue(iterator) != 9)
    {
        if (!fieldValidation(iterator))
        {
            return Step::CHANGE;
        }
        else
        {
            return Step::NEXT;
        }
    }
    return Step::BACK;
}

void MainWindow::doStep(Step step)
{
    switch (step)
    {
    case Step::CHANGE:
    {
        actualGrid[iterator.y][iterator.x]++;
    }
    case Step::NEXT:
    {
        if (iterator.x != 8)
        {
            iterator.x++;
        }
        else
        {
            iterator.y++;
            iterator.x = 0;
        }
    }
    case Step::BACK:
    {
        if (iterator.x != 0)
        {
            iterator.x--;
        }
        else
        {
            iterator.y--;
            iterator.x = 8;
        }
    }
    }
}

void MainWindow::solve()
{

}
