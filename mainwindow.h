#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

enum step
{
    BACK,
    CHANGE,
    NEXT
};

struct CoordsOF
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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit* getField(CoordsOF cof);
    void setFieldValue(CoordsOF cof, const int value);
    int getFieldValue(CoordsOF cof);
    bool fieldValidation(CoordsOF cof);
    void loadToMemoryGridFromUI();
    void loadToActualGridFromMemoryFrid();
    void updateField(CoordsOF cf);
    void updateGrid(int grid[9][9]);


private slots:

    void on_pushButton_Load_clicked();

    void on_pushButton_Restore_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
