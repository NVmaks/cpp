#pragma once
#include "AddRoute.h"
#include "DelRoute.h"
#include "Trip.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для Route
	/// </summary>
	public ref class Route : public System::Windows::Forms::Form
	{
	public:
		Route(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Route()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button3;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ListBox^  listBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(158, 307);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 28);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Изменить рейсы";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Route::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(246, 273);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(68, 28);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Route::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(158, 273);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 28);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Route::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(109, 34);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(249, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Route::comboBox1_SelectedIndexChanged);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(109, 74);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(248, 173);
			this->listBox1->TabIndex = 12;
			// 
			// Route
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 379);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Route";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Маршруты";
			this->Load += gcnew System::EventHandler(this, &Route::Route_Load);
			this->ResumeLayout(false);

		}
	#pragma endregion
		private: System::Void Route_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id, point_a, point_b FROM routes";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					comboBox1->Items->Add(reader->GetString(0)+ ". " + reader->GetString(1) + " - " + reader->GetString(2));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
				Hide();
			}
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			AddRoute^ newAddRoute = gcnew AddRoute();
			newAddRoute->ShowDialog();
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			DelRoute^ newDelRoute = gcnew DelRoute();
			newDelRoute->ShowDialog();
		}
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			Trip^ newTrip = gcnew Trip();
			newTrip->ShowDialog();
		}
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			listBox1->Items->Clear();
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id,time_a,time_b FROM trips WHERE id_routes = @nid_routes";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
				String^ word = comboBox1->Text->Substring(0, comboBox1->Text->IndexOf('.'));
				cmd->Parameters->AddWithValue("@nid_routes", Convert::ToInt32(word));
				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					listBox1->Items->Add(reader->GetString(0) + ") " + reader->GetString(1) + " - " + reader->GetString(2));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
			}
		}
	};
}
