#include <QApplication>
#include <QPushButton>
#include "QToolBar.h"
#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include "VectorDocument.h"
#include "Circle.h"

class WCwindow : public QMainWindow
{
public:
    WCwindow();
private:
    VectorDocument *vectorDocument = new VectorDocument();

    QGridLayout *createFiguresList();

    QHBoxLayout *createFirstRadioGroup();

    void onCreateCircleButtonClicked();

    void onCreateRectangleButtonClicked();

    void onRotateButtonClicked();

    void onMoveButtonClicked();

    void onCreateCircleButtonConstructorClicked(QWidget *widget);
};

void WCwindow::onCreateCircleButtonClicked(){
    QWidget *wdg = new QWidget;
    QLineEdit *xCoord = new QLineEdit("0");
    xCoord->objectName() = "xCoord";
    QLineEdit *yCoord = new QLineEdit("0");
    yCoord->objectName() = "yCoord";
    QLineEdit *radius = new QLineEdit("10");
    radius->objectName() = "radius";
    QGridLayout *qvbl = new QGridLayout;
    qvbl->addWidget(xCoord, 0, 1);
    qvbl->addWidget(yCoord, 1, 1);
    qvbl->addWidget(radius, 2, 1);
    QLabel *xCoordText = new QLabel("Enter x coordinate");
    QLabel *yCoordText = new QLabel("Enter y coordinate");
    QLabel *radiusText = new QLabel("Enter circle radius");
    qvbl->addWidget(xCoordText, 0, 0);
    qvbl->addWidget(yCoordText, 1, 0);
    qvbl->addWidget(radiusText, 2, 0);
    QPushButton *pushButton = new QPushButton("Create circle");
    connect(pushButton, &QPushButton::clicked, this, [this, &wdg]{onCreateCircleButtonConstructorClicked(wdg); });
    qvbl->addWidget(pushButton, 3, 1);
    wdg->setLayout(qvbl);
    wdg->show();
}

void WCwindow::onCreateRectangleButtonClicked() {
    printf("onCreateRectangleButtonClicked\n");
}

void WCwindow::onCreateCircleButtonConstructorClicked(QWidget *wdg) {
    //Circle *figure = new Circle(wdg->findChild<QLineEdit>("radius").text().toDouble(), wdg->findChild<QLineEdit>("xCoord").text().toDouble(),
                 //              wdg->findChild<QLineEdit>("yCoord").text().toDouble(), 255, 255, 255);
    Circle *figure = new Circle(2,2,2, 255, 255, 255);
    vectorDocument->addElement(*figure);
    wdg->close();
}

void WCwindow::onRotateButtonClicked(){
    auto color = vectorDocument->getElements()[0].getColor();
}

void WCwindow::onMoveButtonClicked(){
    printf("onMoveButtonClicked\n");

}
QHBoxLayout *WCwindow::createFirstRadioGroup() {
    QPushButton *buttCreateCirc = new QPushButton(tr("Create circle"));
    QPushButton *buttCreateRect = new QPushButton(tr("Create rectangle"));
    QPushButton *buttRotate = new QPushButton(tr("Rotate figure"));
    QPushButton *buttMove = new QPushButton(tr("Move figure"));
    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(buttCreateCirc);
    vbox->addWidget(buttCreateRect);
    vbox->addWidget(buttRotate);
    vbox->addWidget(buttMove);
    connect(buttCreateCirc, &QPushButton::clicked, this, &WCwindow::onCreateCircleButtonClicked);
    connect(buttCreateRect, &QPushButton::clicked, this, &WCwindow::onCreateRectangleButtonClicked);
    connect(buttRotate, &QPushButton::clicked, this, &WCwindow::onRotateButtonClicked);
    connect(buttMove, &QPushButton::clicked, this, &WCwindow::onMoveButtonClicked);
    return vbox;
}

QGridLayout *WCwindow::createFiguresList() {
    QGridLayout *grid = new QGridLayout();
    for (int i = 0; i < 3; ++i) {
        std::string temp = "FIGURE ";
        temp.append(std::to_string(i));
        QPushButton *addButton = new QPushButton(QString::fromStdString(temp));
        QString buttonStyle = "QPushButton{border:none;background-color:rgba(255, 255, 255,0);}";
        addButton->setStyleSheet(buttonStyle); // Style sheet
        addButton->setMaximumSize(128, 32);
        grid->addWidget(addButton);
    }
    return grid;
}

WCwindow::WCwindow() {
    QGridLayout *layout = new QGridLayout;
    layout->addLayout(createFirstRadioGroup(), 0, 0);
    layout->addLayout(createFiguresList(), 1, 0);
    QWidget * central = new QWidget();
    setCentralWidget(central);
    setFixedSize(1000, 800);
    centralWidget()->setLayout(layout);
    setWindowTitle("Graphics");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    WCwindow win;
    win.show();

//    Rectangle rectangle(0,0,1,1,122,122,122);
//    std::ofstream os("out.json");
//    cereal::JSONOutputArchive archive(os);
//    rectangle.serialize(archive);
//    os.close();

    return app.exec();
}
