#pragma once

namespace Lab05Win {

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

        Label^ lblN;
        TextBox^ tbN;
        Button^ btnFill;
        ListBox^ lbArr;
        GroupBox^ grp;
        RadioButton^ rbA;
        RadioButton^ rbB;
        RadioButton^ rbV;
        Button^ btnCalc;
        Label^ lblOut;

        cli::array<int>^ arr;

        void InitializeComponent(void);
        System::Void btnFill_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCalc_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab05Win
