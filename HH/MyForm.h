#pragma once
#include "Henon_Heles.h"
#include<iostream>
namespace HH {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Henon_Heles* hh;
		double E,y_min,y_max,py_max,py_min,ys,pys;
		double* n_u,*y,*py;
		int* Y, * PY;
		int w, h,N;
		int Y_max, Y_min, PY_max, PY_min;
		bool isdraw;
		Color^ col;
		Graphics^ gr;
		Brush^ br;
		BufferedGraphics^ buffergr;
		
	private: System::Windows::Forms::Button^ button2;
		   BufferedGraphicsContext^ buffergrcont;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Info;
			this->panel1->Location = System::Drawing::Point(113, 99);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(656, 451);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->Location = System::Drawing::Point(190, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->Location = System::Drawing::Point(325, 18);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Info;
			this->textBox3->Location = System::Drawing::Point(468, 19);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(167, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"E";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(296, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"y0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(431, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"py0";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Info;
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(616, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"draw";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Info;
			this->button2->Location = System::Drawing::Point(735, 18);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"clear";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->CancelButton = this->button1;
			this->ClientSize = System::Drawing::Size(865, 598);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	E = Convert::ToDouble(textBox1->Text);
		
	w = panel1->Width;
	h = panel1->Height;
	gr = panel1->CreateGraphics();
	gr->DrawLine(Pens::Black, 20, h - 21, 20, 1);
	gr->DrawLine(Pens::Black, 15, 10, 20, 1);
	gr->DrawLine(Pens::Black, 25, 10, 20, 1);
	gr->DrawLine(Pens::Black, 20, h - 21, w - 2, h - 21);
	gr->DrawLine(Pens::Black, w - 12, h - 26, w - 2, h - 21);
	gr->DrawLine(Pens::Black, w - 12, h - 16, w - 2, h - 21);
	for (int i = h - 21;i > 40;i = i - 27)
	{
		gr->DrawLine(Pens::Black, 20, i, 30,i );
	}

	for (int i = 20;i < w-40;i = i + 30)
	{
		gr->DrawLine(Pens::Black, i, h-21, i, h-31);
	}
	
	/*double* points1 = new double[11];
	double a = -0.5;
	for (int i = 0;i < 11;i++)
	{
		points1[i] = a;
		a = a + 0.1;
	}
	double b = -0.5;
	
	for (int i = h - 21;i > 40;i = i - 27)
	{
		Label^ label3 = gcnew Label;
		label3->Location = Point(60, i);
		label3->Size = System::Drawing::Size(30, 30);
		label3->Text = L"" +b;
		this->panel1->Controls->Add(label3);
		b = b + 0.1;
	}*/
	Label^ label1 = gcnew Label;
	Label^ label2 = gcnew Label;
	label1->Location = Point(30, 20);
	label1->Size = System::Drawing::Size(20, 20);
	label1->Text = L"py";
    label2->Location = Point(w-30, h-50);
	label2->Size = System::Drawing::Size(20, 20);
	label2->Text = L"y";
	this->panel1->Controls->Add(label1);
	this->panel1->Controls->Add(label2);
	n_u = new double[4];
	n_u[0] = 0;
	n_u[1]= Convert::ToDouble(textBox2->Text);
	n_u[3]= Convert::ToDouble(textBox3->Text);
	n_u[2]= sqrt(2 * E - n_u[3] * n_u[3] - n_u[1] * n_u[1] + 2 * n_u[1] * n_u[1] * n_u[1] / 3);
	hh = new Henon_Heles(0.001);
	hh->SetInit(n_u);
	
	N = 1e8;
	Y = new int[N];
	PY = new int[N];
	y = new double[N];
	py = new double[N];
	int j = 0;
	for (int i = 0;i < N;i++)
	{
		hh->DoOneStep();
		if (abs(hh->y1[0]) < 1e-4)
		{
			y[j] = hh->y1[1];
			py[j] = hh->y1[3];
			j++;
		}
		
		hh->SetInit(hh->y1);
	}
	y_min = y_max = 0;
	py_min = py_max = 0;
	for (int i = 0;i < j;i++)
	{
		if (y[i] < y_min) y_min = y[i];
		if (y[i] > y_max) y_max = y[i];
		if (py[i] < py_min) py_min = py[i];
		if (py[i] > py_max) py_max = py[i];
	}
	
	Y_min = w/2-20;
	Y_max = w - 1;
	PY_min = h/2;
	PY_max = h - 1;
	ys = (y_max - y_min) / (Y_max - Y_min);

	pys = (py_max - py_min) / (PY_max - PY_min);
	Brush^ br = gcnew SolidBrush(Color::Red);
	
	/*this->buffergrcont = BufferedGraphicsManager::Current;
	this->buffergrcont->MaximumBuffer = System::Drawing::Size(w + 1, h + 1);
	this->buffergr = buffergrcont->Allocate(gr, Rectangle(0, 0, w + 1, h + 1));
	this->buffergr->Graphics->Clear(System::Drawing::SystemColors::Info);*/
	gr->DrawLine(Pens::Black, 20, h - 21, 20, 1);
	gr->DrawLine(Pens::Black, 15, 10, 20, 1);
	gr->DrawLine(Pens::Black, 25, 10, 20, 1);
	gr->DrawLine(Pens::Black, 20, h-21, w-2, h-21);
	gr->DrawLine(Pens::Black, w-12, h - 26, w - 2, h - 21);
	gr->DrawLine(Pens::Black, w-12, h - 16, w - 2, h - 21);
	
		for (int i = 0;i < j;i++)
		{
			
			Y[i] = Y_min + y[i] / ys/0.8 ;
			PY[i] = PY_min - py[i] / pys/0.8 ;
			gr->FillEllipse(br, Y[i], PY[i], 2, 2);
			//buffergr->Graphics->FillEllipse(br, Y[i] , PY[i] , 4, 4);
		}
		//buffergr->Render();


}

		
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	gr->Clear(System::Drawing::SystemColors::Info);
}
};
}
