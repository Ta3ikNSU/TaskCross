#include <QApplication>
#include <QPushButton>
#include "QToolBar.h"
#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>
#include "VectorDocument.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
#include <QSplitter>


VectorDocument *vectorDocument = new VectorDocument();

class WCwindow : public QMainWindow {
public:
    WCwindow();

private:
    QHBoxLayout *createFirstRadioGroup();

    QVBoxLayout *drawableLayout = new QVBoxLayout();

    void onCreateCircleButtonClicked();

    void onChangeParamsClicked(int index);

    void onChangeParamsAccept(int index, std::vector<QLineEdit *> lineEditors, QWidget *wdg);

    void onCreateRectangleButtonClicked();

    void onRotateButtonClicked();

    void onMoveButtonClicked();

    void onCreateCircleButtonConstructorClicked(QLineEdit *rad, QLineEdit *xCoord, QLineEdit *yCoord, QWidget *wdg);

    void insertToDrawer(FlatFigure *figure);

    void
    onCreateRectangleButtonConstructorClicked(QLineEdit *xCoordFrom, QLineEdit *yCoordFrom, QLineEdit *xCoordTo,
                                              QLineEdit *yCoordTo,
                                              QWidget *wdg);

    void onRotateButtonAccept(QLineEdit *angle, QWidget *wdg);

    void onMoveButtonAccept(QLineEdit *x, QLineEdit *y, QWidget *wdg);

    void onRemoveButtonClick(int index, QWidget *pWidget);
};

class Canvas : public QWidget {
public:
    Canvas() = default;

    void paintEvent(QPaintEvent *event) override;
};

void WCwindow::onCreateCircleButtonClicked() {
    QWidget *wdg = new QWidget;
    QLineEdit *xCoord = new QLineEdit("0");
    QLineEdit *yCoord = new QLineEdit("0");
    QLineEdit *radius = new QLineEdit("100");
    QFormLayout *qvbl = new QFormLayout;
    qvbl->addRow(tr("&Enter x coordinate"), xCoord);
    qvbl->addRow(tr("&Enter y coordinat"), yCoord);
    qvbl->addRow(tr("&Enter circle radius"), radius);
    QPushButton *pushButton = new QPushButton("Create circle");
    connect(pushButton, &QPushButton::clicked, this, [this, radius, xCoord, yCoord, wdg] {
        onCreateCircleButtonConstructorClicked(radius, xCoord, yCoord, wdg);
    });
    qvbl->addWidget(pushButton);
    wdg->setLayout(qvbl);
    wdg->show();
}

void WCwindow::onCreateRectangleButtonClicked() {
    QWidget *wdg = new QWidget;
    QLineEdit *xCoordFrom = new QLineEdit("-100");
    QLineEdit *yCoordFrom = new QLineEdit("100");
    QLineEdit *xCoordTo = new QLineEdit("100");
    QLineEdit *yCoordTo = new QLineEdit("-100");
    QFormLayout *qForm = new QFormLayout;
    qForm->addRow(tr("&Enter start x"), xCoordFrom);
    qForm->addRow(tr("&Enter start y"), yCoordFrom);
    qForm->addRow(tr("&Enter end x"), xCoordTo);
    qForm->addRow(tr("&Enter end y"), yCoordTo);
    QPushButton *pushButton = new QPushButton("Create rectangle");
    connect(pushButton, &QPushButton::clicked, this, [this, xCoordFrom, yCoordFrom, xCoordTo, yCoordTo, wdg] {
        onCreateRectangleButtonConstructorClicked(xCoordFrom, yCoordFrom, xCoordTo, yCoordTo, wdg);
    });
    qForm->addRow(pushButton);
    wdg->setLayout(qForm);
    wdg->show();
}

void WCwindow::onChangeParamsAccept(int index, std::vector<QLineEdit *> lineEditors, QWidget *wdg) {
    std::vector<double> params(lineEditors.size());
    for (int i = 0; i < lineEditors.size(); i++) {
        params[i] = (lineEditors)[i]->text().toDouble();
    }
    vectorDocument->getElements()[index]->replace(params);
    wdg->close();
}

void WCwindow::onRemoveButtonClick(int index, QWidget *wdg) {
    vectorDocument->removeElement(index);
    QWidget *button = drawableLayout->itemAt(index)->widget();
    button->setVisible(false);
    wdg->close();
}

void WCwindow::onChangeParamsClicked(int index) {
    QWidget *wdg = new QWidget;
    auto params = vectorDocument->getElements()[index]->getParams();
    std::vector<std::string> paramsTitles = vectorDocument->getParam(index);
    std::vector<QLineEdit *> lineEditors(params.size());
    QFormLayout *qForm = new QFormLayout();
    int k = 0;
    for (auto it: params) {
        lineEditors[k] = new QLineEdit(QString::fromStdString(std::to_string(it.second)));
        qForm->addRow(tr(paramsTitles[k].c_str()), lineEditors[k]);
        k++;
    }
    QPushButton *pushButton = new QPushButton("Change parameters");
    QPushButton *deleteButton = new QPushButton("Delete figure");
    connect(pushButton, &QPushButton::clicked, this, [this, index, lineEditors, wdg] {
        onChangeParamsAccept(index, lineEditors, wdg);
    });
    connect(deleteButton, &QPushButton::clicked, this, [this, index, lineEditors, wdg] {
        onRemoveButtonClick(index, wdg);
    });
    qForm->addRow(pushButton);
    qForm->addRow(deleteButton);
    wdg->setLayout(qForm);
    wdg->show();
}

