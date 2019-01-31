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
	/// Сводка для Trip
	/// </summary>
	public ref class Trip : public System::Windows::Forms::Form
	{
	public:
		Trip(void)
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
		~Trip()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	protected:
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(45, 212);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Trip::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(390, 212);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Trip::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(199, 46);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(183, 21);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Trip::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(45, 142);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(183, 21);
			this->comboBox2->TabIndex = 9;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Trip::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(262, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Маршрут";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(387, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Время отправления";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(387, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Время прибытия";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(390, 176);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(183, 20);
			this->textBox1->TabIndex = 14;
			this->textBox1->Text = L"ЧЧ : ММ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(390, 115);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(183, 20);
			this->textBox2->TabIndex = 15;
			this->textBox2->Text = L"ЧЧ : ММ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(117, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Рейс";
			// 
			// Trip
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 304);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Trip";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Рейс";
			this->Load += gcnew System::EventHandler(this, &Trip::Trip_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			comboBox2->Items->Clear();
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id,time_a,time_b FROM trips WHERE id_routes = @nid";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
				String^ word = comboBox1->Text;
				word = word->Substring(0, comboBox1->Text->IndexOf('.'));
				
				cmd->Parameters->AddWithValue("@nid", Convert::ToInt32(word));
				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read())
				{
					comboBox2->Items->Add(reader->GetString(0) + ". " + reader->GetString(1) + " - " + reader->GetString(2));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
			}
		}

		private: System::Void Trip_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();
				String^ cmdText = "SELECT id,point_a, point_b FROM routes";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
				MySqlDataReader^ reader = cmd->ExecuteReader();
				while (reader->Read())
				{
					comboBox1->Items->Add(reader->GetString(0) + ". " + reader->GetString(1) + " - " + reader->GetString(2));
				}
			}
			finally{
				if (conn != nullptr) {
					conn->Close();
				}
				Hide();
			}
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox1->Text != "" && comboBox2->Text != "" && comboBox2->Text->IndexOf(':') > 0) {
				String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
				MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
				try
				{
					conn->Open();

					String^ cmdText = "DELETE FROM trips WHERE  id = @nid AND id_routes = @nid_routes";
					String^ word = comboBox1->Text;
					word = word->Substring(0, comboBox1->Text->IndexOf("."));
					String^ word2 = comboBox2->Text;
					word2 = word2->Substring(0, comboBox2->Text->IndexOf("."));
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
					cmd->Parameters->AddWithValue("@nid_routes", Convert::ToInt32(word));
					cmd->Parameters->AddWithValue("@nid", Convert::ToInt32(word2));
					cmd->ExecuteNonQuery();
				}
				finally{
					if (conn != nullptr) {
						conn->Close();
					}
					Hide();
				}
			}
			else
				MessageBox::Show("Данные введены некорректно.");
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if (textBox2->Text != "" && comboBox1->Text != "" && textBox1->Text != "") {
				String^ num1 = textBox2->Text->Substring(0, textBox2->Text->IndexOf(':'));
				String^ num2 = textBox2->Text->Substring(textBox2->Text->IndexOf(':')+1);
				String^ num3 = textBox1->Text->Substring(0, textBox1->Text->IndexOf(':'));
				String^ num4 = textBox1->Text->Substring(textBox1->Text->IndexOf(':') + 1);
				MessageBox::Show(num1);
				MessageBox::Show(num2);
				MessageBox::Show(num3);
				MessageBox::Show(num4);
				Int32 n1,n2,n3,n4;
				if (Int32::TryParse(num1,n1) && Int32::TryParse(num2, n2) && Int32::TryParse(num3, n3) && Int32::TryParse(num4, n4)) {
					String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
					MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
					try
					{
						conn->Open();
						String^ cmdText = "INSERT INTO trips(id_routes, time_a, time_b) VALUES(@nid_routes, @ntime_a, @ntime_b)";
						MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
						String^ word = comboBox1->Text;
						word = word->Substring(0, comboBox1->Text->IndexOf("."));
						cmd->Parameters->AddWithValue("@nid_routes", Convert::ToInt32(word));
						cmd->Parameters->AddWithValue("@ntime_a", textBox2->Text);
						cmd->Parameters->AddWithValue("@ntime_b", textBox1->Text);

						cmd->ExecuteNonQuery();
					}
					finally{
						if (conn != nullptr) {
							conn->Close();
						}
						Hide();
					}
				}
				else
					MessageBox::Show("Данные введены не корректно");
			}
			else {
				MessageBox::Show("Данные введены не корректно");
			}
		}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}