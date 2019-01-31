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
	/// Сводка для DelBus
	/// </summary>
	public ref class DelBus : public System::Windows::Forms::Form
	{
	public:
		DelBus(void)
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
		~DelBus()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	protected:


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Удалить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DelBus::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(85, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(109, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(82, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Введите  id автобуса";
			// 
			// DelBus
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 207);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"DelBus";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Удаление автобуса";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text != "") {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open(); // Открываем соединение

				String^ cmdText = "DELETE FROM bus WHERE @nid = id";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
				cmd->Parameters->AddWithValue("@nid", textBox1->Text);
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
