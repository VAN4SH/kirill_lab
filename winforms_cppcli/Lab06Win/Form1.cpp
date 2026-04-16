#include "Form1.h"

using namespace Lab06Win;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

void Lab06Win::Form1::InitializeComponent(void) {
    components = gcnew Container();
    Text = L"LR6 v25 — matritsa, DataGridView";
    ClientSize = Drawing::Size(640, 480);
    StartPosition = FormStartPosition::CenterScreen;

    lblR = gcnew Label();
    lblR->Text = L"Strok:";
    lblR->Location = Point(10, 12);
    lblR->AutoSize = true;
    tbR = gcnew TextBox();
    tbR->Text = L"6";
    tbR->Location = Point(70, 9);
    tbR->Width = 50;

    lblC = gcnew Label();
    lblC->Text = L"Stolbcov:";
    lblC->Location = Point(140, 12);
    lblC->AutoSize = true;
    tbC = gcnew TextBox();
    tbC->Text = L"6";
    tbC->Location = Point(220, 9);
    tbC->Width = 50;

    btnGen = gcnew Button();
    btnGen->Text = L"Sozdat' tablitsu";
    btnGen->Location = Point(290, 6);
    btnGen->Width = 140;
    btnGen->Click += gcnew EventHandler(this, &Form1::btnGen_Click);

    grid = gcnew DataGridView();
    grid->Location = Point(10, 44);
    grid->Size = Drawing::Size(600, 240);
    grid->ReadOnly = true;
    grid->AllowUserToAddRows = false;
    grid->RowHeadersVisible = false;
    grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

    grp = gcnew GroupBox();
    grp->Text = L"Zadanie (tabl. 6.5, v.25)";
    grp->Location = Point(10, 292);
    grp->Size = Drawing::Size(600, 88);

    rbA = gcnew RadioButton();
    rbA->Text = L"a) max |element| i indeksy";
    rbA->Location = Point(12, 22);
    rbA->AutoSize = true;
    rbA->Checked = true;

    rbB = gcnew RadioButton();
    rbB->Text = L"b) max-min na glavnoj diagonali";
    rbB->Location = Point(12, 46);
    rbB->AutoSize = true;

    rbV = gcnew RadioButton();
    rbV->Text = L"v) 6x6: nech. v stolb.2 * pol. v str.3";
    rbV->Location = Point(300, 22);
    rbV->AutoSize = true;

    grp->Controls->Add(rbA);
    grp->Controls->Add(rbB);
    grp->Controls->Add(rbV);

    btnGo = gcnew Button();
    btnGo->Text = L"Vychislit'";
    btnGo->Location = Point(10, 388);
    btnGo->Width = 120;
    btnGo->Click += gcnew EventHandler(this, &Form1::btnGo_Click);

    lblRes = gcnew Label();
    lblRes->Location = Point(140, 392);
    lblRes->Size = Drawing::Size(470, 40);
    lblRes->AutoSize = false;

    Controls->Add(lblR);
    Controls->Add(tbR);
    Controls->Add(lblC);
    Controls->Add(tbC);
    Controls->Add(btnGen);
    Controls->Add(grid);
    Controls->Add(grp);
    Controls->Add(btnGo);
    Controls->Add(lblRes);

    R = 0;
    C = 0;
    mat = nullptr;
}

System::Void Lab06Win::Form1::btnGen_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        R = Int32::Parse(tbR->Text->Trim());
        C = Int32::Parse(tbC->Text->Trim());
        if (R < 1 || C < 1)
            throw gcnew Exception(L"n > 0");
        Random^ r = gcnew Random();
        mat = gcnew array<int, 2>(R, C);
        grid->Columns->Clear();
        grid->Rows->Clear();
        grid->ColumnCount = C;
        for (int i = 0; i < R; i++) {
            cli::array<Object^>^ row = gcnew cli::array<Object^>(C);
            for (int j = 0; j < C; j++) {
                mat[i, j] = r->Next(-20, 21);
                row[j] = String::Format(L"{0}", mat[i, j]);
            }
            grid->Rows->Add(row);
        }
        lblRes->Text = L"";
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

System::Void Lab06Win::Form1::btnGo_Click(System::Object^ sender, System::EventArgs^ e) {
    if (mat == nullptr) {
        MessageBox::Show(L"Sozdajte tablitsu", L"", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return;
    }
    if (rbA->Checked) {
        int bi = 0, bj = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (Math::Abs(mat[i, j]) > Math::Abs(mat[bi, bj])) {
                    bi = i;
                    bj = j;
                }
        lblRes->Text = String::Format(L"a) max|a|={0} stroka {1} stolbec {2}", mat[bi, bj], bi, bj);
        return;
    }
    if (rbB->Checked) {
        if (R != C) {
            lblRes->Text = L"b) nuzhna kvadratnaja matritsa";
            return;
        }
        int dmin = mat[0, 0], dmax = mat[0, 0];
        for (int i = 0; i < R; i++) {
            if (mat[i, i] < dmin)
                dmin = mat[i, i];
            if (mat[i, i] > dmax)
                dmax = mat[i, i];
        }
        lblRes->Text = String::Format(L"b) max-min na gl. diagonali = {0}", dmax - dmin);
        return;
    }
    if (rbV->Checked) {
        if (R < 6 || C < 6) {
            lblRes->Text = L"v) nuzhno >= 6 strok i >= 6 stolbcov";
            return;
        }
        int cntOdd = 0;
        for (int i = 0; i < 6; i++)
            if (Math::Abs(mat[i, 1]) % 2 == 1)
                cntOdd++;
        int cntPos = 0;
        for (int j = 0; j < 6; j++)
            if (mat[2, j] > 0)
                cntPos++;
        lblRes->Text = String::Format(L"v) {0} * {1} = {2}", cntOdd, cntPos, cntOdd * cntPos);
    }
}
