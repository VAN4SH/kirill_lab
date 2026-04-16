#pragma once

namespace Lab08Win {

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

        MenuStrip^ menu;
        ToolStripMenuItem^ mFile;
        ToolStripMenuItem^ mExit;

        TabControl^ tabs;
        TabPage^ tpIn;
        TabPage^ tpTab;
        TabPage^ tpGr;

        Label^ lblXn;
        Label^ lblXk;
        Label^ lblXh;
        Label^ lblA;
        TextBox^ tbXn;
        TextBox^ tbXk;
        TextBox^ tbXh;
        TextBox^ tbA;
        Button^ btnBuild;

        DataGridView^ grid;
        Label^ lblStat;

        System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

        void InitializeComponent(void);
        System::Void btnBuild_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void mExit_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab08Win
