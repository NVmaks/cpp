#pragma once

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для Purpose
	/// </summary>
	public ref class Purpose : public System::Windows::Forms::Form
	{
	public:
		Purpose(void)
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
		~Purpose()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Назначить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Purpose::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(46, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Рейс";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Автобус";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(139, 47);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Purpose::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(139, 82);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->Sorted = true;
			this->comboBox2->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(63, 151);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(179, 38);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Очистить все рейсы от назначенных автобусов";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Purpose::button2_Click);
			// 
			// Purpose
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 201);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Purpose";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Назначение автобусов";
			this->Load += gcnew System::EventHandler(this, &Purpose::Purpose_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
			private: System::Void Purpose_Load(System::Object^  sender, System::EventArgs^  e) {
				String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
				MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
				try
				{
					conn->Open();

					String^ cmdText = "SELECT id FROM trips";
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

					MySqlDataReader^ reader = cmd->ExecuteReader();

					while (reader->Read())
					{
						comboBox1->Items->Add(reader->GetString(0));
					}
				}
				finally{
					if (conn != nullptr) {
						conn->Close();
					}
				}
			}

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox1->Text != "" && comboBox2->Text != "") {
				String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
				MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
				try
				{
					conn->Open();

					String^ cmdText = "UPDATE trips SET id_bus = @nid_bus WHERE id = @nid";
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
					cmd->Parameters->AddWithValue("@nid_bus", comboBox2->Text);
					cmd->Parameters->AddWithValue("@nid", Convert::ToInt32(comboBox1->Text));

					cmd->ExecuteNonQuery();
				}
				finally{
					if (conn != nullptr) {
						conn->Close();
					}
					Hide();
				}
			}
			else {
				MessageBox::Show("Данные введены не корректно");
			}
		}
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id FROM bus ORDER BY id";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					comboBox2->Items->Add(reader->GetString(0));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
			}
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();
				String^ cmdText = "UPDATE trips SET id_bus = -1 ";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				cmd->ExecuteNonQuery();
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
			}
		}
	};
}
