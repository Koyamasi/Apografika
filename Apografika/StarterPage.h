#pragma once

#include "New_Data.h"
#include "DataInputForm.h"

namespace Apografika {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; // Include SqlClient for database access

	/// <summary>
	/// Summary for StarterPage
	/// </summary>
	public ref class StarterPage : public System::Windows::Forms::Form
	{
	public:
		StarterPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StarterPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ απογραφέςToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ ταμείοToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ καφέςToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ σύνολαToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ μηνιToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ μηνιαίωςToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ετήσιαToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ εβδομάδαToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ μήναςToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ έτοςToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ εβδομάδαToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ μήναςToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ έτοςToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ εβδομάδαToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ μήναςToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ έτοςToolStripMenuItem2;
	private: System::Windows::Forms::Button^ add_button;
	private: void ConnectToDatabase()
	{
		String^ connectionString = "Data Source=DESKTOP-C7TEI74\\LOCALDB#AC5058D7;Initial Catalog=My Restaurant;Integrated Security=True";
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		try {
			connection->Open();
			MessageBox::Show("Connection to database successful!");
			// Perform database operations here
		}
		catch (Exception^ ex) {
			MessageBox::Show("Connection failed: " + ex->Message);
		}
		finally {
			connection->Close();
		}
	}


	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StarterPage::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->απογραφέςToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->μηνιToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->μηνιαίωςToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ετήσιαToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ταμείοToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->εβδομάδαToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->μήναςToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->έτοςToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->καφέςToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->εβδομάδαToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->μήναςToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->έτοςToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->σύνολαToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->εβδομάδαToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->μήναςToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->έτοςToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->απογραφέςToolStripMenuItem,
					this->ταμείοToolStripMenuItem, this->καφέςToolStripMenuItem, this->σύνολαToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(9, 51);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(263, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// απογραφέςToolStripMenuItem
			// 
			this->απογραφέςToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->μηνιToolStripMenuItem,
					this->μηνιαίωςToolStripMenuItem, this->ετήσιαToolStripMenuItem
			});
			this->απογραφέςToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->απογραφέςToolStripMenuItem->Name = L"απογραφέςToolStripMenuItem";
			this->απογραφέςToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->απογραφέςToolStripMenuItem->Text = L"Φαγητό";
			// 
			// μηνιToolStripMenuItem
			// 
			this->μηνιToolStripMenuItem->Name = L"μηνιToolStripMenuItem";
			this->μηνιToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->μηνιToolStripMenuItem->Text = L"Εβδομαδιαίως";
			this->μηνιToolStripMenuItem->Click += gcnew System::EventHandler(this, &StarterPage::μηνιToolStripMenuItem_Click);
			// 
			// μηνιαίωςToolStripMenuItem
			// 
			this->μηνιαίωςToolStripMenuItem->Name = L"μηνιαίωςToolStripMenuItem";
			this->μηνιαίωςToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->μηνιαίωςToolStripMenuItem->Text = L"Μηνιαίως";
			// 
			// ετήσιαToolStripMenuItem
			// 
			this->ετήσιαToolStripMenuItem->Name = L"ετήσιαToolStripMenuItem";
			this->ετήσιαToolStripMenuItem->Size = System::Drawing::Size(170, 24);
			this->ετήσιαToolStripMenuItem->Text = L"Ετήσια";
			// 
			// ταμείοToolStripMenuItem
			// 
			this->ταμείοToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->εβδομάδαToolStripMenuItem,
					this->μήναςToolStripMenuItem, this->έτοςToolStripMenuItem
			});
			this->ταμείοToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ταμείοToolStripMenuItem->Name = L"ταμείοToolStripMenuItem";
			this->ταμείοToolStripMenuItem->Size = System::Drawing::Size(54, 23);
			this->ταμείοToolStripMenuItem->Text = L"Ποτό";
			// 
			// εβδομάδαToolStripMenuItem
			// 
			this->εβδομάδαToolStripMenuItem->Name = L"εβδομάδαToolStripMenuItem";
			this->εβδομάδαToolStripMenuItem->Size = System::Drawing::Size(144, 24);
			this->εβδομάδαToolStripMenuItem->Text = L"Εβδομάδα";
			// 
			// μήναςToolStripMenuItem
			// 
			this->μήναςToolStripMenuItem->Name = L"μήναςToolStripMenuItem";
			this->μήναςToolStripMenuItem->Size = System::Drawing::Size(144, 24);
			this->μήναςToolStripMenuItem->Text = L"Μήνας";
			// 
			// έτοςToolStripMenuItem
			// 
			this->έτοςToolStripMenuItem->Name = L"έτοςToolStripMenuItem";
			this->έτοςToolStripMenuItem->Size = System::Drawing::Size(144, 24);
			this->έτοςToolStripMenuItem->Text = L"Έτος";
			// 
			// καφέςToolStripMenuItem
			// 
			this->καφέςToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->εβδομάδαToolStripMenuItem1,
					this->μήναςToolStripMenuItem1, this->έτοςToolStripMenuItem1
			});
			this->καφέςToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->καφέςToolStripMenuItem->Name = L"καφέςToolStripMenuItem";
			this->καφέςToolStripMenuItem->Size = System::Drawing::Size(63, 23);
			this->καφέςToolStripMenuItem->Text = L"Καφές";
			// 
			// εβδομάδαToolStripMenuItem1
			// 
			this->εβδομάδαToolStripMenuItem1->Name = L"εβδομάδαToolStripMenuItem1";
			this->εβδομάδαToolStripMenuItem1->Size = System::Drawing::Size(144, 24);
			this->εβδομάδαToolStripMenuItem1->Text = L"Εβδομάδα";
			// 
			// μήναςToolStripMenuItem1
			// 
			this->μήναςToolStripMenuItem1->Name = L"μήναςToolStripMenuItem1";
			this->μήναςToolStripMenuItem1->Size = System::Drawing::Size(144, 24);
			this->μήναςToolStripMenuItem1->Text = L"Μήνας";
			// 
			// έτοςToolStripMenuItem1
			// 
			this->έτοςToolStripMenuItem1->Name = L"έτοςToolStripMenuItem1";
			this->έτοςToolStripMenuItem1->Size = System::Drawing::Size(144, 24);
			this->έτοςToolStripMenuItem1->Text = L"Έτος";
			// 
			// σύνολαToolStripMenuItem
			// 
			this->σύνολαToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->εβδομάδαToolStripMenuItem2,
					this->μήναςToolStripMenuItem2, this->έτοςToolStripMenuItem2
			});
			this->σύνολαToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->σύνολαToolStripMenuItem->Name = L"σύνολαToolStripMenuItem";
			this->σύνολαToolStripMenuItem->Size = System::Drawing::Size(69, 23);
			this->σύνολαToolStripMenuItem->Text = L"Σύνολα";
			// 
			// εβδομάδαToolStripMenuItem2
			// 
			this->εβδομάδαToolStripMenuItem2->Name = L"εβδομάδαToolStripMenuItem2";
			this->εβδομάδαToolStripMenuItem2->Size = System::Drawing::Size(144, 24);
			this->εβδομάδαToolStripMenuItem2->Text = L"Εβδομάδα";
			// 
			// μήναςToolStripMenuItem2
			// 
			this->μήναςToolStripMenuItem2->Name = L"μήναςToolStripMenuItem2";
			this->μήναςToolStripMenuItem2->Size = System::Drawing::Size(144, 24);
			this->μήναςToolStripMenuItem2->Text = L"Μήνας";
			// 
			// έτοςToolStripMenuItem2
			// 
			this->έτοςToolStripMenuItem2->Name = L"έτοςToolStripMenuItem2";
			this->έτοςToolStripMenuItem2->Size = System::Drawing::Size(144, 24);
			this->έτοςToolStripMenuItem2->Text = L"Έτος";
			// 
			// add_button
			// 
			this->add_button->BackColor = System::Drawing::Color::Transparent;
			this->add_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add_button.BackgroundImage")));
			this->add_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->add_button->FlatAppearance->BorderSize = 0;
			this->add_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_button->Location = System::Drawing::Point(9, 13);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(36, 35);
			this->add_button->TabIndex = 1;
			this->add_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->add_button->UseVisualStyleBackColor = false;
			this->add_button->Click += gcnew System::EventHandler(this, &StarterPage::add_button_Click);
			// 
			// StarterPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1115, 768);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"StarterPage";
			this->Text = L"StarterPage";
			this->Load += gcnew System::EventHandler(this, &StarterPage::StarterPage_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void StarterPage_Load(System::Object^ sender, System::EventArgs^ e) {

		ConnectToDatabase();
		// Load the image from the file
		System::Drawing::Image^ originalImage = System::Drawing::Image::FromFile("./images/add_image.png");

		// Resize the image to fit the button's size
		System::Drawing::Image^ resizedImage = (gcnew System::Drawing::Bitmap(originalImage, add_button->Size));

		// Set the resized image to the button
		add_button->Image = resizedImage;

		// Set the button's properties to remove text and background issues
		add_button->Text = "";  // No text
		add_button->BackColor = System::Drawing::Color::Transparent; // Set background to transparent
		add_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		add_button->FlatAppearance->BorderSize = 0; // Remove border
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void μηνιToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Open the Data Input Form
		DataInputForm^ inputForm = gcnew DataInputForm();
		inputForm->ShowDialog();

		// Retrieve the data from the form if the user clicked OK
		if (inputForm->DialogResult == System::Windows::Forms::DialogResult::OK)
		{
			// Get all the entered data (list of New_data instances)
			auto enteredData = inputForm->GetEnteredData(); // Ensure this method retrieves New_data objects

			// Process each entry
			for each (New_data ^ newData in enteredData) // Now correctly gets New_data instances
			{
				String^ productName = newData->productName; // No change needed here
				DateTime purchaseDate = newData->purchaseDate;
				String^ supplier = newData->supplier;
				int quantity = newData->quantity;
				double init_price = newData->init_price;
				double final_price = newData->final_price;
				ProductType productType = newData->productType; // Initialize product type
				// Use the properties from newData directly

				// Add the newData to a list or process it further
				// productDataList->Add(newData); // Assuming you have a list to store it
			}
		}
	}

	};
}

	

