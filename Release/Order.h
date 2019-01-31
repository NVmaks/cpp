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
	/// Сводка для Order
	/// </summary>
	public ref class Order : public System::Windows::Forms::Form
	{
	public:
		Order(Form^ parent)
		{
			InitializeComponent();
			Parent = parent;
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^  button2;
	public:
	public: Form^ Parent;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Order()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox2;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(66, 144);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(148, 21);
			this->comboBox2->TabIndex = 12;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(66, 117);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(148, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Order::comboBox1_SelectedIndexChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(66, 91);
			this->textBox3->MaxLength = 11;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(148, 20);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"Номер телефона";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(66, 65);
			this->textBox2->MaxLength = 20;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"Серия и номер паспорта";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(66, 39);
			this->textBox1->MaxLength = 100;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"ФИО";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Заказать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Order::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(89, 204);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Главное меню";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Order::button2_Click);
			// 
			// Order
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Order";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Заказ";
			this->Load += gcnew System::EventHandler(this, &Order::Order_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			Hide();
			Parent->Show();
		}
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			comboBox2->Items->Clear();
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id,time_a,time_b FROM trips WHERE id_routes = @nid";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				String^ word = comboBox1->Text->Substring(0, comboBox1->Text->IndexOf('.'));
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
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if (textBox1->Text != "" && textBox2->Text != "" && textBox3->Text != "" && comboBox1->Text != "" && comboBox2->Text != "") {
				String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
				MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
				try
				{
					conn->Open();

					String^ cmdText = "INSERT INTO tickets(fio, passport, phone, id_trips) VALUES(@nfio, @npassport, @nphone, @nid_trips)";
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
					cmd->Parameters->AddWithValue("@nfio", textBox1->Text);
					cmd->Parameters->AddWithValue("@npassport", textBox2->Text);
					cmd->Parameters->AddWithValue("@nphone", textBox3->Text);
					String^ word = comboBox2->Text;
					word = word->Substring(0, comboBox2->Text->IndexOf('.'));
					cmd->Parameters->AddWithValue("@nid_trips", Convert::ToInt32(word));

					cmd->ExecuteNonQuery();
					Hide();
					Parent->Show();
				}
				finally{
					if (conn != nullptr) {
						conn->Close();
					}
				}
			}
			else {
				MessageBox::Show("Данные введены не корректно");
			}
		}
	private: System::Void Order_Load(System::Object^  sender, System::EventArgs^  e) {
		String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
		MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
		try
		{
			conn->Open();

			String^ cmdText = "SELECT id,point_a,point_b FROM routes";
			MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read())
			{
				comboBox1->Items->Add(reader->GetString(0) + ". "+ reader->GetString(1) + " - "+ reader->GetString(2));
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
