#include "wizard.h"

Wizard::Wizard()
    : QWizard()
{


    this->addPage(createmainpage());

    this->addPage(createfirstpage());

    this->addPage(createsecondpage());

    this->addPage(createthirdpage());

    this->addPage(createfourthpage());

    this->addPage(createdebuggingpage());

    connect(this->button(FinishButton),SIGNAL(clicked()), this, SLOT(Write()));

    //connect(this->button(QWizard::NextButton),
    //SIGNAL(clicked()),this,SLOT(onNextButtonCliked()));


}

Wizard::~Wizard()
{

}


QWizardPage* Wizard::createmainpage()
{
    QWizardPage *mainpage = new QWizardPage;
    mainpage->setTitle("Welcome to iFluid startup");

    QLabel *mainlabel = new QLabel("This wizard will help you write an in-file for iFluid.");

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(mainlabel);

    mainpage->setLayout(mainlayout);

    return mainpage;

}

QWizardPage* Wizard::createfirstpage()
{
    QWizardPage *page1 = new QWizardPage;
    page1->setTitle("iFluid Parameters: Page 1");

    QLabel *D1 = new QLabel("Domain limit in the 0th Dimension");

    QHBoxLayout *hlayout1 = new QHBoxLayout;
    QLabel *XB1 = new QLabel("Enter X Bounds:");

    firstxbound = new QLineEdit;
    firstxbound->setText("0");
    firstxbound->setFixedWidth(50);

    lastxbound = new QLineEdit;
    lastxbound->setText("1");
    lastxbound->setFixedWidth(50);

    QSpacerItem *space1 = new QSpacerItem(500,1);


    hlayout1->addWidget(XB1);
    hlayout1->addWidget(firstxbound);
    hlayout1->addWidget(lastxbound);
    hlayout1->addSpacerItem(space1);

    QVBoxLayout *vlayout1 = new QVBoxLayout;

    vlayout1->addWidget(D1);
    vlayout1->addLayout(hlayout1);

    QLabel *D2 = new QLabel("Domain limit in the 1st Dimension");

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    QLabel *YB2 = new QLabel("Enter Y Bounds:");

    firstybound = new QLineEdit;
    firstybound->setText("0");
    firstybound->setFixedWidth(50);
    lastybound = new QLineEdit;
    lastybound->setText("4");
    lastybound->setFixedWidth(50);

    QSpacerItem *space2 = new QSpacerItem(500,1);

    hlayout2->addWidget(YB2);
    hlayout2->addWidget(firstybound);
    hlayout2->addWidget(lastybound);
    hlayout2->addSpacerItem(space2);

    QVBoxLayout *vlayout2 = new QVBoxLayout;

    QSpacerItem *space3 = new QSpacerItem(500,10);

    vlayout2->addWidget(D2);
    vlayout2->addLayout(hlayout2);
    vlayout2->addSpacerItem(space3);

    QHBoxLayout *hlayout3 = new QHBoxLayout;
    QLabel *compgrid = new QLabel("Enter Computational Grid:");

    firstcoordinate = new QLineEdit;
    firstcoordinate->setText("50");
    firstcoordinate->setFixedWidth(50);
    lastcoordinate = new QLineEdit;
    lastcoordinate->setText("200");
    lastcoordinate->setFixedWidth(50);

    QSpacerItem *space4 = new QSpacerItem(500,20);

    hlayout3->addWidget(compgrid);
    hlayout3->addWidget(firstcoordinate);
    hlayout3->addWidget(lastcoordinate);
    hlayout3->addSpacerItem(space4);

    QLabel *ZL = new QLabel("Lower Boundary in 0th Dimension:");

    zerolower = new QComboBox;
    zerolower->addItem("PERIODIC_BOUNDARY");
    zerolower->addItem("NEUMANN_BOUNDARY");

    QHBoxLayout *zerolowerbox = new QHBoxLayout;
    zerolowerbox->addWidget(ZL);
    zerolowerbox->addWidget(zerolower);

    QLabel *ZU = new QLabel("Upper Boundary in 0th Dimension:");

    zeroupper = new QComboBox;
    zeroupper->addItem("PERIODIC_BOUNDARY");
    zeroupper->addItem("NEUMANN_BOUNDARY");

    QHBoxLayout *zeroupperbox = new QHBoxLayout;
    zeroupperbox->addWidget(ZU);
    zeroupperbox->addWidget(zeroupper);

    QLabel *OL = new QLabel("Lower Boundary in 1st Dimension:");

    onelower = new QComboBox;
    onelower->addItem("PERIODIC_BOUNDARY");
    onelower->addItem("NEUMANN_BOUNDARY");

    QHBoxLayout *onelowerbox = new QHBoxLayout;
    onelowerbox->addWidget(OL);
    onelowerbox->addWidget(onelower);

    QLabel *OU = new QLabel("Upper Boundary in 1st Dimension:");

    oneupper = new QComboBox;
    oneupper->addItem("PERIODIC_BOUNDARY");
    oneupper->addItem("NEUMANN_BOUNDARY");

    QHBoxLayout *oneupperbox = new QHBoxLayout;
    oneupperbox->addWidget(OU);
    oneupperbox->addWidget(oneupper);

    QVBoxLayout *vlayout3 = new QVBoxLayout;
    QSpacerItem *space5 = new QSpacerItem(500,20);

    vlayout3->addSpacerItem(space5);
    vlayout3->addLayout(zerolowerbox);
    vlayout3->addLayout(zeroupperbox);
    vlayout3->addLayout(onelowerbox);
    vlayout3->addLayout(oneupperbox);

    QVBoxLayout *page1layout = new QVBoxLayout;

    page1layout->addLayout(vlayout1);
    page1layout->addLayout(vlayout2);
    page1layout->addLayout(hlayout3);
    page1layout->addLayout(vlayout3);



    page1->setLayout(page1layout);

    return page1;


}


