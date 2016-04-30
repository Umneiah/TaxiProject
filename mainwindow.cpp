#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initial();
    list<node*> tr = map.Destination("55",map.oneSourceAllDestination("22"));
    map.clearVisited();
    pixmap.load(QString::fromUtf8(":images/map.jpg"));//path of image
    ui->MapLbl->setPixmap(pixmap);
    ui->MapLbl->show();
}
void MainWindow::DrawCar()
{
     QPainter painter(&pixmap);
     QPoint p;
     QImage car;
     car.load(QString::fromUtf8(":images/car.png"));  //path of car.png
     list<node*> carlis = map.GetCarList();
     list<node*>::iterator i;
     for(i=carlis.begin();i!=carlis.end();++i)
     {
         p.setX((*i)->getX() - 12);
         p.setY((*i)->getY() - 7);
         painter.drawImage(p,car);
     }
     ui->MapLbl->setPixmap(pixmap);
     ui->MapLbl->show();
}
void MainWindow::DrawLocation(node* n , QString s )
{
     QPainter paint(&pixmap);
         int x = n->getX()-3;
         int y = n->getY()-4;
         QRectF rect(QPoint(x, y), QSize(200, 300));
         paint.setBackgroundMode( Qt::OpaqueMode );
         paint.setBackground( QColor( Qt::blue ) );
         paint.drawText(rect, Qt::AlignJustify, s);
     ui->MapLbl->setPixmap(pixmap);
     ui->MapLbl->show();
}
void MainWindow::DrawTextt(vector<node*> nodeList)
{
     QPainter paint(&pixmap);
     for(vector< node *>::iterator ii= nodeList.begin(); ii != nodeList.end(); ii++)
     {
         int x = (*ii)->getX();
         int y = (*ii)->getY();
         string temp = (*ii)->getName();
         QString Qtemp = QString::fromStdString(temp);
         QRectF rect(QPoint(x-3, y-4), QSize(20, 30));
         paint.setBackgroundMode( Qt::OpaqueMode );
         paint.setBackground( QColor( Qt::cyan ) );
         paint.drawText(rect, Qt::AlignJustify, Qtemp);
     }
     ui->MapLbl->setPixmap(pixmap);
     ui->MapLbl->show();
}
void MainWindow::trial()
{
    map.AddCarList("45");
    map.AddCarList("58");
    map.AddCarList("36");
    map.AddCarList("2");
    map.AddCarList("7");
    DrawCar();
    list<node*> hah = map.NearestCar("20");
    DrawPath(hah,0);
}
void MainWindow::DrawPath(list<node *> path,int choose)
{
    QPen pen;
    if (choose == 1) pen.setColor(Qt::red);
    else pen.setColor(Qt::green);
    pen.setWidth(10);
     QPainter painter(&pixmap);
     painter.setPen(pen);
     list<node *>::iterator g=path.end();
     g--;
    for(list<node *>::iterator i=path.begin();i!=g;i++)
    {
        list<node*>::iterator temp =i;
        temp++;
          QLine l;
          l.setLine((*i)->getX(),(*i)->getY(),(*(temp))->getX(),(*(temp))->getY());
          painter.drawLine(l);
    }
    ui->MapLbl->setPixmap(pixmap);
    ui->MapLbl->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initial()
{
       node *f = new node("0",61,722);
       map.addNewNode(f);
       node *a = new node("1",19,142);
       map.addNewNode(a);
       node *b = new node("2",43,255);
       map.addNewNode(b);
       node *c = new node("3",65,365);
       map.addNewNode(c);
       node *n = new node("4",90,479);
       map.addNewNode(n);
       node *m = new node("5",113,591);
       map.addNewNode(m);
       node *d = new node("6",140,704);
       map.addNewNode(d);
       node *z = new node("7",97,124);
       map.addNewNode(z);
       node *q = new node("8",121,236);
       map.addNewNode(q);
       node *w = new node("9",146,348);
       map.addNewNode(w);
       node *e = new node("10",170,462);
       map.addNewNode(e);
       node *r = new node("11",194,575);
       map.addNewNode(r);
       node *y = new node("12",217,687);
       map.addNewNode(y);
       node *u = new node("13",176,107);
       map.addNewNode(u);
       node *p = new node("14",200,219);
       map.addNewNode(p);
       node *i = new node("15",223,333);
       map.addNewNode(i);
       node *x = new node("16",249,444);
       map.addNewNode(x);
       node *A = new node("17",273,557);
       map.addNewNode(A);
       node *S = new node("18",296,670);
       map.addNewNode(S);
       node *Q = new node("19",255,91);
       map.addNewNode(Q);
       node *W = new node("20",279,203);
       map.addNewNode(W);
       node *R = new node("21",304,314);
       map.addNewNode(R);
       node *T = new node("22",327,427);
       map.addNewNode(T);
       node *Y = new node("23",351,541);
       map.addNewNode(Y);
       node *U = new node("24",376,654);
       map.addNewNode(U);
       node *g = new node("25",400,765);
       map.addNewNode(g);
       node *O = new node("26",334,73);
       map.addNewNode(O);
       node *I = new node("27",359,185);
       map.addNewNode(I);
       node *M = new node("28",382,298);
       map.addNewNode(M);
       node *F = new node("29",407,411);
       map.addNewNode(F);
       node *J = new node("30",431,525);
       map.addNewNode(J);
       node *L = new node("31",455,637);
       map.addNewNode(L);
       node *SSS = new node("32",479,748);
       map.addNewNode(SSS);
       node *G = new node("33",413,55);
       map.addNewNode(G);
       node *D = new node("34",437,169);
       map.addNewNode(D);
       node *ZZ = new node("35",461,281);
       map.addNewNode(ZZ);
       node *EE = new node("36",485,395);
       map.addNewNode(EE);
       node *QQ = new node("37",510,507);
       map.addNewNode(QQ);
       node *WW = new node("38",534,620);
       map.addNewNode(WW);
       node *DDD = new node("39",559,732);
       map.addNewNode(DDD);
       node *RR = new node("40",493,39);
       map.addNewNode(RR);
       node *FF = new node("41",516,152);
       map.addNewNode(FF);
       node *XX = new node("42",540,265);
       map.addNewNode(XX);
       node *TT = new node("43",564,377);
       map.addNewNode(TT);
       node *PP = new node("44",587,490);
       map.addNewNode(PP);
       node *NN = new node("45",612,601);
       map.addNewNode(NN);
       node *FFF = new node("46",637,714);
       map.addNewNode(FFF);
       node *VV = new node("47",572,23);
       map.addNewNode(VV);
       node *qq = new node("48",594,134);
       map.addNewNode(qq);
       node *oo = new node("49",619,247);
       map.addNewNode(oo);
       node *ff = new node("50",643,360);
       map.addNewNode(ff);
       node *as = new node("51",667,472);
       map.addNewNode(as);
       node *yu = new node("52",692,585);
       map.addNewNode(yu);
       node *QQQ = new node("53",714,697);
       map.addNewNode(QQQ);
       node *aq = new node("54",674,115);
       map.addNewNode(aq);
       node *tr = new node("55",698,230);
       map.addNewNode(tr);
       node *br = new node("56",724,345);
       map.addNewNode(br);
       node *er = new node("57",747,457);
       map.addNewNode(er);
       node *wc = new node("58",36,609);
       map.addNewNode(wc);
       a->addAdjnodes(z,10);
       a->addAdjnodes(b,15);
       b->addAdjnodes(a,15);
       b->addAdjnodes(q,10);
       b->addAdjnodes(c,15);
       c->addAdjnodes(b,15);
       c->addAdjnodes(w,10);
       c->addAdjnodes(n,15);
       f->addAdjnodes(wc,15);
       f->addAdjnodes(d,10);
       n->addAdjnodes(m,15);
       n->addAdjnodes(e,10);
       n->addAdjnodes(c,15);
       d->addAdjnodes(f,10);
       d->addAdjnodes(m,15);
       d->addAdjnodes(y,10);
       g->addAdjnodes(SSS,10);
       g->addAdjnodes(U,15);
       SSS->addAdjnodes(g,10);
       SSS->addAdjnodes(DDD,10);
       SSS->addAdjnodes(L,15);
       DDD->addAdjnodes(SSS,10);
       DDD->addAdjnodes(FFF,10);
       DDD->addAdjnodes(WW,15);
       FFF->addAdjnodes(DDD,10);
       FFF->addAdjnodes(QQQ,10);
       FFF->addAdjnodes(NN,15);
       QQQ->addAdjnodes(FFF,10);
       QQQ->addAdjnodes(yu,15);
       m->addAdjnodes(wc,10);
       m->addAdjnodes(r,10);
       m->addAdjnodes(n,15);
       m->addAdjnodes(d,15);
       z->addAdjnodes(u,10);
       z->addAdjnodes(a,10);
       z->addAdjnodes(q,15);
       q->addAdjnodes(p,10);
       q->addAdjnodes(w,15);
       q->addAdjnodes(z,15);
       q->addAdjnodes(b,10);
       w->addAdjnodes(i,10);
       w->addAdjnodes(c,10);
       w->addAdjnodes(q,15);
       w->addAdjnodes(e,15);
       e->addAdjnodes(x,10);
       e->addAdjnodes(r,15);
       e->addAdjnodes(n,10);
       e->addAdjnodes(w,15);
       r->addAdjnodes(A,10);
       r->addAdjnodes(m,10);
       r->addAdjnodes(e,15);
       r->addAdjnodes(y,15);
       y->addAdjnodes(S,10);
       y->addAdjnodes(r,15);
       y->addAdjnodes(d,10);//
       u->addAdjnodes(Q,10);
       u->addAdjnodes(z,10);
       u->addAdjnodes(p,15);
       p->addAdjnodes(W,10);
       p->addAdjnodes(i,15);
       p->addAdjnodes(q,10);
       p->addAdjnodes(u,15);
       i->addAdjnodes(w,10);
       i->addAdjnodes(R,10);
       i->addAdjnodes(x,15);
       i->addAdjnodes(p,15);
       x->addAdjnodes(T,10);
       x->addAdjnodes(e,10);
       x->addAdjnodes(i,15);
       x->addAdjnodes(A,15);
       A->addAdjnodes(Y,10);
       A->addAdjnodes(S,15);
       A->addAdjnodes(x,15);
       A->addAdjnodes(r,10);
       S->addAdjnodes(U,10);
       S->addAdjnodes(y,10);
       S->addAdjnodes(A,15);
       Q->addAdjnodes(W,15);
       Q->addAdjnodes(O,10);
       Q->addAdjnodes(u,10);
       W->addAdjnodes(I,10);
       W->addAdjnodes(p,10);
       W->addAdjnodes(R,15);
       W->addAdjnodes(Q,15);
       R->addAdjnodes(T,15);
       R->addAdjnodes(M,10);
       R->addAdjnodes(i,10);
       R->addAdjnodes(W,15);
       Y->addAdjnodes(J,10);
       Y->addAdjnodes(U,15);
       Y->addAdjnodes(A,10);
       Y->addAdjnodes(T,15);
       T->addAdjnodes(Y,15);
       T->addAdjnodes(R,15);
       T->addAdjnodes(x,10);
       T->addAdjnodes(F,10);
       U->addAdjnodes(L,10);
       U->addAdjnodes(S,10);
       U->addAdjnodes(Y,15);
       U->addAdjnodes(g,15);
       O->addAdjnodes(G,10);
       O->addAdjnodes(I,15);
       O->addAdjnodes(Q,10);
       I->addAdjnodes(M,15);
       I->addAdjnodes(W,10);
       I->addAdjnodes(D,10);
       I->addAdjnodes(O,15);
       M->addAdjnodes(ZZ,10);
       M->addAdjnodes(F,15);
       M->addAdjnodes(I,15);
       M->addAdjnodes(R,10);
       F->addAdjnodes(J,15);
       F->addAdjnodes(EE,10);
       F->addAdjnodes(T,10);
       F->addAdjnodes(M,15);
       J->addAdjnodes(L,15);
       J->addAdjnodes(QQ,10);
       J->addAdjnodes(Y,10);
       J->addAdjnodes(F,15);
       L->addAdjnodes(WW,10);
       L->addAdjnodes(J,15);
       L->addAdjnodes(U,10);
       L->addAdjnodes(SSS,15);
       G->addAdjnodes(RR,10);
       G->addAdjnodes(O,10);
       G->addAdjnodes(D,15);
       D->addAdjnodes(ZZ,15);
       D->addAdjnodes(FF,10);
       D->addAdjnodes(I,10);
       D->addAdjnodes(G,15);
       ZZ->addAdjnodes(EE,15);
       ZZ->addAdjnodes(XX,10);
       ZZ->addAdjnodes(D,15);
       ZZ->addAdjnodes(M,10);
       EE->addAdjnodes(TT,10);
       EE->addAdjnodes(QQ,15);
       EE->addAdjnodes(ZZ,15);
       EE->addAdjnodes(F,10);
       QQ->addAdjnodes(PP,10);
       QQ->addAdjnodes(J,10);
       QQ->addAdjnodes(WW,15);
       QQ->addAdjnodes(EE,15);
       WW->addAdjnodes(NN,10);
       WW->addAdjnodes(QQ,15);
       WW->addAdjnodes(L,10);
       WW->addAdjnodes(DDD,15);
       RR->addAdjnodes(FF,15);
       RR->addAdjnodes(G,10);
       RR->addAdjnodes(VV,10);
       FF->addAdjnodes(XX,15);
       FF->addAdjnodes(qq,10);
       FF->addAdjnodes(D,10);
       FF->addAdjnodes(RR,15);
       XX->addAdjnodes(TT,15);
       XX->addAdjnodes(ZZ,10);
       XX->addAdjnodes(FF,15);
       XX->addAdjnodes(oo,10);
       TT->addAdjnodes(ff,10);
       TT->addAdjnodes(PP,15);
       TT->addAdjnodes(EE,10);
       TT->addAdjnodes(XX,15);
       PP->addAdjnodes(as,10);
       PP->addAdjnodes(TT,15);
       PP->addAdjnodes(QQ,10);
       PP->addAdjnodes(NN,15);
       NN->addAdjnodes(yu,10);
       NN->addAdjnodes(WW,10);
       NN->addAdjnodes(PP,15);
       NN->addAdjnodes(FFF,15);
       VV->addAdjnodes(qq,15);
       VV->addAdjnodes(RR,10);
       qq->addAdjnodes(oo,15);
       qq->addAdjnodes(FF,10);
       qq->addAdjnodes(VV,15);
       qq->addAdjnodes(aq,10);
       oo->addAdjnodes(ff,15);
       oo->addAdjnodes(XX,10);
       oo->addAdjnodes(tr,10);
       oo->addAdjnodes(qq,15);
       ff->addAdjnodes(as,15);
       ff->addAdjnodes(TT,10);
       ff->addAdjnodes(oo,15);
       ff->addAdjnodes(br,10);
       as->addAdjnodes(yu,15);
       as->addAdjnodes(PP,10);
       as->addAdjnodes(ff,15);
       as->addAdjnodes(er,10);
       yu->addAdjnodes(NN,10);
       yu->addAdjnodes(QQQ,15);
       aq->addAdjnodes(tr,15);
       aq->addAdjnodes(qq,10);
       tr->addAdjnodes(br,15);
       tr->addAdjnodes(oo,10);
       tr->addAdjnodes(aq,15); //check keda
       br->addAdjnodes(ff,10);
       br->addAdjnodes(er,15);
       wc->addAdjnodes(m,10);
       wc->addAdjnodes(f,15);
}
void MainWindow::on_ShowAll_button_clicked()
{
    DrawTextt(map.getVec());
}
void MainWindow::on_AddCars_button_clicked()
{
    list <node*> temppp;
    temppp.clear();
    meh.clear();
    heh.clear();
    map.SetCarList(temppp);
    pixmap.load(QString::fromUtf8(":images/map.jpg"));
    ui->MapLbl->setPixmap(pixmap);
    ui->MapLbl->show();
    QString input_locations = ui->CarLocation_text->toPlainText();
    QStringList list_of_locations = input_locations.split("\n");
    if (input_locations.length() == 0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Enter Taxi locations!");
        messageBox.setFixedSize(0,0);
    }
    else
    {
        for(QStringList :: iterator i = list_of_locations.begin() ; i != list_of_locations.end() ; i++)
        {
            if((*i)=="") break;
            string current_location =(*i).toLocal8Bit().constData(); //convert Qstring to string
            map.AddCarList(current_location);
        }
    }    
    DrawCar();
}
void MainWindow::on_Start_button_clicked()
{
      QString start_location = ui->Start_text->QLineEdit::text();
      string start =start_location.toLocal8Bit().constData(); //convert Qstring to string
      QString End_location = ui->End_text->QLineEdit::text();
      string end = End_location.toLocal8Bit().constData(); //convert Qstring to string
      if (start.length() != 0 || end.length() != 0)
      {
          node* nstart = map.findNodeByName(start);
          node* nend = map.findNodeByName(end);
          start1=nstart;
          end1=nend;
          DrawLocation(nstart , "Start");
          DrawLocation(nend , "End");
          meh = map.Destination(start,map.oneSourceAllDestination(end));
          if(! map.GetCarList().empty()) heh = map.NearestCar(start);
      }
      else
      {
          QMessageBox messageBox;
          messageBox.critical(0,"Error","Enter Start and Destinition!");
          messageBox.setFixedSize(0,0);
      }
}
void MainWindow::on_getCar_clicked()
{
   if(map.GetCarList().empty())
   {
       QMessageBox messageBox;
       messageBox.critical(0,"Error","Enter Taxi locations!");
       messageBox.setFixedSize(0,0);
   }
   else
   {
       QString start_location = ui->Start_text->QLineEdit::text();
       string start =start_location.toLocal8Bit().constData(); //convert Qstring to string
       node * ori = heh.back();
       map.CarMovement(ori,map.findNodeByName(start));
       pixmap.load(QString::fromUtf8(":images/map.jpg"));
       ui->MapLbl->setPixmap(pixmap);
       ui->MapLbl->show();
       DrawCar();
       DrawPath(heh,0);
       DrawLocation(start1 , "Start");
       DrawLocation(end1 , "End");

   }
}
void MainWindow::on_Run_clicked()
{
    QString start_location = ui->Start_text->QLineEdit::text();
    string start =start_location.toLocal8Bit().constData();
    QString End_location = ui->End_text->QLineEdit::text();
    string end = End_location.toLocal8Bit().constData(); //convert Qstring to string
    map.CarMovement(map.findNodeByName(start),map.findNodeByName(end));
    pixmap.load(QString::fromUtf8(":images/map.jpg"));
    ui->MapLbl->setPixmap(pixmap);
    ui->MapLbl->show();
    DrawCar();
    DrawPath(heh,0);
    DrawLocation(start1 , "Start");
    DrawLocation(end1 , "End");
    DrawPath(meh,1);
    QString og = QString::number(map.GetPathLength(meh));
    QString og1 = QString::number(map.GetPathLength(meh)*2.5/10);
    ui->ogra->setText("Path length = "+og +" m"+"\n"+"Cost = "+og1+" LE");
}

void MainWindow::on_save_clicked()
{
    QFile e("state.txt");
    e.open(QIODevice::WriteOnly | QIODevice::Text);
    list<node*> carlis = map.GetCarList();
    list<node*>::iterator i;
    for(i=carlis.begin();i!=carlis.end();++i)
    {
           QTextStream outStream(&e);
           QString qstr = QString::fromStdString((*i)->getName());
           outStream <<qstr<<endl;
    }
    e.close();
}

void MainWindow::on_load_clicked()
{
    QString written;
     QFile e("state.txt");
     e.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&e);
     while(!in.atEnd())
     {
         QString line = in.readLine();
         string c =line.toLocal8Bit().constData(); //convert Qstring to string
         map.AddCarList(c);
         written+=line;
         if(!in.atEnd()) written+="\n";
     }
     e.resize(0);
     ui->CarLocation_text->setPlainText(written);
    DrawCar();
}
