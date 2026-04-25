#pragma once

namespace Lab03Win {

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
        System::ComponentModel::Container^ components;

        Label^ lblXn;
        Label^ lblXk;
        Label^ lblXh;
        Label^ lblA;
        TextBox^ tbXn;
        TextBox^ tbXk;
        TextBox^ tbXh;
        TextBox^ tbA;
        Button^ btnGo;
        DataGridView^ grid;
        Label^ lblMin;
        Label^ lblMax;

        void InitializeComponent(void);
        System::Void btnGo_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab03Win
