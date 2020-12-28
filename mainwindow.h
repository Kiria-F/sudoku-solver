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

    int memoryField[9][9];
    int actualField[9][9];

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit* getField(const int y, const int x);
    void setFieldValue(const int y, const int x, const int value);
    int getFieldValue(const int y, const int x);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
