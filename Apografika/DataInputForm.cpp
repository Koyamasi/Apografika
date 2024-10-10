#include "DataInputForm.h"

namespace Apografika {

    DataInputForm::DataInputForm()
    {
        InitializeComponent();
    }

    System::Collections::Generic::List<New_data^>^ DataInputForm::GetEnteredData()
    {
        auto dataList = gcnew System::Collections::Generic::List<New_data^>();

        for each (DataGridViewRow ^ row in dataGridView->Rows)
        {
            if (!row->IsNewRow)
            {
                DateTime purchaseDate = row->Cells[0]->Value != nullptr ? DateTime::Parse(row->Cells[0]->Value->ToString()) : DateTime::Now;
                String^ supplier = row->Cells[1]->Value != nullptr ? row->Cells[1]->Value->ToString() : "";
                String^ productName = row->Cells[2]->Value != nullptr ? row->Cells[2]->Value->ToString() : "";
                int quantity = row->Cells[3]->Value != nullptr ? Convert::ToInt32(row->Cells[3]->Value) : 0;
                double init_price = row->Cells[4]->Value != nullptr ? Convert::ToDouble(row->Cells[4]->Value) : 0.0;
                double final_price = row->Cells[5]->Value != nullptr ? Convert::ToDouble(row->Cells[5]->Value) : 0.0;
                String^ productTypeStr = row->Cells[6]->Value->ToString();
                ProductType productType;

                if (productTypeStr == L"Φαγητό") {
                    productType = ProductType::Type1;
                }
                else if (productTypeStr == L"Ποτό") {
                    productType = ProductType::Type2;
                }
                else if (productTypeStr == L"Καφές") {
                    productType = ProductType::Type3;
                }

                New_data^ newData = gcnew New_data(purchaseDate, supplier, productName, quantity, init_price, final_price, productType);
                dataList->Add(newData);
            }
        }

        return dataList;
    }

    void DataInputForm::InitializeComponent()
    {
        this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
        this->submitButton = (gcnew System::Windows::Forms::Button());
        this->addRowButton = (gcnew System::Windows::Forms::Button());
        this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
        this->dataGridViewComboBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
        this->SuspendLayout();

        // 
        // dataGridView
        // 
        this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(7) {
            this->dataGridViewTextBoxColumn1,
                this->dataGridViewTextBoxColumn2,
                this->dataGridViewTextBoxColumn3,
                this->dataGridViewTextBoxColumn4,
                this->dataGridViewTextBoxColumn5,
                this->dataGridViewTextBoxColumn6,
                this->dataGridViewComboBoxColumn7
        });
        this->dataGridView->Location = System::Drawing::Point(20, 20);
        this->dataGridView->Name = L"dataGridView";
        this->dataGridView->Size = System::Drawing::Size(1400, 300);
        this->dataGridView->TabIndex = 0;

        // 
        // dataGridViewTextBoxColumn1
        // 
        this->dataGridViewTextBoxColumn1->HeaderText = L"Purchase Date";
        this->dataGridViewTextBoxColumn1->Name = L"purchaseDateColumn";
        // 
        // dataGridViewTextBoxColumn2
        // 
        this->dataGridViewTextBoxColumn2->HeaderText = L"Supplier";
        this->dataGridViewTextBoxColumn2->Name = L"SupplierColumn";
        // 
        // dataGridViewTextBoxColumn3
        // 
        this->dataGridViewTextBoxColumn3->HeaderText = L"Product Name";
        this->dataGridViewTextBoxColumn3->Name = L"productNameColumn";
        // 
        // dataGridViewTextBoxColumn4
        // 
        this->dataGridViewTextBoxColumn4->HeaderText = L"Quantity";
        this->dataGridViewTextBoxColumn4->Name = L"quantityColumn";
        // 
        // dataGridViewTextBoxColumn5
        // 
        this->dataGridViewTextBoxColumn5->HeaderText = L"Initial Price";
        this->dataGridViewTextBoxColumn5->Name = L"initPriceColumn";
        // 
        // dataGridViewTextBoxColumn6
        // 
        this->dataGridViewTextBoxColumn6->HeaderText = L"Final Price";
        this->dataGridViewTextBoxColumn6->Name = L"finalPriceColumn";
        // 
        // dataGridViewComboBoxColumn7
        // 
        this->dataGridViewComboBoxColumn7->HeaderText = L"Product Type";
        this->dataGridViewComboBoxColumn7->Name = L"productTypeColumn"; 
        this->dataGridViewComboBoxColumn7->Items->AddRange(gcnew cli::array<System::Object^>(3) {
            L"Φαγητό", L"Ποτό", L"Καφές"
        });

