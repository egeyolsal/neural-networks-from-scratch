#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Network.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Set_Net;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ ClassCountBox;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ ClassNoBox;

	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// User Defined Variables
		int  class_count = 0, numSample = 0, inputDim = 2;
		float *Samples, *targets, *Weights, *bias;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveDataToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ testingToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ToolStripMenuItem^ regressionToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ EpochBox;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ LearningRateBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ minErrorBox;



		   /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Set_Net = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClassCountBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ClassNoBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->regressionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->EpochBox = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->LearningRateBox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->minErrorBox = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(13, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(802, 578);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Set_Net);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->ClassCountBox);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(869, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Network Architecture";
			// 
			// Set_Net
			// 
			this->Set_Net->Location = System::Drawing::Point(10, 61);
			this->Set_Net->Name = L"Set_Net";
			this->Set_Net->Size = System::Drawing::Size(131, 33);
			this->Set_Net->TabIndex = 2;
			this->Set_Net->Text = L"Network Setting";
			this->Set_Net->UseVisualStyleBackColor = true;
			this->Set_Net->Click += gcnew System::EventHandler(this, &Form1::Set_Net_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Class Count";
			// 
			// ClassCountBox
			// 
			this->ClassCountBox->FormattingEnabled = true;
			this->ClassCountBox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->ClassCountBox->Location = System::Drawing::Point(10, 20);
			this->ClassCountBox->Name = L"ClassCountBox";
			this->ClassCountBox->Size = System::Drawing::Size(82, 21);
			this->ClassCountBox->TabIndex = 0;
			this->ClassCountBox->Text = L"2";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->ClassNoBox);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox2->Location = System::Drawing::Point(879, 191);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(190, 61);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Data Collection";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(98, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Sample Label";
			// 
			// ClassNoBox
			// 
			this->ClassNoBox->FormattingEnabled = true;
			this->ClassNoBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9"
			});
			this->ClassNoBox->Location = System::Drawing::Point(7, 20);
			this->ClassNoBox->Name = L"ClassNoBox";
			this->ClassNoBox->Size = System::Drawing::Size(75, 21);
			this->ClassNoBox->TabIndex = 0;
			this->ClassNoBox->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(876, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->processToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1463, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->readDataToolStripMenuItem,
					this->saveDataToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readDataToolStripMenuItem
			// 
			this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			this->readDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->readDataToolStripMenuItem->Text = L"Read_Data";
			this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->saveDataToolStripMenuItem->Text = L"Save_Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->trainingToolStripMenuItem,
					this->testingToolStripMenuItem, this->regressionToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingToolStripMenuItem_Click);
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->testingToolStripMenuItem->Text = L"Testing";
			this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			// 
			// regressionToolStripMenuItem
			// 
			this->regressionToolStripMenuItem->Name = L"regressionToolStripMenuItem";
			this->regressionToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->regressionToolStripMenuItem->Text = L"Regression";
			this->regressionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::regressionToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(869, 299);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(247, 283);
			this->textBox1->TabIndex = 5;
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(1151, 282);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"chart1";
			// 
			// EpochBox
			// 
			this->EpochBox->FormattingEnabled = true;
			this->EpochBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"500", L"1000", L"5000", L"10000", L"100000" });
			this->EpochBox->Location = System::Drawing::Point(10, 61);
			this->EpochBox->Name = L"EpochBox";
			this->EpochBox->Size = System::Drawing::Size(82, 21);
			this->EpochBox->TabIndex = 7;
			this->EpochBox->Text = L"500";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->LearningRateBox);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->EpochBox);
			this->groupBox3->Controls->Add(this->minErrorBox);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox3->Location = System::Drawing::Point(1200, 50);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 155);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Settings";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(108, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Learning Rate";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(108, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Epoch";
			// 
			// LearningRateBox
			// 
			this->LearningRateBox->FormattingEnabled = true;
			this->LearningRateBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0,1", L"0,01", L"0,001", L"0,0001" });
			this->LearningRateBox->Location = System::Drawing::Point(10, 108);
			this->LearningRateBox->Name = L"LearningRateBox";
			this->LearningRateBox->Size = System::Drawing::Size(82, 21);
			this->LearningRateBox->TabIndex = 8;
			this->LearningRateBox->Text = L"0,01";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(108, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Min Error";
			// 
			// minErrorBox
			// 
			this->minErrorBox->FormattingEnabled = true;
			this->minErrorBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0,01", L"0,001", L"0,0001", L"0,00001" });
			this->minErrorBox->Location = System::Drawing::Point(10, 20);
			this->minErrorBox->Name = L"minErrorBox";
			this->minErrorBox->Size = System::Drawing::Size(82, 21);
			this->minErrorBox->TabIndex = 0;
			this->minErrorBox->Text = L"0,001";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1463, 633);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void draw_sample(int temp_x, int temp_y, int label) {
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			switch (label) {
			case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
			}//switch
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
			pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		}//draw_sample

		void DrawRegressionLine(float* Weights, float* bias) {

			pictureBox1->Refresh();

			int width = pictureBox1->Width;
			int height = pictureBox1->Height;
			int centerX = width / 2;
			int centerY = height / 2;

			// Draw the regression line
			Pen^ linePen = gcnew Pen(Color::Red, 3.0f);

				float* mean = new float[2];
				float* std = new float[2];
				Z_Score_Parameters(Samples, numSample, 2, mean, std);
				// Get x coordinates at left and right edges (in data coordinates)
				float x1_data = float(-centerX);
				float x2_data = float(centerX);

				x1_data = (x1_data - mean[0]) / std[0];
				x2_data = (x2_data - mean[0]) / std[0];

				// Calculate corresponding y values: y = w * x + b
				float y1_data = Weights[0] * x1_data + bias[0];
				float y2_data = Weights[0] * x2_data + bias[0];

				y1_data = (y1_data * std[1]) + mean[1];
				y2_data = (y2_data * std[1]) + mean[1];

				// Convert back to screen coordinates
				int x1_screen = 0;
				int y1_screen = centerY - int(y1_data);
				int x2_screen = width;
				int y2_screen = centerY - int(y2_data);


				System::Diagnostics::Debug::WriteLine("x1:" + x1_screen);
				System::Diagnostics::Debug::WriteLine("x2:" +x2_screen);
				System::Diagnostics::Debug::WriteLine("y1:" + y1_screen);
				System::Diagnostics::Debug::WriteLine("y2:" + y2_screen);

				pictureBox1->CreateGraphics()->DrawLine(linePen, x1_screen, y1_screen, x2_screen, y2_screen);

				textBox1->Text += "\r\nRegression Line Equation:\r\n";
				textBox1->Text += "y = " + System::Convert::ToString(Weights[0]) + " * x + " +
					System::Convert::ToString(bias[0]) + "\r\n";
			
				
				for (int i = 0; i < numSample; i++) {
					draw_sample(Samples[i * inputDim] + pictureBox1->Width / 2, pictureBox1->Height / 2 - Samples[i * inputDim + 1], targets[i]);
				}

			delete linePen;
		}

        #pragma endregion
	    private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if( class_count == 0)
				MessageBox::Show("The Network Architecture should be firtly set up");
			else {
				float* x= new float[inputDim];
				int temp_x = (System::Convert::ToInt32(e->X));
				int temp_y = (System::Convert::ToInt32(e->Y));
				x[0] = float(temp_x - (pictureBox1->Width / 2));
				x[1] = float(pictureBox1->Height / 2 - temp_y);
				int label;
				int numLabel = Convert::ToInt32(ClassNoBox->Text);
				if (numLabel > class_count)
					MessageBox::Show("The class label cannot be greater than the maximum number of classes.");
				else {
					label = numLabel - 1; // Döngüler 0 dan baþladýðýndan, label deðeri 0 dan baþlamasý için bir eksiði alýnmýþtýr
					if (numSample == 0) { // Dinamik alýnan ilk örnek için sadece
						numSample = 1;  
						Samples = new float[numSample * inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							Samples[i] = x[i];
						targets[0] = float(label);
					}
					else {
						numSample++;
						Samples = Add_Data(Samples, numSample, x, inputDim);
						targets = Add_Labels(targets, numSample, label);
					}//else
					draw_sample(temp_x, temp_y, label);
					label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
					delete [] x;
				}//else of if (Etiket ...
			}//else
	    }//pictureMouseClick
        private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			//Ana eksen doðrularini cizdir
			Pen^ pen = gcnew Pen(Color::Black, 3.0f);
			int center_width, center_height;
			center_width = (int)(pictureBox1->Width / 2);
			center_height = (int)(pictureBox1->Height / 2);
			e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);
        }
        private: System::Void Set_Net_Click(System::Object^ sender, System::EventArgs^ e) {
			// Network is constructed
			class_count = Convert::ToInt32(ClassCountBox->Text);
			Weights = new float[class_count * inputDim];
			bias = new float[class_count];
			//initialize weights for single layer
			if (class_count > 2) {
				Weights = init_array_random(class_count * inputDim);
				bias = init_array_random(class_count);
			}
			else {
				int numOutNeuron = 1;
				Weights = init_array_random(inputDim);
				bias = init_array_random(numOutNeuron);
			}
			Set_Net->Text = " Network is Ready : ";
        }//Set_Net
        private: System::Void readDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			char** c = new char *[2];
			// Veri Kümesini okunacak 
			MessageBox::Show("Veri Kümesini Yükleyin");
			c[0] = "../Data/Samples.txt";
			c[1] = "../Data/weights.txt";
			std::ifstream file;
			int num, w, h, Dim, label;
			file.open(c[0]); 
			if (file.is_open()) {
				//MessageBox::Show("Dosya acildi");
				file >> Dim>> w >> h >>num;
				textBox1->Text += "Dimension: "+ Convert::ToString(Dim) + "- Width: "+ Convert::ToString(w)+" - Height: "+ Convert::ToString(h)+ " - Number of Class: "+ Convert::ToString(num) +"\r\n";
				// Set network values
				class_count = num;
				inputDim = Dim;
				Weights = new float[class_count * inputDim];
				bias = new float[class_count];
				numSample = 0;
				float* x = new float[inputDim];
				while (!file.eof())
				{
					if (numSample == 0) { //ilk örnek için sadece
						numSample = 1;
						Samples = new float[inputDim]; targets = new float[numSample];
						for (int i = 0; i < inputDim; i++)
							   file>>Samples[i];
						file >> targets[0];
					}
					else {
						
						for (int i = 0; i < inputDim; i++)
							file >> x[i];
						file >> label;
						if (!file.eof()) {
							numSample++;
							Samples = Add_Data(Samples, numSample, x, inputDim);
							targets = Add_Labels(targets, numSample, label);
						}
					}//else
				} //while
				delete[]x;
				file.close();
				for (int i = 0; i < numSample; i++) {
					draw_sample(Samples[i*inputDim]+w, h-Samples[i*inputDim+1], targets[i]);
					for (int j = 0; j < inputDim; j++)
						textBox1->Text += Convert::ToString(Samples[i * inputDim + j]) + " ";
					textBox1->Text += Convert::ToString(targets[i]) + "\r\n";
				}
				//draw_sample(temp_x, temp_y, label);
				label3->Text = "Samples Count: " + System::Convert::ToString(numSample);
				MessageBox::Show("The file was read successfully.");
			}//file.is_open
			else MessageBox::Show("Dosya acilamadi");
			//Get weights
			int Layer;
			file.open(c[1]);
			if (file.is_open()) {
				file >> Layer >> Dim >> num;
				class_count = num;
				inputDim = Dim;
				Weights = new float[class_count * inputDim];
				bias = new float[class_count];
				textBox1->Text += "Layer: " + Convert::ToString(Layer) + " Dimension: " + Convert::ToString(Dim) + " numClass:" + Convert::ToString(num) + "\r\n";
				while (!file.eof())
				{
					for (int i = 0; i < class_count; i++)
						for (int j = 0; j < inputDim; j++)
							file >> Weights[i * inputDim + j];
					for (int i = 0; i < class_count; i++)
						file >> bias[i];
				}
				file.close();
			}//file.is_open
			delete[]c;
        }//Read_Data
        private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (numSample != 0) {
				char** c = new char* [2];
				// Dataset will be written
				c[0] = "../Data/Samples.txt";
				c[1] = "../Data/weights.txt";
				std::ofstream ofs(c[0]);
				if (!ofs.bad()) {
					// Width,  Height, number of Class, data+label
					ofs <<inputDim<<" "<< pictureBox1->Width / 2 << " " << pictureBox1->Height / 2 <<" "<<class_count<< std::endl;
					for (int i = 0; i < numSample; i++) {
						for (int d = 0; d < inputDim; d++)
							ofs << Samples[i*inputDim+d] << " ";
						ofs << targets[i] << std::endl;
					}
					ofs.close();
				}
				else MessageBox::Show("Samples icin dosya acilamadi");
				std::ofstream file(c[1]);
				if (!file.bad()) {
					// #Layer Dimension numClass weights biases
					file << 1 <<" "<<inputDim << " " << class_count << std::endl;
					for (int k = 0; k < class_count*inputDim; k++) 
							file << Weights[k] << " ";
					file << std::endl;
					for (int k = 0; k < class_count; k++)
						file << bias[k] << " ";
					file.close();
				}
				else MessageBox::Show("Weight icin dosya acilamadi");
				delete[]c;	
			}
			else MessageBox::Show("At least one sample should be given");
        }//Save_Data
	    private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			float* x = new float[2];
			float* mean = new float[2];
			float* std = new float[2];
			//mean ve std tekrar hesaplanýyor, Aslýnda eðitimde bunlar saklanmalý oradan alýnmalý
			Z_Score_Parameters(Samples, numSample, inputDim, mean, std);
			//MessageBox::Show("mean: "+System::Convert::ToString(mean[0])+ " "+ System::Convert::ToString(mean[1]));
			int num, temp_x, temp_y;
			Bitmap^ surface = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = surface;
			Color c;
			for (int row = 0; row < pictureBox1->Height; row += 2) {
				for (int column = 0; column < pictureBox1->Width; column += 2) {
					x[0] = (float)(column - (pictureBox1->Width / 2));
					x[1] = (float)((pictureBox1->Height / 2) - row);
					x[0] = (x[0] - mean[0]) / std[0];
					x[1] = (x[1] - mean[1]) / std[1];
					num = Test_Forward(x, Weights, bias, class_count, inputDim);
					//MessageBox::Show("merhaba: class :" + System::Convert::ToString(numClass));
					switch (num) {
					case 0: c = Color::FromArgb(0, 0, 0); break;
					case 1: c = Color::FromArgb(255, 0, 0); break;
					case 2: c = Color::FromArgb(0, 255, 0); break;
					case 3: c = Color::FromArgb(0, 0, 255); break;
					default: c = Color::FromArgb(0, 255, 255);
					}//switch
					surface->SetPixel(column, row, c);
				}//column
				//MessageBox::Show("merhaba2: class :" + System::Convert::ToString(numClass));
			}
			//Samples Draw
			Pen^ pen;// = gcnew Pen(Color::Black, 3.0f);
			MessageBox::Show("Examples will be drawn");
			for (int i = 0; i < numSample; i++) {
				switch (int(targets[i])) {
				case 0: pen = gcnew Pen(Color::Black, 3.0f); break;
				case 1: pen = gcnew Pen(Color::Red, 3.0f); break;
				case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
				case 3: pen = gcnew Pen(Color::Green, 3.0f); break;
				case 4: pen = gcnew Pen(Color::Yellow, 3.0f); break;
				case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
				default: pen = gcnew Pen(Color::YellowGreen, 3.0f);
				}//switch
				temp_x = int(Samples[i * inputDim]) + pictureBox1->Width / 2;
				temp_y = pictureBox1->Height / 2 - int(Samples[i * inputDim + 1]);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
				pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
			}
			delete[] x;
			delete[] mean;
			delete[] std;
	    }//Testing
	private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		float learning_rate, Min_Err;
		int Max_epoch, epoch;

		learning_rate = Convert::ToSingle(LearningRateBox->Text);
		Min_Err = Convert::ToSingle(minErrorBox->Text);
		Max_epoch = Convert::ToInt32(EpochBox->Text);

		System::Diagnostics::Debug::WriteLine(learning_rate + " " + Min_Err + " " + Max_epoch);


		float* normSamples = normalize_data(Samples, numSample, inputDim); // Z_Score
		float* err = train_fcn(normSamples, numSample, targets, inputDim, Weights, bias, learning_rate, Min_Err, Max_epoch, epoch, class_count);

		// Results


		label3->Text = "Epoch : " + System::Convert::ToString(epoch) +
			" Error : " + System::Convert::ToString(err[epoch-1]);

		label3->Refresh();
		chart1->Refresh();


		for (int i = 0; i < epoch; i++)
			chart1->Series["Series1"]->Points->AddXY(i, err[i]);


		delete[] err;
		delete[] normSamples;
}
private: System::Void regressionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	float* SamplesX = new float[numSample];
	float* SamplesY = new float[numSample];
	if (numSample < 2) {
		MessageBox::Show("Please click at least 2 points on the picture box for regression!");
		return;
	}

	// Training parameters
	float learning_rate;  
	float Min_Err;
	int Max_epoch;
	int epoch;

	learning_rate = Convert::ToSingle(LearningRateBox->Text);
	Min_Err = Convert::ToSingle(minErrorBox->Text);
	Max_epoch = Convert::ToInt32(EpochBox->Text);

	System::Diagnostics::Debug::WriteLine(learning_rate + " " + Min_Err + " " + Max_epoch);

	textBox1->Clear();
	textBox1->Text += "Number of points: " + System::Convert::ToString(numSample) + "\r\n";

	float* mean = new float[2];
	float* std = new float[2];
	Z_Score_Parameters(Samples, numSample, inputDim, mean, std);
	
	for (int i = 0; i < numSample; i++) {
		SamplesX[i] = (Samples[i * inputDim + 0]-mean[0])/std[0];
		SamplesY[i] = (Samples[i * inputDim + 1] - mean[1]) /std[1];
	}

	// Train the regression model
	float* err = train_regression(SamplesX, numSample, SamplesY,
		1, Weights, bias,
		learning_rate, Min_Err, Max_epoch, epoch, 1);


	// Display results
	textBox1->Text += "Epoch: " + System::Convert::ToString(epoch) + "\r\n";
	textBox1->Text += "Learned Weight (slope): " + System::Convert::ToString(Weights[0]) + "\r\n";
	textBox1->Text += "Bias: " + System::Convert::ToString(bias[0]) + "\r\n";

	label3->Text = " Error: " + System::Convert::ToString(err[epoch - 1]);

	chart1->Refresh();

	for (int i = 0; i < epoch; i++)
		chart1->Series["Series1"]->Points->AddXY(i, err[i]);


	// Draw the regression line on pictureBox
	DrawRegressionLine(Weights, bias);

	delete[] err;

	MessageBox::Show("Regression line fitted and drawn!");

}
};
}
