# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 6.8.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QGridLayout, QLabel, QLayout,
    QMainWindow, QPushButton, QSizePolicy, QStatusBar,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.setEnabled(True)
        MainWindow.resize(480, 640)
        palette = QPalette()
        brush = QBrush(QColor(255, 255, 255, 255))
        brush.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.WindowText, brush)
        brush1 = QBrush(QColor(49, 49, 49, 255))
        brush1.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Button, brush1)
        brush2 = QBrush(QColor(74, 74, 74, 255))
        brush2.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Light, brush2)
        brush3 = QBrush(QColor(61, 61, 61, 255))
        brush3.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Midlight, brush3)
        brush4 = QBrush(QColor(25, 25, 25, 255))
        brush4.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Dark, brush4)
        brush5 = QBrush(QColor(33, 33, 33, 255))
        brush5.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Mid, brush5)
        palette.setBrush(QPalette.Active, QPalette.Text, brush)
        palette.setBrush(QPalette.Active, QPalette.BrightText, brush)
        palette.setBrush(QPalette.Active, QPalette.ButtonText, brush)
        brush6 = QBrush(QColor(0, 0, 0, 255))
        brush6.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.Base, brush6)
        palette.setBrush(QPalette.Active, QPalette.Window, brush1)
        palette.setBrush(QPalette.Active, QPalette.Shadow, brush6)
        brush7 = QBrush(QColor(24, 24, 24, 255))
        brush7.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.AlternateBase, brush7)
        brush8 = QBrush(QColor(255, 255, 220, 255))
        brush8.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Active, QPalette.ToolTipBase, brush8)
        palette.setBrush(QPalette.Active, QPalette.ToolTipText, brush6)
        brush9 = QBrush(QColor(255, 255, 255, 127))
        brush9.setStyle(Qt.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Active, QPalette.PlaceholderText, brush9)
#endif
        palette.setBrush(QPalette.Active, QPalette.Accent, brush6)
        palette.setBrush(QPalette.Inactive, QPalette.WindowText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Button, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Light, brush2)
        palette.setBrush(QPalette.Inactive, QPalette.Midlight, brush3)
        palette.setBrush(QPalette.Inactive, QPalette.Dark, brush4)
        palette.setBrush(QPalette.Inactive, QPalette.Mid, brush5)
        palette.setBrush(QPalette.Inactive, QPalette.Text, brush)
        palette.setBrush(QPalette.Inactive, QPalette.BrightText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.ButtonText, brush)
        palette.setBrush(QPalette.Inactive, QPalette.Base, brush6)
        palette.setBrush(QPalette.Inactive, QPalette.Window, brush1)
        palette.setBrush(QPalette.Inactive, QPalette.Shadow, brush6)
        palette.setBrush(QPalette.Inactive, QPalette.AlternateBase, brush7)
        palette.setBrush(QPalette.Inactive, QPalette.ToolTipBase, brush8)
        palette.setBrush(QPalette.Inactive, QPalette.ToolTipText, brush6)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Inactive, QPalette.PlaceholderText, brush9)
