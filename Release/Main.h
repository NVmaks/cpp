#pragma once
#include "View.h"
#include "Order.h"
#include "Password.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data::SqlClient;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Просмотр маршрутов";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(86, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Заказать билет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(86, 130);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 40);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Диспетчер";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(86, 176);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(109, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Выход";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Главное меню";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		View^ newView = gcnew View(this);
		newView->Show();
	}

	private: System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Order^ newOrder = gcnew Order(this);
		newOrder->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Password^ newPassword = gcnew Password(this);
		newPassword->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
