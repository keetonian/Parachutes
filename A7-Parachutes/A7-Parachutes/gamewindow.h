#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <sprite.h>
#include <QPainter>
#include <QTimer>
#include "gameLogic.h"
#include "Box2D/Box2D.h"
#include <QDebug>
#include <QKeyEvent>
#include <QmediaPlayer>

namespace Ui {
class gameWindow;
}

class gameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* e);
    void startGame();
    ~gameWindow();

private:
    Ui::gameWindow *ui;

    gameLogic* game;

    QPixmap pm;

    int scale;

    void connectSignalsAndSlots();

    void setListWidget(QString word);

    QTimer * timer;

    QmediaPlayer player;


protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public slots:
    void receiveNewWord(QString word); //Connected to gameLogic::newWord
    void receiveNewLevel(int level);//Connected to gameLogic::newLevel
    void receiveFail();//Connected to gameLogic::failed
    void receiveVictory();//Connected to gameLogic::victory
    void actionTimerUpdated(QString message);
    void scoreUpdated(QString score);

signals:
    void letterTyped(QChar letter);
    void newHeight(int);
    void newWidth(int);
    void readyToPlay();

    void pauseGame();
    void unPauseGame();
private slots:
    void on_actionPause_triggered();
    void on_actionStart_triggered();
};

#endif // GAMEWINDOW_H
