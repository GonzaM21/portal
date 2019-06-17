/********************************************************************************
** Form generated from reading UI file 'VentanaPrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QStackedWidget *stackedWidget;
    QWidget *inicio;
    QPushButton *comenzarButton;
    QWidget *entrada;
    QPushButton *submit;
    QFrame *horizontalFrame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *port;
    QFrame *horizontalFrame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *host;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nombre;
    QWidget *eleccionSala;
    QPushButton *crearSalaButton;
    QPushButton *elegirSalaButton;
    QListWidget *listaSalas;
    QLabel *label_5;
    QPushButton *reloadButton;
    QWidget *crearSala;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLineEdit *nombreSala;
    QPushButton *crearSalaButton_2;
    QWidget *salaEspera;
    QLabel *integrantesLabel;
    QLabel *sala;
    QPushButton *comenzarJuego;
    QListWidget *integrantesLista;
    QPushButton *reloadButton_2;
    QWidget *page;

    void setupUi(QWidget *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QStringLiteral("VentanaPrincipal"));
        VentanaPrincipal->setEnabled(true);
        VentanaPrincipal->resize(776, 711);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaPrincipal->setWindowIcon(icon);
        VentanaPrincipal->setToolTipDuration(0);
        VentanaPrincipal->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"   border-image: url(:/images/myimage.png) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        stackedWidget = new QStackedWidget(VentanaPrincipal);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 791, 731));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#inicio\n"
"{\n"
"   border-image: url(:/img/portada.jpeg) 0 0 0 0 stretch stretch;\n"
"}\n"
"QFrame\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton#reloadButton\n"
"{\n"
"   border-image: url(:/img/reload.png) 0 0 0 0 stretch stretch;\n"
"}"));
        inicio = new QWidget();
        inicio->setObjectName(QStringLiteral("inicio"));
        comenzarButton = new QPushButton(inicio);
        comenzarButton->setObjectName(QStringLiteral("comenzarButton"));
        comenzarButton->setGeometry(QRect(560, 390, 211, 101));
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(30);
        comenzarButton->setFont(font);
        comenzarButton->setAutoDefault(false);
        comenzarButton->setFlat(false);
        stackedWidget->addWidget(inicio);
        entrada = new QWidget();
        entrada->setObjectName(QStringLiteral("entrada"));
        submit = new QPushButton(entrada);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(160, 536, 421, 71));
        horizontalFrame_3 = new QFrame(entrada);
        horizontalFrame_3->setObjectName(QStringLiteral("horizontalFrame_3"));
        horizontalFrame_3->setGeometry(QRect(160, 400, 421, 121));
        horizontalLayout_3 = new QHBoxLayout(horizontalFrame_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(horizontalFrame_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        port = new QLineEdit(horizontalFrame_3);
        port->setObjectName(QStringLiteral("port"));

        horizontalLayout_3->addWidget(port);

        port->raise();
        label_3->raise();
        horizontalFrame_2 = new QFrame(entrada);
        horizontalFrame_2->setObjectName(QStringLiteral("horizontalFrame_2"));
        horizontalFrame_2->setGeometry(QRect(160, 250, 421, 141));
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(horizontalFrame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        host = new QLineEdit(horizontalFrame_2);
        host->setObjectName(QStringLiteral("host"));

        horizontalLayout_2->addWidget(host);

        horizontalFrame = new QFrame(entrada);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(160, 100, 421, 141));
        horizontalFrame->setStyleSheet(QLatin1String("QFrame \n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(25, 10, 25, 10);
        label = new QLabel(horizontalFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label);

        nombre = new QLineEdit(horizontalFrame);
        nombre->setObjectName(QStringLiteral("nombre"));

        horizontalLayout->addWidget(nombre);

        nombre->raise();
        label->raise();
        stackedWidget->addWidget(entrada);
        horizontalFrame_3->raise();
        horizontalFrame_2->raise();
        horizontalFrame->raise();
        submit->raise();
        eleccionSala = new QWidget();
        eleccionSala->setObjectName(QStringLiteral("eleccionSala"));
        crearSalaButton = new QPushButton(eleccionSala);
        crearSalaButton->setObjectName(QStringLiteral("crearSalaButton"));
        crearSalaButton->setGeometry(QRect(450, 520, 281, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(crearSalaButton->sizePolicy().hasHeightForWidth());
        crearSalaButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(40);
        crearSalaButton->setFont(font1);
        elegirSalaButton = new QPushButton(eleccionSala);
        elegirSalaButton->setObjectName(QStringLiteral("elegirSalaButton"));
        elegirSalaButton->setGeometry(QRect(450, 440, 281, 71));
        sizePolicy.setHeightForWidth(elegirSalaButton->sizePolicy().hasHeightForWidth());
        elegirSalaButton->setSizePolicy(sizePolicy);
        elegirSalaButton->setFont(font1);
        listaSalas = new QListWidget(eleccionSala);
        listaSalas->setObjectName(QStringLiteral("listaSalas"));
        listaSalas->setGeometry(QRect(50, 270, 301, 321));
        label_5 = new QLabel(eleccionSala);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 220, 301, 51));
        QFont font2;
        font2.setPointSize(25);
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        reloadButton = new QPushButton(eleccionSala);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));
        reloadButton->setGeometry(QRect(320, 260, 31, 27));
        stackedWidget->addWidget(eleccionSala);
        crearSala = new QWidget();
        crearSala->setObjectName(QStringLiteral("crearSala"));
        groupBox = new QGroupBox(crearSala);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 180, 741, 651));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(116, 16, 521, 131));
        QFont font3;
        font3.setPointSize(30);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        nombreSala = new QLineEdit(groupBox);
        nombreSala->setObjectName(QStringLiteral("nombreSala"));
        nombreSala->setGeometry(QRect(200, 180, 361, 51));
        crearSalaButton_2 = new QPushButton(groupBox);
        crearSalaButton_2->setObjectName(QStringLiteral("crearSalaButton_2"));
        crearSalaButton_2->setGeometry(QRect(200, 250, 361, 91));
        crearSalaButton_2->setFont(font3);
        stackedWidget->addWidget(crearSala);
        salaEspera = new QWidget();
        salaEspera->setObjectName(QStringLiteral("salaEspera"));
        integrantesLabel = new QLabel(salaEspera);
        integrantesLabel->setObjectName(QStringLiteral("integrantesLabel"));
        integrantesLabel->setGeometry(QRect(200, 130, 411, 61));
        integrantesLabel->setFont(font3);
        integrantesLabel->setAlignment(Qt::AlignCenter);
        sala = new QLabel(salaEspera);
        sala->setObjectName(QStringLiteral("sala"));
        sala->setGeometry(QRect(200, 50, 411, 61));
        sala->setFont(font1);
        sala->setAlignment(Qt::AlignCenter);
        comenzarJuego = new QPushButton(salaEspera);
        comenzarJuego->setObjectName(QStringLiteral("comenzarJuego"));
        comenzarJuego->setGeometry(QRect(260, 500, 301, 121));
        comenzarJuego->setFont(font2);
        integrantesLista = new QListWidget(salaEspera);
        integrantesLista->setObjectName(QStringLiteral("integrantesLista"));
        integrantesLista->setGeometry(QRect(200, 200, 411, 271));
        reloadButton_2 = new QPushButton(salaEspera);
        reloadButton_2->setObjectName(QStringLiteral("reloadButton_2"));
        reloadButton_2->setGeometry(QRect(580, 200, 31, 27));
        stackedWidget->addWidget(salaEspera);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);

        retranslateUi(VentanaPrincipal);

        stackedWidget->setCurrentIndex(4);
        comenzarButton->setDefault(true);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QWidget *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", 0));
        comenzarButton->setText(QApplication::translate("VentanaPrincipal", "Comenzar", 0));
        submit->setText(QApplication::translate("VentanaPrincipal", "Iniciar Juego", 0));
        label_3->setText(QApplication::translate("VentanaPrincipal", "Ingresar puerto", 0));
        label_2->setText(QApplication::translate("VentanaPrincipal", "Ingresar host", 0));
        label->setText(QApplication::translate("VentanaPrincipal", "Ingresar Nombre", 0));
        crearSalaButton->setText(QApplication::translate("VentanaPrincipal", "Crear Sala", 0));
        elegirSalaButton->setText(QApplication::translate("VentanaPrincipal", "Elegir Sala", 0));
        label_5->setText(QApplication::translate("VentanaPrincipal", "Salas Disponibles", 0));
        reloadButton->setText(QString());
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("VentanaPrincipal", "Ingrese el nombre de la sala", 0));
        crearSalaButton_2->setText(QApplication::translate("VentanaPrincipal", "Crear", 0));
        integrantesLabel->setText(QApplication::translate("VentanaPrincipal", "Integrantes", 0));
        sala->setText(QApplication::translate("VentanaPrincipal", "Sala Nombre", 0));
        comenzarJuego->setText(QApplication::translate("VentanaPrincipal", "Comenzar", 0));
        reloadButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
