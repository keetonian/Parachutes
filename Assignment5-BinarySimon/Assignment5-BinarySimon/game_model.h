#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <QMainWindow>
#include <QObject>      // QObject
#include <QDebug>       // qDebug()
#include <QString>      // QString
#include <QStringList>  // QStringList

class game_model : public QObject
{
    Q_OBJECT

private:
    QTimer *timer;

    int game_state;

    // Pattern:
    QStringList sequence;
    // the currrent progression of the pattern
    int current_sequence_progress;
    // the delay between the flashing of the pattern
    int display_sequence_delay;
    // add another move to the sequence
    void add_to_sequence();

    // Stats:
    int total_number_of_rounds;
    int total_moves;

private slots:

protected:

public:
    explicit game_model(QObject *parent = 0);
    ~game_model();
    void gameStart();

    void checkSequence(QString color);
    QStringList getSequence();
    int getDisplaySequenceDelay();

    void nextState(bool restartGame = false);

    int getTotalNumberOfRounds();
    int getTotalMoves();

    enum gameState : int
    {
        Start,
        DisplaySequence,
        UserInput,
        GameOver,
    };

public slots:


signals:
    void signalStateChange(int);
    void signalProgressUpdate(int);
    void signalSequenceComplete();
    void signalGameOver();
};

#endif // GAME_MODEL_H

/*
 * Notes: I was getting a vtable error, solved by doing this:
 * Another possibility is that the class in question once didn't belong to Qt meta object system (that is, it had no Q_OBJECT or maybe didn't inherit from QObject at all), so qmake needs to be run again in order to create the necessary rules for MOC. The easiest way to force qmake to be run is to make some insignificant changes to the project file to update its timestamp, like adding and then removing some white space.
 * http://stackoverflow.com/questions/4774291/q-object-throwing-undefined-reference-to-vtable-error
 *
 */
