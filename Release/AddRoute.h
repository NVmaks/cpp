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
	/// Сводка для AddRoute
	/// </summary>
	public ref class AddRoute : public System::Windows::Forms::Form
	{
	public:
		AddRoute(void)
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
		~AddRoute()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddRoute::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(76, 71);
			this->textBox2->MaxLength = 30;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"Пункт назначения";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(76, 45);
			this->textBox1->MaxLength = 30;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"Пункт отправления";
			// 
			// AddRoute
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(302, 182);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"AddRoute";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавление маршрута";
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
					String^ cmdText = "INSERT INTO routes(point_a,point_b) VALUES(@npoint_a, @npoint_b)";
					MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
					cmd->Parameters->AddWithValue("@npoint_a", textBox1->Text);
					cmd->Parameters->AddWithValue("@npoint_b", textBox2->Text);

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
