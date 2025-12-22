#pragma once
#include "Process.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdint>
#include "Network.h"
#include <vector>
#include <numeric> 
#include <algorithm> 
#include <random>
#include <fstream>
#include <stack>

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

		int* layer_sizes;
		int num_layers_total;
		float* GlobalWeights;
		float* GlobalBiases;
		float* SavedEncoderWeights = nullptr;
		float* SavedEncoderBiases = nullptr;

		// Encoder mimarisini hatýrlamak için
		int EncoderNumLayers = 0;
		int* EncoderLayerSizes = nullptr;

	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::ComboBox^ EpochBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ minErrorBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ LearningRateBox;
	private: System::Windows::Forms::ToolStripMenuItem^ trainAutoEncoderToolStripMenuItem;		 
	private: System::Windows::Forms::ToolStripMenuItem^ readEncoderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveEncoderToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ HiddenLayerBox;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::ToolStripMenuItem^ trainingWithEncoderToolStripMenuItem;

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


		   /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->readEncoderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveEncoderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainAutoEncoderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingWithEncoderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->HiddenLayerBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->LearningRateBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->EpochBox = (gcnew System::Windows::Forms::ComboBox());
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
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->readDataToolStripMenuItem,
					this->saveDataToolStripMenuItem, this->readEncoderToolStripMenuItem, this->saveEncoderToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readDataToolStripMenuItem
			// 
			this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			this->readDataToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->readDataToolStripMenuItem->Text = L"Read_Data";
			this->readDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readDataToolStripMenuItem_Click);
			// 
			// saveDataToolStripMenuItem
			// 
			this->saveDataToolStripMenuItem->Name = L"saveDataToolStripMenuItem";
			this->saveDataToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->saveDataToolStripMenuItem->Text = L"Save_Data";
			this->saveDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveDataToolStripMenuItem_Click);
			// 
			// readEncoderToolStripMenuItem
			// 
			this->readEncoderToolStripMenuItem->Name = L"readEncoderToolStripMenuItem";
			this->readEncoderToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->readEncoderToolStripMenuItem->Text = L"Read_Encoder";
			this->readEncoderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readEncoderToolStripMenuItem_Click);
			// 
			// saveEncoderToolStripMenuItem
			// 
			this->saveEncoderToolStripMenuItem->Name = L"saveEncoderToolStripMenuItem";
			this->saveEncoderToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->saveEncoderToolStripMenuItem->Text = L"Save_Encoder";
			this->saveEncoderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveEncoderToolStripMenuItem_Click);
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->trainingToolStripMenuItem,
					this->testingToolStripMenuItem, this->trainAutoEncoderToolStripMenuItem, this->trainingWithEncoderToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			this->trainingToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->trainingToolStripMenuItem->Text = L"Training";
			this->trainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingToolStripMenuItem_Click);
			// 
			// testingToolStripMenuItem
			// 
			this->testingToolStripMenuItem->Name = L"testingToolStripMenuItem";
			this->testingToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->testingToolStripMenuItem->Text = L"Testing";
			this->testingToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::testingToolStripMenuItem_Click);
			// 
			// trainAutoEncoderToolStripMenuItem
			// 
			this->trainAutoEncoderToolStripMenuItem->Name = L"trainAutoEncoderToolStripMenuItem";
			this->trainAutoEncoderToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->trainAutoEncoderToolStripMenuItem->Text = L"Train AutoEncoder";
			this->trainAutoEncoderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainAutoEncoderToolStripMenuItem_Click);
			// 
			// trainingWithEncoderToolStripMenuItem
			// 
			this->trainingWithEncoderToolStripMenuItem->Name = L"trainingWithEncoderToolStripMenuItem";
			this->trainingWithEncoderToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->trainingWithEncoderToolStripMenuItem->Text = L"Training with Encoder";
			this->trainingWithEncoderToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::trainingWithEncoderToolStripMenuItem_Click);
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
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(1151, 282);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"chart1";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->HiddenLayerBox);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->LearningRateBox);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->EpochBox);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->minErrorBox);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox3->Location = System::Drawing::Point(1187, 50);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 202);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Settings";
			// 
			// HiddenLayerBox
			// 
			this->HiddenLayerBox->Location = System::Drawing::Point(10, 151);
			this->HiddenLayerBox->Name = L"HiddenLayerBox";
			this->HiddenLayerBox->Size = System::Drawing::Size(82, 20);
			this->HiddenLayerBox->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(108, 151);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Hidden Layers";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(108, 110);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Learning Rate";
			// 
			// LearningRateBox
			// 
			this->LearningRateBox->FormattingEnabled = true;
			this->LearningRateBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0,1", L"0,01", L"0,001", L"0,0001" });
			this->LearningRateBox->Location = System::Drawing::Point(10, 107);
			this->LearningRateBox->Name = L"LearningRateBox";
			this->LearningRateBox->Size = System::Drawing::Size(82, 21);
			this->LearningRateBox->TabIndex = 10;
			this->LearningRateBox->Text = L"0,1";
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
			// EpochBox
			// 
			this->EpochBox->FormattingEnabled = true;
			this->EpochBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"500", L"1000", L"5000", L"10000", L"100000" });
			this->EpochBox->Location = System::Drawing::Point(10, 61);
			this->EpochBox->Name = L"EpochBox";
			this->EpochBox->Size = System::Drawing::Size(82, 21);
			this->EpochBox->TabIndex = 8;
			this->EpochBox->Text = L"500";
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
			this->minErrorBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0,1", L"0,01", L"0,001", L"0,0001" });
			this->minErrorBox->Location = System::Drawing::Point(10, 20);
			this->minErrorBox->Name = L"minErrorBox";
			this->minErrorBox->Size = System::Drawing::Size(82, 21);
			this->minErrorBox->TabIndex = 0;
			this->minErrorBox->Text = L"0,01";
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

		uint32_t swap_endian(uint32_t val) {
			return ((val >> 24) & 0x000000FF) |
				((val >> 8) & 0x0000FF00) |
				((val << 8) & 0x00FF0000) |
				((val << 24) & 0xFF000000);
		}

		bool LoadMNIST_Subset(const char* img_path, const char* lbl_path)
		{
			FILE* f_images = fopen(img_path, "rb");
			FILE* f_labels = fopen(lbl_path, "rb");

			if (!f_images || !f_labels) {
				if (f_images) fclose(f_images);
				if (f_labels) fclose(f_labels);
				return false;
			}

			uint32_t magic, num_imgs, rows, cols;

			// Read image file header
			fread(&magic, 4, 1, f_images);
			fread(&num_imgs, 4, 1, f_images);
			fread(&rows, 4, 1, f_images);
			fread(&cols, 4, 1, f_images);

			// Fix endianness for ALL values
			num_imgs = swap_endian(num_imgs);
			rows = swap_endian(rows);
			cols = swap_endian(cols);

			// Read label file header
			fread(&magic, 4, 1, f_labels);
			fread(&magic, 4, 1, f_labels); // Skip label count

			// Update inputDim
			this->inputDim = rows * cols; // 784

			int SAMPLES_PER_DIGIT = 100;
			this->numSample = SAMPLES_PER_DIGIT * 10;

			// Clean up old data
			if (this->Samples != nullptr) {
				delete[] this->Samples;
				this->Samples = nullptr;
			}
			if (this->targets != nullptr) {
				delete[] this->targets;
				this->targets = nullptr;
			}

			// Allocate new arrays
			this->Samples = new float[this->numSample * this->inputDim];
			this->targets = new float[this->numSample];

			int counts[10] = { 0 };
			int collected = 0;
			unsigned char temp_lbl;
			unsigned char* temp_pixels = new unsigned char[this->inputDim];

			// Read until we collect enough samples
			while (collected < this->numSample && !feof(f_images) && !feof(f_labels)) {

				// Read label
				if (fread(&temp_lbl, 1, 1, f_labels) != 1) break;

				// Read image pixels
				if (fread(temp_pixels, 1, this->inputDim, f_images) != this->inputDim) break;

				int label = (int)temp_lbl;

				// Store if we need more of this digit
				if (label >= 0 && label <= 9 && counts[label] < SAMPLES_PER_DIGIT) {
					this->targets[collected] = (float)label;

					// Normalize pixels: 0-255 -> 0.0-1.0
					for (int i = 0; i < this->inputDim; i++) {
						this->Samples[collected * this->inputDim + i] = (float)temp_pixels[i] / 255.0f;
					}

					counts[label]++;
					collected++;
				}
			}

			delete[] temp_pixels;
			fclose(f_images);
			fclose(f_labels);

			// Verify we collected enough data
			if (collected < this->numSample) {
				this->numSample = collected; // Update to actual count
			}


			// Shuffle indices
			std::vector<int> idx(numSample);
			iota(idx.begin(), idx.end(), 0);
			std::shuffle(idx.begin(), idx.end(), std::mt19937{ std::random_device{}() });

			// Create shuffled copies
			float* ShuffledSamples = new float[numSample * inputDim];
			float* ShuffledTargets = new float[numSample];

			for (int i = 0; i < numSample; i++) {
				ShuffledTargets[i] = targets[idx[i]];
				memcpy(
					&ShuffledSamples[i * inputDim],
					&Samples[idx[i] * inputDim],
					inputDim * sizeof(float)
				);
			}

			delete[] Samples;
			delete[] targets;

			Samples = ShuffledSamples;
			targets = ShuffledTargets;


			return true;
		}


		void Save_Encoder_File(const char* filename) {
			if (SavedEncoderWeights == nullptr || EncoderLayerSizes == nullptr) {
				MessageBox::Show("There are no trained encoders to register!");
				return;
			}

			std::ofstream file(filename);
			if (file.is_open()) {
				//
				file << EncoderNumLayers << std::endl;
				for (int i = 0; i < EncoderNumLayers; i++) {
					file << EncoderLayerSizes[i] << " ";
				}
				file << std::endl;

				int total_enc_w = 0;
				int total_enc_b = 0;
				for (int i = 0; i < EncoderNumLayers - 1; i++) {
					total_enc_w += EncoderLayerSizes[i] * EncoderLayerSizes[i + 1];
					total_enc_b += EncoderLayerSizes[i + 1];
				}

				file << "ENCODER_WEIGHTS" << std::endl;
				for (int i = 0; i < total_enc_w; i++) {
					file << SavedEncoderWeights[i] << " ";
				}
				file << std::endl;


				file << "ENCODER_BIASES" << std::endl;
				for (int i = 0; i < total_enc_b; i++) {
					file << SavedEncoderBiases[i] << " ";
				}
				file.close();
				MessageBox::Show("Encoder weights were successfully saved.:\n" + gcnew String(filename));
			}
			else {
				MessageBox::Show("The file could not be created!");
			}
		}

		bool Load_Encoder_File(const char* filename) {
			std::ifstream file(filename);
			if (!file.is_open()) {
				MessageBox::Show("Encoder file not found! Train and save AE first.");
				return false;
			}

			// Mimariyi oku
			int temp_val = 0;
			file >> temp_val;
			EncoderNumLayers = temp_val;

			if (EncoderLayerSizes) delete[] EncoderLayerSizes;
			EncoderLayerSizes = new int[EncoderNumLayers];

			for (int i = 0; i < EncoderNumLayers; i++) {
				file >> EncoderLayerSizes[i];
			}

			int total_enc_w = 0;
			int total_enc_b = 0;
			for (int i = 0; i < EncoderNumLayers - 1; i++) {
				total_enc_w += EncoderLayerSizes[i] * EncoderLayerSizes[i + 1];
				total_enc_b += EncoderLayerSizes[i + 1];
			}

			if (SavedEncoderWeights) delete[] SavedEncoderWeights;
			if (SavedEncoderBiases) delete[] SavedEncoderBiases;
			SavedEncoderWeights = new float[total_enc_w];
			SavedEncoderBiases = new float[total_enc_b];

			char buffer[256];
			file.getline(buffer, 256); 
			file.getline(buffer, 256); 

			for (int i = 0; i < total_enc_w; i++) {
				file >> SavedEncoderWeights[i];
			}

			file.getline(buffer, 256);
			file.getline(buffer, 256); // Read and skip the "ENCODER_BIASES" section.

			for (int i = 0; i < total_enc_b; i++) {
				file >> SavedEncoderBiases[i];
			}

			file.close();

			// Log
			textBox1->Text += "Encoder Loaded From File.\r\n";
			textBox1->Text += "Arch: ";
			for (int i = 0; i < EncoderNumLayers; i++) textBox1->Text += EncoderLayerSizes[i] + " ";
			textBox1->Text += "\r\n";

			return true;
		}


		// It reads the string entered by the user (e.g., "256, 64") and returns a vector.
		std::vector<int> ParseLayerConfig() {
			std::vector<int> layers;
			try {

				array<String^>^ parts = HiddenLayerBox->Text->Split(',');

				for (int i = 0; i < parts->Length; i++) {
					// Remove the spaces and convert to a number.
					String^ s = parts[i]->Trim();
					if (!String::IsNullOrEmpty(s)) {
						int val = Convert::ToInt32(s);
						if (val > 0) layers.push_back(val);
					}
				}
			}
			catch (Exception^ e) {
				MessageBox::Show("Layer settings are incorrect! Please enter the number in the format '256, 64'.");
				layers.clear();
			}
			return layers;
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
					label = numLabel - 1; //Döngüler 0 dan baþladýðýndan, label deðeri 0 dan baþlamasý için bir eksiði alýnmýþtýr
					if (numSample == 0) { //Dinamik alýnan ilk örnek için sadece
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
			
			std::ifstream file;
			file.open("../Data/mnist_network.txt");

			if (!file.is_open()) {
				MessageBox::Show("Error: Could not find mnist_network.txt\n\nPlease train and save network first.");
				return;
			}

			// Read network architecture (native int variables)
			int temp_num_layers;
			file >> temp_num_layers;
			this->num_layers_total = temp_num_layers;

			// Allocate layer sizes array
			if (this->layer_sizes != nullptr) delete[] this->layer_sizes;
			this->layer_sizes = new int[this->num_layers_total];

			// Read each layer size (native int)
			for (int i = 0; i < this->num_layers_total; i++) {
				int temp_size;
				file >> temp_size;
				this->layer_sizes[i] = temp_size;
			}

			// Update class members
			this->inputDim = this->layer_sizes[0];
			this->class_count = this->layer_sizes[this->num_layers_total - 1];

			// Calculate total weights and biases
			int total_w = 0;
			int total_b = 0;
			for (int i = 0; i < this->num_layers_total - 1; i++) {
				total_w += this->layer_sizes[i] * this->layer_sizes[i + 1];
				total_b += this->layer_sizes[i + 1];
			}

			// Allocate memory
			if (this->GlobalWeights != nullptr) delete[] this->GlobalWeights;
			if (this->GlobalBiases != nullptr) delete[] this->GlobalBiases;

			this->GlobalWeights = new float[total_w];
			this->GlobalBiases = new float[total_b];

			// Skip to WEIGHTS section
			char buffer[256];
			file.getline(buffer, 256); // Skip rest of current line
			file.getline(buffer, 256); // Read "WEIGHTS" line

			// Read all weights (native float)
			for (int i = 0; i < total_w; i++) {
				float temp_weight;
				file >> temp_weight;
				this->GlobalWeights[i] = temp_weight;
			}

			// Skip to BIASES section
			file.getline(buffer, 256); // Skip rest of current line
			file.getline(buffer, 256); // Read "BIASES" line

			// Read all biases (native float)
			for (int i = 0; i < total_b; i++) {
				float temp_bias;
				file >> temp_bias;
				this->GlobalBiases[i] = temp_bias;
			}

			file.close();

			textBox1->Text = "- Network Loaded -\r\n\r\n";
			textBox1->Text += "Architecture: ";
			for (int i = 0; i < this->num_layers_total; i++) {
				textBox1->Text += System::Convert::ToString(this->layer_sizes[i]);
				if (i < this->num_layers_total - 1) textBox1->Text += " -> ";
			}
			textBox1->Text += "\r\n\r\n";
			textBox1->Text += "Total weights: " + System::Convert::ToString(total_w) + "\r\n";
			textBox1->Text += "Total biases: " + System::Convert::ToString(total_b) + "\r\n\r\n";
			textBox1->Text += "Network ready for testing!\r\n";


        }//Read_Data
        private: System::Void saveDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			// Check if network is trained
			if (GlobalWeights == nullptr || GlobalBiases == nullptr || layer_sizes == nullptr) {
				MessageBox::Show("No trained network to save! Please train first.");
				return;
			}

			// Calculate total weights and biases
			int total_w = 0;
			int total_b = 0;
			for (int i = 0; i < num_layers_total - 1; i++) {
				total_w += layer_sizes[i] * layer_sizes[i + 1];
				total_b += layer_sizes[i + 1];
			}

			// Save network architecture and weights
			std::ofstream file("../Data/mnist_network.txt");
			if (!file.bad()) {
				// Header: num_layers, then each layer size
				file << num_layers_total << std::endl;
				for (int i = 0; i < num_layers_total; i++) {
					file << layer_sizes[i] << " ";
				}
				file << std::endl;

				// Save all weights
				file << "WEIGHTS" << std::endl;
				for (int i = 0; i < total_w; i++) {
					file << GlobalWeights[i] << " ";
					if ((i + 1) % 10 == 0) file << std::endl;
				}
				file << std::endl;

				// Save all biases
				file << "BIASES" << std::endl;
				for (int i = 0; i < total_b; i++) {
					file << GlobalBiases[i] << " ";
				}
				file << std::endl;

				file.close();

				textBox1->Text += "\r\n- Nwtwork Saved -\r\n";
				textBox1->Text += "File: ../Data/mnist_network.txt\r\n";
				textBox1->Text += "Layers: " + num_layers_total + "\r\n";
				textBox1->Text += "Total weights: " + total_w + "\r\n";
				textBox1->Text += "Total biases: " + total_b + "\r\n";

				MessageBox::Show("Network saved successfully!\n\nFile: mnist_network.txt\nWeights: " + total_w + "\nBiases: " + total_b);
			}
			else {
				MessageBox::Show("Error: Could not create file for saving!");
			}


        }//Save_Data
	    private: System::Void testingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			
			if (GlobalWeights == nullptr || GlobalBiases == nullptr) {
				MessageBox::Show("Please train the network first!");
				return;
			}

			// Load Mnist Test Data
			bool success = LoadMNIST_Subset("t10k-images.idx3-ubyte", "t10k-labels.idx1-ubyte");

			if (!success) {
				MessageBox::Show("ERROR: Could not load MNIST test files!\n\nMake sure these files exist:\n- t10k-images.idx3-ubyte\n- t10k-labels.idx1-ubyte");
				return;
			}

			textBox1->Text = "- Testing Started -\r\n";
			textBox1->Text += "Loaded " + System::Convert::ToString(numSample) + " test samples\r\n\r\n";

			int correct_count = 0;
			int confusion_matrix[10][10] = { 0 }; // For detailed analysis

			// Allocate buffers for forward pass
			int max_layer_size = 0;
			for (int i = 0; i < num_layers_total; i++) {
				if (layer_sizes[i] > max_layer_size)
					max_layer_size = layer_sizes[i];
			}

			float* current_input = new float[max_layer_size];
				
				// Check if layer_sizes matches class_count to avoid crashes
				if (layer_sizes[num_layers_total - 1] != class_count) {
					// Ideally handle error, but here we just force it for safety logic
					class_count = layer_sizes[num_layers_total - 1];
				}

				int input_dim = layer_sizes[0];
				float* desired = new float[class_count];
				//epoch = 0;

				// Calculate Offsets
				int num_matrices = num_layers_total - 1;
				int* w_offsets = new int[num_matrices];
				int* b_offsets = new int[num_matrices];
				int* node_offsets = new int[num_layers_total];

				int w_ptr = 0;
				int b_ptr = 0;
				int node_ptr = 0;
				int total_nodes = 0;

				for (int i = 0; i < num_layers_total; i++) {
					node_offsets[i] = node_ptr;
					node_ptr += layer_sizes[i];
					total_nodes += layer_sizes[i];

					if (i < num_matrices) {
						w_offsets[i] = w_ptr;
						b_offsets[i] = b_ptr;
						w_ptr += (layer_sizes[i] * layer_sizes[i + 1]);
						b_ptr += layer_sizes[i + 1];
					}
				}

				// Allocate RAM for Neural Activities
				float* all_net = new float[total_nodes];
				float* all_fnet = new float[total_nodes];
				float* all_fnet_der = new float[total_nodes];
				float* all_delta = new float[total_nodes];

				// Training Loop

				//total_err = 0.0f;

				for (int step = 0; step < numSample; step++) {

					// Forward
					// Load Input Data into Layer 0
					for (int i = 0; i < input_dim; i++) {
						all_fnet[i] = Samples[step * input_dim + i];
					}

					for (int l = 0; l < num_matrices; l++) {
						int inputs = layer_sizes[l];
						int nodes = layer_sizes[l + 1];

						// Set pointers to the correct section of the arrays
						float* W = &GlobalWeights[w_offsets[l]];
						float* B = &GlobalBiases[b_offsets[l]];
						float* Input = &all_fnet[node_offsets[l]];     // Output of prev layer
						float* Net = &all_net[node_offsets[l + 1]];      // Net of curr layer
						float* Fnet = &all_fnet[node_offsets[l + 1]];    // Output of curr layer
						float* FNetDer = &all_fnet_der[node_offsets[l + 1]];

						for (int k = 0; k < nodes; k++) {
							Net[k] = 0.0f;
							for (int i = 0; i < inputs; i++) {
								Net[k] += W[k * inputs + i] * Input[i];
							}
							Net[k] += B[k];

							// Activation function
							Fnet[k] = ((2.0f / (1.0f + exp(-Net[k]))) - 1.0f);
							FNetDer[k] = (0.5f * (1.0f - Fnet[k] * Fnet[k]));
						}
					}
					// Find predicted class
					int predicted_class = 0;
					float* Fnet = &all_fnet[node_offsets[num_matrices]];
					float max_val = Fnet[0];

					for (int k = 1; k < 10; k++) {
						if (Fnet[k] > max_val) {
							max_val = Fnet[k];
							predicted_class = k;
						}
					}

					// Check against true label
					int true_label = (int)targets[step];

					if (predicted_class == true_label) {
						correct_count++;
					}
					
					// Update confusion matrix
					confusion_matrix[true_label][predicted_class]++;
				}
				// Calculate 
				float accuracy = (float)correct_count / (float)numSample * 100.0f;

				textBox1->Text += "- Results -\r\n";
				textBox1->Text += "Accuracy: " + accuracy.ToString("F2") + "%\r\n";
				textBox1->Text += "Correct: " + correct_count + " / " + numSample + "\r\n\r\n";

				textBox1->Text += "Per-Class Accuracy:\r\n";
				for (int i = 0; i < 10; i++) {
					int total_class = 0;
					for (int j = 0; j < 10; j++) {
						total_class += confusion_matrix[i][j];
					}
					if (total_class > 0) {
						float class_acc = (float)confusion_matrix[i][i] / (float)total_class * 100.0f;
						textBox1->Text += "  Digit " + i + ": " + class_acc.ToString("F1") + "%\r\n";
					}
				}

				// Clean up
				delete[] current_input;

				MessageBox::Show("Testing completed!\n\nAccuracy: " + accuracy.ToString("F2") + "%");

				delete[] w_offsets; delete[] b_offsets; delete[] node_offsets;
				delete[] all_net; delete[] all_fnet; delete[] all_fnet_der; delete[] all_delta;
				delete[] desired;
			
	    }//Testing

	private: System::Void trainingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Load Mnist Training Data
		bool success = LoadMNIST_Subset("train-images.idx3-ubyte", "train-labels.idx1-ubyte");

		if (!success) {
			MessageBox::Show("ERROR: Could not load MNIST training files!\n\nMake sure these files are in the same folder as your .exe:\n- train-images.idx3-ubyte\n- train-labels.idx1-ubyte");
			return;
		}

		textBox1->Text = "- Training Started -\r\n";
		textBox1->Text += "Loaded " + System::Convert::ToString(numSample) + " training samples\r\n";
		textBox1->Text += "Input dimension: " + System::Convert::ToString(inputDim) + "\r\n\r\n";


		// Get hidden layers from the user 
		std::vector<int> hiddenLayers = ParseLayerConfig();
		if (hiddenLayers.size() == 0) return; // Hata varsa çýk

		// Total layers = Input + Hidden Layers + Output
		num_layers_total = 2 + hiddenLayers.size();

		if (layer_sizes) delete[] layer_sizes;
		layer_sizes = new int[num_layers_total];

		// Input Layer
		layer_sizes[0] = inputDim; // 784

		// Hidden Layers
		for (size_t i = 0; i < hiddenLayers.size(); i++) {
			layer_sizes[i + 1] = hiddenLayers[i];
		}

		// 3. Çýkýþ Katmaný
		this->class_count = 10;
		layer_sizes[num_layers_total - 1] = class_count;

		// Log Bas
		textBox1->Text += "Architecture: ";
		for (int i = 0; i < num_layers_total; i++) {
			textBox1->Text += layer_sizes[i].ToString();
			if (i < num_layers_total - 1) textBox1->Text += " ->\r\n ";
		}


		float learning_rate;
		float Min_Err;
		int Max_epoch;
		int epoch;
		this->class_count = 10;       // MNIST digits 0-9


		learning_rate = Convert::ToSingle(LearningRateBox->Text);
		Min_Err = Convert::ToSingle(minErrorBox->Text);
		Max_epoch = Convert::ToInt32(EpochBox->Text);


		int total_w = 0;
		int total_b = 0;
		for (int i = 0; i < num_layers_total - 1; i++) {
			total_w += layer_sizes[i] * layer_sizes[i + 1];
			total_b += layer_sizes[i + 1];
		}

		textBox1->Text += "Total weights: " + total_w + "\r\n";
		textBox1->Text += "Total biases: " + total_b + "\r\n\r\n";

		// 5. ALLOCATE AND INITIALIZE WEIGHTS
		if (GlobalWeights) delete[] GlobalWeights;
		if (GlobalBiases) delete[] GlobalBiases;

		GlobalWeights = new float[total_w];
		GlobalBiases = new float[total_b];

		// Xavier initialization for better convergence
		for (int i = 0; i < total_w; i++) {
			GlobalWeights[i] = ((float)rand() / RAND_MAX - 0.5f) * 0.2f; // Small random values
		}
		for (int i = 0; i < total_b; i++) {
			GlobalBiases[i] = 0.0f;
		}

		textBox1->Text += "Starting training.\r\n";
		textBox1->Refresh();


		float* err = train_fcn_mlp(
			Samples, numSample, targets,
			layer_sizes, num_layers_total,
			GlobalWeights, GlobalBiases,
			learning_rate, Min_Err, 
			Max_epoch, epoch, class_count
		);


		textBox1->Text += "\r\n- Training Completed -\r\n";
		textBox1->Text += "Epoch: " + System::Convert::ToString(epoch) + "\r\n";
		if (epoch > 0) {
			textBox1->Text += "Final error: " + System::Convert::ToString(err[epoch - 1]) + "\r\n";
		}


		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series1"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;

		for (int i = 0; i < epoch; i++) {
			chart1->Series["Series1"]->Points->AddXY(i, err[i]);
		}
		chart1->ChartAreas[0]->AxisX->Title = "Epoch";
		chart1->ChartAreas[0]->AxisY->Title = "Error";
		chart1->Refresh();

		if (err) delete[] err;

		MessageBox::Show("Training completed!\n\nEpoch: " + epoch + "\n\nYou can now test the network.");

}
private: System::Void trainAutoEncoderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	

	if (numSample == 0) LoadMNIST_Subset("train-images.idx3-ubyte", "train-labels.idx1-ubyte");

	textBox1->Text = "- AutoEncoder Training -\r\n";

	// Get the encoder structure from the user
	std::vector<int> userHiddenLayers = ParseLayerConfig();
	if (userHiddenLayers.size() == 0) {
		MessageBox::Show("Please enter the hidden layers (e.g., 256, 64, 256).");
		return;
	}

	// Vektörde AE mimarisi
	std::vector<int> ae_arch;
	ae_arch.push_back(Convert::ToInt32(inputDim)); // 784

	// Encoder Kýsmý (256, 64)
	for (int val : userHiddenLayers) ae_arch.push_back(val);

	if (userHiddenLayers.size() > 1) {
		for (int i = userHiddenLayers.size() - 2; i >= 0; i--) {
			ae_arch.push_back(userHiddenLayers[i]);
		}
	}

	// Çýkýþ (784)
	ae_arch.push_back(Convert::ToInt32(inputDim));

	num_layers_total = ae_arch.size();
	if (layer_sizes) delete[] layer_sizes;
	layer_sizes = new int[num_layers_total];

	textBox1->Text += "AE Arch: ";
	for (int i = 0; i < num_layers_total; i++) {
		layer_sizes[i] = ae_arch[i];
		textBox1->Text += layer_sizes[i].ToString();
		if (i < num_layers_total - 1) textBox1->Text += " -> ";
	}
	textBox1->Text += "\r\n";


	int bottleneckIndex = 0; 
	int minNeurons = 999999;

	for (int i = 0; i < num_layers_total; i++) {
		if (layer_sizes[i] < minNeurons) {
			minNeurons = layer_sizes[i];
			bottleneckIndex = i;
		}
	}

	EncoderNumLayers = bottleneckIndex + 1;

	textBox1->Text += "Bottleneck detected at layer " + bottleneckIndex + " (" + minNeurons + " neurons).\r\n";
	textBox1->Text += "Encoder will be saved up to this layer.\r\n";


	if (EncoderLayerSizes) delete[] EncoderLayerSizes;
	EncoderLayerSizes = new int[EncoderNumLayers];
	for (int i = 0; i < EncoderNumLayers; i++) {
		EncoderLayerSizes[i] = layer_sizes[i];
	}

	int total_w = 0;
	int total_b = 0;
	for (int i = 0; i < num_layers_total - 1; i++) {
		total_w += layer_sizes[i] * layer_sizes[i + 1];
		total_b += layer_sizes[i + 1];
	}

	if (GlobalWeights) delete[] GlobalWeights;
	if (GlobalBiases) delete[] GlobalBiases;
	GlobalWeights = new float[total_w];
	GlobalBiases = new float[total_b];


	for (int i = 0; i < total_w; i++) GlobalWeights[i] = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
	for (int i = 0; i < total_b; i++) GlobalBiases[i] = 0.0f;


	float learning_rate; 
	float Min_Err;
	int Max_epoch;        
	int epoch;
	this->class_count = 10;       // MNIST digits 0-9


	learning_rate = Convert::ToSingle(LearningRateBox->Text);
	Min_Err = Convert::ToSingle(minErrorBox->Text);
	Max_epoch = Convert::ToInt32(EpochBox->Text);

	float* err = train_autoencoder(Samples, numSample, layer_sizes, num_layers_total,
		GlobalWeights, GlobalBiases, learning_rate, Min_Err, Max_epoch, epoch);

	// 5. Grafiði Çiz (Reconstruction Error)
	chart1->Series["Series1"]->Points->Clear();
	for (int i = 0; i < epoch; i++) chart1->Series["Series1"]->Points->AddXY(i, err[i]);

	textBox1->Text += "Epochs: " + System::Convert::ToString(epoch) + "\r\n";
	textBox1->Text += "AE Training Done. Final Error: " + err[epoch - 1] + "\r\n";

	int enc_w_total = 0;
	int enc_b_total = 0;


	for (int i = 0; i < EncoderNumLayers - 1; i++) {
		enc_w_total += EncoderLayerSizes[i] * EncoderLayerSizes[i + 1];
		enc_b_total += EncoderLayerSizes[i + 1];
	}

	if (SavedEncoderWeights) delete[] SavedEncoderWeights;
	if (SavedEncoderBiases) delete[] SavedEncoderBiases;
	SavedEncoderWeights = new float[enc_w_total];
	SavedEncoderBiases = new float[enc_b_total];

	// GlobalWeights dizisinin baþýndan itibaren (ilk iki matrisi) kopyala
	for (int i = 0; i < enc_w_total; i++) SavedEncoderWeights[i] = GlobalWeights[i];
	for (int i = 0; i < enc_b_total; i++) SavedEncoderBiases[i] = GlobalBiases[i];

	MessageBox::Show("The autoencoder has been trained! The encoder has been stored in memory.");

	delete[] err;
	

}
private: System::Void trainingWithEncoderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	if (SavedEncoderWeights == nullptr) {
		MessageBox::Show("Please train Autoencoder first!");
		return;
	}


	if (numSample == 0) {
		bool success = LoadMNIST_Subset("train-images.idx3-ubyte", "train-labels.idx1-ubyte");
		if (!success) {
			MessageBox::Show("MNIST data could not be loaded!");
			return;
		}
	}

	textBox1->Text += "\r\n- Classifier Training (With Pre-trained Encoder) -\r\n";

	String^ userLayerInput = HiddenLayerBox->Text->Trim();
	array<String^>^ userLayersSplit = userLayerInput->Split(gcnew array<wchar_t>{','}, StringSplitOptions::RemoveEmptyEntries);

	int numUserAddedLayers = userLayersSplit->Length;

	if (numUserAddedLayers == 0) {
		MessageBox::Show("Please enter the layers to be added (e.g., 10 or 64.10).");
		return;
	}

	// New total number of layers: Encoder Depth + User Additions
	num_layers_total = EncoderNumLayers + numUserAddedLayers;

	if (layer_sizes) delete[] layer_sizes;
	layer_sizes = new int[num_layers_total];

	// Copy the Encoder Structure
	for (int i = 0; i < EncoderNumLayers; i++) {
		layer_sizes[i] = EncoderLayerSizes[i];
	}

	// Paste the Layers Added by the User
	for (int i = 0; i < numUserAddedLayers; i++) {
		try {
			layer_sizes[EncoderNumLayers + i] = Convert::ToInt32(userLayersSplit[i]);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: Layer sizes must be numeric!");
			return;
		}
	}

	textBox1->Text += "\r\n- Classifier Training (Transfer Learning) -\r\n";
	textBox1->Text += "Architecture: ";
	for (int i = 0; i < num_layers_total; i++) {
		textBox1->Text += layer_sizes[i].ToString();
		if (i < num_layers_total - 1) textBox1->Text += " -> ";
	}
	
	int enc_w_count = 0;
	int enc_b_count = 0;


	for (int i = 0; i < EncoderNumLayers - 1; i++) {
		enc_w_count += layer_sizes[i] * layer_sizes[i + 1];
		enc_b_count += layer_sizes[i + 1];
	}

	int total_w = 0;
	int total_b = 0;
	for (int i = 0; i < num_layers_total - 1; i++) {
		total_w += layer_sizes[i] * layer_sizes[i + 1];
		total_b += layer_sizes[i + 1];
	}

	if (GlobalWeights) delete[] GlobalWeights;
	if (GlobalBiases) delete[] GlobalBiases;
	GlobalWeights = new float[total_w];
	GlobalBiases = new float[total_b];


	for (int i = 0; i < enc_w_count; i++) GlobalWeights[i] = SavedEncoderWeights[i];
	for (int i = 0; i < enc_b_count; i++) GlobalBiases[i] = SavedEncoderBiases[i];

	for (int i = enc_w_count; i < total_w; i++)
		GlobalWeights[i] = ((float)rand() / RAND_MAX - 0.5f) * 0.2f;

	for (int i = enc_b_count; i < total_b; i++)
		GlobalBiases[i] = 0.0f;

	textBox1->Text += "Encoder weights transferred. Traning last layer.\r\n";

	
	float learning_rate;
	float Min_Err;
	int Max_epoch; 
	int epoch;
	this->class_count = 10;       // MNIST digits 0-9


	learning_rate = Convert::ToSingle(LearningRateBox->Text);
	Min_Err = Convert::ToSingle(minErrorBox->Text);
	Max_epoch = Convert::ToInt32(EpochBox->Text);

	if (layer_sizes[num_layers_total - 1] != class_count) {
		textBox1->Text += "WARNING: Last layer size (" + layer_sizes[num_layers_total - 1] +
			") does not match class count (" + class_count + ")!\r\n";
	}

	float* err = train_fcn_mlp(Samples, numSample, targets, layer_sizes, num_layers_total,
		GlobalWeights, GlobalBiases, learning_rate, Min_Err, Max_epoch, epoch, 10);

	textBox1->Text += "Epoch: " + System::Convert::ToString(epoch) + "\r\n";
	textBox1->Text += "Training Done. Final Error: " + err[epoch - 1] + "\r\n";

	chart1->Series["Series1"]->Points->Clear();
	for (int i = 0; i < epoch; i++) chart1->Series["Series1"]->Points->AddXY(i, err[i]);

	MessageBox::Show("Sýnýflandýrýcý Transfer Learning ile eðitildi!");
	delete[] err;
}
private: System::Void readEncoderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	// Once you open the program, you can directly press this button and start pulling the weights.
	if (Load_Encoder_File("../Data/trained_encoder.txt")) {
		MessageBox::Show("Encoder loaded! You can now create a 'Train Classifier'.");
	}
}
private: System::Void saveEncoderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	// Press this button after AE has been trained.
	Save_Encoder_File("../Data/trained_encoder.txt");
}
};
}
