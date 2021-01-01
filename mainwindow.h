#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "tree.h"
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
    int x;
    int y;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int** memoryGrid;
    Tree* root;
    int lastGenIndex;

    bool stepSolve_solved = false;
    bool stepSolve_error = false;
    bool stepSolve_prevNeedToChange = false;

public:
    MainWindow(QWidget *parent = nullptr);  // Конструктор чо
    ~MainWindow();  // Деструктор чо

    QLineEdit* getField(CoordsOfField cof);  // Возвращает поле UI по координатам
    void setFieldValue(CoordsOfField cof, const int value);  // Устанавливает value в поле UI
    int getFieldValue(CoordsOfField cof);  // Возвращает значение поля UI
    void loadToMemoryGridFromUI();  // Загружает сетку в memoryGrid UI
    int** getGrigFromUI();  // Возвращает сетку из UI
    //void updateField(int** grid, CoordsOfField cf);  // Обовляет поле UI
    void updateGrid(int** grid);  // Обновляет сетку UI
    void setFieldsEnabled(bool enable);  // Устанавливает флаг isEnabled у всех полей

    void debugGrid(int** grid);  // Отображает сетку в окне дебага
    void loadToRootFromMemoryGrid();  // Загружает сетку в корень из memoryGrid
    bool fieldValidation(int** grid, CoordsOfField cof);  // Проверяет поле на валидность
    bool gridValidation(int** grid);  // Проверяет сетку на валидность
    bool* findFieldSolves(int** grid, CoordsOfField cof);  // Возвращает список допустимых значений поля
    int findFieldSolvesCount(int** grid, CoordsOfField cof);  // Возвращает кол-во решений сетки
    int findFieldSolvesCount(bool* solves);  // Возвращает кол-во решений сетки
    int findMinimalSolvesCount(int** grid);  // Возвращает минимальное кол-во возможных решений полей сетки
    CoordsOfField findFieldForSolvesCount(int** grid, int solvesCount);  // Возвращает первое поле по его КВР (кол-ву возможных решений)
    CoordsOfField findMinimalSolvesCountField(int** grid);  // Возвращает первое поле с минимальным кол-вом решений
    int findEmptyFieldsCount(int** grid);  // Возвращает кол-во пустых полей сетки
    QList<Tree*> getLastGen();  // Возвращает список сеток последнего поколения
    Tree* isGenHaveSolvedGrid(QList<Tree*> gen);  // Возвращает решённую сетку поколения, если таковая имеется
    QList<int**> findGridSolves(int** grid);  // Возвращает список следующего поколения решений сетки
    void addSolvesListToTree(QList<int**> solves, Tree* tree);  // Добавляет список решений в дерево
    int** getSolvedChildFromGen(QList<Tree*> gen);  // Возвращает решённую сетку из поколения

    void freeGridMemory(int**& grid);  // Освобождает память из-под сетки
    void allocateGridMemory(int**& grid);  // Выделяет память под сетку
    int** cloneGrid(int** from); // Клонирует сетку
    void cloneGrid(int** from, int** to);  // Клонирует сетку

    QList<CoordsOfField> findSimpleFields(int** grid);  // Возвращает координаты полей с КВР = 1
    void fillSimpleField(int** grid, CoordsOfField cof);  // Заполняет поля сетки с КВР = 1
    void fillSimpleFields(int** grid);  // Заполняет поля сетки с КВР = 1

    void solve();  // Запуск алгоритма решения
    void stepSolve();  // Запуск алгоритма пошагового решения

private slots:

    void on_pushButton_Load_clicked();
    void on_pushButton_Solve_clicked();
    void on_pushButton_Restore_clicked();
    void on_pushButton_Step_clicked();
    void on_pushButton_Set_clicked();
    void on_pushButton_Debug_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