int figCounter = 0;

void WCwindow::insertToDrawer(FlatFigure *figure) {
    QPushButton *figureLabel = new QPushButton(QString::fromStdString(figure->getType()));
    int index = figCounter;
    figCounter++;
    figureLabel->setStyleSheet("color: white;"
                               "background-color: rgba(255, 255, 255, 10);");
    drawableLayout->addWidget(figureLabel);
    connect(figureLabel, &QPushButton::clicked, this, [this, index] {
        onChangeParamsClicked(index);
    });
}

void WCwindow::onCreateCircleButtonConstructorClicked(QLineEdit *radius, QLineEdit *xCoord, QLineEdit *yCoord,
                                                      QWidget *wdg) {
    double rad = radius->text().toDouble();
    double x = xCoord->text().toDouble();
    double y = yCoord->text().toDouble();
    Circle *figure = new Circle(rad, x, y, 255, 137, 0);
    vectorDocument->addElement(figure);
    wdg->close();
    insertToDrawer(figure);
}


void
WCwindow::onCreateRectangleButtonConstructorClicked(QLineEdit *xCoordFrom, QLineEdit *yCoordFrom, QLineEdit *xCoordTo,
                                                    QLineEdit *yCoordTo, QWidget *wdg) {
    double xFrom = xCoordFrom->text().toDouble();
    double yFrom = yCoordFrom->text().toDouble();
    double xTo = xCoordTo->text().toDouble();
    double yTo = yCoordTo->text().toDouble();
    Rectangle *figure = new Rectangle(xFrom, yFrom, xTo, yTo, 0, 196, 0);
    vectorDocument->addElement(figure);
    wdg->close();
    insertToDrawer(figure);
}

void WCwindow::onRotateButtonAccept(QLineEdit *angle, QWidget *wdg) {
    vectorDocument->setAngle(angle->text().toDouble());
    wdg->close();
}

void WCwindow::onRotateButtonClicked() {
    QWidget *wdg = new QWidget;
    QLineEdit *angle = new QLineEdit("0");
    QFormLayout *qForm = new QFormLayout;
    qForm->addRow(tr("&Enter angle rotate"), angle);
    QPushButton *pushButton = new QPushButton("Rotate");
    connect(pushButton, &QPushButton::clicked, this, [this, angle, wdg] {
        onRotateButtonAccept(angle, wdg);
    });
    qForm->addRow(pushButton);
    wdg->setLayout(qForm);
    wdg->show();
}

void WCwindow::onMoveButtonAccept(QLineEdit *x, QLineEdit *y, QWidget *wdg) {
    vectorDocument->move(x->text().toDouble(), y->text().toDouble());
    wdg->close();
}

void WCwindow::onMoveButtonClicked() {
    QWidget *wdg = new QWidget;
    QLineEdit *move_x = new QLineEdit("0");
    QLineEdit *move_y = new QLineEdit("0");
    QFormLayout *qForm = new QFormLayout;
    qForm->addRow(tr("&Enter move x"), move_x);
    qForm->addRow(tr("&Enter move y"), move_y);
    QPushButton *pushButton = new QPushButton("Move");
    connect(pushButton, &QPushButton::clicked, this, [this, move_x, move_y, wdg] {
        onMoveButtonAccept(move_x, move_y, wdg);
    });
    qForm->addRow(pushButton);
    wdg->setLayout(qForm);
    wdg->show();
}

QHBoxLayout *WCwindow::createFirstRadioGroup() {
    QPushButton *buttCreateCirc = new QPushButton(tr("Create circle"));
    QPushButton *buttCreateRect = new QPushButton(tr("Create rectangle"));
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    QPushButton *buttRotate = new QPushButton(tr("Rotate figure"));
    QPushButton *buttMove = new QPushButton(tr("Move figure"));
    QHBoxLayout *hBox = new QHBoxLayout;
    hBox->addWidget(buttCreateCirc);
    hBox->addWidget(buttCreateRect);
    hBox->addWidget(splitter);
    hBox->addWidget(buttRotate);
    hBox->addWidget(buttMove);
    connect(buttCreateCirc, &QPushButton::clicked, this, &WCwindow::onCreateCircleButtonClicked);
    connect(buttCreateRect, &QPushButton::clicked, this, &WCwindow::onCreateRectangleButtonClicked);
    connect(buttRotate, &QPushButton::clicked, this, &WCwindow::onRotateButtonClicked);
    connect(buttMove, &QPushButton::clicked, this, &WCwindow::onMoveButtonClicked);
    return hBox;
}

WCwindow::WCwindow() {
    QHBoxLayout *hLayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(createFirstRadioGroup());
    hLayout->addLayout(drawableLayout);
    QWidget *canvas = new Canvas();
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    canvas->setSizePolicy(spLeft);
    hLayout->addWidget(canvas);
    drawableLayout->setAlignment(Qt::AlignTop);
    QWidget *central = new QWidget();
    vLayout->addLayout(hLayout);
    setCentralWidget(central);
    setFixedSize(1000, 800);
    centralWidget()->setLayout(vLayout);
    setWindowTitle("Graphics");
}

void Canvas::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    vectorDocument->draw(&painter);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    WCwindow win;
    win.show();

    // пример сериализации
/*    Rectangle rectangle(0,0,1,1,122,122,122);
    std::ofstream os("out.json");
    cereal::JSONOutputArchive archive(os);
    rectangle.serialize(archive);
    os.close();*/
    return app.exec();
}
