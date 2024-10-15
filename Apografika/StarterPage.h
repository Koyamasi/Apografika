#pragma once
#include "DataInputForm.h"
#include "Data_handling.h"

namespace Apografika {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class StarterPage : public Form
    {
    private:
        Button^ addButton;
        Button^ type1Button;
        Button^ type2Button;
        Button^ type3Button;
        DataGridView^ dataGridView;
        Label^ meanPriceLabel; // Label to display mean prices

    public:
        StarterPage() {
            InitializeComponent();
            UpdateMeanPrices(); // Calculate and display mean prices on startup
        }

    private:
        void InitializeComponent() {
            this->Text = "Product Data";
            this->Size = Drawing::Size(800, 600);

            // Initialize buttons
            addButton = gcnew Button();
            addButton->Text = "Add invoice";
            addButton->Location = Point(10, 10);
            addButton->Click += gcnew EventHandler(this, &StarterPage::addButton_Click);

            type1Button = gcnew Button();
            type1Button->Text = "Food";
            type1Button->Location = Point(100, 10);
            type1Button->Click += gcnew EventHandler(this, &StarterPage::type1Button_Click);

            type2Button = gcnew Button();
            type2Button->Text = "Drink";
            type2Button->Location = Point(190, 10);
            type2Button->Click += gcnew EventHandler(this, &StarterPage::type2Button_Click);

            type3Button = gcnew Button();
            type3Button->Text = "Buffet";
            type3Button->Location = Point(280, 10);
            type3Button->Click += gcnew EventHandler(this, &StarterPage::type3Button_Click);

            // Initialize DataGridView
            dataGridView = gcnew DataGridView();
            dataGridView->Location = Point(10, 50);
            dataGridView->Size = Drawing::Size(760, 400);
            dataGridView->AutoGenerateColumns = false;

            // Add columns to DataGridView
            dataGridView->Columns->Add("purchaseDate", "Purchase Date");
            dataGridView->Columns->Add("supplier", "Supplier");
            dataGridView->Columns->Add("productName", "Product Name");
            dataGridView->Columns->Add("quantity", "Quantity");
            dataGridView->Columns->Add("init_price", "Initial Price");
            dataGridView->Columns->Add("final_price", "Final Price");
            dataGridView->Columns->Add("productType", "Product Type");

            // Initialize mean price label
            meanPriceLabel = gcnew Label();
            meanPriceLabel->Location = Point(10, 470);
            meanPriceLabel->Size = Drawing::Size(760, 100);
            meanPriceLabel->Text = "Mean Prices (Last Year): ";

            // Add controls to the form
            this->Controls->Add(addButton);
            this->Controls->Add(type1Button);
            this->Controls->Add(type2Button);
            this->Controls->Add(type3Button);
            this->Controls->Add(dataGridView);
            this->Controls->Add(meanPriceLabel);
        }

        // Add button click event handler
        void addButton_Click(Object^ sender, EventArgs^ e) {
            DataInputForm^ form = gcnew DataInputForm();
            form->ShowDialog(); // Open as a pop-up
            UpdateMeanPrices(); // Update mean prices after adding data
        }

        // Button click event handlers for filtering the data by product type
        void type1Button_Click(Object^ sender, EventArgs^ e) {
            FilterData(ProductType::Type1);
        }

        void type2Button_Click(Object^ sender, EventArgs^ e) {
            FilterData(ProductType::Type2);
        }

        void type3Button_Click(Object^ sender, EventArgs^ e) {
            FilterData(ProductType::Type3);
        }

        // Function to filter data based on product type
        void FilterData(ProductType type) {
            dataGridView->Rows->Clear(); // Clear current data

            auto allData = Data_handling::GetInstance()->GetAllData();

            for each (New_data ^ data in allData) {
                if (data->productType == type) {
                    dataGridView->Rows->Add(
                        data->purchaseDate.ToString(),
                        data->supplier,
                        data->productName,
                        data->quantity.ToString(),
                        data->init_price.ToString("F2"),
                        data->final_price.ToString("F2"),
                        data->productType.ToString()
                    );
                }
            }

            UpdateMeanPrices(); // Update mean prices after filtering
        }

        // Function to update mean prices for each month of the last year
        void UpdateMeanPrices() {
            array<double>^ monthlyPrices = gcnew array<double>(12);
            array<int>^ monthlyCounts = gcnew array<int>(12);
            auto allData = Data_handling::GetInstance()->GetAllData();
            DateTime now = DateTime::Now;

            // Calculate total prices and counts for each month
            for each (New_data ^ data in allData) {
                if (data->purchaseDate.Year == now.Year - 1 || data->purchaseDate.Year == now.Year) {
                    int monthIndex = data->purchaseDate.Month - 1;
                    monthlyPrices[monthIndex] += data->final_price; // Use final_price or init_price as needed
                    monthlyCounts[monthIndex]++;
                }
            }

            // Prepare the mean price display
            String^ meanPricesText = "Mean Prices (Last Year): ";
            for (int i = 0; i < 12; i++) {
                if (monthlyCounts[i] > 0) {
                    double meanPrice = monthlyPrices[i] / monthlyCounts[i];
                    meanPricesText += String::Format("Month {0}: {1:F2}, ", i + 1, meanPrice);
                }
                else {
                    meanPricesText += String::Format("Month {0}: N/A, ", i + 1);
                }
            }

            // Update the label with the mean prices
            meanPriceLabel->Text = meanPricesText;
        }
    };
}
