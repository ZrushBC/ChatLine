#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,618);
//无边框和透明
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
//创建总界面
    QWidget *allWidget = new QWidget(this);
//创建主界面
    QWidget *mainWidget = new QWidget(allWidget);
// 创建一个QWidget作为导航栏
    QWidget *navWidget = new QWidget(mainWidget);
    //设置大小
    navWidget->setFixedWidth(150);
// 创建两个QPushButton作为导航栏的按钮，分别代表聊天和好友
    chatBtn = new QPushButton("主页", navWidget);
    homieBtn = new QPushButton("设置", navWidget);
    //设置大小
    chatBtn->setFixedHeight(50);
    homieBtn->setFixedHeight(50);
// 创建一个QHBoxLayout作为导航栏的布局
    QVBoxLayout *vnavLayout = new QVBoxLayout();
    // 将按钮添加到导航栏的布局中
    vnavLayout->setSpacing(0); //控件间间距
    vnavLayout->setMargin(0);
    vnavLayout->addWidget(chatBtn);
    vnavLayout->addWidget(homieBtn);
    vnavLayout->addStretch();
// 设置导航栏的布局
    navWidget->setLayout(vnavLayout);
    navWidget->setStyleSheet("background:rgb(185,185,185)");
//navWidget->resize(80,this->width());

//分界线
    QFrame *line = new QFrame();
//line->setObjectName(QStringLiteral("line"));
    line->setStyleSheet("background:rgb(255,185,185)");
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
// 创建一个QStackedWidget作为页面容器
    pages = new QStackedWidget(mainWidget);
    //pages->setStyleSheet("background:rgb(95,159,255)");
// 创建两个页面QWidget，分别代表聊天、好友
    chat = new Chat(pages);
    homie = new Homie(pages);
    // 将页面添加到页面容器中
    pages->addWidget(chat);
    pages->addWidget(homie);

// 创建一个QVBoxLayout作为主界面的布局
    QHBoxLayout *mainLayout = new QHBoxLayout();
    // 将导航栏和页面容器添加到总界面的布局中
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->addWidget(navWidget);
//    mainLayout->addWidget(line);
    mainLayout->addWidget(pages);
// 设置主界面的布局
    mainWidget->setLayout(mainLayout);

//创建一个QVBoxLayout作为总界面的布局
    QVBoxLayout *hnavLayout = new QVBoxLayout();
    //创建一个头部导航栏
    QWidget *headWidget = new QWidget(this);
    headWidget->setFixedHeight(30);
    headWidget->setStyleSheet("background:rgb(255,189,255)");
    //关闭按钮
    Btn *close_btn=new Btn(true);
    close_btn->setParent(headWidget);
    close_btn->move(this->width()-close_btn->width()-12,10);
    connect(close_btn,&QPushButton::clicked,this,&MainWindow::close);
    //最小化按钮
    Btn *min_btn=new Btn(false);
    min_btn->setParent(headWidget);
    min_btn->move(this->width()-min_btn->width()-32,10);
    connect(min_btn,&QPushButton::clicked,this,&MainWindow::showMinimized);
    //设置布局
    hnavLayout->setSpacing(0); //控件间间距
    hnavLayout->setMargin(0);
    hnavLayout->addWidget(headWidget);
    hnavLayout->addWidget(mainWidget);
//设置总界面的布局
    allWidget->setLayout(hnavLayout);
// 设置主窗口的中央部件
    this->setCentralWidget(allWidget);
// 创建一个QButtonGroup作为导航栏的按钮组
    navGroup = new QButtonGroup(mainWidget);
    navGroup->addButton(chatBtn, 0);
    navGroup->addButton(homieBtn, 1);
    navGroup->setExclusive(true);
// 连接导航栏按钮的clicked()信号到页面容器的setCurrentIndex()槽
    connect(navGroup, QOverload<int>::of(&QButtonGroup::idClicked), pages, &QStackedWidget::setCurrentIndex);
}


//鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    this->move(event->globalPos() - this->dPos);
}


MainWindow::~MainWindow()
{
    delete ui;
}
