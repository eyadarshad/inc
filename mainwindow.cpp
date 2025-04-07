#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QJSEngine>
#include <QJSValue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int index = ui->stackedWidget->indexOf(ui->dashboard);
    qDebug() << "Index of page 211111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111:" << index;

    // Span display across columns 0-2
    ui->gridLayout->addWidget(ui->display, 0, 0, 1, 3);

    // Create backspace (cross) button
    QPushButton *backspaceBtn = new QPushButton("⌫");
    backspaceBtn->setFixedSize(60, 60);
    ui->gridLayout->addWidget(backspaceBtn, 0, 3);  // Top-right corner

    connect(backspaceBtn, &QPushButton::clicked, this, [=]() {
        QString text = ui->display->text();
        if (!text.isEmpty()) {
            ui->display->setText(text.left(text.length() - 1));
        }
    });

    // Updated buttons with "C" as the first one
    QStringList buttons = {
        "7", "8", "9", "C",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
    };

    int pos = 0;
    for (int row = 1; row <= 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QString label = buttons[pos];

            QPushButton *btn = new QPushButton(label);
            btn->setObjectName("btn" + label);
            btn->setFixedSize(60, 60);
            ui->gridLayout->addWidget(btn, row, col);

            connect(btn, &QPushButton::clicked, this, [=]() {
                QString val = btn->text();
                if (val == "=") {
                    QJSEngine engine;
                    QJSValue result = engine.evaluate(ui->display->text());
                    ui->display->setText(result.toString());
                } else if (val == "C") {
                    ui->display->clear();
                } else {
                    ui->display->setText(ui->display->text() + val);
                }
            });

            ++pos;
        }
    }
    // Connect Page 1 button to go to Page 2
    connect(ui->page1, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->page3, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page4, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->page5, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page6, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });
    connect(ui->page7, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page21, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->page22, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page23, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->page24, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page25, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
        connect(ui->page26, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(6);
        });

        // Connect Page 2 button to go back to Page 1
        connect(ui->page27, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(7);
        });
    });
    connect(ui->page31, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page32, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->page33, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page34, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->page35, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page36, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });
    connect(ui->page37, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page41, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->page42, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page43, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->page44, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page45, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });
    connect(ui->page46, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page47, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });
    connect(ui->page51, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page52, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->page53, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page54, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->page55, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page56, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });
    connect(ui->page57, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page61, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->page62, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page63, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->page64, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page65, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });
    connect(ui->page66, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page67, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });
    connect(ui->page71, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page72, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->page73, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page74, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->page75, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(5);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->page76, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(6);
    });
    connect(ui->page77, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(7);
    });
    connect(ui->pagew1, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(8);
    });
    connect(ui->pagew2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(9);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->pagew3, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(10);
    });
    connect(ui->pagew4, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(11);
    });
    connect(ui->pagew21, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(8);
    });
    connect(ui->pagew22, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(9);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->pagew23, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(10);
    });
    connect(ui->pagew24, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(11);
    });
    connect(ui->pagew31, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(8);
    });
    connect(ui->pagew32, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(9);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->pagew33, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(10);
    });
    connect(ui->pagew34, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(11);
    });
    connect(ui->pages1, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(8);
    });
    connect(ui->pages2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(9);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->pages3, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(10);
    });
    connect(ui->pages4, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(11);
    });
    connect(ui->btnlogout, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnlogout_2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    // Connect Page 2 button to go back to Page 1
    connect(ui->btnlogout_3, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnlogout_4, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        connect(ui->btnlogout_5, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->btnlogout_6, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });

        // Connect Page 2 button to go back to Page 1
        connect(ui->btnlogout_7, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->btnlogout_8, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->btnlogout_9, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->btnlogout_10, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });

        // Connect Page 2 button to go back to Page 1
        connect(ui->btnlogout_11, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->btnlogout_12, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(0);
        });
        connect(ui->cross, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(7);
        });
        connect(ui->cross_2, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(3);
        });

        connect(ui->addprod, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(13);
        });
        connect(ui->addworker111, &QPushButton::clicked, this, [=]() {
            ui->stackedWidget->setCurrentIndex(12);
        });
    });

}


MainWindow::~MainWindow()
{
    delete ui;
}
