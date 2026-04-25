#include "Form1.h"
#include "../include/MathVariant25.h"

#include <cmath>

using namespace Lab04Win;
using namespace System;
using namespace System::Drawing;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;

static double ParseDouble(TextBox^ tb) {
    String^ s = tb->Text->Trim()->Replace(L",", L".");
    return Double::Parse(s, CultureInfo::InvariantCulture);
}

void Lab04Win::Form1::InitializeComponent(void) {
    components = gcnew System::ComponentModel::Container();
    Text = L"LR4 v25 — Chart, tri grafa (raznye cveta)";
    ClientSize = Drawing::Size(720, 520);
    StartPosition = FormStartPosition::CenterScreen;

    int y0 = 10;
    lblXn = gcnew Label();
    lblXn->Text = L"xn";
    lblXn->Location = Point(10, y0);
    lblXn->AutoSize = true;
    tbXn = gcnew TextBox();
    tbXn->Text = L"-3.8";
    tbXn->Location = Point(40, y0 - 2);
    tbXn->Width = 70;

    lblXk = gcnew Label();
    lblXk->Text = L"xk";
    lblXk->Location = Point(130, y0);
    lblXk->AutoSize = true;
    tbXk = gcnew TextBox();
    tbXk->Text = L"17.1";
    tbXk->Location = Point(160, y0 - 2);
    tbXk->Width = 70;

    lblXh = gcnew Label();
    lblXh->Text = L"xh";
    lblXh->Location = Point(250, y0);
    lblXh->AutoSize = true;
    tbXh = gcnew TextBox();
    tbXh->Text = L"0.65";
    tbXh->Location = Point(280, y0 - 2);
    tbXh->Width = 60;

    btnPlot = gcnew Button();
    btnPlot->Text = L"Postroit' grafiki";
    btnPlot->Location = Point(360, y0 - 4);
    btnPlot->Width = 160;
    btnPlot->Click += gcnew EventHandler(this, &Form1::btnPlot_Click);

    chart = gcnew Chart();
    chart->Location = Point(10, y0 + 36);
    chart->Size = Drawing::Size(680, 440);
    chart->Legends->Add(gcnew Legend(L"Legend1"));
    ChartArea^ area = gcnew ChartArea(L"Main");
    chart->ChartAreas->Add(area);
    area->AxisX->Title = L"x";
    area->AxisY->Title = L"y";

    Controls->Add(lblXn);
    Controls->Add(tbXn);
    Controls->Add(lblXk);
    Controls->Add(tbXk);
    Controls->Add(lblXh);
    Controls->Add(tbXh);
    Controls->Add(btnPlot);
    Controls->Add(chart);
}

System::Void Lab04Win::Form1::btnPlot_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double xn = ParseDouble(tbXn);
        double xk = ParseDouble(tbXk);
        double xh = ParseDouble(tbXh);
        if (xh <= 0) {
            MessageBox::Show(L"xh > 0", L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        chart->Series->Clear();

        Series^ s1 = gcnew Series(L"f1: x<=0");
        s1->ChartType = SeriesChartType::Line;
        s1->Color = Color::Red;
        s1->BorderWidth = 2;
        chart->Series->Add(s1);

        Series^ s2 = gcnew Series(L"f2: 0<x<=5");
        s2->ChartType = SeriesChartType::Line;
        s2->Color = Color::Blue;
        s2->BorderWidth = 2;
        chart->Series->Add(s2);

        Series^ s3 = gcnew Series(L"f3: x>5");
        s3->ChartType = SeriesChartType::Line;
        s3->Color = Color::Green;
        s3->BorderWidth = 2;
        chart->Series->Add(s3);

        for (double x = xn; x <= xk + 1e-9; x += xh) {
            double y = Lab4_y(x);
            if (x <= 0.0)
                s1->Points->AddXY(x, y);
            else if (x <= 5.0)
                s2->Points->AddXY(x, y);
            else
                s3->Points->AddXY(x, y);
        }
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
