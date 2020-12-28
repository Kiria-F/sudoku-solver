#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

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
    QLineEdit* getField(const int y, const int x);
    void setFieldValue(const int y, const int x, const int value);
    int getFieldValue(const int y, const int x);
    bool fieldValidation(const int y, const int x);
    void loadToMemoryGridFromUI();
    void loadToActualGridFromMemoryFrid();
    void updateField(const int y, const int x);
    void updateGrid(int grid[9][9]);

private slots:

    void on_pushButton_Load_clicked();

    void on_pushButton_Restore_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