        // 
        // addRowButton
        // 
        this->addRowButton->Location = System::Drawing::Point(100, 340);
        this->addRowButton->Name = L"addRowButton";
        this->addRowButton->Size = System::Drawing::Size(75, 23);
        this->addRowButton->TabIndex = 2;
        this->addRowButton->Text = L"Add entry";
        this->addRowButton->Click += gcnew System::EventHandler(this, &DataInputForm::addButton_Click);

        // 
        // submitButton
        // 
        this->submitButton->Location = System::Drawing::Point(20, 340);
        this->submitButton->Name = L"submitButton";
        this->submitButton->Size = System::Drawing::Size(75, 23);
        this->submitButton->TabIndex = 1;
        this->submitButton->Text = L"Submit";
        this->submitButton->Click += gcnew System::EventHandler(this, &DataInputForm::submitButton_Click);

        // 
        // DataInputForm
        // 
        this->ClientSize = System::Drawing::Size(640, 400); // Adjusted size
        this->Controls->Add(this->dataGridView);
        this->Controls->Add(this->submitButton);
        this->Controls->Add(this->addRowButton);
        this->Name = L"DataInputForm";
        this->Text = L"Input Data";
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
        this->ResumeLayout(false);
    }

    void DataInputForm::submitButton_Click(Object^ sender, EventArgs^ e)
    {
        auto dataHandling = Data_handling::GetInstance();
        String^ message = L"Current Entries:\n\n";

        for each (DataGridViewRow ^ row in dataGridView->Rows)
        {
            if (!row->IsNewRow)
            {
                DateTime purchaseDate = row->Cells[0]->Value != nullptr ? DateTime::Parse(row->Cells[0]->Value->ToString()) : DateTime::Now;
                String^ supplier = row->Cells[1]->Value != nullptr ? row->Cells[1]->Value->ToString() : "";
                String^ productName = row->Cells[2]->Value != nullptr ? row->Cells[2]->Value->ToString() : "";
                int quantity = row->Cells[3]->Value != nullptr ? Convert::ToInt32(row->Cells[3]->Value) : 0;
                double init_price = row->Cells[4]->Value != nullptr ? Convert::ToDouble(row->Cells[4]->Value) : 0.0;
                double final_price = row->Cells[5]->Value != nullptr ? Convert::ToDouble(row->Cells[5]->Value) : 0.0;
                String^ productTypeStr = row->Cells[6]->Value->ToString();
                ProductType productType;

                if (productTypeStr == L"Φαγητό") {
                    productType = ProductType::Type1;
                }
                else if (productTypeStr == L"Ποτό") {
                    productType = ProductType::Type2;
                }
                else if (productTypeStr == L"Καφές") {
                    productType = ProductType::Type3;
                }

                New_data^ newData = gcnew New_data(purchaseDate, supplier, productName, quantity, init_price, final_price, productType);
                dataHandling->AddData(newData);

                // Append current entry to the message
            }
        }

        // Show a message box with the current entries
        MessageBox::Show(message, L"Entries", MessageBoxButtons::OK, MessageBoxIcon::Information);

        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }


    void DataInputForm::addButton_Click(Object^ sender, EventArgs^ e)
    {
        DataGridViewRow^ newRow = gcnew DataGridViewRow();
        newRow->CreateCells(dataGridView); // Ensure cells are created for the row
        newRow->Cells[0]->Value = DateTime::Now; // Set current date
        newRow->Cells[1]->Value = "Nikolis"; // Example value
        newRow->Cells[2]->Value = "mpamies"; // Default price
        newRow->Cells[3]->Value = 0; // Default quantity
        newRow->Cells[4]->Value = 0; // Default quantity
        newRow->Cells[5]->Value = 0; // Default quantity
        newRow->Cells[6]->Value = L"Φαγητό"; // Correct index for product type as string
        dataGridView->Rows->Add(newRow);
    }
}
