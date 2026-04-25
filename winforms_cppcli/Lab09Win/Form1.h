#pragma once

namespace Lab09Win {

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

        Label^ lblR;
        Label^ lblC;
        TextBox^ tbR;
        TextBox^ tbC;
        Button^ btnGen;
        DataGridView^ grid;
        ListBox^ lbB;
        Button^ btnSort;

        array<double, 2>^ mat;
        array<double>^ bvec;
        int R;
        int C;

        static void insertionSort(array<double>^ b);
        void refreshBlist(bool sorted);

        void InitializeComponent(void);
        System::Void btnGen_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSort_Click(System::Object^ sender, System::EventArgs^ e);
    };

} // namespace Lab09Win