#endif
        palette.setBrush(QPalette.Inactive, QPalette.Accent, brush6)
        palette.setBrush(QPalette.Disabled, QPalette.WindowText, brush4)
        palette.setBrush(QPalette.Disabled, QPalette.Button, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Light, brush2)
        palette.setBrush(QPalette.Disabled, QPalette.Midlight, brush3)
        palette.setBrush(QPalette.Disabled, QPalette.Dark, brush4)
        palette.setBrush(QPalette.Disabled, QPalette.Mid, brush5)
        palette.setBrush(QPalette.Disabled, QPalette.Text, brush4)
        palette.setBrush(QPalette.Disabled, QPalette.BrightText, brush)
        palette.setBrush(QPalette.Disabled, QPalette.ButtonText, brush4)
        palette.setBrush(QPalette.Disabled, QPalette.Base, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Window, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.Shadow, brush6)
        palette.setBrush(QPalette.Disabled, QPalette.AlternateBase, brush1)
        palette.setBrush(QPalette.Disabled, QPalette.ToolTipBase, brush8)
        palette.setBrush(QPalette.Disabled, QPalette.ToolTipText, brush6)
        brush10 = QBrush(QColor(25, 25, 25, 127))
        brush10.setStyle(Qt.SolidPattern)
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette.Disabled, QPalette.PlaceholderText, brush10)
#endif
        brush11 = QBrush(QColor(35, 35, 35, 255))
        brush11.setStyle(Qt.SolidPattern)
        palette.setBrush(QPalette.Disabled, QPalette.Accent, brush11)
        MainWindow.setPalette(palette)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayoutWidget = QWidget(self.centralwidget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(0, 10, 481, 601))
        self.buttonLayout = QGridLayout(self.gridLayoutWidget)
        self.buttonLayout.setObjectName(u"buttonLayout")
        self.buttonLayout.setSizeConstraint(QLayout.SizeConstraint.SetMaximumSize)
        self.buttonLayout.setVerticalSpacing(10)
        self.buttonLayout.setContentsMargins(0, 0, 0, 0)
        self.button_8 = QPushButton(self.gridLayoutWidget)
        self.button_8.setObjectName(u"button_8")
        sizePolicy = QSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.button_8.sizePolicy().hasHeightForWidth())
        self.button_8.setSizePolicy(sizePolicy)
        self.button_8.setBaseSize(QSize(50, 50))
        font = QFont()
        font.setPointSize(20)
        self.button_8.setFont(font)

        self.buttonLayout.addWidget(self.button_8, 2, 1, 1, 1)

        self.button_9 = QPushButton(self.gridLayoutWidget)
        self.button_9.setObjectName(u"button_9")
        sizePolicy.setHeightForWidth(self.button_9.sizePolicy().hasHeightForWidth())
        self.button_9.setSizePolicy(sizePolicy)
        self.button_9.setBaseSize(QSize(50, 50))
        self.button_9.setFont(font)

        self.buttonLayout.addWidget(self.button_9, 2, 2, 1, 1)

        self.button_5 = QPushButton(self.gridLayoutWidget)
        self.button_5.setObjectName(u"button_5")
        sizePolicy.setHeightForWidth(self.button_5.sizePolicy().hasHeightForWidth())
        self.button_5.setSizePolicy(sizePolicy)
        self.button_5.setBaseSize(QSize(50, 50))
        self.button_5.setFont(font)

        self.buttonLayout.addWidget(self.button_5, 3, 1, 1, 1)

        self.button_2 = QPushButton(self.gridLayoutWidget)
        self.button_2.setObjectName(u"button_2")
        sizePolicy.setHeightForWidth(self.button_2.sizePolicy().hasHeightForWidth())
        self.button_2.setSizePolicy(sizePolicy)
        self.button_2.setBaseSize(QSize(50, 50))
        self.button_2.setFont(font)

        self.buttonLayout.addWidget(self.button_2, 9, 1, 1, 1)

        self.button_1 = QPushButton(self.gridLayoutWidget)
        self.button_1.setObjectName(u"button_1")
        sizePolicy.setHeightForWidth(self.button_1.sizePolicy().hasHeightForWidth())
        self.button_1.setSizePolicy(sizePolicy)
        self.button_1.setBaseSize(QSize(50, 50))
        self.button_1.setFont(font)

        self.buttonLayout.addWidget(self.button_1, 9, 0, 1, 1)

        self.button_add = QPushButton(self.gridLayoutWidget)
        self.button_add.setObjectName(u"button_add")
        sizePolicy.setHeightForWidth(self.button_add.sizePolicy().hasHeightForWidth())
        self.button_add.setSizePolicy(sizePolicy)
        self.button_add.setBaseSize(QSize(50, 50))
        self.button_add.setFont(font)

        self.buttonLayout.addWidget(self.button_add, 1, 3, 1, 1)

        self.button_3 = QPushButton(self.gridLayoutWidget)
        self.button_3.setObjectName(u"button_3")
        sizePolicy.setHeightForWidth(self.button_3.sizePolicy().hasHeightForWidth())
        self.button_3.setSizePolicy(sizePolicy)
        self.button_3.setBaseSize(QSize(50, 50))
        self.button_3.setFont(font)

        self.buttonLayout.addWidget(self.button_3, 9, 2, 1, 1)

        self.button_7 = QPushButton(self.gridLayoutWidget)
        self.button_7.setObjectName(u"button_7")
        sizePolicy.setHeightForWidth(self.button_7.sizePolicy().hasHeightForWidth())
        self.button_7.setSizePolicy(sizePolicy)
        self.button_7.setBaseSize(QSize(50, 50))
        self.button_7.setFont(font)

        self.buttonLayout.addWidget(self.button_7, 2, 0, 1, 1)

        self.button_multiply = QPushButton(self.gridLayoutWidget)
        self.button_multiply.setObjectName(u"button_multiply")
        sizePolicy.setHeightForWidth(self.button_multiply.sizePolicy().hasHeightForWidth())
        self.button_multiply.setSizePolicy(sizePolicy)
        self.button_multiply.setBaseSize(QSize(50, 50))
        self.button_multiply.setFont(font)

        self.buttonLayout.addWidget(self.button_multiply, 3, 3, 1, 1)

        self.button_clear = QPushButton(self.gridLayoutWidget)
        self.button_clear.setObjectName(u"button_clear")
        sizePolicy.setHeightForWidth(self.button_clear.sizePolicy().hasHeightForWidth())
        self.button_clear.setSizePolicy(sizePolicy)
        self.button_clear.setBaseSize(QSize(50, 50))
        self.button_clear.setFont(font)

        self.buttonLayout.addWidget(self.button_clear, 1, 0, 1, 1)

        self.button_4 = QPushButton(self.gridLayoutWidget)
        self.button_4.setObjectName(u"button_4")
        sizePolicy.setHeightForWidth(self.button_4.sizePolicy().hasHeightForWidth())
        self.button_4.setSizePolicy(sizePolicy)
        self.button_4.setBaseSize(QSize(50, 50))
        self.button_4.setFont(font)

        self.buttonLayout.addWidget(self.button_4, 3, 0, 1, 1)

        self.button_substract = QPushButton(self.gridLayoutWidget)
        self.button_substract.setObjectName(u"button_substract")
        sizePolicy.setHeightForWidth(self.button_substract.sizePolicy().hasHeightForWidth())
        self.button_substract.setSizePolicy(sizePolicy)
        self.button_substract.setBaseSize(QSize(50, 50))
        self.button_substract.setFont(font)

        self.buttonLayout.addWidget(self.button_substract, 2, 3, 1, 1)

        self.button_divide = QPushButton(self.gridLayoutWidget)
        self.button_divide.setObjectName(u"button_divide")
        sizePolicy.setHeightForWidth(self.button_divide.sizePolicy().hasHeightForWidth())
        self.button_divide.setSizePolicy(sizePolicy)
        self.button_divide.setBaseSize(QSize(50, 50))
        self.button_divide.setFont(font)

        self.buttonLayout.addWidget(self.button_divide, 9, 3, 1, 1)

        self.button_6 = QPushButton(self.gridLayoutWidget)
        self.button_6.setObjectName(u"button_6")
        sizePolicy.setHeightForWidth(self.button_6.sizePolicy().hasHeightForWidth())
        self.button_6.setSizePolicy(sizePolicy)
        self.button_6.setBaseSize(QSize(50, 50))
        self.button_6.setFont(font)

        self.buttonLayout.addWidget(self.button_6, 3, 2, 1, 1)

        self.label_display = QLabel(self.gridLayoutWidget)
        self.label_display.setObjectName(u"label_display")
        sizePolicy.setHeightForWidth(self.label_display.sizePolicy().hasHeightForWidth())
        self.label_display.setSizePolicy(sizePolicy)
        font1 = QFont()
        font1.setPointSize(20)
        font1.setBold(True)
        self.label_display.setFont(font1)
        self.label_display.setAlignment(Qt.AlignmentFlag.AlignRight|Qt.AlignmentFlag.AlignTrailing|Qt.AlignmentFlag.AlignVCenter)
        self.label_display.setMargin(10)

        self.buttonLayout.addWidget(self.label_display, 0, 0, 1, 4)

        self.button_0 = QPushButton(self.gridLayoutWidget)
        self.button_0.setObjectName(u"button_0")
        sizePolicy.setHeightForWidth(self.button_0.sizePolicy().hasHeightForWidth())
        self.button_0.setSizePolicy(sizePolicy)
        self.button_0.setFont(font)

        self.buttonLayout.addWidget(self.button_0, 10, 0, 1, 2)

        self.button_equals = QPushButton(self.gridLayoutWidget)
        self.button_equals.setObjectName(u"button_equals")
        sizePolicy.setHeightForWidth(self.button_equals.sizePolicy().hasHeightForWidth())
        self.button_equals.setSizePolicy(sizePolicy)
        self.button_equals.setBaseSize(QSize(50, 50))
        self.button_equals.setFont(font)

        self.buttonLayout.addWidget(self.button_equals, 10, 2, 1, 2)

        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Calculator", None))
        self.button_8.setText(QCoreApplication.translate("MainWindow", u"8", None))
        self.button_9.setText(QCoreApplication.translate("MainWindow", u"9", None))
        self.button_5.setText(QCoreApplication.translate("MainWindow", u"5", None))
        self.button_2.setText(QCoreApplication.translate("MainWindow", u"2", None))
        self.button_1.setText(QCoreApplication.translate("MainWindow", u"1", None))
        self.button_add.setText(QCoreApplication.translate("MainWindow", u"+", None))
        self.button_3.setText(QCoreApplication.translate("MainWindow", u"3", None))
        self.button_7.setText(QCoreApplication.translate("MainWindow", u"7", None))
        self.button_multiply.setText(QCoreApplication.translate("MainWindow", u"*", None))
        self.button_clear.setText(QCoreApplication.translate("MainWindow", u"C", None))
        self.button_4.setText(QCoreApplication.translate("MainWindow", u"4", None))
        self.button_substract.setText(QCoreApplication.translate("MainWindow", u"-", None))
        self.button_divide.setText(QCoreApplication.translate("MainWindow", u"/", None))
        self.button_6.setText(QCoreApplication.translate("MainWindow", u"6", None))
        self.label_display.setText(QCoreApplication.translate("MainWindow", u"Dupa", None))
        self.button_0.setText(QCoreApplication.translate("MainWindow", u"0", None))
        self.button_equals.setText(QCoreApplication.translate("MainWindow", u"=", None))
    # retranslateUi

