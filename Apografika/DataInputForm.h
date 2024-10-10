#pragma once
#include "Data_handling.h"

namespace Apografika {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class DataInputForm : public Form
    {
    private:
        System::Windows::Forms::DataGridView^ dataGridView;
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;  //imerominia
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;  //promitheytis
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;  //proion
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;  //posotita
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;  //arxiki timi
        System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;  //teliki timi
        System::Windows::Forms::DataGridViewComboBoxColumn^ dataGridViewComboBoxColumn7;    //eidos proiontos
        System::Windows::Forms::Button^ submitButton;
        System::Windows::Forms::Button^ addRowButton;

    public:
        DataInputForm();
        System::Collections::Generic::List<New_data^>^ DataInputForm::GetEnteredData();

    private:
        void InitializeComponent();
        void submitButton_Click(Object^ sender, EventArgs^ e);
        void addButton_Click(Object^ sender, EventArgs^ e);
    };
}
