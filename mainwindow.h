#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QToolButton>
#include <QCompleter>
#include "items.h"
#include "editor.h"
#include "strings.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    void createCharacterActions();  // Create character actions in toolbar
    void updateCharacterValues();
    void updateCharacterItemBrowser();
    void simpleComboBoxChangedHandler(const QString& newValue,
                                      const std::string specifier,
                                      const std::string* arrayBasePointer,
                                      const int arraySize);
    void simpleSpinBoxChangedHandler(const QString& newValue,
                                     const std::string specifier);
    void loadTopLevelChildren(QTreeWidget* itemBrowser,
                              int topLevelIndex,
                              const int beginIndex,
                              const int endIndex,
                              std::string type = "");
    ~MainWindow();

private slots:
    void characterNameActionHandler();
    void saveCharacterHandler();

    void on_lineEditName_editingFinished();

    void on_comboBoxDifficultyEdit_currentTextChanged(const QString& newDifficulty);
    void on_comboBoxRaceEdit_currentTextChanged(const QString& newRace);
    void on_comboBoxClassEdit_currentTextChanged(const QString& newClass);
    void on_comboBoxAllegianceEdit_currentIndexChanged(const QString& newAllegiance);
    void on_comboBoxVariantEdit_currentIndexChanged(const QString& newVariant);
    void on_comboBoxUniformEdit_currentIndexChanged(const QString& newUniform);
    void on_comboBoxAugmentEdit_currentIndexChanged(const QString& newAugment);

    void on_spinBoxVitVal_valueChanged(const QString& newVit);
    void on_spinBoxDexVal_valueChanged(const QString& newDex);
    void on_spinBoxMagVal_valueChanged(const QString& newMag);
    void on_spinBoxStrVal_valueChanged(const QString& newFai);
    void on_spinBoxTecVal_valueChanged(const QString& newTec);
    void on_spinBoxFaiVal_valueChanged(const QString& newFai);
    void on_spinBoxLevelVal_valueChanged(const QString& newCharacterLevel);
    void on_spinBoxAllegianceLevelVal_valueChanged(const QString& newAllegianceLevel);
    void on_treeWidgetItemBrowser_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_lineEditItemName_editingFinished();

private:
    Editor* _e;
    QCompleter* _itemCompleter;
    QCompleter* _combatChipCompleter;
    Ui::MainWindow* _ui;
};
#endif
