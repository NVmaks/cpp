#pragma once
#include "Purpose.h"
#include "Route.h"
#include "Bus.h"
#include "View.h"

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Dispatcher
	/// </summary>
	public ref class Dispatcher : public System::Windows::Forms::Form
	{
	public:
		Dispatcher(Form^ parent)
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
		~Dispatcher()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button4;
	protected:
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(44, 192);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(197, 53);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Главное меню";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Dispatcher::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(44, 133);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(197, 53);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Список автобусов";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Dispatcher::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(197, 53);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Маршруты и время отправления";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Dispatcher::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(44, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(197, 53);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Назначение автобусов на рейс";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Dispatcher::button1_Click);
			// 
			// Dispatcher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Dispatcher";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Диспетчер";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		View^ newView = gcnew View(this);
		newView->Show();
		Bus^ newBus = gcnew Bus(this);
		newBus->Show();
		Purpose^ newPurpose = gcnew Purpose();
		newPurpose->Show();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Route^ newRoute = gcnew Route();
		newRoute->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Bus^ newBus = gcnew Bus(this);
		newBus->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		Hide();
		Parent->Show();
	}
};
}
