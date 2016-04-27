#pragma once

namespace chest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		public:
			MainForm(void)
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
			~MainForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  Exit;
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
				this->Exit = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// Exit
				// 
				this->Exit->Location = System::Drawing::Point(361, 152);
				this->Exit->Name = L"Exit";
				this->Exit->Size = System::Drawing::Size(232, 97);
				this->Exit->TabIndex = 0;
				this->Exit->Text = L"Выход";
				this->Exit->UseVisualStyleBackColor = true;
				this->Exit->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
				// 
				// MainForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(605, 261);
				this->Controls->Add(this->Exit);
				this->Name = L"MainForm";
				this->Text = L"Закрывашка";
				this->ResumeLayout(false);
		}
	#pragma endregion

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//Close();
		}
	};
}
