#pragma once
#include "Dispatcher.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Сводка для Password
	/// </summary>
	public ref class Password : public System::Windows::Forms::Form
	{
	public:
		Password(Form^ parent)
		{
			InitializeComponent();
			Parent = parent;
			//
			//TODO: добавьте код конструктора
			//
		}
	public: Form^ Parent;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Password()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(77, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Войти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Password::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(114, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Введите";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(77, 89);
			this->textBox2->MaxLength = 20;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"admin";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(77, 63);
			this->textBox1->MaxLength = 20;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(126, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"admin";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(77, 153);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Главное  меню";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Password::button2_Click);
			// 
			// Password
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 232);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Password";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизация";
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
				String^ cmdText = "SELECT password FROM dispatchers WHERE login = @nlogin";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
				cmd->Parameters->AddWithValue("@nlogin", textBox1->Text);
				MySqlDataReader^ reader = cmd->ExecuteReader();
				while (reader->Read()) {
					if (textBox2->Text == reader->GetString(0))
					{
						Hide();
						Dispatcher^ newDispatcher = gcnew Dispatcher(Parent);
						newDispatcher->Show();
					}
					else {
						MessageBox::Show("Неверный пароль");
					}
				}
				
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
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Parent->Show();
	}
};
}
