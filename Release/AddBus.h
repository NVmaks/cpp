#pragma once

using namespace MySql::Data::MySqlClient;
namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddBus
	/// </summary>
	public ref class AddBus : public System::Windows::Forms::Form
	{
	public:
		AddBus(void)
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
		~AddBus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;



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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 134);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(250, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddBus::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(160, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(105, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 71);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(105, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(99, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Модель";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Регистрационный номер";
			// 
			// AddBus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 205);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"AddBus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавление автобуса";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if (textBox1->Text != "" && textBox2->Text != "") {
				String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
				MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
				try
				{
					conn->Open();

					String^ cmdText = "INSERT INTO bus(model,number) VALUES(@nmodel, @nnumber)";
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
					cmd->Parameters->AddWithValue("@nmodel", textBox1->Text);
					cmd->Parameters->AddWithValue("@nnumber", textBox2->Text);

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
	};
}
