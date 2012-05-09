#include<QtGui>

#include"mainwindow.h"
#include "spreadsheet.h"

MainWindow::MainWindow()
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);

    createActions();
    createMenus();
    createContexMenu();
    createStatusBar();

    readSettings();

    findDialog = 0;


    setCurrentFile("");
}

void MainWindow::createActions()
{
    newAction = new QAction(tr(&New),this);
    newAction->setIcon();
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction,SIGNAL(triggered()),
            this,SLOT(newFile()));

    openAction = new QAction(tr(&Open),this);
    openAction->setIcon();
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(openAction,SIGNAL(triggered()),
            this,SLOT(open()));

    saveAction = new QAction(tr(&Save),this);
    saveAction->setIcon();
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("File saved"));
    connect(saveAction,SIGNAL(triggered()),
            this,SLOT(save()));

    saveAsAction = new QAction(tr(Save &As),this);
    saveAsAction->setStatusTip(tr("File saved"));
    connect(saveAsAction,SIGNAL(triggered()),
            this,SLOT(saveAs()));

    for(int i = 0;i < MaxRecentFiles;i++){
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i],SIGNAL(triggered()),
                this,SLOT(openRecentFile()));
    }

    exitAction = new QAction(tr(E&xit),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction,SIGNAL(triggered()),
            this,SLOT(close()));

    cutAction = new QAction(tr("Cu&t"),this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip((tr("File cut")));
    connect(cutAction,SIGNAL(triggered()),
            spreadsheet,SLOT(cut()));

    copyAction = new QAction(tr("&Copy"),this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("File copied"));
    connect(copyAction,SIGNAL(triggered()),
            spreadsheet,SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("File pasted"));
    connect(pasteAction,SIGNAL(triggered()),
            spreadsheet,SLOT(paste()));

    deleteAction = new QAction(tr("&Delete"),this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("File deleted"));
    connect(deleteAction,SIGNAL(triggered()),
            spreadsheet,SLOT(dele()));

    selectAllAction = new QAction(tr("&All"),this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction,SIGNAL(triggered()),
            spreadsheet,SLOT(selectAll()));

    showGridAction = new QAction(tr("&Show Grid"),this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
    connect(showGridAction,SIGNAL(toggled(bool)),
            spreadsheet,SLOT(setShowGrid(bool)));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for(int i = 0;i<MaxRecentFiles;i++)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);

}

void MainWindow::createContexMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContexMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel("W999");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel);

    connect(spreadsheet,SIGNAL(currentCellChanged(int,int,int,int)),
            this,SLOT(updateStatusBar()));
    connect(spreadsheet,SIGNAL(modified()),
            this,SLOT(SpreadsheetModified()));

}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::SpreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}
