<<<<<<< HEAD
#ifndef COINCONTROLDIALOG_H
#define COINCONTROLDIALOG_H
=======
// Copyright (c) 2011-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_COINCONTROLDIALOG_H
#define BITCOIN_QT_COINCONTROLDIALOG_H

#include "amount.h"
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

#include <QAbstractButton>
#include <QAction>
#include <QDialog>
#include <QList>
#include <QMenu>
#include <QPoint>
#include <QString>
#include <QTreeWidgetItem>

<<<<<<< HEAD
namespace Ui {
    class CoinControlDialog;
}
class WalletModel;
class CCoinControl;
=======
class PlatformStyle;
class WalletModel;

class CCoinControl;
class CTxMemPool;

namespace Ui {
    class CoinControlDialog;
}

#define ASYMP_UTF8 "\xE2\x89\x88"

class CCoinControlWidgetItem : public QTreeWidgetItem
{
public:
    CCoinControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    CCoinControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    CCoinControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

class CoinControlDialog : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit CoinControlDialog(QWidget *parent = 0);
    ~CoinControlDialog();

    void setModel(WalletModel *model);
    
    // static because also called from sendcoinsdialog
    static void updateLabels(WalletModel*, QDialog*);
    static QString getPriorityLabel(double);
    
    static QList<qint64> payAmounts;
    static CCoinControl *coinControl;
=======
    explicit CoinControlDialog(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~CoinControlDialog();

    void setModel(WalletModel *model);

    // static because also called from sendcoinsdialog
    static void updateLabels(WalletModel*, QDialog*);
    static QString getPriorityLabel(double dPriority, double mempoolEstimatePriority);

    static QList<CAmount> payAmounts;
    static CCoinControl *coinControl;
    static bool fSubtractFeeFromAmount;
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36

private:
    Ui::CoinControlDialog *ui;
    WalletModel *model;
    int sortColumn;
    Qt::SortOrder sortOrder;
<<<<<<< HEAD
    
=======

>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
    QMenu *contextMenu;
    QTreeWidgetItem *contextMenuItem;
    QAction *copyTransactionHashAction;
    QAction *lockAction;
    QAction *unlockAction;
<<<<<<< HEAD
    
    QString strPad(QString, int, QString);
    void sortView(int, Qt::SortOrder);
    void updateView();
    
    enum
    {
        COLUMN_CHECKBOX,
=======

    const PlatformStyle *platformStyle;

    void sortView(int, Qt::SortOrder);
    void updateView();

    enum
    {
        COLUMN_CHECKBOX = 0,
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
        COLUMN_AMOUNT,
        COLUMN_LABEL,
        COLUMN_ADDRESS,
        COLUMN_DATE,
        COLUMN_CONFIRMATIONS,
        COLUMN_PRIORITY,
        COLUMN_TXHASH,
        COLUMN_VOUT_INDEX,
<<<<<<< HEAD
        COLUMN_AMOUNT_INT64,
        COLUMN_PRIORITY_INT64
    };
    
private slots:
=======
    };
    friend class CCoinControlWidgetItem;

private Q_SLOTS:
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
    void showMenu(const QPoint &);
    void copyAmount();
    void copyLabel();
    void copyAddress();
    void copyTransactionHash();
    void lockCoin();
    void unlockCoin();
    void clipboardQuantity();
    void clipboardAmount();
    void clipboardFee();
    void clipboardAfterFee();
    void clipboardBytes();
    void clipboardPriority();
    void clipboardLowOutput();
    void clipboardChange();
    void radioTreeMode(bool);
    void radioListMode(bool);
    void viewItemChanged(QTreeWidgetItem*, int);
    void headerSectionClicked(int);
    void buttonBoxClicked(QAbstractButton*);
    void buttonSelectAllClicked();
    void updateLabelLocked();
};

<<<<<<< HEAD
#endif // COINCONTROLDIALOG_H
=======
#endif // BITCOIN_QT_COINCONTROLDIALOG_H
>>>>>>> 3b4ed770f88229b11bf62b90f128f3054b17ab36
