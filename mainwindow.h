#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "tree.h"

struct CoordsOfField
{
    int x;
    int y;
};

struct FieldExploreResult
{
    int value;
    bool solves[9];
    int solvesCount;
};

struct GridExploreResult
{
    bool isSolvable;
    bool isSolved;
    FieldExploreResult minimalSolvesCountField;
    CoordsOfField minimalSolvesCountFieldCoords;
    int emptyFieldsCount;
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

public:
    MainWindow(QWidget *parent = nullptr);  // Конструктор чо
    ~MainWindow();  // Деструктор чо
    void keyReleaseEvent(QKeyEvent *e);  // Обработчик событий
    //bool event(QEvent *e);

    QLineEdit* getField(CoordsOfField cof);  // Возвращает поле UI по координатам
    void setFieldValue(CoordsOfField cof, const int value);  // Устанавливает value в поле UI
    int getFieldValue(CoordsOfField cof);  // Возвращает значение поля UI
    void loadToMemoryGridFromUI();  // Загружает сетку в memoryGrid UI
    int** getGrigFromUI();  // Возвращает сетку из UI
    //void updateField(int** grid, CoordsOfField cf);  // Обовляет поле UI
    void updateGrid(int** grid);  // Обновляет сетку UI
    void setFieldsEnabled(bool enable);  // Устанавливает флаг isEnabled у всех полей
    CoordsOfField getFocusCoords();  // Возвращает координаты поля под фокусом
    void moveSelectionRight();
    void moveSelectionDown();
    void moveSelectionLeft();
    void moveSelectionUp();

    void debugGrid(int** grid, bool solveCounts = false);  // Отображает сетку в окне дебага
    void loadToRootFromMemoryGrid();  // Загружает сетку в корень из memoryGrid
    bool fieldValidation(int** grid, CoordsOfField cof);  // Проверяет поле на валидность [F]
    bool gridValidation(int** grid);  // Проверяет сетку на валидность [G]
    bool* findFieldSolves(int** grid, CoordsOfField cof);  // Возвращает список допустимых значений поля [F]
    int findFieldSolvesCount(int** grid, CoordsOfField cof);  // Возвращает кол-во решений поля [F]
    int findFieldSolvesCount(bool* solves);  // Возвращает кол-во решений поля [F]
    int findMinimalSolvesCountFieldSolvesCount(int** grid);  // Возвращает КВР поля с минимальным КВР [G]
    CoordsOfField findFieldForSolvesCount(int** grid, int solvesCount);  // Возвращает первое поле по его КВР (кол-ву возможных решений) [G]
    CoordsOfField findMinimalSolvesCountField(int** grid);  // Возвращает первое поле с минимальным кол-вом решений [G]
    int findEmptyFieldsCount(int** grid);  // Возвращает кол-во пустых полей сетки [G]
    QList<Tree*> getLastGen();  // Возвращает список сеток последнего поколения
    Tree* isGenHaveSolvedGrid(QList<Tree*> gen);  // Возвращает решённую сетку поколения, если таковая имеется
    QList<int**> findGridSolves(int** grid);  // Возвращает список следующего поколения решений сетки
    QList<int**> findGridSolves(int** grid, GridExploreResult gridExploreResult);  // Возвращает список следующего поколения решений сетки
    void addSolvesListToTree(QList<int**> solves, Tree* tree);  // Добавляет список решений в дерево
    int** getSolvedChildFromGen(QList<Tree*> gen);  // Возвращает решённую сетку из поколения
    bool isGridSolvable(int** grid);  // Распознаёт неразрешимую сетку [G]
    FieldExploreResult exploreField(int** grid, CoordsOfField cof);  // Исследует поле
    GridExploreResult exploreGrid(int** grid);  // Исследует поле

    void freeGridMemory(int**& grid);  // Освобождает память из-под сетки
    void allocateGridMemory(int**& grid);  // Выделяет память под сетку
    int** cloneGrid(int** from); // Клонирует сетку
    void cloneGrid(int** from, int** to);  // Клонирует сетку

    QList<CoordsOfField> findSimpleFields(int** grid);  // Возвращает координаты полей с КВР = 1 [G]
    void fillSimpleField(int** grid, CoordsOfField cof);  // Заполняет поля сетки с КВР = 1
    void fillSimpleFields(int** grid);  // Заполняет поля сетки с КВР = 1

    void solve();  // Запуск старого некрутого неоптимизированного рабочего алгоритма решения
    void solve_NEW();  // Запуск нового крутого оптимизированного нерабочего алгоритма решения

private slots:

    void on_pushButton_Load_clicked();
    void on_pushButton_Solve_clicked();
    void on_pushButton_Restore_clicked();
    void on_pushButton_Debug_clicked();
    void on_pushButton_SolveNEW_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
