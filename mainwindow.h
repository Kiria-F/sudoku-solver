#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

enum Step
{
    BACK,
    CHANGE,
    NEXT
};

enum Result
{
    OK,
    ERROR,
    END
};

struct CoordsOfField
{
    int y;
    int x;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int memoryGrid[9][9];
    int actualGrid[9][9];
    CoordsOfField iterator = {0, 0};

    bool stepSolve_solved = false;
    bool stepSolve_error = false;
    bool stepSolve_prevNextToChange = false;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit* getField(CoordsOfField cof);
    void setFieldValue(CoordsOfField cof, const int value);
    int getFieldValue(CoordsOfField cof);
    bool fieldValidation(CoordsOfField cof);
    bool gridValidation();
    void loadToMemoryGridFromUI();
    void loadToActualGridFromMemoryGrid();
    void updateField(CoordsOfField cf);
    void updateGrid(int grid[9][9]);
    void setFieldsEnabled(bool enable);
    bool next();
    bool back();
    Step getNextStep();
    bool doStep();
    void solve();
    void stepSolve();

private slots:

    void on_pushButton_Load_clicked();
    void on_pushButton_Solve_clicked();
    void on_pushButton_Restore_clicked();
    void on_pushButton_Step_clicked();
    void on_pushButton_Set_clicked();
    void on_pushButton_DebugArray_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
