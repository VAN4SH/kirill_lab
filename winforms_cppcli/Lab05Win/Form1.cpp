#include "Form1.h"

using namespace Lab05Win;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

void Lab05Win::Form1::InitializeComponent(void) {
    components = gcnew System::ComponentModel::Container();
    Text = L"LR5 v25 — massiv, sluchajnye -50..70";
    ClientSize = Drawing::Size(520, 420);
    StartPosition = FormStartPosition::CenterScreen;

    lblN = gcnew Label();
    lblN->Text = L"Razmer n:";
    lblN->Location = Point(12, 14);
    lblN->AutoSize = true;

    tbN = gcnew TextBox();
    tbN->Text = L"12";
    tbN->Location = Point(100, 11);
    tbN->Width = 60;

    btnFill = gcnew Button();
    btnFill->Text = L"Zapolnit' massiv";
    btnFill->Location = Point(180, 8);
    btnFill->Width = 160;
    btnFill->Click += gcnew EventHandler(this, &Form1::btnFill_Click);

    lbArr = gcnew ListBox();
    lbArr->Location = Point(12, 48);
    lbArr->Size = Drawing::Size(480, 120);

    grp = gcnew GroupBox();
    grp->Text = L"Zadanie (tabl. 5.1, v.25)";
    grp->Location = Point(12, 180);
    grp->Size = Drawing::Size(480, 100);

    rbA = gcnew RadioButton();
    rbA->Text = L"a) summa otritsatel'nyh";
    rbA->Location = Point(16, 24);
    rbA->AutoSize = true;
    rbA->Checked = true;

    rbB = gcnew RadioButton();
    rbB->Text = L"b) summa pri indekse %3==0";
    rbB->Location = Point(16, 48);
    rbB->AutoSize = true;

    rbV = gcnew RadioButton();
    rbV->Text = L"v) |min|*|max|";
    rbV->Location = Point(16, 72);
    rbV->AutoSize = true;

    grp->Controls->Add(rbA);
    grp->Controls->Add(rbB);
    grp->Controls->Add(rbV);

    btnCalc = gcnew Button();
    btnCalc->Text = L"Vychislit'";
    btnCalc->Location = Point(12, 292);
    btnCalc->Width = 140;
    btnCalc->Click += gcnew EventHandler(this, &Form1::btnCalc_Click);

    lblOut = gcnew Label();
    lblOut->Location = Point(12, 330);
    lblOut->Size = Drawing::Size(480, 60);
    lblOut->AutoSize = false;

    Controls->Add(lblN);
    Controls->Add(tbN);
    Controls->Add(btnFill);
    Controls->Add(lbArr);
    Controls->Add(grp);
    Controls->Add(btnCalc);
    Controls->Add(lblOut);
}

System::Void Lab05Win::Form1::btnFill_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        int n = Int32::Parse(tbN->Text->Trim());
        if (n <= 0)
            throw gcnew FormatException(L"n > 0");
        Random^ r = gcnew Random();
        arr = gcnew cli::array<int>(n);
        lbArr->Items->Clear();
        for (int i = 0; i < n; i++) {
            arr[i] = r->Next(-50, 71);
            lbArr->Items->Add(String::Format(L"[{0}] = {1}", i, arr[i]));
        }
        lblOut->Text = L"";
    } catch (Exception^ ex) {
        MessageBox::Show(ex->Message, L"Oshibka", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

System::Void Lab05Win::Form1::btnCalc_Click(System::Object^ sender, System::EventArgs^ e) {
    if (arr == nullptr || arr->Length == 0) {
        MessageBox::Show(L"Snachala zapolnite massiv", L"", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return;
    }
    long long sumNeg = 0;
    for (int i = 0; i < arr->Length; i++)
        if (arr[i] < 0)
            sumNeg += arr[i];

    long long sumIdx = 0;
    for (int i = 0; i < arr->Length; i++)
        if (i % 3 == 0)
            sumIdx += arr[i];

    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < arr->Length; i++) {
        if (arr[i] < mn)
            mn = arr[i];
        if (arr[i] > mx)
            mx = arr[i];
    }
    long long prod = (long long) Math::Abs(mn) * (long long) Math::Abs(mx);

    if (rbA->Checked)
        lblOut->Text = L"a) " + sumNeg.ToString();
    else if (rbB->Checked)
        lblOut->Text = L"b) " + sumIdx.ToString();
    else
        lblOut->Text = L"v) " + prod.ToString();
}
