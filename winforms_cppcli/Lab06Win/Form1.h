#pragma once

namespace Lab06Win {

    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class Form1 : public Form {
    public:
        Form1(void) { InitializeComponent(); }

    protected:
        ~Form1() {
            if (components) {
                delete components;
            }
        }

    private:
        Container^ components;

        Label^ lblR;
        Label^ lblC;
        TextBox^ tbR;
        TextBox^ tbC;
        Button^ btnGen;
        DataGridView^ grid;
        GroupBox^ grp;
        RadioButton^ rbA;
        RadioButton^ rbB;
        RadioButton^ rbV;
        Button^ btnGo;
        Label^ lblRes;

        array<int, 2>^ mat;
        int R;
        int C;

        void InitializeComponent(void);
        System::Void btnGen_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab06Win
