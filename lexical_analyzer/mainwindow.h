//mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onLexButtonClicked();
private:
    Ui::MainWindow *ui;
    QTextEdit* _leftTextEdit;
    QTextEdit* _rightTextEdit;
};
#endif // MAINWINDOW_H