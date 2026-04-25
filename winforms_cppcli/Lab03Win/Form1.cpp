#include "Form1.h"
#include "../include/MathVariant25.h"

#include <cmath>

using namespace Lab03Win;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;

static double ParseDouble(TextBox^ tb) {
    String^ s = tb->Text->Trim()->Replace(L",", L".");
    return Double::Parse(s, CultureInfo::InvariantCulture);
}

void Lab03Win::Form1::InitializeComponent(void) {
    components = gcnew System::ComponentModel::Container();
    Text = L"LR3 v25 — tabuljacija (while), DataGridView";
    ClientSize = Drawing::Size(560, 460);
    StartPosition = FormStartPosition::CenterScreen;

    int y0 = 12;
    lblXn = gcnew Label();
    lblXn->Text = L"xn";
    lblXn->Location = Point(12, y0);
    lblXn->AutoSize = true;
    tbXn = gcnew TextBox();
    tbXn->Text = L"-7.4";
    tbXn->Location = Point(80, y0 - 2);
    tbXn->Width = 80;

    lblXk = gcnew Label();
    lblXk->Text = L"xk";
    lblXk->Location = Point(180, y0);
    lblXk->AutoSize = true;
    tbXk = gcnew TextBox();
    tbXk->Text = L"0.6";
    tbXk->Location = Point(220, y0 - 2);
    tbXk->Width = 80;

    lblXh = gcnew Label();
    lblXh->Text = L"xh";
    lblXh->Location = Point(320, y0);
    lblXh->AutoSize = true;
    tbXh = gcnew TextBox();
    tbXh->Text = L"0.16";
    tbXh->Location = Point(360, y0 - 2);
    tbXh->Width = 70;

    lblA = gcnew Label();
    lblA->Text = L"a";
    lblA->Location = Point(450, y0);
    lblA->AutoSize = true;
    tbA = gcnew TextBox();
    tbA->Text = L"7";
    tbA->Location = Point(470, y0 - 2);
    tbA->Width = 60;

    btnGo = gcnew Button();
    btnGo->Text = L"Tabulirovat'";
    btnGo->Location = Point(12, y0 + 36);
    btnGo->Width = 140;
    btnGo->Click += gcnew EventHandler(this, &Form1::btnGo_Click);

    grid = gcnew DataGridView();
    grid->Location = Point(12, y0 + 80);
    grid->Size = Drawing::Size(520, 280);
    grid->ReadOnly = true;
    grid->AllowUserToAddRows = false;
    grid->RowHeadersVisible = false;
    grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
    grid->ColumnCount = 2;
    grid->Columns[0]->HeaderText = L"x";
    grid->Columns[1]->HeaderText = L"y";

    lblMin = gcnew Label();
    lblMin->Location = Point(12, y0 + 370);
    lblMin->Width = 520;
    lblMin->AutoSize = false;
    lblMax = gcnew Label();
    lblMax->Location = Point(12, y0 + 395);
    lblMax->Width = 520;

    Controls->Add(lblXn);
    Controls->Add(tbXn);
    Controls->Add(lblXk);
    Controls->Add(tbXk);
    Controls->Add(lblXh);
    Controls->Add(tbXh);
    Controls->Add(lblA);
    Controls->Add(tbA);
    Controls->Add(btnGo);
    Controls->Add(grid);
    Controls->Add(lblMin);
    Controls->Add(lblMax);
}

System::Void Lab03Win::Form1::btnGo_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double xn = ParseDouble(tbXn);
        double xk = ParseDouble(tbXk);
        double xh = ParseDouble(tbXh);
        double a = ParseDouble(tbA);
        if (xh <= 0) {
            MessageBox::Show(L"Shag xh dolzhen byt' > 0", L"Oshibka", MessageBoxButtons::OK,
                             MessageBoxIcon::Warning);
            return;
        }

        grid->Rows->Clear();
        double x = xn;
        double ymin = Lab3_y(xn, a);
        double ymax = ymin;

        while (x <= xk + 1e-9) {
            double yy = Lab3_y(x, a);
            if (yy < ymin) ymin = yy;
            if (yy > ymax) ymax = yy;
            grid->Rows->Add(String::Format(L"{0:F5}", x), String::Format(L"{0:F5}", yy));
            x += xh;
        }

        lblMin->Text = String::Concat(L"Min y: ", ymin.ToString(L"F5"));
        lblMax->Text = String::Concat(L"Max y: ", ymax.ToString(L"F5"));
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka vvoda", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
