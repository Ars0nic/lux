#ifndef __LUXGATE_DIALOG_H__
#define __LUXGATE_DIALOG_H__

#include <QWidget>
#include <QObject>
#include <QTableWidget>
#include <stdint.h>
#include "clientmodel.h"
#include "walletmodel.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "qcustomplot.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>
#include <QMainWindow>


namespace Ui {
    class LuxgateDialog;
}
class WalletModel;
class QDockWidget;

struct CurrencyPair
{
    CurrencyPair(QString baseCurrency,QString quoteCurrency):   baseCurrency(baseCurrency),
                                                                quoteCurrency(quoteCurrency)
    {}
    QString baseCurrency;
    QString quoteCurrency;
};
extern CurrencyPair curCurrencyPair;

class LuxgateDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit LuxgateDialog(QWidget *parent = 0);
    ~LuxgateDialog();

    void setModel(WalletModel *model);

private:
    Ui::LuxgateDialog *ui;
    WalletModel *model;
    QDockWidget* dockBidPanel;
    QDockWidget* dockAskPanel;
    QDockWidget* dockConfigPanel;
    void moveWidgetsToDocks();
    QDockWidget* createDock(QWidget* widget, const QString& title);
};

#endif //__LUXGATE_DIALOG_H__
