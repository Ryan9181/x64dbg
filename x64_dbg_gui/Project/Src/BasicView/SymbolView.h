#ifndef SYMBOLVIEW_H
#define SYMBOLVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QList>
#include <QMenu>
#include "StdTable.h"
#include "Bridge.h"
#include "SearchListView.h"

namespace Ui {
class SymbolView;
}

class SymbolView : public QWidget
{
    Q_OBJECT

public:
    explicit SymbolView(QWidget *parent = 0);
    ~SymbolView();
    void setupContextMenu();

private slots:
    void addMsgToSymbolLogSlot(QString msg);
    void clearSymbolLogSlot();
    void moduleSelectionChanged(int index);
    void updateSymbolList(int module_count, SYMBOLMODULEINFO* modules);
    void symbolFollow();
    void symbolFollowDump();
    void symbolContextMenu(const QPoint & pos);
    void symbolAddressCopy();
    void symbolDecoratedCopy();
    void symbolUndecoratedCopy();

signals:
    void showCpu();

private:
    Ui::SymbolView *ui;
    QVBoxLayout* mMainLayout;
    QVBoxLayout* mSymbolLayout;
    QWidget* mSymbolPlaceHolder;
    SearchListView* mSearchListView;
    StdTable* mModuleList;
    QList<uint_t> mModuleBaseList;
    QAction* mFollowSymbolAction;
    QAction* mFollowSymbolDumpAction;
    QAction* mCopySymbolAddress;
    QAction* mCopyDecoratedSymbolAction;
    QAction* mCopyUndecoratedSymbolAction;

    static void cbSymbolEnum(SYMBOLINFO* symbol, void* user);
};

#endif // SYMBOLVIEW_H