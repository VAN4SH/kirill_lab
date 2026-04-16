#include "Form1.h"

using namespace Lab09Win;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

void Lab09Win::Form1::insertionSort(array<double>^ b) {
    for (int i = 1; i < b->Length; i++) {
        double key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

void Lab09Win::Form1::refreshBlist(bool sorted) {
    lbB->Items->Clear();
    if (bvec == nullptr)
        return;
    for (int i = 0; i < bvec->Length; i++)
        lbB->Items->Add(String::Format(L"B[{0}] = {1:F4}", i, bvec[i]));
    if (sorted)
        lbB->Items->Insert(0, L"--- posle sortirovki vstavkami ---");
    else
        lbB->Items->Insert(0, L"--- do sortirovki ---");
}

void Lab09Win::Form1::InitializeComponent(void) {
    components = gcnew Container();
    Text = L"LR9 v25 — matritsa, B po strokam, sortirovka vstavkoj";
    ClientSize = Drawing::Size(720, 480);
    StartPosition = FormStartPosition::CenterScreen;

    lblR = gcnew Label();
    lblR->Text = L"Strok r:";
    lblR->Location = Point(10, 12);
    lblR->AutoSize = true;
    tbR = gcnew TextBox();
    tbR->Text = L"5";
    tbR->Location = Point(80, 9);
    tbR->Width = 40;

    lblC = gcnew Label();
    lblC->Text = L"Stolbcov c:";
    lblC->Location = Point(140, 12);
    lblC->AutoSize = true;
    tbC = gcnew TextBox();
    tbC->Text = L"6";
    tbC->Location = Point(230, 9);
    tbC->Width = 40;

    btnGen = gcnew Button();
    btnGen->Text = L"Sozdat' A i B";
    btnGen->Location = Point(290, 6);
    btnGen->Width = 140;
    btnGen->Click += gcnew EventHandler(this, &Form1::btnGen_Click);

    grid = gcnew DataGridView();
    grid->Location = Point(10, 44);
    grid->Size = Drawing::Size(680, 220);
    grid->ReadOnly = true;
    grid->AllowUserToAddRows = false;
    grid->RowHeadersVisible = false;
    grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;

    lbB = gcnew ListBox();
    lbB->Location = Point(10, 276);
    lbB->Size = Drawing::Size(680, 120);

    btnSort = gcnew Button();
    btnSort->Text = L"Sortirovat' B (vstavka)";
    btnSort->Location = Point(10, 408);
    btnSort->Width = 200;
    btnSort->Click += gcnew EventHandler(this, &Form1::btnSort_Click);

    Controls->Add(lblR);
    Controls->Add(tbR);
    Controls->Add(lblC);
    Controls->Add(tbC);
    Controls->Add(btnGen);
    Controls->Add(grid);
    Controls->Add(lbB);
    Controls->Add(btnSort);

    R = 0;
    C = 0;
    mat = nullptr;
    bvec = nullptr;
}

System::Void Lab09Win::Form1::btnGen_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        R = Int32::Parse(tbR->Text->Trim());
        C = Int32::Parse(tbC->Text->Trim());
        if (R < 1 || C < 1)
            throw gcnew Exception(L"> 0");
        Random^ r = gcnew Random();
        mat = gcnew array<double, 2>(R, C);
        grid->Columns->Clear();
        grid->Rows->Clear();
        grid->ColumnCount = C;
        for (int i = 0; i < R; i++) {
            cli::array<Object^>^ row = gcnew cli::array<Object^>(C);
            for (int j = 0; j < C; j++) {
                mat[i, j] = r->NextDouble() * 20.0 - 10.0;
                row[j] = String::Format(L"{0:F2}", mat[i, j]);
            }
            grid->Rows->Add(row);
        }

        bvec = gcnew array<double>(R);
        for (int i = 0; i < R; i++) {
            double rmin = mat[i, 0], rmax = mat[i, 0];
            for (int j = 1; j < C; j++) {
                if (mat[i, j] < rmin)
                    rmin = mat[i, j];
                if (mat[i, j] > rmax)
                    rmax = mat[i, j];
            }
            bvec[i] = rmax + rmin;
        }
        refreshBlist(false);
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

System::Void Lab09Win::Form1::btnSort_Click(System::Object^ sender, System::EventArgs^ e) {
    if (bvec == nullptr) {
        MessageBox::Show(L"Sozdajte A i B", L"", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return;
    }
    insertionSort(bvec);
    refreshBlist(true);
}