QWizardPage* Wizard::createsecondpage()
{
    QWizardPage *page2 = new QWizardPage;
    page2->setTitle("iFluid Parameters: Page 2");

    QHBoxLayout *mtimebox = new QHBoxLayout;
    QLabel *maxtime = new QLabel("Enter max time:");

    line1 = new QLineEdit;
    line1->setText("0.38");
    line1->setFixedWidth(60);

    QSpacerItem *mtimespace = new QSpacerItem(500,1);

    mtimebox->addWidget(maxtime);
    mtimebox->addWidget(line1);
    mtimebox->addSpacerItem(mtimespace);

    QHBoxLayout *mstepbox = new QHBoxLayout;
    QLabel *maxstep = new QLabel("Enter max step:");

    line2 = new QLineEdit;
    line2->setText("100000");
    line2->setFixedWidth(60);

    QSpacerItem *mstepspace = new QSpacerItem(500,1);

    mstepbox->addWidget(maxstep);
    mstepbox->addWidget(line2);
    mstepbox->addSpacerItem(mstepspace);

    QHBoxLayout *pintervalbox = new QHBoxLayout;
    QLabel *printinterval = new QLabel("Print interval:");

    line3 = new QLineEdit;
    line3->setText("0.1");
    line3->setFixedWidth(60);

    QSpacerItem *pintspace = new QSpacerItem(500,1);

    pintervalbox->addWidget(printinterval);
    pintervalbox->addWidget(line3);
    pintervalbox->addSpacerItem(pintspace);

    QHBoxLayout *mframebox = new QHBoxLayout;
    QLabel *movie = new QLabel("Movie frame interval:");

    line4 = new QLineEdit;
    line4->setText("0.01");
    line4->setFixedWidth(60);

    QSpacerItem *mframespace = new QSpacerItem(500,1);

    mframebox->addWidget(movie);
    mframebox->addWidget(line4);
    mframebox->addSpacerItem(mframespace);

    QHBoxLayout *CFLbox = new QHBoxLayout;
    QLabel *CFL = new QLabel("CFL factor:");

    line5 = new QLineEdit;
    line5->setText("0.75");
    line5->setFixedWidth(60);

    QSpacerItem *CFLspace = new QSpacerItem(500,1);

    CFLbox->addWidget(CFL);
    CFLbox->addWidget(line5);
    CFLbox->addSpacerItem(CFLspace);

    QHBoxLayout *redintbox = new QHBoxLayout;
    QLabel *redinterval = new QLabel("Redistribution interval:");

    line6 = new QLineEdit;
    line6->setText("5");
    line6->setFixedWidth(60);

    QSpacerItem *redintspace = new QSpacerItem(500,1);

    redintbox->addWidget(redinterval);
    redintbox->addWidget(line6);
    redintbox->addSpacerItem(redintspace);

    QHBoxLayout *probtypebox = new QHBoxLayout;
    QLabel *ptype = new QLabel("Enter the problem type:");
    probtype = new QComboBox;
    probtype->addItem("TWO_FLUID_BUBBLE");
    probtype->addItem("TWO_FLUID_RT");
    probtype->addItem("TWO_FLUID_KH");
    probtype->addItem("FLUID_SOLID_CIRCLE");

    probtypebox->addWidget(ptype);
    probtypebox->addWidget(probtype);

    QHBoxLayout *projtypebox = new QHBoxLayout;
    QLabel *proj_type = new QLabel("Enter the projection type:");
    projectiontype = new QComboBox;
    projectiontype->addItem("SIMPLE");
    projectiontype->addItem("BELL_COLELLA");
    projectiontype->addItem("KIM_MOIN");
    projectiontype->addItem("PEROT_BOTELLA");

    projtypebox->addWidget(proj_type);
    projtypebox->addWidget(projectiontype);


    QVBoxLayout *vertlayout = new QVBoxLayout;

    QSpacerItem *vertlayoutspace = new QSpacerItem(500,30);

    vertlayout->addLayout(mtimebox);
    vertlayout->addLayout(mstepbox);
    vertlayout->addLayout(pintervalbox);
    vertlayout->addLayout(mframebox);
    vertlayout->addLayout(CFLbox);
    vertlayout->addLayout(redintbox);
    vertlayout->addSpacerItem(vertlayoutspace);
    vertlayout->addLayout(probtypebox);
    vertlayout->addLayout(projtypebox);

    QVBoxLayout *page2layout = new QVBoxLayout;

    page2layout->addLayout(vertlayout);



    page2->setLayout(page2layout);

    return page2;

}



