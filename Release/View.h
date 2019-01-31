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
	/// Сводка для View
	/// </summary>
	public ref class View : public System::Windows::Forms::Form
	{
	public:
		View(Form^ parent)
		{
			InitializeComponent();
			Parent = parent;
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;

	public:
	public: Form^ Parent;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~View()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(295, 381);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &View::button1_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column7, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(764, 328);
			this->dataGridView1->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Пункт отправления";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Пункт назначения";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"id рейса";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Время отправления";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Время прибытия";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"id автобуса";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Регистрационный номер";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// View
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 430);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"View";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Просмотр маршрутов";
			this->Load += gcnew System::EventHandler(this, &View::View_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
	#pragma endregion
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			Hide();
			Parent->Show();
		}
		private: System::Void View_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT routes.point_a, routes.point_b, trips.id, trips.time_a, trips.time_b, trips.id_bus,bus.number FROM trips LEFT JOIN routes ON trips.id_routes = routes.id LEFT JOIN bus ON trips.id_bus = bus.id ORDER BY routes.point_a, routes.point_b,trips.time_a";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				MySqlDataReader^ reader = cmd->ExecuteReader();
				while (reader->Read())
				{ 
					//if (reader->GetString(5) != Null) {		//ОШИБКА. Надо вывести id_bus. Не выводится, так как GetString не может быть NULL.
						dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4), reader->GetString(5));
					//}
					//else
					//dataGridView1->Rows->Add(reader->GetString(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4), "Автобус не назначен", "Автобус не назначен");
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
