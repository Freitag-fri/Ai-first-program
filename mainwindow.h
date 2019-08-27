#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <neironhidden.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    static const int quantityLayer = 3;
    const int quantityNeiron[quantityLayer] = {4,5,6};
    std::list <std::list <neironHidden>> arrAI;
};

#endif // MAINWINDOW_H
