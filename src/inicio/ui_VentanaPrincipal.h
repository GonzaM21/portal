/********************************************************************************
** Form generated from reading UI file 'VentanaPrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QLocale>
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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QStackedWidget *stackedWidget;
    QWidget *inicio;
    QPushButton *editarMapa;
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
    QWidget *crearSala;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLineEdit *nombreSala;
    QPushButton *continuar;
    QWidget *salaEspera;
    QLabel *integrantesLabel;
    QLabel *sala;
    QPushButton *comenzarJuego;
    QListWidget *integrantesLista;
    QPushButton *reloadButton;
    QWidget *configMapa;
    QFrame *horizontalFrame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *alto;
    QFrame *horizontalFrame_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *ancho;
    QPushButton *pushButton;
    QWidget *editorMapa;
    QTableWidget *mapa;
    QListWidget *objetos;
    QPushButton *guardarMapa;
    QGroupBox *asociarPop;
    QLabel *label_7;
    QLineEdit *numPuerta;
    QPushButton *asociar;

    void setupUi(QWidget *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QStringLiteral("VentanaPrincipal"));
        VentanaPrincipal->setEnabled(true);
        VentanaPrincipal->resize(700, 700);
        QIcon icon;
        icon.addFile(QStringLiteral("resources/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        VentanaPrincipal->setWindowIcon(icon);
        VentanaPrincipal->setToolTipDuration(0);
        VentanaPrincipal->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"   border-image: url(:/images/myimage.png) 0 0 0 0 stretch stretch;\n"
"   border-width: 0px;\n"
"}"));
        VentanaPrincipal->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        stackedWidget = new QStackedWidget(VentanaPrincipal);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 700, 700));
        stackedWidget->setStyleSheet(QLatin1String("QWidget#inicio\n"
"{\n"
"   border-image: url(portada.jpeg) 0 0 0 0 stretch stretch;\n"
"}\n"
"QFrame\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton#reloadButton\n"
"{\n"
"   border-image: url(reload.png) 0 0 0 0 stretch stretch;\n"
"}"));
        inicio = new QWidget();
        inicio->setObjectName(QStringLiteral("inicio"));
        editarMapa = new QPushButton(inicio);
        editarMapa->setObjectName(QStringLiteral("editarMapa"));
        editarMapa->setGeometry(QRect(480, 430, 203, 53));
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(25);
        editarMapa->setFont(font);
        editarMapa->setAutoDefault(false);
        editarMapa->setFlat(false);
        comenzarButton = new QPushButton(inicio);
        comenzarButton->setObjectName(QStringLiteral("comenzarButton"));
        comenzarButton->setGeometry(QRect(480, 304, 203, 63));
        QFont font1;
        font1.setFamily(QStringLiteral("Century Schoolbook L"));
        font1.setPointSize(30);
        comenzarButton->setFont(font1);
        comenzarButton->setAutoDefault(false);
        comenzarButton->setFlat(false);
        stackedWidget->addWidget(inicio);
        entrada = new QWidget();
        entrada->setObjectName(QStringLiteral("entrada"));
        entrada->setMouseTracking(true);
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
        crearSalaButton->setGeometry(QRect(220, 300, 351, 141));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(crearSalaButton->sizePolicy().hasHeightForWidth());
        crearSalaButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(40);
        crearSalaButton->setFont(font2);
        elegirSalaButton = new QPushButton(eleccionSala);
        elegirSalaButton->setObjectName(QStringLiteral("elegirSalaButton"));
        elegirSalaButton->setGeometry(QRect(220, 150, 351, 141));
        sizePolicy.setHeightForWidth(elegirSalaButton->sizePolicy().hasHeightForWidth());
        elegirSalaButton->setSizePolicy(sizePolicy);
        elegirSalaButton->setFont(font2);
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
        continuar = new QPushButton(groupBox);
        continuar->setObjectName(QStringLiteral("continuar"));
        continuar->setGeometry(QRect(200, 250, 361, 91));
        continuar->setFont(font3);
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
        sala->setFont(font2);
        sala->setAlignment(Qt::AlignCenter);
        comenzarJuego = new QPushButton(salaEspera);
        comenzarJuego->setObjectName(QStringLiteral("comenzarJuego"));
        comenzarJuego->setGeometry(QRect(260, 500, 301, 121));
        QFont font4;
        font4.setPointSize(25);
        comenzarJuego->setFont(font4);
        integrantesLista = new QListWidget(salaEspera);
        integrantesLista->setObjectName(QStringLiteral("integrantesLista"));
        integrantesLista->setGeometry(QRect(200, 200, 411, 271));
        reloadButton = new QPushButton(salaEspera);
        reloadButton->setObjectName(QStringLiteral("reloadButton"));
        reloadButton->setGeometry(QRect(580, 200, 31, 27));
        stackedWidget->addWidget(salaEspera);
        configMapa = new QWidget();
        configMapa->setObjectName(QStringLiteral("configMapa"));
        horizontalFrame_4 = new QFrame(configMapa);
        horizontalFrame_4->setObjectName(QStringLiteral("horizontalFrame_4"));
        horizontalFrame_4->setGeometry(QRect(190, 260, 421, 141));
        horizontalLayout_4 = new QHBoxLayout(horizontalFrame_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(horizontalFrame_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        alto = new QLineEdit(horizontalFrame_4);
        alto->setObjectName(QStringLiteral("alto"));

        horizontalLayout_4->addWidget(alto);

        horizontalFrame_5 = new QFrame(configMapa);
        horizontalFrame_5->setObjectName(QStringLiteral("horizontalFrame_5"));
        horizontalFrame_5->setGeometry(QRect(190, 110, 421, 141));
        horizontalFrame_5->setStyleSheet(QLatin1String("QFrame \n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(horizontalFrame_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(25, 10, 25, 10);
        label_6 = new QLabel(horizontalFrame_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral(""));

        horizontalLayout_5->addWidget(label_6);

        ancho = new QLineEdit(horizontalFrame_5);
        ancho->setObjectName(QStringLiteral("ancho"));

        horizontalLayout_5->addWidget(ancho);

        pushButton = new QPushButton(configMapa);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 410, 421, 101));
        QFont font5;
        font5.setPointSize(36);
        font5.setItalic(true);
        pushButton->setFont(font5);
        stackedWidget->addWidget(configMapa);
        editorMapa = new QWidget();
        editorMapa->setObjectName(QStringLiteral("editorMapa"));
        mapa = new QTableWidget(editorMapa);
        if (mapa->columnCount() < 37)
            mapa->setColumnCount(37);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(24, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(25, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(26, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(27, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(28, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(29, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(30, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(31, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(32, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(33, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(34, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(35, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        mapa->setHorizontalHeaderItem(36, __qtablewidgetitem36);
        if (mapa->rowCount() < 37)
            mapa->setRowCount(37);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(1, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(2, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(3, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(4, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(5, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(6, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(7, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(8, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(9, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(10, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(11, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(12, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(13, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(14, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(15, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(16, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(17, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(18, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(19, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(20, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(21, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(22, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(23, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(24, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(25, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(26, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(27, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(28, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(29, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(30, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(31, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(32, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(33, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(34, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(35, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        mapa->setVerticalHeaderItem(36, __qtablewidgetitem73);
        mapa->setObjectName(QStringLiteral("mapa"));
        mapa->setGeometry(QRect(9, 10, 681, 520));
        mapa->setMouseTracking(true);
        mapa->setDragEnabled(true);
        mapa->setDragDropOverwriteMode(true);
        mapa->setDragDropMode(QAbstractItemView::DragDrop);
        mapa->setDefaultDropAction(Qt::CopyAction);
        mapa->setAlternatingRowColors(false);
        mapa->setIconSize(QSize(50, 50));
        mapa->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        mapa->setShowGrid(true);
        mapa->setGridStyle(Qt::DashLine);
        mapa->setCornerButtonEnabled(true);
        mapa->setColumnCount(37);
        mapa->horizontalHeader()->setVisible(false);
        mapa->horizontalHeader()->setDefaultSectionSize(50);
        mapa->horizontalHeader()->setHighlightSections(false);
        mapa->horizontalHeader()->setMinimumSectionSize(50);
        mapa->verticalHeader()->setVisible(false);
        mapa->verticalHeader()->setDefaultSectionSize(50);
        mapa->verticalHeader()->setHighlightSections(false);
        mapa->verticalHeader()->setMinimumSectionSize(50);
        objetos = new QListWidget(editorMapa);
        QIcon icon1;
        icon1.addFile(QStringLiteral("resources/qt/Acid.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(objetos);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral("resources/qt/Button_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(objetos);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral("resources/qt/Capa 1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(objetos);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral("resources/qt/Energy_Emitter_Charged_U.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(objetos);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QStringLiteral("resources/qt/Energy_Emitter_Charged_D.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(objetos);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QStringLiteral("resources/qt/Energy_Emitter_Charged_R.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(objetos);
        __qlistwidgetitem5->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QStringLiteral("resources/qt/Capa 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(objetos);
        __qlistwidgetitem6->setIcon(icon7);
        QIcon icon8;
        icon8.addFile(QStringLiteral("resources/qt/Energy_barrier_h.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(objetos);
        __qlistwidgetitem7->setIcon(icon8);
        QIcon icon9;
        icon9.addFile(QStringLiteral("resources/qt/Energy_barrier_v.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(objetos);
        __qlistwidgetitem8->setIcon(icon9);
        QIcon icon10;
        icon10.addFile(QStringLiteral("resources/qt/Energy_Emitter_Charged_L.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(objetos);
        __qlistwidgetitem9->setIcon(icon10);
        QIcon icon11;
        icon11.addFile(QStringLiteral("resources/qt/Energy_Emitter_U.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(objetos);
        __qlistwidgetitem10->setIcon(icon11);
        QIcon icon12;
        icon12.addFile(QStringLiteral("resources/qt/Energy_Emitter_L.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(objetos);
        __qlistwidgetitem11->setIcon(icon12);
        QIcon icon13;
        icon13.addFile(QStringLiteral("resources/qt/Energy_Emitter_R.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(objetos);
        __qlistwidgetitem12->setIcon(icon13);
        QIcon icon14;
        icon14.addFile(QStringLiteral("resources/qt/Energy_Emitter_D.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem13 = new QListWidgetItem(objetos);
        __qlistwidgetitem13->setIcon(icon14);
        QIcon icon15;
        icon15.addFile(QStringLiteral("resources/qt/Metal_block.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem14 = new QListWidgetItem(objetos);
        __qlistwidgetitem14->setIcon(icon15);
        QIcon icon16;
        icon16.addFile(QStringLiteral("resources/qt/Stone_block.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem15 = new QListWidgetItem(objetos);
        __qlistwidgetitem15->setIcon(icon16);
        QIcon icon17;
        icon17.addFile(QStringLiteral("resources/qt/Traingular_Metal_block.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem16 = new QListWidgetItem(objetos);
        __qlistwidgetitem16->setIcon(icon17);
        QIcon icon18;
        icon18.addFile(QStringLiteral("resources/qt/Traingulat_Metal_block_r.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem17 = new QListWidgetItem(objetos);
        __qlistwidgetitem17->setIcon(icon18);
        QIcon icon19;
        icon19.addFile(QStringLiteral("resources/qt/Traingulat_Metal_block_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem18 = new QListWidgetItem(objetos);
        __qlistwidgetitem18->setIcon(icon19);
        QIcon icon20;
        icon20.addFile(QStringLiteral("resources/qt/Traingulat_Metal_block_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem19 = new QListWidgetItem(objetos);
        __qlistwidgetitem19->setIcon(icon20);
        QIcon icon21;
        icon21.addFile(QStringLiteral("resources/qt/Cake_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem20 = new QListWidgetItem(objetos);
        __qlistwidgetitem20->setIcon(icon21);
        objetos->setObjectName(QStringLiteral("objetos"));
        objetos->setGeometry(QRect(0, 530, 600, 161));
        objetos->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        objetos->setLayoutDirection(Qt::LeftToRight);
        objetos->setLocale(QLocale(QLocale::C, QLocale::AnyCountry));
        objetos->setProperty("showDropIndicator", QVariant(true));
        objetos->setDragEnabled(true);
        objetos->setDragDropOverwriteMode(false);
        objetos->setDragDropMode(QAbstractItemView::DragDrop);
        objetos->setDefaultDropAction(Qt::IgnoreAction);
        objetos->setSelectionMode(QAbstractItemView::SingleSelection);
        objetos->setSelectionBehavior(QAbstractItemView::SelectRows);
        objetos->setIconSize(QSize(50, 50));
        objetos->setMovement(QListView::Snap);
        objetos->setFlow(QListView::LeftToRight);
        objetos->setResizeMode(QListView::Fixed);
        objetos->setLayoutMode(QListView::SinglePass);
        objetos->setSpacing(5);
        objetos->setGridSize(QSize(75, 150));
        objetos->setViewMode(QListView::IconMode);
        objetos->setModelColumn(0);
        objetos->setUniformItemSizes(false);
        objetos->setBatchSize(150);
        objetos->setWordWrap(false);
        objetos->setSelectionRectVisible(true);
        guardarMapa = new QPushButton(editorMapa);
        guardarMapa->setObjectName(QStringLiteral("guardarMapa"));
        guardarMapa->setGeometry(QRect(600, 530, 91, 165));
        asociarPop = new QGroupBox(editorMapa);
        asociarPop->setObjectName(QStringLiteral("asociarPop"));
        asociarPop->setGeometry(QRect(210, 220, 201, 181));
        asociarPop->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        label_7 = new QLabel(asociarPop);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(6, 26, 191, 61));
        numPuerta = new QLineEdit(asociarPop);
        numPuerta->setObjectName(QStringLiteral("numPuerta"));
        numPuerta->setGeometry(QRect(10, 100, 181, 27));
        asociar = new QPushButton(asociarPop);
        asociar->setObjectName(QStringLiteral("asociar"));
        asociar->setGeometry(QRect(60, 140, 99, 27));
        stackedWidget->addWidget(editorMapa);

        retranslateUi(VentanaPrincipal);

        stackedWidget->setCurrentIndex(6);
        editarMapa->setDefault(true);
        comenzarButton->setDefault(true);
        objetos->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QWidget *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", Q_NULLPTR));
        editarMapa->setText(QApplication::translate("VentanaPrincipal", "Editar Mapa", Q_NULLPTR));
        comenzarButton->setText(QApplication::translate("VentanaPrincipal", "Comenzar", Q_NULLPTR));
        submit->setText(QApplication::translate("VentanaPrincipal", "Iniciar Juego", Q_NULLPTR));
        label_3->setText(QApplication::translate("VentanaPrincipal", "Ingresar puerto", Q_NULLPTR));
        label_2->setText(QApplication::translate("VentanaPrincipal", "Ingresar host", Q_NULLPTR));
        label->setText(QApplication::translate("VentanaPrincipal", "Ingresar Nombre", Q_NULLPTR));
        crearSalaButton->setText(QApplication::translate("VentanaPrincipal", "Crear Sala", Q_NULLPTR));
        elegirSalaButton->setText(QApplication::translate("VentanaPrincipal", "Elegir Sala", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_4->setText(QApplication::translate("VentanaPrincipal", "Ingrese el nombre de la sala", Q_NULLPTR));
        continuar->setText(QApplication::translate("VentanaPrincipal", "Continuar", Q_NULLPTR));
        integrantesLabel->setText(QApplication::translate("VentanaPrincipal", "Integrantes", Q_NULLPTR));
        sala->setText(QApplication::translate("VentanaPrincipal", "Sala Nombre", Q_NULLPTR));
        comenzarJuego->setText(QApplication::translate("VentanaPrincipal", "Comenzar", Q_NULLPTR));
        reloadButton->setText(QString());
        label_5->setText(QApplication::translate("VentanaPrincipal", "Ingresar alto", Q_NULLPTR));
        label_6->setText(QApplication::translate("VentanaPrincipal", "Ingresar Ancho", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VentanaPrincipal", "Crear", Q_NULLPTR));

        const bool __sortingEnabled = objetos->isSortingEnabled();
        objetos->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = objetos->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("VentanaPrincipal", "Acid", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = objetos->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("VentanaPrincipal", "Button", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = objetos->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("VentanaPrincipal", "Gate", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = objetos->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("VentanaPrincipal", "RecvU", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = objetos->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("VentanaPrincipal", "RecvD", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = objetos->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("VentanaPrincipal", "RecvR", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem6 = objetos->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("VentanaPrincipal", "Rock", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem7 = objetos->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("VentanaPrincipal", "BarrH", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem8 = objetos->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("VentanaPrincipal", "BarrV", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem9 = objetos->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("VentanaPrincipal", "RecvL", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem10 = objetos->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("VentanaPrincipal", "EnerU", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem11 = objetos->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("VentanaPrincipal", "EnerL", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem12 = objetos->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("VentanaPrincipal", "EnerR", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem13 = objetos->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("VentanaPrincipal", "EnerD", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem14 = objetos->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("VentanaPrincipal", "Metal", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem15 = objetos->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("VentanaPrincipal", "Stone", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem16 = objetos->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("VentanaPrincipal", "Tria4", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem17 = objetos->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("VentanaPrincipal", "Tria5", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem18 = objetos->item(18);
        ___qlistwidgetitem18->setText(QApplication::translate("VentanaPrincipal", "Tria6", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem19 = objetos->item(19);
        ___qlistwidgetitem19->setText(QApplication::translate("VentanaPrincipal", "Tria7", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem20 = objetos->item(20);
        ___qlistwidgetitem20->setText(QApplication::translate("VentanaPrincipal", "Cake", Q_NULLPTR));
        objetos->setSortingEnabled(__sortingEnabled);

        guardarMapa->setText(QApplication::translate("VentanaPrincipal", "SAVE", Q_NULLPTR));
        asociarPop->setTitle(QString());
        label_7->setText(QApplication::translate("VentanaPrincipal", "Ingrese la puerta a asociar", Q_NULLPTR));
        asociar->setText(QApplication::translate("VentanaPrincipal", "asociar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
