<<<<<<< HEAD
#ifndef COINCONTROLTREEWIDGET_H
#define COINCONTROLTREEWIDGET_H
=======
// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_COINCONTROLTREEWIDGET_H
#define BITCOIN_QT_COINCONTROLTREEWIDGET_H
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

#include <QKeyEvent>
#include <QTreeWidget>

<<<<<<< HEAD
class CoinControlTreeWidget : public QTreeWidget {
Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = 0);
    
protected:
  virtual void  keyPressEvent(QKeyEvent *event);
};

#endif // COINCONTROLTREEWIDGET_H
=======
class CoinControlTreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit CoinControlTreeWidget(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // BITCOIN_QT_COINCONTROLTREEWIDGET_H
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