QWizardPage* Wizard::createthirdpage()
{

    QWizardPage *page3 = new QWizardPage;
    page3->setTitle("iFluid Parameters: Page 3");

    QHBoxLayout *fourteenth = new QHBoxLayout;
    QLabel *meanpos = new QLabel("Enter mean position of fluid interface:");

    line7 = new QLineEdit;
    line7->setText("2.6");
    line7->setFixedWidth(50);

    QSpacerItem *space_14 = new QSpacerItem(140,1);

    fourteenth->addWidget(meanpos);
    fourteenth->addWidget(line7);
    fourteenth->addSpacerItem(space_14);

    QHBoxLayout *fifteenth = new QHBoxLayout;
    QLabel *sinemodes = new QLabel("Enter number of sine modes:");

    line8 = new QLineEdit;
    line8->setText("1");
    line8->setFixedWidth(50);

    QSpacerItem *space_15 = new QSpacerItem(500,1);

    fifteenth->addWidget(sinemodes);
    fifteenth->addWidget(line8);
    fifteenth->addSpacerItem(space_15);

    QHBoxLayout *sixteenth = new QHBoxLayout;
    QLabel *freq = new QLabel("Enter frequency of mode 1:");

    line9 = new QLineEdit;
    line9->setText("1");
    line9->setFixedWidth(50);

    QSpacerItem *space_16 = new QSpacerItem(500,1);

    sixteenth->addWidget(freq);
    sixteenth->addWidget(line9);
    sixteenth->addSpacerItem(space_16);

    QHBoxLayout *seventeenth = new QHBoxLayout;
    QLabel *amp = new QLabel("Ente amplitude of mode 1:");

    line10 = new QLineEdit;
    line10->setText("0.05");
    line10->setFixedWidth(50);

    QSpacerItem *space_17 = new QSpacerItem(500,1);

    seventeenth->addWidget(amp);
    seventeenth->addWidget(line10);
    seventeenth->addSpacerItem(space_17);

    QHBoxLayout *eighteenth = new QHBoxLayout;
    QLabel *phase = new QLabel("Enter phase of mode 1:");

    line11 = new QLineEdit;
    line11->setText("270");
    line11->setFixedWidth(50);

    QSpacerItem *space_18 = new QSpacerItem(500,1);

    eighteenth->addWidget(phase);
    eighteenth->addWidget(line11);
    eighteenth->addSpacerItem(space_18);

    QHBoxLayout *nineteenth = new QHBoxLayout;
    QLabel *dandv1 = new QLabel("Enter density and viscosity of fluid 1:");

    den1 = new QLineEdit;
    den1->setText("0.1");
    den1->setFixedWidth(70);
    vis1 = new QLineEdit;
    vis1->setText("0.00628");
    vis1->setFixedWidth(70);

    QSpacerItem *space_19 = new QSpacerItem(50,1);

    nineteenth->addWidget(dandv1);
    nineteenth->addWidget(den1);
    nineteenth->addWidget(vis1);
    nineteenth->addSpacerItem(space_19);

    QHBoxLayout *twenty = new QHBoxLayout;
    QLabel *dandv2 = new QLabel("Enter density and viscosity of fluid 2:");

    den2 = new QLineEdit;
    den2->setText("1.0");
    den2->setFixedWidth(70);
    vis2 = new QLineEdit;
    vis2->setText("0.00628");
    vis2->setFixedWidth(70);

    QSpacerItem *space_20 = new QSpacerItem(50,1);

    twenty->addWidget(dandv2);
    twenty->addWidget(den2);
    twenty->addWidget(vis2);
    twenty->addSpacerItem(space_20);

    QHBoxLayout *twentyone = new QHBoxLayout;
    QLabel *gravity = new QLabel("Enter gravity:");

    grav1 = new QLineEdit;
    grav1->setText("0.0");
    grav1->setFixedWidth(70);
    grav2 = new QLineEdit;
    grav2->setText("-100.0");
    grav2->setFixedWidth(70);

    QSpacerItem *space_21 = new QSpacerItem(500,1);

    twentyone->addWidget(gravity);
    twentyone->addWidget(grav1);
    twentyone->addWidget(grav2);
    twentyone->addSpacerItem(space_21);

    QHBoxLayout *twentytwo = new QHBoxLayout;
    QLabel *surftension = new QLabel("Enter surface tension:");

    line12 = new QLineEdit;
    line12->setText("0.0");
    line12->setFixedWidth(50);

    QSpacerItem *space_22 = new QSpacerItem(500,1);

    twentytwo->addWidget(surftension);
    twentytwo->addWidget(line12);
    twentytwo->addSpacerItem(space_22);

    QHBoxLayout *twentythree = new QHBoxLayout;
    QLabel *smoothrad = new QLabel("Enter factor of smoothing radius:");

    line13 = new QLineEdit;
    line13->setText("1");
    line13->setFixedWidth(50);

    QSpacerItem *space_23 = new QSpacerItem(180,1);

    twentythree->addWidget(smoothrad);
    twentythree->addWidget(line13);
    twentythree->addSpacerItem(space_23);

    QVBoxLayout *vertlayout = new QVBoxLayout;

    QSpacerItem *vertspace = new QSpacerItem(500,10);

    vertlayout->addLayout(fourteenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(fifteenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(sixteenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(seventeenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(eighteenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(nineteenth);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(twenty);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(twentyone);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(twentytwo);
    vertlayout->addSpacerItem(vertspace);
    vertlayout->addLayout(twentythree);


    QVBoxLayout *page3layout = new QVBoxLayout;

    page3layout->addLayout(vertlayout);


    page3->setLayout(page3layout);

    return page3;

}

QWizardPage* Wizard::createfourthpage()
{

    QWizardPage *page4 = new QWizardPage;
    page4->setTitle("iFluid Parameters: Page 4");

    mv_pressure = new QCheckBox;
    mv_pressure->setText("Pressure");
    mv_pressure->setChecked(true);

    mv_vorticity = new QCheckBox;
    mv_vorticity->setText("Vorticity");
    mv_vorticity->setChecked(true);

    mv_velocity = new QCheckBox;
    mv_velocity->setText("Velocity");
    mv_velocity->setChecked(true);

    mv_velocityfield = new QCheckBox;
    mv_velocityfield->setText("Vector Velocity Field");
    mv_velocityfield->setChecked(true);

    QVBoxLayout *vertlayout = new QVBoxLayout;

    QLabel *whatmovie = new QLabel("What Movie Type(s) Would You Like To Make?");

    vertlayout->addWidget(whatmovie);
    vertlayout->addWidget(mv_pressure);
    vertlayout->addWidget(mv_vorticity);
    vertlayout->addWidget(mv_velocity);
    vertlayout->addWidget(mv_velocityfield);

    QVBoxLayout *page4layout = new QVBoxLayout;

    page4layout->addLayout(vertlayout);


    page4->setLayout(page4layout);

    return page4;

}

QWizardPage* Wizard::createdebuggingpage()
{

    QWizardPage *page5 = new QWizardPage;
    page5->setTitle("iFluid Parameters: Page 5 (Debugging Options)");

    QHBoxLayout *debuggingmain = new QHBoxLayout;
    QLabel *debugging_yn = new QLabel("Would you like to turn debugging on?");
    debugcombo = new QComboBox;
    debugcombo->addItem("Yes");
    debugcombo->addItem("No");

    debuggingmain->addWidget(debugging_yn);
    debuggingmain->addWidget(debugcombo);

    QHBoxLayout *debuggingopt1 = new QHBoxLayout;
    QLabel *debugging_string1 = new QLabel("Enter the debugging string:");

    line14 = new QLineEdit;
    line14->setText("ttrace");
    line14->setFixedWidth(150);

    QSpacerItem *opt1space = new QSpacerItem(80,1);

    debuggingopt1->addWidget(debugging_string1);
    debuggingopt1->addWidget(line14);
    debuggingopt1->addSpacerItem(opt1space);

    QHBoxLayout *debuggingopt2 = new QHBoxLayout;
    QLabel *debugging_string2 = new QLabel("Enter the debugging string:");

    line15 = new QLineEdit;
    line15->setText("tCLOCK");
    line15->setFixedWidth(150);

    QSpacerItem *opt2space = new QSpacerItem(80,1);

    debuggingopt2->addWidget(debugging_string2);
    debuggingopt2->addWidget(line15);
    debuggingopt2->addSpacerItem(opt2space);

    QHBoxLayout *debuggingopt3 = new QHBoxLayout;
    QLabel *debugging_string3 = new QLabel("Enter the debugging string:");

    line16 = new QLineEdit;
    line16->setText("tstep_size");
    line16->setFixedWidth(150);

    QSpacerItem *opt3space = new QSpacerItem(80,1);

    debuggingopt3->addWidget(debugging_string3);
    debuggingopt3->addWidget(line16);
    debuggingopt3->addSpacerItem(opt3space);

    QHBoxLayout *debuggingopt4 = new QHBoxLayout;
    QLabel *debugging_string4 = new QLabel("Enter the debugging string:");

    line17 = new QLineEdit;
    line17->setText("sample_velocity");
    line17->setFixedWidth(150);

    QSpacerItem *opt4space = new QSpacerItem(80,1);

    debuggingopt4->addWidget(debugging_string4);
    debuggingopt4->addWidget(line17);
    debuggingopt4->addSpacerItem(opt4space);

    QHBoxLayout *samplelinetype = new QHBoxLayout;
    QLabel *slinetypelabel = new QLabel("Enter the sample line type:");

    line18 = new QLineEdit;
    line18->setText("x");
    line18->setFixedWidth(150);

    QSpacerItem *linetypspace = new QSpacerItem(80,1);

    samplelinetype->addWidget(slinetypelabel);
    samplelinetype->addWidget(line18);
    samplelinetype->addSpacerItem(linetypspace);

    QHBoxLayout *samplelinecoord = new QHBoxLayout;
    QLabel *slinecoordlabel = new QLabel("Enter the sample line coordinate:");
    \
    line19 = new QLineEdit;
    line19->setText("0.5");
    line19->setFixedWidth(50);

    QSpacerItem *linecoordspace = new QSpacerItem(160,1);

    samplelinecoord->addWidget(slinecoordlabel);
    samplelinecoord->addWidget(line19);
    samplelinecoord->addSpacerItem(linecoordspace);

    QHBoxLayout *startstep = new QHBoxLayout;
    QLabel *startsteplabel = new QLabel("Enter the start step for sample:");

    line20 = new QLineEdit;
    line20->setText("0");
    line20->setFixedWidth(50);

    QSpacerItem *startstepspace = new QSpacerItem(160,1);

    startstep->addWidget(startsteplabel);
    startstep->addWidget(line20);
    startstep->addSpacerItem(startstepspace);

    QHBoxLayout *endstep = new QHBoxLayout;
    QLabel *endsteplabel = new QLabel("Enter the end step for sample:");

    line21 = new QLineEdit;
    line21->setText("10");
    line21->setFixedWidth(50);

    QSpacerItem *endstepspace = new QSpacerItem(160,1);

    endstep->addWidget(endsteplabel);
    endstep->addWidget(line21);
    endstep->addSpacerItem(endstepspace);

    QHBoxLayout *stepint = new QHBoxLayout;
    QLabel *stepintlabel = new QLabel("Enter the step interval for sample:");

    line22 = new QLineEdit;
    line22->setText("1");
    line22->setFixedWidth(50);

    QSpacerItem *stepintspace = new QSpacerItem(160,1);

    stepint->addWidget(stepintlabel);
    stepint->addWidget(line22);
    stepint->addSpacerItem(stepintspace);


    QVBoxLayout *page5layout = new QVBoxLayout;

    QSpacerItem *vertspace = new QSpacerItem(500,5);

    page5layout->addLayout(debuggingmain);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(debuggingopt1);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(debuggingopt2);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(debuggingopt3);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(debuggingopt4);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(samplelinetype);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(samplelinecoord);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(startstep);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(endstep);
    page5layout->addSpacerItem(vertspace);
    page5layout->addLayout(stepint);



    page5->setLayout(page5layout);

    return page5;
}



























