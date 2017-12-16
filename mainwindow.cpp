#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connects the signals and slots of the buttons and sliders to each function
    //Makes the grade calculator reactive when input values are altered (setValue)
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));
    connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));
    connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), ui->spinBox_6, SLOT(setValue(int)));
    connect(ui->horizontalSlider_7, SIGNAL(valueChanged(int)), ui->spinBox_7, SLOT(setValue(int)));
    connect(ui->horizontalSlider_8, SIGNAL(valueChanged(int)), ui->spinBox_8, SLOT(setValue(int)));
    connect(ui->horizontalSlider_9, SIGNAL(valueChanged(int)), ui->spinBox_9, SLOT(setValue(int)));
    connect(ui->horizontalSlider_10, SIGNAL(valueChanged(int)), ui->spinBox_10, SLOT(setValue(int)));
    connect(ui->horizontalSlider_11, SIGNAL(valueChanged(int)), ui->spinBox_11, SLOT(setValue(int)));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));
    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));
    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));
    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->horizontalSlider_6, SLOT(setValue(int)));
    connect(ui->spinBox_7, SIGNAL(valueChanged(int)), ui->horizontalSlider_7, SLOT(setValue(int)));
    connect(ui->spinBox_8, SIGNAL(valueChanged(int)), ui->horizontalSlider_8, SLOT(setValue(int)));
    connect(ui->spinBox_9, SIGNAL(valueChanged(int)), ui->horizontalSlider_9, SLOT(setValue(int)));
    connect(ui->spinBox_10, SIGNAL(valueChanged(int)), ui->horizontalSlider_10, SLOT(setValue(int)));
    connect(ui->spinBox_11, SIGNAL(valueChanged(int)), ui->horizontalSlider_11, SLOT(setValue(int)));

    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_3, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_4, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_5, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_6, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_7, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_8, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));
    QObject::connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(computegrade()));

    QObject::connect(ui->spinBox_9, SIGNAL(valueChanged(int)), this, SLOT(whichscheme()));
    QObject::connect(ui->spinBox_10, SIGNAL(valueChanged(int)), this, SLOT(whichscheme()));
    QObject::connect(ui->spinBox_11, SIGNAL(valueChanged(int)), this, SLOT(whichscheme()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Define the computegrade() function using the grading schemes
void MainWindow::computegrade() const {

    std::vector<double> scores;
    double hwscores = 0;
    double mt1score = 0;
    double mt2score = 0;
    double finalexam = 0;

    scores.push_back(ui->spinBox->value());
    scores.push_back(ui->spinBox_2->value());
    scores.push_back(ui->spinBox_3->value());
    scores.push_back(ui->spinBox_4->value());
    scores.push_back(ui->spinBox_5->value());
    scores.push_back(ui->spinBox_6->value());
    scores.push_back(ui->spinBox_7->value());
    scores.push_back(ui->spinBox_8->value());

    mt1score = (ui->spinBox_9->value());
    mt2score = (ui->spinBox_10->value());
    finalexam = (ui->spinBox_11->value());

    for(int i=0; i<(int)scores.size(); ++i){
        hwscores+=scores[i];
    }
    hwscores/=8.0;

    double schemeA = 0;
    double schemeB = 0;

    schemeA = (hwscores*.25) + ((mt1score + mt2score)*.20) + (finalexam*.35);

    if(mt1score>mt2score){
        schemeB = (hwscores*.25) + (mt1score*.30) + (finalexam*.44);
    }
    else{
        schemeB = (hwscores*.25) + (mt2score*.30) + (finalexam*.44);
    }

    double betterscore = 0;
    if(schemeA>schemeB){
        betterscore = schemeA;
    }
    else{
        betterscore = schemeB;
    }

    ui->label_13->setText(QString::number(betterscore));

}

//Determines which grading scheme to use to get the higher grade
void MainWindow::whichscheme() const{

    double mt1score = 0;
    double mt2score = 0;
    double finalexam = 0;

    mt1score = (ui->spinBox_9->value());
    mt2score = (ui->spinBox_10->value());
    finalexam = (ui->spinBox_11->value());

    double schemeA = 0;
    double schemeB = 0;

    schemeA = ((mt1score + mt2score)*.20) + (finalexam*.35);

    if(mt1score>mt2score){
        schemeB = (mt1score*.30) + (finalexam*.44);
    }
    else{
        schemeB = (mt2score*.30) + (finalexam*.44);
    }

    if(schemeA>schemeB){
        ui->radioButton->click();
        ui->radioButton->setDisabled(false);
        ui->radioButton->setChecked(true);
        ui->radioButton_2->setDisabled(true);
        ui->radioButton_2->setChecked(false);
    }
    else{
        ui->radioButton_2->click();
        ui->radioButton_2->setDisabled(false);
        ui->radioButton_2->setChecked(true);
        ui->radioButton->setDisabled(true);
        ui->radioButton->setChecked(false);
    }
}
