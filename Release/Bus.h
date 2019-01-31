#pragma once
#include "AddBus.h"
#include "DelBus.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для Bus
	/// </summary>
	public ref class Bus : public System::Windows::Forms::Form
	{
	public:
		Bus(Form^ parent)
		{
			InitializeComponent();
			Parent = parent;
			
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;






	public:
	public: Form^ Parent;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Bus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	protected:
	private: System::Windows::Forms::Button^  button1;



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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(261, 317);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 41);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Bus::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(350, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 41);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Bus::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(162, 317);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 41);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Назад";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Bus::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(81, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(459, 263);
			this->dataGridView1->TabIndex = 9;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"id";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Модель";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Номер";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Статус";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Bus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(611, 403);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Bus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Автобусы";
			this->Load += gcnew System::EventHandler(this, &Bus::Bus_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			AddBus^ newAddBus = gcnew AddBus();
			newAddBus->ShowDialog();
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			DelBus^ newDelBus = gcnew DelBus();
			newDelBus->ShowDialog();
		}
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			Hide();
			Parent->Show();
		}
		private: System::Void Bus_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id,model,number,status FROM bus";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
				Hide();
			}
		}
	};
}
