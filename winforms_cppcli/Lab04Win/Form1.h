#pragma once

namespace Lab04Win {

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

        Label^ lblXn;
        Label^ lblXk;
        Label^ lblXh;
        TextBox^ tbXn;
        TextBox^ tbXk;
        TextBox^ tbXh;
        Button^ btnPlot;
        System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

        void InitializeComponent(void);
        System::Void btnPlot_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab04Win
