#include "Form1.h"
#include "../include/MathVariant25.h"

#include <cmath>

using namespace Lab08Win;
using namespace System;
using namespace System::Drawing;
using namespace System::Globalization;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;

static double ParseDouble(TextBox^ tb) {
    String^ s = tb->Text->Trim()->Replace(L",", L".");
    return Double::Parse(s, CultureInfo::InvariantCulture);
}

void Lab08Win::Form1::InitializeComponent(void) {
    components = gcnew Container();
    Text = L"LR8 v25 — vkladki (tablitsa + grafik), menju";
    ClientSize = Drawing::Size(720, 520);
    StartPosition = FormStartPosition::CenterScreen;

    menu = gcnew MenuStrip();
    mFile = gcnew ToolStripMenuItem(L"&Fajl");
    mExit = gcnew ToolStripMenuItem(L"&Vyhod");
    mExit->Click += gcnew EventHandler(this, &Form1::mExit_Click);
    mFile->DropDownItems->Add(mExit);
    menu->Items->Add(mFile);
    MainMenuStrip = menu;

    tabs = gcnew TabControl();
    tabs->Location = Point(8, 28);
    tabs->Size = Drawing::Size(696, 472);

    tpIn = gcnew TabPage(L"Vvod (xn,xk,xh,a)");
    tpTab = gcnew TabPage(L"Tablitsa");
    tpGr = gcnew TabPage(L"Grafik");

    lblXn = gcnew Label();
    lblXn->Text = L"xn";
    lblXn->Location = Point(16, 20);
    lblXn->AutoSize = true;
    tbXn = gcnew TextBox();
    tbXn->Text = L"-7.4";
    tbXn->Location = Point(80, 17);
    tbXn->Width = 80;

    lblXk = gcnew Label();
    lblXk->Text = L"xk";
    lblXk->Location = Point(200, 20);
    lblXk->AutoSize = true;
    tbXk = gcnew TextBox();
    tbXk->Text = L"8.5";
    tbXk->Location = Point(240, 17);
    tbXk->Width = 80;

    lblXh = gcnew Label();
    lblXh->Text = L"xh";
    lblXh->Location = Point(360, 20);
    lblXh->AutoSize = true;
    tbXh = gcnew TextBox();
    tbXh->Text = L"0.11";
    tbXh->Location = Point(400, 17);
    tbXh->Width = 70;

    lblA = gcnew Label();
    lblA->Text = L"a";
    lblA->Location = Point(500, 20);
    lblA->AutoSize = true;
    tbA = gcnew TextBox();
    tbA->Text = L"7";
    tbA->Location = Point(520, 17);
    tbA->Width = 60;

    btnBuild = gcnew Button();
    btnBuild->Text = L"Postroit' tablitsu i grafik";
    btnBuild->Location = Point(16, 60);
    btnBuild->Width = 220;
    btnBuild->Click += gcnew EventHandler(this, &Form1::btnBuild_Click);

    tpIn->Controls->Add(lblXn);
    tpIn->Controls->Add(tbXn);
    tpIn->Controls->Add(lblXk);
    tpIn->Controls->Add(tbXk);
    tpIn->Controls->Add(lblXh);
    tpIn->Controls->Add(tbXh);
    tpIn->Controls->Add(lblA);
    tpIn->Controls->Add(tbA);
    tpIn->Controls->Add(btnBuild);

    lblStat = gcnew Label();
    lblStat->Dock = DockStyle::Bottom;
    lblStat->Height = 44;
    lblStat->AutoSize = false;

    grid = gcnew DataGridView();
    grid->Dock = DockStyle::Fill;
    grid->ReadOnly = true;
    grid->AllowUserToAddRows = false;
    grid->RowHeadersVisible = false;
    grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
    grid->ColumnCount = 2;
    grid->Columns[0]->HeaderText = L"x";
    grid->Columns[1]->HeaderText = L"y";

    tpTab->Controls->Add(lblStat);
    tpTab->Controls->Add(grid);

    chart = gcnew Chart();
    chart->Dock = DockStyle::Fill;
    ChartArea^ area = gcnew ChartArea(L"A1");
    chart->ChartAreas->Add(area);
    chart->Legends->Add(gcnew Legend(L"L1"));
    area->AxisX->Title = L"x";
    area->AxisY->Title = L"y";
    Series^ ser = gcnew Series(L"y(x)");
    ser->ChartType = SeriesChartType::Line;
    ser->Color = Color::DarkBlue;
    ser->BorderWidth = 2;
    chart->Series->Add(ser);
    tpGr->Controls->Add(chart);

    tabs->TabPages->Add(tpIn);
    tabs->TabPages->Add(tpTab);
    tabs->TabPages->Add(tpGr);

    Controls->Add(tabs);
    Controls->Add(menu);
}

System::Void Lab08Win::Form1::mExit_Click(System::Object^ sender, System::EventArgs^ e) { Close(); }

System::Void Lab08Win::Form1::btnBuild_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double xn = ParseDouble(tbXn);
        double xk = ParseDouble(tbXk);
        double xh = ParseDouble(tbXh);
        double a = ParseDouble(tbA);
        if (xh <= 0) {
            MessageBox::Show(L"xh > 0", L"", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        grid->Rows->Clear();
        chart->Series[0]->Points->Clear();

        double ymin = Lab8_y(xn, a);
        double ymax = ymin;
        for (double x = xn; x <= xk + 1e-9; x += xh) {
            double yy = Lab8_y(x, a);
            if (yy < ymin)
                ymin = yy;
            if (yy > ymax)
                ymax = yy;
            grid->Rows->Add(String::Format(L"{0:F5}", x), String::Format(L"{0:F5}", yy));
            chart->Series[0]->Points->AddXY(x, yy);
        }
        lblStat->Text = String::Format(L"Min y: {0:F5}\r\nMax y: {1:F5}", ymin, ymax);

        tabs->SelectedIndex = 1;
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
