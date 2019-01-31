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
	/// —водка дл€ DelRoute
	/// </summary>
	public ref class DelRoute : public System::Windows::Forms::Form
	{
	public:
		DelRoute(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DelRoute()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(63, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"”далить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DelRoute::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(63, 48);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(163, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// DelRoute
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 193);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"DelRoute";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"”даление маршрута";
			this->Load += gcnew System::EventHandler(this, &DelRoute::DelRoute_Load);
			this->ResumeLayout(false);

		}
		#pragma endregion
			private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				if (comboBox1->Text != "") {
					String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
					MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
					try
					{
						conn->Open(); // ќткрываем соединение

						String^ cmdText = "DELETE FROM routes WHERE id = @nid";
						MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);
						String^ word = comboBox1->Text->Substring(0, comboBox1->Text->IndexOf('.'));
						cmd->Parameters->AddWithValue("@nid", Convert::ToInt32(word));
						cmd->ExecuteNonQuery();
					}
					finally{
						if (conn != nullptr) {
							conn->Close();
						}
						Hide();
					}
				}
			}
		private: System::Void DelRoute_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ myConnectionString = "Database=bus_station; Data Source=localhost;User Id=root;Password=root";
			MySqlConnection^ conn = gcnew MySqlConnection(myConnectionString);
			try
			{
				conn->Open();

				String^ cmdText = "SELECT id, point_a, point_b FROM routes";
				MySqlCommand^ cmd = gcnew MySqlCommand(cmdText, conn);

				MySqlDataReader^ reader = cmd->ExecuteReader();

				if (reader != nullptr) {
					while (reader->Read())
					{
						comboBox1->Items->Add(reader->GetString(0) + ". " + reader->GetString(1) + " - " + reader->GetString(2));
					}
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
